///////////////////////////////////////////////////////////////////////////////
// MotorControllerCtrl.h

#ifndef __MOTORCONTROLLERCTRL_H__
#define __MOTORCONTROLLERCTRL_H__

#include <atlbase.h>
#include <atlcom.h>

#define MOTORCONTROLLERDRV_NAME "MOTORCONTROLLER"

#include "resource.h"       // main symbols
#include "MotorControllerW32.h"
#include "TcBase.h"
#include "MotorControllerClassFactory.h"
#include "TcOCFCtrlImpl.h"

class CMotorControllerCtrl 
	: public CComObjectRootEx<CComMultiThreadModel>
	, public CComCoClass<CMotorControllerCtrl, &CLSID_MotorControllerCtrl>
	, public IMotorControllerCtrl
	, public ITcOCFCtrlImpl<CMotorControllerCtrl, CMotorControllerClassFactory>
{
public:
	CMotorControllerCtrl();
	virtual ~CMotorControllerCtrl();

DECLARE_REGISTRY_RESOURCEID(IDR_MOTORCONTROLLERCTRL)
DECLARE_NOT_AGGREGATABLE(CMotorControllerCtrl)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CMotorControllerCtrl)
	COM_INTERFACE_ENTRY(IMotorControllerCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl2)
END_COM_MAP()

};

#endif // #ifndef __MOTORCONTROLLERCTRL_H__
