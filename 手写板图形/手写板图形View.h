
// ��д��ͼ��View.h : C��д��ͼ��View ��Ľӿ�
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







class C��д��ͼ��View : public CView
{


protected: // �������л�����
	C��д��ͼ��View();
	DECLARE_DYNCREATE(C��д��ͼ��View)

// ����
public:
	C��д��ͼ��Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~C��д��ͼ��View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	CPoint m_ptOrigin;
	BOOL  m_bDraw;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);

	
// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // ��д��ͼ��View.cpp �еĵ��԰汾
inline C��д��ͼ��Doc* C��д��ͼ��View::GetDocument() const
   { return reinterpret_cast<C��д��ͼ��Doc*>(m_pDocument); }
#endif

