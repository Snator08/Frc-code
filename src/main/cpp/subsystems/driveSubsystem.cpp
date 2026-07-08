#include "subsystems/driveSubsystem.h"
#include "frc/smartdashboard/SmartDashboard.h"

driveSubsystem::driveSubsystem() {
    motor2Left.Configure(rev::spark::SparkBaseConfig{}.Follow(motor1Left), rev::spark::SparkBase::ResetMode::kNoResetSafeParameters, rev::spark::SparkBase::PersistMode::kPersistParameters);
    motor2Right.Configure(rev::spark::SparkBaseConfig{}.Follow(motor1Right), rev::spark::SparkBase::ResetMode::kNoResetSafeParameters, rev::spark::SparkBase::PersistMode::kPersistParameters);\

    m_turnPID.EnableContinuousInput(-180.0, 180.0);

    m_turnPID.SetTolerance(2.0);
}

void driveSubsystem::Periodic() {
    frc::SmartDashboard::GetBoolean("Gyro Connected", navx.IsCalibrating());
}

void driveSubsystem::arcadeDrive(double rotation, double speed) {
    m_drive.ArcadeDrive(rotation, speed);
}

void driveSubsystem::turnRate(double speed) {
    m_drive.ArcadeDrive(speed, 0);
}

double driveSubsystem::getYaw() {
    return navx.GetYaw();
}