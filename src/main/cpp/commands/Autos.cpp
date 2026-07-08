#include <frc2/command/Commands.h>
#include "Autos.h"

frc2::CommandPtr DriveForwardAuto(driveSubsystem* driveSubsystem) {
    return frc2::cmd::StartEnd([driveSubsystem] {driveSubsystem->drive(0.5);},
                             [driveSubsystem] {driveSubsystem->stop();}).WithTimeout(1_s);
};