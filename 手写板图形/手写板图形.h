
// ��д��ͼ��.h : ��д��ͼ�� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C��д��ͼ��App:
// �йش����ʵ�֣������ ��д��ͼ��.cpp
//

class C��д��ͼ��App : public CWinAppEx
{
public:
	C��д��ͼ��App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��д��ͼ��App theApp;
