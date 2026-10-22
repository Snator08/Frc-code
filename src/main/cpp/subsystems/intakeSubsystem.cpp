#include "subsystems/intakeSubsystem.h"
#include <rev/config/SparkMaxConfig.h>

intakeSubsystem::intakeSubsystem() {
    rev::spark::SparkBaseConfig config{};

    config.OpenLoopRampRate(2);

    intakeShootMotor.Configure(config, rev::spark::SparkBase::ResetMode::kNoResetSafeParameters,
                 rev::spark::SparkBase::PersistMode::kNoPersistParameters);


}

void intakeSubsystem::Set(double speed) {
    intakeShootMotor.Set(speed);
}