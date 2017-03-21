
// 手写板图形View.cpp : C手写板图形View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "手写板图形.h"
#endif

#include "手写板图形Doc.h"
#include "手写板图形View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
HINSTANCE hDlltemp;
CPoint mpoint;
bool down(false);
RECT mretc;
float bl;
// C手写板图形View

IMPLEMENT_DYNCREATE(C手写板图形View, CView)

BEGIN_MESSAGE_MAP(C手写板图形View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_MESSAGE(WM_SXBDOWN, OnSXBDOWN)
	ON_MESSAGE(WM_SXBUP, OnSXBUP)
	ON_MESSAGE(WM_SXBMOVE, OnSXBMove)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_SXBZC, &C手写板图形View::OnSxbzc)
	ON_COMMAND(ID_FILE_SAVE, &C手写板图形View::OnFileSave)
END_MESSAGE_MAP()

// C手写板图形View 构造/析构

C手写板图形View::C手写板图形View()
{
	// TODO: 在此处添加构造代码

}

C手写板图形View::~C手写板图形View()
{
}

BOOL C手写板图形View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C手写板图形View 绘制

void C手写板图形View::OnDraw(CDC* /*pDC*/)
{
	C手写板图形Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C手写板图形View 打印

BOOL C手写板图形View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C手写板图形View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C手写板图形View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C手写板图形View 诊断

#ifdef _DEBUG
void C手写板图形View::AssertValid() const
{
	CView::AssertValid();
}

void C手写板图形View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

void C手写板图形View::OnLButtonDown(UINT nFlags, CPoint point)
{
	//OutputDebugString(L"鼠标已经开始点击");
	
	CView::OnLButtonDown(nFlags, point);
}

void C手写板图形View::OnLButtonUp(UINT nFlags, CPoint point)
{
	/*
	HDC hdc;
	hdc = ::GetDC(m_hWnd);
	//移动到线条的起点
	MoveToEx(hdc, m_ptOrigin.x, m_ptOrigin.y, NULL);
	//画线
	LineTo(hdc, point.x, point.y);
	//释放设备描述表
	::ReleaseDC(m_hWnd, hdc);
	*/
		//使用CDC类实现
	
	/*
	CDC *pDC = GetDC();
	pDC->MoveTo(m_ptOrigin);
	pDC->LineTo(point);
	ReleaseDC(pDC);
	*/
	//OutputDebugString(L"鼠标点击结束");
	CView::OnLButtonUp(nFlags, point);
}



C手写板图形Doc* C手写板图形View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C手写板图形Doc)));
	return (C手写板图形Doc*)m_pDocument;
}
#endif //_DEBUG


// C手写板图形View 消息处理程序


void C手写板图形View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	

	CView::OnMouseMove(nFlags, point);
}


