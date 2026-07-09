#include "commands/AutoShootCommand.h"

autoShootCommand::autoShootCommand(driveSubsystem* m_drive, diverterSubsystem* m_diverter, intakeSubsystem* m_intake, frc::Translation2d Target) 
: m_drive(m_drive), m_diverter(m_diverter), m_intake(m_intake), Target(Target) {
    AddRequirements({m_drive, m_diverter, m_intake});
}

void autoShootCommand::Initialize() {}

void autoShootCommand::Execute() {

    
    m_drive->faceTarget(Target);
    //add shooter speed
    if(m_drive->isFacingTarget()) {
        m_intake->Set(-1);
        m_diverter->Set(-1);
    }
}

void autoShootCommand::End(bool interrupted) {
    m_intake->Set(0);
    m_diverter->Set(0);
}

bool autoShootCommand::IsFinished() {
    return false;
}