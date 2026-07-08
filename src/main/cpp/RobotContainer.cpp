#include "robotContainer.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include "Autos.h"
#include <frc2/command/Commands.h>
#include <frc/DriverStation.h>
//#include <cameraserver/CameraServer.h>

RobotContainer::RobotContainer() {


    m_drive.SetDefaultCommand(frc2::cmd::Run([this] {
        if(frc::DriverStation::IsTeleopEnabled) {
            m_drive.arcadeDrive(-m_controller1.GetLeftX(), -m_controller1.GetLeftY());
        }
    },
    {&m_drive}
));

//frc::CameraServer::StartAutomaticCapture();

m_controller1.A().WhileTrue(frc2::cmd::StartEnd(
    [this] {m_intake.Set(-1); m_diverter.Set(-1);},
    [this] {m_intake.Set(0); m_diverter.Set(0);},
    {&m_intake}
));
    

m_controller1.B().WhileTrue(frc2::cmd::StartEnd(
    [this] {m_intake.Set(-1); m_diverter.Set(1);},
    [this] {m_intake.Set(0); m_diverter.Set(0);},
    {&m_diverter}
));

}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
    return DriveForwardAuto(&m_drive);
}