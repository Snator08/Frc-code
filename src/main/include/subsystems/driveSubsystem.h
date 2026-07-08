#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/kinematics/DifferentialDriveOdometry.h>
#include <photon/PhotonCamera.h>
#include <rev/SparkMax.h>
#include <frc/Encoder.h>
#include <studica/AHRS.h>
#include "Constants.h"
#include <frc/controller/PIDController.h>



class driveSubsystem : public frc2::SubsystemBase {
    private:
        photon::PhotonCamera camera1{OperatorConstants::camera1Name};

        //---------------------
        // Setup Motor Objects
        //---------------------
        rev::spark::SparkMax motor1Left{9, rev::spark::SparkLowLevel::MotorType::kBrushed}; //Left Side of bot with 1 being the front motors
        rev::spark::SparkMax motor2Left{4, rev::spark::SparkLowLevel::MotorType::kBrushed}; //Left Side of bot with 2 being the rear motors
        rev::spark::SparkMax motor1Right{5, rev::spark::SparkLowLevel::MotorType::kBrushed}; //Right Side of bot with 1 being the front motors
        rev::spark::SparkMax motor2Right{6, rev::spark::SparkLowLevel::MotorType::kBrushed}; //Right Side of bot with 2 being the rear motors

        frc::DifferentialDrive m_drive{motor1Left, motor1Right};

        //-----------------------
        // Setup Encoder Objects
        //-----------------------

        frc::Encoder m_encoderX{0, 1};
        frc::Encoder m_encoderY{2, 3};

        //-------------------
        // Setup Gyro Object
        //-------------------

        studica::AHRS navx{studica::AHRS::kUSB1};


        frc::DifferentialDriveOdometry m_odometry;

       frc::PIDController m_turnPID{1.0, 0.0, 0.0};

    public:
        driveSubsystem();

        void Periodic() override;
        void arcadeDrive(double speed, double rotation);
        void faceTarget(frc::Translation2d targetPose);
        bool isFacingTarget();
        void drive(double speed);
        void stop();
        double getYaw();
};