#include "subsystems/diverterSubsystem.h"

void diverterSubsystem::Set(double speed) {
    diverterMotor.Set(speed);
}