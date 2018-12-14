#include <iostream>
#include <windows.h>
#include <conio.h>
#include "C:\TwinCAT\AdsApi\TcAdsDll\Include\TcAdsDef.h"
#include "C:\TwinCAT\AdsApi\TcAdsDll\Include\TcAdsAPI.h"

using namespace std;

void main()
{
	long      nErr, nPort;
	AmsAddr   Addr;
	PAmsAddr  pAddr = &Addr;
	ULONG     lHdlVar, nData;
	char      szVar[] = { "AdsModule.ADS_Data.Count" };

	// Open communication port on the ADS router
	nPort = AdsPortOpen();
	nErr = AdsGetLocalAddress(pAddr);
	if (nErr) cerr << "Error: AdsGetLocalAddress: " << nErr << '\n';
	pAddr->port = 350;

	// Get the handle of the C++-variable <szVar> 
	nErr = AdsSyncReadWriteReq(pAddr, ADSIGRP_SYM_HNDBYNAME, 0x0, sizeof(lHdlVar), &lHdlVar, sizeof(szVar), szVar);
	if (nErr) cerr << "Error: AdsSyncReadWriteReq: " << nErr << '\n';
	do
	{
		// Read the value of a C++-variable, via handle 
		nErr = AdsSyncReadReq(pAddr, ADSIGRP_SYM_VALBYHND, lHdlVar, sizeof(nData), &nData);
		if (nErr)
			cerr << "Error: AdsSyncReadReq: " << nErr << '\n';
		else
			cout << "Value: " << nData << '\n';
		cout.flush();
		if (nData > 10)
		{
			// Set the value of the C++ variable to 0 
			nData = 0;
			nErr = AdsSyncWriteReq(pAddr, ADSIGRP_SYM_VALBYHND, lHdlVar, sizeof(nData), &nData);
			if (nErr) cerr << "Error: AdsSyncWriteReq: " << nErr << '\n';
		}
	} while (_getch() == '\r');  // read next value with RETURN

	// Release the handle of the C++-variable
	nErr = AdsSyncWriteReq(pAddr, ADSIGRP_SYM_RELEASEHND, 0, sizeof(lHdlVar), &lHdlVar);
	if (nErr) cerr << "Error: AdsSyncWriteReq: " << nErr << '\n';

	// Close the communication port
	nErr = AdsPortClose();
	if (nErr) cerr << "Error: AdsPortClose: " << nErr << '\n';
}
