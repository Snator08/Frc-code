#pragma once
#include "../subsystems/driveSubsystem.h"
#include "../subsystems/diverterSubsystem.h"
#include "../subsystems/intakeSubsystem.h"
#include <frc2/command/CommandHelper.h>

class autoShootCommand : public frc2::CommandHelper<frc2::Command, autoShootCommand> {
    private:
        driveSubsystem* m_drive;
        diverterSubsystem* m_diverter;
        intakeSubsystem* m_intake;
        frc::Translation2d Target;

    public:
        autoShootCommand(driveSubsystem* m_drive, diverterSubsystem* m_diverter, intakeSubsystem* m_intake, frc::Translation2d Target);

        void Initialize() override;
        void Execute() override;
        void End(bool interrupted) override;
        bool IsFinished() override;
};