void C手写板图形View::OnSxbzc()
{
	// TODO: 在此添加命令处理程序代码
	//MessageBox(L"View Clicked!");
	hDlltemp = LoadLibrary(L"DigitNoteController.dll");

	((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveView()->GetClientRect(&mretc);


	bl = (float)mretc.right / 20900.0;
	if (hDlltemp != NULL)

	{


		PopenPort openPort = (PopenPort)GetProcAddress(hDlltemp, "_openPort@0");


		PgetDGBleInfo getDGBleInfo = (PgetDGBleInfo)GetProcAddress(hDlltemp, "_getDGBleInfo");

		PgetDGVersion getDGVersion = (PgetDGVersion)GetProcAddress(hDlltemp, "_getDGVersion@4");

		PsetDGBleName  setDGBleName = (PsetDGBleName)GetProcAddress(hDlltemp, "_setDGBleName@4");

		PconnectDevice connectDevice = (PconnectDevice)GetProcAddress(hDlltemp, "_connectDevice@0");

		PgetDeviceBleInfo getDeviceBleInfo = (PgetDeviceBleInfo)GetProcAddress(hDlltemp, "_getDeviceBleInfo@8");

		PgetDeviceName getDeviceName = (PgetDeviceName)GetProcAddress(hDlltemp, "_getDeviceName@4");

		PgetDeviceFirmwareVersion getDeviceFirmwareVersion = (PgetDeviceFirmwareVersion)GetProcAddress(hDlltemp, "_getDeviceFirmwareVersion@8");
		PgetDeviceBatteryState getDeviceBatteryState = (PgetDeviceBatteryState)GetProcAddress(hDlltemp, "_getDeviceBatteryState@8");

		PsetDeviceDateTimeWithSecond setDeviceDateTimeWithSecond = (PsetDeviceDateTimeWithSecond)GetProcAddress(hDlltemp, "_getDeviceDataTimeWithSecond@4");

		PsetDeviceName setDeviceName = (PsetDeviceName)GetProcAddress(hDlltemp, "_setDeviceName@4");

		PhardwareReset hardwareReset = (PhardwareReset)GetProcAddress(hDlltemp, "_hardwareReset@0");

		PfactoryReset factoryReset = (PfactoryReset)GetProcAddress(hDlltemp, "_factoryReset@0");
		PswitchToRealTimeMode switchToRealTimeMode = (PswitchToRealTimeMode)GetProcAddress(hDlltemp, "_switchToRealTimeMode@0");

		PswitchToUploadMode switchToUploadMode = (PswitchToUploadMode)GetProcAddress(hDlltemp, "_switchToUploadMode@0");

		PqueryFileConut queryFileConut = (PqueryFileConut)GetProcAddress(hDlltemp, "_queryFileConut@4");

		PtransferOldestFile transferOldestFile = (PtransferOldestFile)GetProcAddress(hDlltemp, "_transferOldestFile@0");

		PtransferNewestFile transferNewestFile = (PtransferNewestFile)GetProcAddress(hDlltemp, "_transferNewestFile@0");

		PgetUploadFileInfo getUploadFileInfo = (PgetUploadFileInfo)GetProcAddress(hDlltemp, "_getUploadFileInfo@8");

		PstopTransfer stopTransfer = (PstopTransfer)GetProcAddress(hDlltemp, "_stopTransfer@0");

		PGetUploadFile GetUploadFile = (PGetUploadFile)GetProcAddress(hDlltemp, "_GetUploadFile@0");

		PdeleteUploadFile deleteUploadFile = (PdeleteUploadFile)GetProcAddress(hDlltemp, "_deleteUploadFile@0");


		PopenFileEncryptionWithKey openFileEncryptionWithKey = (PopenFileEncryptionWithKey)GetProcAddress(hDlltemp, "_openFileEncryptionWithKey@4");

		PcloseFileEncryptionByKey closeFileEncryptionByKey = (PcloseFileEncryptionByKey)GetProcAddress(hDlltemp, "_closeFileEncryptionByKey@4");

		PqueryFileEncryptionStatus queryFileEncryptionStatus = (PqueryFileEncryptionStatus)GetProcAddress(hDlltemp, "_queryFileEncryptionStatus@4");

		PverifyFileEncryptionByKey verifyFileEncryptionByKey = (PverifyFileEncryptionByKey)GetProcAddress(hDlltemp, "_verifyFileEncryptionByKey@4");


		PSetCallBackForRealTimePenDatas SetCallBackForRealTimePenDatas = (PSetCallBackForRealTimePenDatas)GetProcAddress(hDlltemp, "_SetCallBackForRealTimePenDatas@4");
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

				}

			}

		}
	}


}

LRESULT C手写板图形View::OnSXBDOWN(WPARAM wParam, LPARAM lParam)
{
	m_ptOrigin = (CPoint)lParam;
	m_bDraw = true;
	OutputDebugString(L"放下手写笔");
	return 0;
}

LRESULT C手写板图形View::OnSXBUP(WPARAM wParam, LPARAM lParam)
{
	m_bDraw = false;
	OutputDebugString(L"手写笔抬起");
	return 0;
}

LRESULT C手写板图形View::OnSXBMove(WPARAM wParam, LPARAM lParam)
{
	CClientDC dc(this);
	//创建一个画笔
	int x = (255-((int)wParam / 8))*1.2;
	x < 255 ? x : 255;
	int wath = (int)(((255-x) / 255.0) * 6);
	CPen pen(PS_SOLID, wath, RGB(x, x, x));
	//将创建的画笔选入设备描述表
	CPen *pOldPen = dc.SelectObject(&pen);
	if (m_bDraw == true)
	{
		dc.MoveTo(m_ptOrigin);
		dc.LineTo(CPoint(lParam));
		m_ptOrigin = CPoint(lParam);  //每次都更新起点
	}
	CString xxx;
	xxx.Format(L"笔画宽度：%d  ,  颜色深度:  %d   \r\n",wath,x);
	OutputDebugString(xxx);
	return 0;
}

