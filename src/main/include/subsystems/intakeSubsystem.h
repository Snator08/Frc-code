#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMax.h>

class intakeSubsystem : public frc2::SubsystemBase {
    private:
        //--------------------
        // Setup Motor Objects
        //--------------------

        rev::spark::SparkMax intakeShootMotor{3, rev::spark::SparkLowLevel::MotorType::kBrushed};

    public:
        void Set(double speed);
};