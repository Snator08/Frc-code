#include "subsystems/intakeSubsystem.h"
#include <rev/config/SparkMaxConfig.h>

intakeSubsystem::intakeSubsystem() {
    rev::spark::SparkMaxConfig config{};

    config.OpenLoopRampRate(5.0);

config.closedLoop.Pid(0.01, 0.0, 0.0);

    intakeShootMotor.Configure(config, rev::spark::SparkMax::ResetMode::kResetSafeParameters,
                 rev::spark::SparkMax::PersistMode::kPersistParameters);


}

void intakeSubsystem::Set(double speed) {
    intakeShootMotor.Set(speed);
}

void intakeSubsystem::moveToPos(double pos) {
    rev::spark::SparkClosedLoopController m_closedloop = intakeShootMotor.GetClosedLoopController();
    m_closedloop.SetSetpoint(pos, rev::spark::SparkLowLevel::ControlType::kPosition);
}