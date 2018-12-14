// MotorControllerCtrl.cpp : Implementation of CTcMotorControllerCtrl
#include "TcPch.h"
#pragma hdrstop

#include "MotorControllerW32.h"
#include "MotorControllerCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CMotorControllerCtrl

CMotorControllerCtrl::CMotorControllerCtrl() 
	: ITcOCFCtrlImpl<CMotorControllerCtrl, CMotorControllerClassFactory>() 
{
}

CMotorControllerCtrl::~CMotorControllerCtrl()
{
}

