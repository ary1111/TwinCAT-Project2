///////////////////////////////////////////////////////////////////////////////
// MotorControllerDriver.cpp
#include "TcPch.h"
#pragma hdrstop

#include "MotorControllerDriver.h"
#include "MotorControllerClassFactory.h"

DECLARE_GENERIC_DEVICE(MOTORCONTROLLERDRV)

IOSTATUS CMotorControllerDriver::OnLoad( )
{
	TRACE(_T("CObjClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new CMotorControllerClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID CMotorControllerDriver::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl CMotorControllerDriver::MOTORCONTROLLERDRV_GetVersion( )
{
	return( (MOTORCONTROLLERDRV_Major << 8) | MOTORCONTROLLERDRV_Minor );
}

