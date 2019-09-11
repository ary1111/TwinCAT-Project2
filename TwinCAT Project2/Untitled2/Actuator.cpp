///////////////////////////////////////////////////////////////////////////////
// Actuator.cpp
#include "Actuator.h"

Actuator::Actuator(float gearRatio, float nominalCurrent, float torqueConstant)
{
    m_gearratio = gearRatio;
    m_nominalcurrent = nominalCurrent;
    m_torqueconstant = torqueConstant;
}

void Actuator::SetParameters(float gearRatio, float nominalCurrent, float torqueConstant)
{
    m_gearratio = gearRatio;
    m_nominalcurrent = nominalCurrent;
    m_torqueconstant = torqueConstant;
}

int Actuator::ConvertInputTorque(float torque)
{
    return (int)(torque / m_gearratio*(1000/(m_nominalcurrent*m_torqueconstant)));
}