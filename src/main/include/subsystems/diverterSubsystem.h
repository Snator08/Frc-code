#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMax.h>

class diverterSubsystem : public frc2::SubsystemBase {
    private:
        rev::spark::SparkMax diverterMotor{1, rev::spark::SparkLowLevel::MotorType::kBrushed};

    public:
        void Set(double speed);

};