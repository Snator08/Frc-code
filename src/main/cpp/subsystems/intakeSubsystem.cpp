#include "subsystems/intakeSubsystem.h"

void intakeSubsystem::Set(double speed) {
    intakeShootMotor.Set(speed);
}