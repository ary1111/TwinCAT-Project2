///////////////////////////////////////////////////////////////////////////////
// Actuator.h
#pragma once

class Actuator
{
private:
    float m_gearratio;
    float m_nominalcurrent;
    float m_torqueconstant;
    float m_realvelocity;
    float m_rawvelocity [500] = {};
public:
    Actuator(){};
    Actuator(float gearRatio, float nominalCurrent, float torqueConstant);

    void SetParameters(float gearRatio, float nominalCurrent, float torqueConstant);
    int ConvertInputTorque(float torque);
    void FilterVelocity(float rawVelocity);
    float GetVelocity();
};