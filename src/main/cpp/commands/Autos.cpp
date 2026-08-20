#include <frc2/command/Commands.h>
#include "Autos.h"

frc2::CommandPtr DriveForwardAuto(intakeSubsystem* m_intake) {
    return frc2::cmd::Sequence(frc2::cmd::RunOnce(
        [m_intake] {m_intake->Set(0.5);}, {m_intake}),
        frc2::cmd::Wait(3_s),
        frc2::cmd::RunOnce([m_intake] {m_intake->Set(0);}, {m_intake}),
        frc2::cmd::Wait(3_s)).Repeatedly();
    }