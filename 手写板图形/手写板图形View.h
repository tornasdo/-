
// 手写板图形View.h : C手写板图形View 类的接口
//
//#include "shouxieban.h"
#pragma once


#define WM_SXBDOWN WM_USER+531
#define WM_SXBUP WM_USER+532
#define WM_SXBMOVE WM_USER+533



void WINAPI ProgressCallbackForRealTimePenDatas(int x, int y, int preasure);

//HWND chuangkou;



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







class C手写板图形View : public CView
{


protected: // 仅从序列化创建
	C手写板图形View();
	DECLARE_DYNCREATE(C手写板图形View)

// 特性
public:
	C手写板图形Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~C手写板图形View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	CPoint m_ptOrigin;
	BOOL  m_bDraw;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);

	
// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//shouxieban m_shouxieban;
	afx_msg void OnSxbzc();

	afx_msg LRESULT OnSXBDOWN(WPARAM wParam , LPARAM lParam);
	afx_msg LRESULT OnSXBUP(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSXBMove(WPARAM wParam, LPARAM lParam);
	







	afx_msg void OnFileSave();
};

#ifndef _DEBUG  // 手写板图形View.cpp 中的调试版本
inline C手写板图形Doc* C手写板图形View::GetDocument() const
   { return reinterpret_cast<C手写板图形Doc*>(m_pDocument); }
#endif

