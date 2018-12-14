///////////////////////////////////////////////////////////////////////////////
// Module1.h
#pragma once

#include "Untitled2Interfaces.h"
#include "TcMath.h"
#include <vector>

class CModule1 
	: public ITComObject
	, public ITcADI
	, public ITcWatchSource
///<AutoGeneratedContent id="InheritanceList">
	, public ITcCyclic
///</AutoGeneratedContent>
{
public:
	DECLARE_IUNKNOWN()
	DECLARE_IPERSIST(CID_Untitled2CModule1)
	DECLARE_ITCOMOBJECT_LOCKOP()
	DECLARE_ITCADI()
	DECLARE_ITCWATCHSOURCE()
	DECLARE_OBJPARAWATCH_MAP()
	DECLARE_OBJDATAAREA_MAP()

	CModule1();
	virtual	~CModule1();


///<AutoGeneratedContent id="InterfaceMembers">
	// ITcCyclic
	virtual HRESULT TCOMAPI CycleUpdate(ITcTask* ipTask, ITcUnknown* ipCaller, ULONG_PTR context);

///</AutoGeneratedContent>

	//Ryason begin
	void read_angle();
	void update_position();
	void update_jacobian();
	void calibrate();
	void convert_angle();
	void simple_joint_response();
	void simple_box_interior();
	//void SetReference_torque();
	void set_reference_torque();
	void set_dynamic_torque();
	void force_response();
	void compensate_gravity();
	void compensate_staticmu();
	void zero_torque();

	float offset1;
	float DEG1;
	float DEG2;
	float DEG3;
	float DEG4;
    float DEG5;
	float phi;
	float qB;
	float qM;
	float qQ;
    float phiScale;
    float phiOrig;
    float phiDelta;
    float phiTemp;

	float J11;
	float J12;
	float J14;

	float J21;
	float J24;

	float J31;
	float J32;
	float J34;


	float L1;
	float L2;
	float L3;
	float L4;
	float L5;
    float LW;

	float t1;
	float t2;
	float t3;
	float	t4;
	
	float g;			// units: m/s^2
	float mA;
	float mB;
	float mC;
	float mD;
	float mE;
	float mF;
	float mG;
	float mH;
	float mI;
	float mJ;
	float mK;
	float mL;
	float mM;
	float mP;
	float mQ;

	float    Acmx;
	float    Bcmx;
	float    Ccmx;
	float    Dcmx;
	float	   Dcmy;
	float    Ecmx;
	float    Ecmy;
	float    Fcmx;
	float    Fcmz;
	float    Gcmx;
	float    Gcmz;
	float    Hcmx;
	float    Hcmz;
	float    Icmx;
	float    Icmy;
	float    Icmz;
	float    Jcmz;
	float    Lcmx;
	float    Lcmz;
	float    Mcmx;
	float    Mcmy;
	float    Mcmz;
	float    Pcmx;
	float    Pcmy;
	float    Pcmz;
	float    Qcmx;
	float    Qcmy;
	float    Qcmz;
	//Ryason end

protected:
	DECLARE_ITCOMOBJECT_SETSTATE();

	HRESULT AddModuleToCaller();
	VOID RemoveModuleFromCaller();

	// Tracing
	CTcTrace m_Trace;

///<AutoGeneratedContent id="Members">
	TcTraceLevel m_TraceLevelMax;
	Module1Parameter m_Parameter;
	Module1Inputs m_Inputs;
	Module1Outputs m_Outputs;
	Module1ADS_data m_ADS_data;
	Module1Controls m_Controls;
	Module1System m_System;
	ITcCyclicCallerInfoPtr m_spCyclicCaller;
///</AutoGeneratedContent>

	// TODO: Custom variable
	UINT m_counter;
};
