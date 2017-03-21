
// ��д��ͼ��View.cpp : C��д��ͼ��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��д��ͼ��.h"
#endif

#include "��д��ͼ��Doc.h"
#include "��д��ͼ��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
HINSTANCE hDlltemp;
CPoint mpoint;
bool down(false);
RECT mretc;
float bl;
// C��д��ͼ��View

IMPLEMENT_DYNCREATE(C��д��ͼ��View, CView)

BEGIN_MESSAGE_MAP(C��д��ͼ��View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_MESSAGE(WM_SXBDOWN, OnSXBDOWN)
	ON_MESSAGE(WM_SXBUP, OnSXBUP)
	ON_MESSAGE(WM_SXBMOVE, OnSXBMove)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_SXBZC, &C��д��ͼ��View::OnSxbzc)
	ON_COMMAND(ID_FILE_SAVE, &C��д��ͼ��View::OnFileSave)
END_MESSAGE_MAP()

// C��д��ͼ��View ����/����

C��д��ͼ��View::C��д��ͼ��View()
{
	// TODO: �ڴ˴���ӹ������

}

C��д��ͼ��View::~C��д��ͼ��View()
{
}

BOOL C��д��ͼ��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��д��ͼ��View ����

void C��д��ͼ��View::OnDraw(CDC* /*pDC*/)
{
	C��д��ͼ��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C��д��ͼ��View ��ӡ

BOOL C��д��ͼ��View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C��д��ͼ��View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C��д��ͼ��View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C��д��ͼ��View ���

#ifdef _DEBUG
void C��д��ͼ��View::AssertValid() const
{
	CView::AssertValid();
}

void C��д��ͼ��View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

void C��д��ͼ��View::OnLButtonDown(UINT nFlags, CPoint point)
{
	//OutputDebugString(L"����Ѿ���ʼ���");
	
	CView::OnLButtonDown(nFlags, point);
}

void C��д��ͼ��View::OnLButtonUp(UINT nFlags, CPoint point)
{
	/*
	HDC hdc;
	hdc = ::GetDC(m_hWnd);
	//�ƶ������������
	MoveToEx(hdc, m_ptOrigin.x, m_ptOrigin.y, NULL);
	//����
	LineTo(hdc, point.x, point.y);
	//�ͷ��豸������
	::ReleaseDC(m_hWnd, hdc);
	*/
		//ʹ��CDC��ʵ��
	
	/*
	CDC *pDC = GetDC();
	pDC->MoveTo(m_ptOrigin);
	pDC->LineTo(point);
	ReleaseDC(pDC);
	*/
	//OutputDebugString(L"���������");
	CView::OnLButtonUp(nFlags, point);
}



C��д��ͼ��Doc* C��д��ͼ��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��д��ͼ��Doc)));
	return (C��д��ͼ��Doc*)m_pDocument;
}
#endif //_DEBUG


// C��д��ͼ��View ��Ϣ�������


void C��д��ͼ��View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	

	CView::OnMouseMove(nFlags, point);
}


void C��д��ͼ��View::OnSxbzc()
{
	// TODO: �ڴ���������������
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

LRESULT C��д��ͼ��View::OnSXBDOWN(WPARAM wParam, LPARAM lParam)
{
	m_ptOrigin = (CPoint)lParam;
	m_bDraw = true;
	OutputDebugString(L"������д��");
	return 0;
}

LRESULT C��д��ͼ��View::OnSXBUP(WPARAM wParam, LPARAM lParam)
{
	m_bDraw = false;
	OutputDebugString(L"��д��̧��");
	return 0;
}

LRESULT C��д��ͼ��View::OnSXBMove(WPARAM wParam, LPARAM lParam)
{
	CClientDC dc(this);
	//����һ������
	int x = (255-((int)wParam / 8))*1.2;
	x < 255 ? x : 255;
	int wath = (int)(((255-x) / 255.0) * 6);
	CPen pen(PS_SOLID, wath, RGB(x, x, x));
	//�������Ļ���ѡ���豸������
	CPen *pOldPen = dc.SelectObject(&pen);
	if (m_bDraw == true)
	{
		dc.MoveTo(m_ptOrigin);
		dc.LineTo(CPoint(lParam));
		m_ptOrigin = CPoint(lParam);  //ÿ�ζ��������
	}
	CString xxx;
	xxx.Format(L"�ʻ���ȣ�%d  ,  ��ɫ���:  %d   \r\n",wath,x);
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


void C��д��ͼ��View::OnFileSave()
{
	// TODO: �ڴ���������������
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
	bfh.bfType = ((WORD)('M' << 8) | 'B');   //bfh.bfType=0x4D42;//bmp����  
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
	
	OutputDebugString(L"ͼƬ����ɹ� "+ ss);
	//AfxMessageBox("ͼƬ����ɹ���");
	//SaveFlag = TRUE;
}
