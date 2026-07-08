#include "subsystems/driveSubsystem.h"
#include "frc/smartdashboard/SmartDashboard.h"

#define WheelCircomference 10

driveSubsystem::driveSubsystem() : m_odometry{navx.GetRotation2d(), units::meter_t(m_encoderX.GetDistance()), units::meter_t(m_encoderY.GetDistance())} {
    motor2Left.Configure(rev::spark::SparkBaseConfig{}.Follow(motor1Left), rev::spark::SparkBase::ResetMode::kNoResetSafeParameters, rev::spark::SparkBase::PersistMode::kPersistParameters);
    motor2Right.Configure(rev::spark::SparkBaseConfig{}.Follow(motor1Right), rev::spark::SparkBase::ResetMode::kNoResetSafeParameters, rev::spark::SparkBase::PersistMode::kPersistParameters);\

    m_turnPID.EnableContinuousInput(-180.0, 180.0);

    m_turnPID.SetTolerance(2.0);

    m_encoderX.SetDistancePerPulse(OperatorConstants::deadwheelCircumference / 2048);
    m_encoderY.SetDistancePerPulse(OperatorConstants::deadwheelCircumference / 2048);

}

void driveSubsystem::Periodic() {

    m_odometry.Update(navx.GetRotation2d(), units::meter_t(m_encoderX.GetDistance()), units::meter_t(m_encoderY.GetDistance()));

    frc::SmartDashboard::GetBoolean("Gyro Connected", navx.IsCalibrating());
}

void driveSubsystem::arcadeDrive(double rotation, double speed) {
    m_drive.ArcadeDrive(speed, rotation);
}

void driveSubsystem::faceTarget(frc::Pose2d targetPose) {
     //Odom positon
     frc::Pose2d pose = m_odometry.GetPose();

    double targetAngle = atan2(targetPose.Y().value() - pose.Y().value(), targetPose.X().value() - pose.X().value());


    double output = m_turnPID.Calculate(pose.Rotation().Degrees().value(), targetAngle);

    m_drive.ArcadeDrive(0.0, output);
}

double driveSubsystem::getYaw() {
    return navx.GetYaw();
}