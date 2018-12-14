///////////////////////////////////////////////////////////////////////////////
// MotorControllerDriver.h

#ifndef __MOTORCONTROLLERDRIVER_H__
#define __MOTORCONTROLLERDRIVER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TcBase.h"

#define MOTORCONTROLLERDRV_NAME        "MOTORCONTROLLER"
#define MOTORCONTROLLERDRV_Major       1
#define MOTORCONTROLLERDRV_Minor       0

#define DEVICE_CLASS CMotorControllerDriver

#include "ObjDriver.h"

class CMotorControllerDriver : public CObjDriver
{
public:
	virtual IOSTATUS	OnLoad();
	virtual VOID		OnUnLoad();

	//////////////////////////////////////////////////////
	// VxD-Services exported by this driver
	static unsigned long	_cdecl MOTORCONTROLLERDRV_GetVersion();
	//////////////////////////////////////////////////////
	
};

Begin_VxD_Service_Table(MOTORCONTROLLERDRV)
	VxD_Service( MOTORCONTROLLERDRV_GetVersion )
End_VxD_Service_Table


#endif // ifndef __MOTORCONTROLLERDRIVER_H__