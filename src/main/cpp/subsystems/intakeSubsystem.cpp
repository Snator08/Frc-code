#include "subsystems/intakeSubsystem.h"
#include <rev/config/SparkMaxConfig.h>

intakeSubsystem::intakeSubsystem() {
    rev::spark::SparkMaxConfig config{};

    config.OpenLoopRampRate(5.0);

    intakeShootMotor.Configure(config, rev::spark::SparkMax::ResetMode::kResetSafeParameters,
                 rev::spark::SparkMax::PersistMode::kPersistParameters);
}

void intakeSubsystem::Set(double speed) {
    intakeShootMotor.Set(speed);
}