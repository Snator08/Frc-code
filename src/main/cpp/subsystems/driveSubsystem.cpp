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
    m_drive.ArcadeDrive(speed, rotation);
}

void driveSubsystem::faceTarget(frc::Pose2d targetPose) {
    // Odom positon
    // auto pose = getPos();

    //double targetAngle = atan2(targetPose.Y() - pose.Y(), targetPose.X() - pose.X());


    //double output = m_turnPID.Calculate(pose.Rotation().Degrees().value(), targetAngle);

    //m_drive.ArcadeDrive(0.0, output);
}

double driveSubsystem::getYaw() {
    return navx.GetYaw();
}