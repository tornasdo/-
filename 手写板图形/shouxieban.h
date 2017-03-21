#pragma once
typedef int(*PopenPort)();

typedef int(*PgetDGBleInfo)(char *, char *);

typedef int(*PgetDGVersion)(char *);

typedef long(*PsetDGBleName)(char *);

typedef int(*PconnectDevice)();

typedef int(*PgetDeviceBleInfo)(char *, char *);
typedef int(*PgetDeviceName)(char *);
typedef int(*PgetDeviceFirmwareVersion)(char *, char *);

typedef int(*PgetDeviceBatteryState)(int, int);

typedef int(*PsetDeviceDateTimeWithSecond)(int);

typedef int(*PsetDeviceName)(char *);

typedef int(*PhardwareReset)();

typedef int(*PfactoryReset)();

typedef int(*PswitchToRealTimeMode)();

typedef int(*PswitchToUploadMode)();
typedef int(*PqueryFileConut)(int &);

typedef int(*PtransferOldestFile)();

typedef int(*PtransferNewestFile)();

typedef int(*PgetUploadFileInfo)(int &, int &);

typedef int(*PstopTransfer)();

typedef int(*PGetUploadFile)();

typedef int(*PdeleteUploadFile)();

typedef int(*PopenFileEncryptionWithKey)(char *);

typedef int(*PcloseFileEncryptionByKey)(char *);
typedef int(*PqueryFileEncryptionStatus)(int &);
typedef int(*PverifyFileEncryptionByKey)(char *);



typedef void(WINAPI *CallbackFun)(int x, int y, int preasure);
typedef void(WINAPI *PSetCallBackForRealTimePenDatas)(CallbackFun callbackfun);
class shouxieban
{
public:
	shouxieban();
	~shouxieban();
protected:
	PopenPort openPort ;


	PgetDGBleInfo getDGBleInfo ;

	PgetDGVersion getDGVersion ;

	PsetDGBleName  setDGBleName ;

	PconnectDevice connectDevice ;

	PgetDeviceBleInfo getDeviceBleInfo;

	PgetDeviceName getDeviceName;

	PgetDeviceFirmwareVersion getDeviceFirmwareVersion ;
	PgetDeviceBatteryState getDeviceBatteryState ;

	PsetDeviceDateTimeWithSecond setDeviceDateTimeWithSecond ;

	PsetDeviceName setDeviceName ;

	PhardwareReset hardwareReset ;

	PfactoryReset factoryReset;
	PswitchToRealTimeMode switchToRealTimeMode;

	PswitchToUploadMode switchToUploadMode;

	PqueryFileConut queryFileConut;

	PtransferOldestFile transferOldestFile;

	PtransferNewestFile transferNewestFile ;

	PgetUploadFileInfo getUploadFileInfo ;

	PstopTransfer stopTransfer ;

	PGetUploadFile GetUploadFile ;

	PdeleteUploadFile deleteUploadFile ;


	PopenFileEncryptionWithKey openFileEncryptionWithKey ;

	PcloseFileEncryptionByKey closeFileEncryptionByKey;

	PqueryFileEncryptionStatus queryFileEncryptionStatus;

	PverifyFileEncryptionByKey verifyFileEncryptionByKey;


	PSetCallBackForRealTimePenDatas SetCallBackForRealTimePenDatas;



	HINSTANCE hDll;
public:
	int GetRealData(void WINAPI ProgressCallbackForRealTimePenDatas(int x, int y, int preasure));
};

