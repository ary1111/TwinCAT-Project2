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

void Actuator::FilterVelocity(float rawVelocity)
{
    int n=500;
    float n_sum;
    for (int i = n-1; i >0; i--)
    {
        m_rawvelocity[i] = m_rawvelocity[i - 1];
        n_sum += m_rawvelocity[i];
    }
    m_rawvelocity[0] = rawVelocity;
    n_sum += m_rawvelocity[0];
    m_realvelocity = n_sum / n;
}

float Actuator::GetVelocity()
{
    return m_realvelocity;
}