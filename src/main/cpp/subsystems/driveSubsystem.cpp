#include "subsystems/driveSubsystem.h"
#include "frc/smartdashboard/SmartDashboard.h"

#define WheelCircomference 10

driveSubsystem::driveSubsystem() {
    motor2Left.Configure(rev::spark::SparkBaseConfig{}.Follow(motor1Left), rev::spark::SparkBase::ResetMode::kNoResetSafeParameters, rev::spark::SparkBase::PersistMode::kPersistParameters);
    motor2Right.Configure(rev::spark::SparkBaseConfig{}.Follow(motor1Right), rev::spark::SparkBase::ResetMode::kNoResetSafeParameters, rev::spark::SparkBase::PersistMode::kPersistParameters);


}


void driveSubsystem::arcadeDrive(double rotation, double speed) {
    m_drive.ArcadeDrive(speed, rotation);
}


void driveSubsystem::drive(double speed) {
    m_drive.ArcadeDrive(speed, 0);
}

void driveSubsystem::stop() {
    m_drive.ArcadeDrive(0, 0);
}