void WINAPI ProgressCallbackForRealTimePenDatas(int x, int y, int preasure)
{
	int bx;
	int by;
	bx = bl*x;
	by = bl*y;
	if (preasure>0)
	{
		if (down)
		{
			
			
			LPARAM lParam = MAKEWPARAM(bx,by);
			

			::PostMessage(((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveView()->GetSafeHwnd(), WM_SXBMOVE, preasure, lParam);
			//::PostMessage(((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveView()->GetSafeHwnd(), WM_MOUSEMOVE, preasure, lParam);
			//move
		}
		else
		{
			down = true;
			LPARAM lParam = MAKEWPARAM(bx, by);
			::PostMessage(((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveView()->GetSafeHwnd(), WM_SXBDOWN, preasure, lParam);
			//::PostMessage(((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveView()->GetSafeHwnd(), WM_LBUTTONDOWN, preasure, lParam);
			//click
		}
	}
	else
	{
		
		if (down)
		{
			LPARAM lParam = MAKEWPARAM(bx, by);
			CView* pView = ((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveView();
			int x = pView->SendMessage(WM_SXBUP, preasure, lParam);
			//CString  temp;
			//temp.Format(_T("%d"), x);
			//OutputDebugString(temp);
			//pView->SendMessage(WM_LBUTTONUP, preasure, lParam);
			//::PostMessage(((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveView()->GetSafeHwnd(), WM_SXBUP, 1, lParam);
			//::PostMessage(((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveView()->GetSafeHwnd(), WM_LBUTTONUP, 1, lParam);

			down = false;
			
		}
		

	}
}


void C手写板图形View::OnFileSave()
{
	// TODO: 在此添加命令处理程序代码
	//OutputDebugString(L"fffff");
	CClientDC  dc(this);
	CDC   memDC;
	memDC.CreateCompatibleDC(&dc);
	CBitmap   bm;
	CRect rect;
	GetClientRect(&rect);
	int   Width = rect.Width();
	int   Height = rect.Height();
	bm.CreateCompatibleBitmap(&dc, Width, Height);
	CBitmap*     pOld = memDC.SelectObject(&bm);
	memDC.BitBlt(0, 0, Width, Height, &dc, 1, 1, SRCCOPY);
	memDC.SelectObject(pOld);
	BITMAP     btm;
	bm.GetBitmap(&btm);
	DWORD     size = btm.bmWidthBytes   *   btm.bmHeight;
	LPSTR   lpData = (LPSTR)GlobalAlloc(GPTR, size);
	BITMAPFILEHEADER       bfh;
	BITMAPINFOHEADER     bih;
	bih.biBitCount = btm.bmBitsPixel;
	bih.biClrImportant = 0;
	bih.biClrUsed = 0;
	bih.biCompression = 0;
	bih.biHeight = btm.bmHeight;
	bih.biPlanes = 1;
	bih.biSize = sizeof(BITMAPINFOHEADER);
	bih.biSizeImage = size;
	bih.biWidth = btm.bmWidth;
	bih.biXPelsPerMeter = 0;
	bih.biYPelsPerMeter = 0;
	GetDIBits(dc, bm, 0, bih.biHeight, lpData, (BITMAPINFO*)&bih, DIB_RGB_COLORS);
	bfh.bfReserved1 = bfh.bfReserved2 = 0;
	bfh.bfType = ((WORD)('M' << 8) | 'B');   //bfh.bfType=0x4D42;//bmp类型  
	bfh.bfSize = 54 + size;
	bfh.bfOffBits = 54;
	CFileDialog   dlg(false, _T("BMP"), _T("*.bmp"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("*.bmp|*.bmp|*.*|*.*|"));
	if (dlg.DoModal() != IDOK)
		return;

	CFile     bf;
	CString   ss = dlg.GetPathName();
	if (bf.Open(ss, CFile::modeCreate | CFile::modeWrite))
	{
		bf.Write(&bfh, sizeof(BITMAPFILEHEADER));
		bf.Write(&bih, sizeof(BITMAPINFOHEADER));
		bf.Write(lpData, size);
		bf.Close();
	}
	GlobalFree(lpData);
	
	OutputDebugString(L"图片保存成功 "+ ss);
	//AfxMessageBox("图片保存成功！");
	//SaveFlag = TRUE;
}
