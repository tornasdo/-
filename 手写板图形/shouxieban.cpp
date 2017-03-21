#include "stdafx.h"
#include "shouxieban.h"


shouxieban::shouxieban()
{
	hDll = LoadLibrary(L"DigitNoteController.dll");

	if (hDll != NULL)

	{


		openPort = (PopenPort)GetProcAddress(hDll, "_openPort@0");


		getDGBleInfo = (PgetDGBleInfo)GetProcAddress(hDll, "_getDGBleInfo");

		getDGVersion = (PgetDGVersion)GetProcAddress(hDll, "_getDGVersion@4");

		setDGBleName = (PsetDGBleName)GetProcAddress(hDll, "_setDGBleName@4");

		connectDevice = (PconnectDevice)GetProcAddress(hDll, "_connectDevice@0");

		getDeviceBleInfo = (PgetDeviceBleInfo)GetProcAddress(hDll, "_getDeviceBleInfo@8");

		getDeviceName = (PgetDeviceName)GetProcAddress(hDll, "_getDeviceName@4");

		getDeviceFirmwareVersion = (PgetDeviceFirmwareVersion)GetProcAddress(hDll, "_getDeviceFirmwareVersion@8");
		getDeviceBatteryState = (PgetDeviceBatteryState)GetProcAddress(hDll, "_getDeviceBatteryState@8");

		setDeviceDateTimeWithSecond = (PsetDeviceDateTimeWithSecond)GetProcAddress(hDll, "_getDeviceDataTimeWithSecond@4");

		setDeviceName = (PsetDeviceName)GetProcAddress(hDll, "_setDeviceName@4");

		hardwareReset = (PhardwareReset)GetProcAddress(hDll, "_hardwareReset@0");

		factoryReset = (PfactoryReset)GetProcAddress(hDll, "_factoryReset@0");
		switchToRealTimeMode = (PswitchToRealTimeMode)GetProcAddress(hDll, "_switchToRealTimeMode@0");
		switchToUploadMode = (PswitchToUploadMode)GetProcAddress(hDll, "_switchToUploadMode@0");

		queryFileConut = (PqueryFileConut)GetProcAddress(hDll, "_queryFileConut@4");

		transferOldestFile = (PtransferOldestFile)GetProcAddress(hDll, "_transferOldestFile@0");

		transferNewestFile = (PtransferNewestFile)GetProcAddress(hDll, "_transferNewestFile@0");

		getUploadFileInfo = (PgetUploadFileInfo)GetProcAddress(hDll, "_getUploadFileInfo@8");

		stopTransfer = (PstopTransfer)GetProcAddress(hDll, "_stopTransfer@0");

		GetUploadFile = (PGetUploadFile)GetProcAddress(hDll, "_GetUploadFile@0");

		deleteUploadFile = (PdeleteUploadFile)GetProcAddress(hDll, "_deleteUploadFile@0");


		openFileEncryptionWithKey = (PopenFileEncryptionWithKey)GetProcAddress(hDll, "_openFileEncryptionWithKey@4");

		closeFileEncryptionByKey = (PcloseFileEncryptionByKey)GetProcAddress(hDll, "_closeFileEncryptionByKey@4");

		queryFileEncryptionStatus = (PqueryFileEncryptionStatus)GetProcAddress(hDll, "_queryFileEncryptionStatus@4");

		verifyFileEncryptionByKey = (PverifyFileEncryptionByKey)GetProcAddress(hDll, "_verifyFileEncryptionByKey@4");


		SetCallBackForRealTimePenDatas = (PSetCallBackForRealTimePenDatas)GetProcAddress(hDll, "_SetCallBackForRealTimePenDatas@4");
	}
}

	
	
shouxieban::~shouxieban() 
{

}

int shouxieban::GetRealData( void WINAPI ProgressCallbackForRealTimePenDatas(int x, int y, int preasure))
{
	if (openPort != NULL)

	{

		int Ret = openPort();
		if (Ret == 0)
		{
			//openPort Success
			if (switchToRealTimeMode != NULL)
			{
				int Ret = switchToRealTimeMode();
				if (Ret == 0)
				{
					SetCallBackForRealTimePenDatas((CallbackFun)ProgressCallbackForRealTimePenDatas);
				}
				else
				{
					return Ret;
				}
			}
		
		}
		else
		{
			return Ret;
			//openPort Fail£¬Please refer to the error code reference table
		}



	}
	return 0;
}
