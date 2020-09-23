
// MFCApplication1View.cpp : CMFCApplication1View 類別的實作
//

#include "stdafx.h"
#include "Dialog1.h"
#include <omp.h>
// SHARED_HANDLERS 可以定義在實作預覽、縮圖和搜尋篩選條件處理常式的
// ATL 專案中，並允許與該專案共用文件程式碼。
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CView)
	// 標準列印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_OPEN, &CMFCApplication1View::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE, &CMFCApplication1View::OnFileSave)
	ON_COMMAND(ID_IMAGE_TEST1, &CMFCApplication1View::OnImageTest1)
	ON_COMMAND(ID_IMAGE_TEST2, &CMFCApplication1View::OnImageTest2)
	ON_COMMAND(ID_IMAGE_TOYUV, &CMFCApplication1View::OnImageToyuv)
	ON_COMMAND(ID_IMAGE_TEST3, &CMFCApplication1View::OnImageTest3)
	ON_COMMAND(ID_IMAGE_BACKRGB, &CMFCApplication1View::OnImageBackrgb)
	ON_COMMAND(ID_IMAGE_ZOOM, &CMFCApplication1View::OnImageZoom)
	ON_COMMAND(ID_PROCESS_POLARTORECTANGULAR, &CMFCApplication1View::OnProcessPolartorectangular)
	ON_COMMAND(ID_IMAGE_INVERSE, &CMFCApplication1View::OnImageInverse)
	ON_COMMAND(ID_PROCESS_POWER, &CMFCApplication1View::OnProcessPower)
	ON_COMMAND(ID_PROCESS_SOBELEDGEDETECTOR, &CMFCApplication1View::OnProcessSobeledgedetector)
	ON_COMMAND(ID_PROCESS_ADDGAUSSIANNOISE, &CMFCApplication1View::OnProcessAddgaussiannoise)
	ON_COMMAND(ID_PROCESS_ADDSALT, &CMFCApplication1View::OnProcessAddsalt)
	ON_COMMAND(ID_PROCESS_BOXFILTER, &CMFCApplication1View::OnProcessBoxfilter)
	ON_COMMAND(ID_PROCESS_COMPUTETHESNR, &CMFCApplication1View::OnProcessComputethesnr)
	ON_COMMAND(ID_PROCESS_MEDIANFILTER, &CMFCApplication1View::OnProcessMedianfilter)
	ON_COMMAND(ID_NOISE_PMED, &CMFCApplication1View::OnNoisePmed)
END_MESSAGE_MAP()

// CMFCApplication1View 建構/解構

CMFCApplication1View::CMFCApplication1View()
{
	// TODO: 在此加入建構程式碼
	m_bShowImage = false;
    SetState = false;
}

CMFCApplication1View::~CMFCApplication1View()
{
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此經由修改 CREATESTRUCT cs 
	// 達到修改視窗類別或樣式的目的

	return CView::PreCreateWindow(cs);
}

// CMFCApplication1View 描繪

void CMFCApplication1View::OnDraw(CDC* pDC)
{
	CMFCApplication1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此加入原生資料的描繪程式碼
	 if (m_bShowImage) {
        DispImg.Draw(*pDC, 0, 0);
    }    
    if (SetState) {
        //改變視窗title
        //CString CTitle("Title Test");
        LPCTSTR title = CTitle;
        pDoc->SetTitle(title);
        
        //改變子視窗大小
        CMDIChildWnd* childWnd = (CMDIChildWnd*)((CFrameWnd*)AfxGetApp()-> m_pMainWnd)-> GetActiveFrame();
        childWnd->SetWindowPos(&CWnd::wndTop, NULL, NULL, DispImg.GetWidth() + 22, DispImg.GetHeight() + 48, SWP_SHOWWINDOW);
        
        SetState = false;
    }
}


// CMFCApplication1View 列印

BOOL CMFCApplication1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 預設的準備列印程式碼
	return DoPreparePrinting(pInfo);
}

void CMFCApplication1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 加入列印前額外的初始設定
}

void CMFCApplication1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 加入列印後的清除程式碼
}


// CMFCApplication1View 診斷

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // 內嵌非偵錯版本
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication1View 訊息處理常式


void CMFCApplication1View::OnFileOpen()
{
	// TODO: 在此加入您的命令處理常式程式碼
	if ( LoadImg(&OrgImg, &CTitle) ) {
        ImageCopy(&DispImg, &OrgImg);
        m_bShowImage = true;
        SetState = true;
        Invalidate();
    } else
        return;
}


void CMFCApplication1View::OnFileSave()
{
	// TODO: 在此加入您的命令處理常式程式碼
	SaveImg(&DispImg);
}


void CMFCApplication1View::OnImageTest1()
{
	// TODO: 在此加入您的命令處理常式程式碼

	int h = DispImg.GetHeight();
    int w = DispImg.GetWidth(); 

	COLORREF color;
	BYTE r, g, b, gray;

	//#pragma omp parallel for
	for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
			color = DispImg.GetPixel(j, i);	

			r=GetRValue(color);
			g=GetGValue(color);
			b=GetBValue(color);

			gray = r*0.299 + g*0.587 + b*0.114;

			//DispImg.SetPixel( j, i, RGB(r, g, b) );
			DispImg.SetPixel( j, i, RGB(gray, gray, gray) );

		}
	}

	Invalidate();

}


void CMFCApplication1View::OnImageTest2()
{
	// TODO: 在此加入您的命令處理常式程式碼

	int h = DispImg.GetHeight();
    int w = DispImg.GetWidth(); 

	COLORREF color;
	BYTE r, g, b, gray;

	int **ary = new int*[h];
	for(int i=0; i<h; i++) {
		ary[i] = new int[w]; 
		memset( ary[i], 0, w*sizeof(int) );
	}

	//#pragma omp parallel for
	for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
			color = DispImg.GetPixel(j, i);	

			r=GetRValue(color);
			g=GetGValue(color);
			b=GetBValue(color);

			gray = r*0.299 + g*0.587 + b*0.114;
			ary[i][j] = gray;
		}
	}

	//#pragma omp parallel for
	for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {

			DispImg.SetPixel( j, i, RGB(ary[i][j], ary[i][j], ary[i][j]) );
		}
	}

	for(int i=0; i<h; i++)
		delete []ary[i]; //delete []var代表delete的對象是array
	delete []ary;

	Invalidate();
}

void CMFCApplication1View::OnImageTest3()
{
	int h = DispImg.GetHeight();
    int w = DispImg.GetWidth(); 

	
    //gpImg.Create(P.nWidth,P.nHeight,8,0);
    RGBQUAD     ColorTab[256];
    for (int i = 0; i < 256; i++) {
        ColorTab[i].rgbBlue = ColorTab[i].rgbGreen =
                                  ColorTab[i].rgbRed   = i;
    }
	Y.Destroy();
    Y.Create(w, h, 8, 0);
    Y.SetColorTable(0, 256, ColorTab);
	
    
    BYTE **ImgY;	ImgY = (BYTE**) Create2DList(&Y);
	BYTE **ImgO;	ImgO=(BYTE**) Create2DList(&DispImg);

	for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
				//ImgY[i][j] = RGB2Y(ImgO[i][j*3+2], ImgO[i][j*3+1], ImgO[i][j*3+0]);
				ImgY[i][j] = ImgO[i][j*3+2]*0.299 + ImgO[i][j*3+1]*0.587 + ImgO[i][j*3+0]*0.114;
		}
	}

	ImageCopy(&DispImg, &Y);
	Invalidate();
}

void CMFCApplication1View::OnImageToyuv()
{
	// TODO: 在此加入您的命令處理常式程式碼
	int h = DispImg.GetHeight();
    int w = DispImg.GetWidth(); 

	
    //gpImg.Create(P.nWidth,P.nHeight,8,0);
    RGBQUAD     ColorTab[256];
    for (int i = 0; i < 256; i++) {
        ColorTab[i].rgbBlue = ColorTab[i].rgbGreen =
                                  ColorTab[i].rgbRed   = i;
    }
	Y.Destroy();
    Y.Create(w, h, 8, 0);
    Y.SetColorTable(0, 256, ColorTab);
	U.Destroy();
    U.Create(w, h, 8, 0);
    U.SetColorTable(0, 256, ColorTab);
	V.Destroy();
    V.Create(w, h, 8, 0);
    V.SetColorTable(0, 256, ColorTab);
    
    BYTE **ImgY;	ImgY = (BYTE**) Create2DList(&Y);
	BYTE **ImgU;	ImgU = (BYTE**) Create2DList(&U);
	BYTE **ImgV;	ImgV = (BYTE**) Create2DList(&V);

	BYTE **ImgO;	ImgO=(BYTE**) Create2DList(&DispImg);

	for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
				ImgY[i][j] = RGB2Y(ImgO[i][j*3+2], ImgO[i][j*3+1], ImgO[i][j*3+0]);
				ImgU[i][j] = RGB2U(ImgO[i][j*3+2], ImgO[i][j*3+1], ImgO[i][j*3+0]);
				ImgV[i][j] = RGB2V(ImgO[i][j*3+2], ImgO[i][j*3+1], ImgO[i][j*3+0]);
		}
	}

	ImageCopy(&DispImg, &Y);
	Invalidate();
}


void CMFCApplication1View::OnImageBackrgb()
{
	// TODO: 在此加入您的命令處理常式程式碼
	int h = DispImg.GetHeight();
    int w = DispImg.GetWidth(); 

	CImage ColorImage;
	ColorImage.Destroy();
    ColorImage.Create(w, h, 24, 0);
    
    //BYTE **ImgY;	ImgY = (BYTE**) Create2DList(&Y);
	BYTE **ImgY;	ImgY=(BYTE**) Create2DList(&DispImg);
	BYTE **ImgU;	ImgU = (BYTE**) Create2DList(&U);
	BYTE **ImgV;	ImgV = (BYTE**) Create2DList(&V);

	BYTE **ImgO;	ImgO=(BYTE**) Create2DList(&ColorImage);

	for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
			ImgO[i][j*3+0] = YUV2B(ImgY[i][j], ImgU[i][j], ImgV[i][j]);
			ImgO[i][j*3+1] = YUV2G(ImgY[i][j], ImgU[i][j], ImgV[i][j]);
			ImgO[i][j*3+2] = YUV2R(ImgY[i][j], ImgU[i][j], ImgV[i][j]);
		}
	}

	ImageCopy(&DispImg, &ColorImage);
	Invalidate();
}


void CMFCApplication1View::OnImageZoom()
{
	// check dose default image exist or not
    if (DispImg.IsNull()) {
        CString fmt;
        fmt = "Please load image first";
        ::AfxMessageBox(fmt);
        return ;
    }

	//
	struct  IMAGEPARAMENT P;
    GetImageParament(&DispImg, &P);
	int byte = P.nBytesPerPixel;

	if(byte==3)
		CMFCApplication1View::OnImageToyuv();

	// TODO: 在此加入您的命令處理常式程式碼
	int h = DispImg.GetHeight();
	int w = DispImg.GetWidth();

	double ZoomT = 1;

	int zh=0, zw=0;
	
	Dialog1 dlg1;
    
    dlg1.input = ZoomT;
    dlg1.Text1 = "Please input Zooming times for Height";
    if (dlg1.DoModal() == IDOK)  {
        ZoomT = dlg1.input;
		zh = h*ZoomT;
    }

	dlg1.input = ZoomT;
    dlg1.Text1 = "Please input Zooming times for Width";
    if (dlg1.DoModal() == IDOK)  {
        ZoomT = dlg1.input;
		zw = w*ZoomT;
    }
	

	//h = h*2;
	//Zoom(&DispImg, zh, zw);
	ImageCopy(&AnsImg, &DispImg);
	CreateStretchImage(&AnsImg, &DispImg, zh, zw);
	ColorToGray(&DispImg, &DispImg);
	//CImage td;
	//Zoom2(&DispImg, &td, 500, 500);

	//ImageCopy(&DispImg, &td);
	SetState = true;

	if(!U.IsNull()){
		//Zoom(&U, zh, zw);
		//Zoom(&V, zh, zw);
		
		ImageCopy(&AnsImg, &U);
		CreateStretchImage(&AnsImg, &U, zh, zw);
		ColorToGray(&U, &U);
		ImageCopy(&AnsImg, &V);
		CreateStretchImage(&AnsImg, &V, zh, zw);
		ColorToGray(&V, &V);
		
	}

	
	if(byte==3)
		CMFCApplication1View::OnImageBackrgb();
		
	RedrawWindow();
}


void CMFCApplication1View::OnProcessPolartorectangular()
{
	// TODO: 在此加入您的命令處理常式程式碼
	if (DispImg.IsNull()) {
        CString fmt;
        fmt = "Please load image first";
        ::AfxMessageBox(fmt);
        return ;
    }
    
    int h = DispImg.GetHeight();
    int w = DispImg.GetWidth();

	//
	double pi = 3.1415926;
	//int h2 = h * pi;
	//int w2 = w/2;
	int h2 = h / 2;
	int w2 = w * pi;
   
	Dialog1 dlg1;    
	dlg1.input = pi;
	dlg1.Text1 = "Please input the scaling of width (Default = W x π)";
	if (dlg1.DoModal() == IDOK)  {
		w2 = dlg1.input * w;
	}

	double shift_view = 90;
	//Dialog1 dlg1;    
	dlg1.input = shift_view;
	dlg1.Text1 = "Please input Shift angle(0-360)";
	if (dlg1.DoModal() == IDOK)  {
		shift_view = dlg1.input / 360 ;
	}

	AnsImg.Destroy();
    AnsImg.Create(w2, h2, 8, 0);
    //gpImg.Create(P.nWidth,P.nHeight,8,0);
    RGBQUAD     ColorTab[256];
    for (int i = 0; i < 256; i++) {
        ColorTab[i].rgbBlue = ColorTab[i].rgbGreen =
                                  ColorTab[i].rgbRed   = i;
    }
    AnsImg.SetColorTable(0, 256, ColorTab);
    
    BYTE **ImgO;
    ImgO = (BYTE**) Create2DList(&DispImg);
    
    BYTE **ImgP;
    ImgP = (BYTE**) Create2DList(&AnsImg);
    

		int centerX = w/2;
		int centerY = h/2;
		int radius = centerX;

		for (int i = 0; i < h2; i++) {
			for (int j = 0; j < w2; j++) {

				/*
				double r = sqrt(pow((double)j,2)+pow((double)i,2));
				double slop;
				if(i==0)	slop = 0;
				else		slop= (double)i/j;
				double angle = atan(slop);

				double x = r*cos(angle) ;
				double y = r*sin(angle) ;
				*/
				double r = radius - i;
				//double angle = -((double)(j+1) / w2) * pi * 2;
				double theta = -((double)(j+1) / w2 - shift_view) * pi * 2; 

				double x = r*cos(theta) + centerX;
				double y = r*sin(theta) + centerY;

				if( abs((int)x) < h && abs((int)y < w))
					ImgP[i][j] = ImgO[abs((int)x)][abs((int)y)];

			}

		}



    ImageCopy(&DispImg, &AnsImg);
    Invalidate();
	SetState = 1;
    
    Release2DList(ImgO);
    Release2DList(ImgP);
}


void CMFCApplication1View::OnImageInverse()
{
	if (DispImg.IsNull()) {
        CString fmt;
        fmt = "Please load image first";
        ::AfxMessageBox(fmt);
        return ;
    }
	struct  IMAGEPARAMENT P;
    GetImageParament(&DispImg, &P);
	int byte = P.nBytesPerPixel;

	if(byte==3)
		CMFCApplication1View::OnImageToyuv();
    
    ImageCopy(&AnsImg, &DispImg);
    
    int h = DispImg.GetHeight();
    int w = DispImg.GetWidth();
    
    BYTE **ImgO;
    ImgO = (BYTE**) Create2DList(&DispImg);
    
    BYTE **ImgP;
    ImgP = (BYTE**) Create2DList(&AnsImg);
    
    
    for (int i = 0+1; i < h-1; i++) {
        for (int j = 0+1; j < w-1; j++) {
            
			ImgP[i][j] = 255-ImgO[i][j]; 
        }
    }
    //
	ImageCopy(&DispImg, &AnsImg);

	if(byte == 3){
		/*
		if(!U.IsNull()){
			ImageCopy(&Y,&DispImg);

			ImageCopy(&DispImg, &U);
			CMFCApplication1View::OnImageInverse();
			ImageCopy(&U, &DispImg);

			ImageCopy(&DispImg, &V);
			CMFCApplication1View::OnImageInverse();
			ImageCopy(&V, &DispImg);
		}
		*/
		CMFCApplication1View::OnImageBackrgb();
	}

    
    Invalidate();
    
    Release2DList(ImgO);
    Release2DList(ImgP);
}


void CMFCApplication1View::OnProcessPower()
{
	if (DispImg.IsNull()) {
        CString fmt;
        fmt = "Please load image first";
        ::AfxMessageBox(fmt);
        return ;
    }
	struct  IMAGEPARAMENT P;
    GetImageParament(&DispImg, &P);
	int byte = P.nBytesPerPixel;

	if(byte==3)
		CMFCApplication1View::OnImageToyuv();
    
    ImageCopy(&AnsImg, &DispImg);
    
    int h = DispImg.GetHeight();
    int w = DispImg.GetWidth();
    
    double **TDB_num = new double*[h];
    for (int i = 0; i < h; i++) {
        TDB_num[i] = new double[w];
        memset( TDB_num[i], 0, w * sizeof(double) );
    }
    
    
    BYTE **ImgO;
    ImgO = (BYTE**) Create2DList(&DispImg);
    
    BYTE **ImgP;
    ImgP = (BYTE**) Create2DList(&AnsImg);
    
    double P2 = 1;
    
    Dialog1 dlg1;
    dlg1.input = P2;
    dlg1.Text1 = "Please input power P";
    if (dlg1.DoModal() == IDOK)  {
        P2 = dlg1.input;
    }
    
    double Omax = 0;//Find original max pixel value
    double Pmax = 0; //Find powered max pixel valu
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            TDB_num[i][j] = 255 * pow((double)ImgO[i][j] / 255, P2);
            
            if (Pmax < TDB_num[i][j]) { //powered max pixel valu
                Pmax = TDB_num[i][j];
            }
            /*
            if (Omax < ImgO[i][j]) { //original max pixel value
                Omax = ImgP[i][j];
            }
			*/
        }
    }
    //csvwrite(TDB_num,h,w,"Powered",P);
    Omax = 255;
    //normalize
    //double norP = max/255;
    //double norP = Pmax/Omax;
    /*
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            ImgP[i][j] = TDB_num[i][j]/norP;
        }
    }
    */
    //Normalize to 1
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            ImgP[i][j] = TDB_num[i][j] / Pmax * Omax;
            TDB_num[i][j] = TDB_num[i][j] / Pmax * Omax;
        }
    }
    //csvwrite(TDB_num,h,w,"Powered-Normalized",P);
    

    ImageCopy(&DispImg, &AnsImg);
	if(byte==3)
		CMFCApplication1View::OnImageBackrgb();

    Invalidate();
    
    Release2DList(ImgO);
    Release2DList(ImgP);
    
    delete TDB_num;
    TDB_num = NULL;
}


void CMFCApplication1View::OnProcessSobeledgedetector()
{
	// TODO: 在此加入您的命令處理常式程式碼
	if (DispImg.IsNull()) {
        CString fmt;
        fmt = "Please load image first";
        ::AfxMessageBox(fmt);
        return ;
    }
	struct  IMAGEPARAMENT P;
    GetImageParament(&DispImg, &P);
	int byte = P.nBytesPerPixel;

	if(byte==3)
		CMFCApplication1View::OnImageToyuv();
    
    ImageCopy(&AnsImg, &DispImg);
    
    int h = DispImg.GetHeight();
    int w = DispImg.GetWidth();
    
    BYTE **ImgO;
    ImgO = (BYTE**) Create2DList(&DispImg);
    
    BYTE **ImgP;
    ImgP = (BYTE**) Create2DList(&AnsImg);
    
    //
    double K = 2;
    /*
    Dialog1 dlg1;
    dlg1.input = K;
    dlg1.Text1 = "Please input K of the filter" ;
    if (dlg1.DoModal() == IDOK)  {
        K = dlg1.input;
    }
	*/
    //double mask[3][3] = {{1, b, 1}, {b, b * b, b}, {1, b, 1}};
    /*
    int fh = 3;
    int fw = 3;
    
    int adjustX = (fw % 2) ? 1 : 0;
    int adjustY = (fh % 2) ? 1 : 0;
    int xBound = (int)(fw / 2);
    int yBound = (int)(fh / 2);
    */
	
	double GR;
	double GC;
    for (int i = 0+1; i < h-1; i++) {
        for (int j = 0+1; j < w-1; j++) {
            /*
			int sum = 0;
            int cnt = 0;
            
            for (int v = -yBound; v != yBound + adjustY; ++v) {
                for (int u = -xBound; u != xBound + adjustX; ++u) {
                    // check boundary
                    if (j + u < 0 || i + v < 0 || j + u >= w || i + v >= h)
                        continue;
                        
                    sum += ImgO[i + v][j + u] * mask[v + yBound][u + xBound];
                    cnt++;
                }
            }
            double val = (double)sum / pow((b + 2), 2);
            //double val = (double)sum / (pow((b+2), 2)-(fh*fw-cnt));
            ImgP[i][j] = val;
			*/

			//Row gradient
			GR = ((ImgO[i-1][j+1]+K*ImgO[i][j+1]+ImgO[i+1][j+1])-(ImgO[i-1][j-1]+K*ImgO[i][j-1]+ImgO[i+1][j-1]))/(K+2);
			//Column gradient
			GC = ((ImgO[i-1][j-1]+K*ImgO[i-1][j]+ImgO[i-1][j+1])-(ImgO[i+1][j-1]+K*ImgO[i+1][j]+ImgO[i+1][j+1]))/(K+2);

			ImgP[i][j] = pow( (pow(GR, 2.0)+pow(GC, 2.0) ), 0.5);
        }
    }
	//
	int ts = 30;    
	Dialog1 dlg1;

	dlg1.input = ts;
	dlg1.Text1 = "Please Threshold: ";
	if (dlg1.DoModal() == IDOK)  {
		ts = dlg1.input;
	}
	else
		return;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if(ImgP[i][j] >= ts)
				ImgP[i][j] = 0;
			else
				ImgP[i][j] = 255;
		}
	}
    //
	

    ImageCopy(&DispImg, &AnsImg);
	if(byte==3)
		CMFCApplication1View::OnImageBackrgb();
    Invalidate();
    
    Release2DList(ImgO);
    Release2DList(ImgP);
}


void CMFCApplication1View::OnProcessAddgaussiannoise()
{
	// TODO: 在此加入您的命令處理常式程式碼
	if (DispImg.IsNull()) {
        CString fmt;
        fmt = "Please load image first";
        ::AfxMessageBox(fmt);
        return ;
    }
	struct  IMAGEPARAMENT P;
    GetImageParament(&DispImg, &P);
	int byte = P.nBytesPerPixel;

	if(byte==3)
		CMFCApplication1View::OnImageToyuv();
    
    ImageCopy(&AnsImg, &DispImg);
    
    int h = DispImg.GetHeight();
    int w = DispImg.GetWidth();
    
    BYTE **ImgD;
    ImgD = (BYTE**) Create2DList(&DispImg);
    
    BYTE **ImgH;
    ImgH = (BYTE**) Create2DList(&AnsImg);
    
    double Sigma = 10;
    
    Dialog1 dlg1;
    dlg1.input = Sigma;
    dlg1.Text1 = "Please input the amplitude (Sigma)";
    if (dlg1.DoModal() == IDOK)  {
        Sigma = dlg1.input;
    }
	else
		return;
    
    const int WHITE = 255;
    const int BLACK = 0;
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
        
            double GauNoise = 0;
            for (int ri = 0; ri < 12; ri++)
                GauNoise += ((double)rand() / RAND_MAX);
            GauNoise = Sigma * (GauNoise - 6);
            
            int newVal = ImgD[i][j] + GauNoise;
            
            if (newVal > WHITE)
                ImgH[i][j] = WHITE;
            else if (newVal < BLACK)
                ImgH[i][j] = BLACK;
            else
                ImgH[i][j] = newVal;
        }
    }
    ImageCopy(&DispImg, &AnsImg);
    if(byte==3)
		CMFCApplication1View::OnImageBackrgb();
    Invalidate();
    
    Release2DList(ImgD);
    Release2DList(ImgH);
}


void CMFCApplication1View::OnProcessAddsalt()
{
	// TODO: 在此加入您的命令處理常式程式碼
	if (DispImg.IsNull()) {
        CString fmt;
        fmt = "Please load image first";
        ::AfxMessageBox(fmt);
        return ;
    }
	struct  IMAGEPARAMENT P;
    GetImageParament(&DispImg, &P);
	int byte = P.nBytesPerPixel;

	if(byte==3)
		CMFCApplication1View::OnImageToyuv();
    
    ImageCopy(&AnsImg, &DispImg);
    
    int h = DispImg.GetHeight();
    int w = DispImg.GetWidth();
    
    BYTE **ImgD;
    ImgD = (BYTE**) Create2DList(&DispImg);
    
    BYTE **ImgH;
    ImgH = (BYTE**) Create2DList(&AnsImg);
    
    /*
    double Sigma = 10;
    
    Dialog1 dlg1;
    dlg1.input = Sigma;
    dlg1.Text1= "Please input the aplitud (Sigma)";
    if(dlg1.DoModal() == IDOK)  {
        Sigma = dlg1.input;
    }
	else
		return;
    */
    
    const int WHITE = 255;
    const int BLACK = 0;
    double salt = 0.01, pepper = 0.01;
    
    Dialog1 dlg1;
    dlg1.input = salt;
    dlg1.Text1 = "Please input the degree of the pepper and salt" ;
    if (dlg1.DoModal() == IDOK)  {
        salt = pepper = dlg1.input;
    }
	else
		return;
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            double val = (double)rand() / RAND_MAX;
            
            if (val < salt) {
                ImgH[i][j] = BLACK;
            } else if (val > 1 - pepper) {
                ImgH[i][j] = WHITE;
            } else {
                ImgH[i][j] = ImgD[i][j];
            }
        }
    }
    ImageCopy(&DispImg, &AnsImg);
    if(byte==3)
		CMFCApplication1View::OnImageBackrgb();
    Invalidate();
    
    Release2DList(ImgD);
    Release2DList(ImgH);
}


void CMFCApplication1View::OnProcessBoxfilter()
{
	if (DispImg.IsNull()) {
        CString fmt;
        fmt = "Please load image first";
        ::AfxMessageBox(fmt);
        return ;
    }
	struct  IMAGEPARAMENT P;
    GetImageParament(&DispImg, &P);
	int byte = P.nBytesPerPixel;

	if(byte==3)
		CMFCApplication1View::OnImageToyuv();
    
    ImageCopy(&AnsImg, &DispImg);
    
    int h = DispImg.GetHeight();
    int w = DispImg.GetWidth();
    
    BYTE **ImgO;
    ImgO = (BYTE**) Create2DList(&DispImg);
    
    BYTE **ImgP;
    ImgP = (BYTE**) Create2DList(&AnsImg);
    
    //
    int fh = 3;
    int fw = 3;

	Dialog1 dlg1;
    dlg1.input = fh;
    dlg1.Text1= "Please input the size of mask";
    if(dlg1.DoModal() == IDOK)  {
        fh = fw = dlg1.input;
    }
	else
		return;
    
    int adjustX = (fw % 2) ? 1 : 0;
    int adjustY = (fh % 2) ? 1 : 0;
    int xBound = (int)(fw / 2);
    int yBound = (int)(fh / 2);
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int sum = 0, cnt = 0;
            
            for (int v = -yBound; v != yBound + adjustY; ++v) {
                for (int u = -xBound; u != xBound + adjustX; ++u) {
                    // check boundary
                    if (j + u < 0 || i + v < 0 || j + u >= w || i + v >= h)
                        continue;
                        
                    sum += ImgO[i + v][j + u];
                    cnt++;
                }
            }
            double val = (double)sum / cnt;
            ImgP[i][j] = val;
        }
    }
    //
    ImageCopy(&DispImg, &AnsImg);
    if(byte==3)
		CMFCApplication1View::OnImageBackrgb();
    Invalidate();
    
    Release2DList(ImgO);
    Release2DList(ImgP);
}


void CMFCApplication1View::OnProcessComputethesnr()
{
	if (DispImg.IsNull()) {
        CString fmt;
        fmt = "Please load image first";
        ::AfxMessageBox(fmt);
        return ;
    }


    
    /*
    //ImageCopy(&AnsImg, &DispImg);
    CString fmt;
    //fmt = "Please load Original image";
    fmt = "Now load Original image";
    ::AfxMessageBox(fmt);
    //CModuleView::OnFileOpen();
    //CImage OrgImgH;
    //LoadImg(&OrgImgH);
    */

	CImage NoiseImg;
	if(!LoadImg(&NoiseImg, &CTitle))
		return;

    
    int h = DispImg.GetHeight();
    int w = DispImg.GetWidth();
    
    BYTE **ImgD;
    ImgD = (BYTE**) Create2DList(&DispImg);
    
    BYTE **ImgH;
    ImgH = (BYTE**) Create2DList(&NoiseImg);
    
	/*
    int h = DispImg.GetHeight();
    int w = DispImg.GetWidth();
    
    BYTE **ImgD;
    ImgD = (BYTE**) Create2DList(&DispImg);
    
    BYTE **ImgH;
    ImgH = (BYTE**) Create2DList(&OrgImg);
    */
    
    // ||n||
    int n = h * w;
    
    // compute mean of signal
    double sumU = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            sumU += ImgH[i][j]; //original img
        }
    }
    double u = (double)sumU / n;
    
    // compute variance of signal
    double diffVS = 0.0, sumVS  = 0.0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            diffVS = ImgH[i][j] - u;    //original img
            sumVS += diffVS * diffVS;
        }
    }
    double VS = (double)sumVS / n;
    
    // compute mean of noise
    double sumN = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            sumN += (ImgD[i][j] - ImgH[i][j]);  //noise img - original img
        }
    }
    double un;
    if ( sumN == 0 || n == 0 )
        un = 0;
    else
        un = (double)sumN / n;
        
    // compute variance of noise
    double diffVN = 0.0, sumVN = 0.0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            diffVN = ImgD[i][j] - ImgH[i][j] - un; //noise img - original img - mean of noise
            sumVN += diffVN * diffVN;
        }
    }
    double VN;
    if ( sumVN == 0 || n == 0 )
        VN = 0;
    else
        VN = (double)sumVN / n;
        
    CString fmt;
    double SNR;
    if ( VN == 0 ) {
        SNR = 99999999999999999;
        fmt = ("SNR of image = ∞");
        ::AfxMessageBox(fmt);
    } else {
        SNR = 20 * log10(sqrt(VS) / sqrt(VN));
        fmt.Format(_T("SNR of image = %f"), SNR);
        ::AfxMessageBox(fmt);
    }
    
    Release2DList(ImgD);
    Release2DList(ImgH);
}

int compare(const void* arg1, const void* arg2) {
    return *(int**)arg1 > *(int**)arg2;
}

void CMFCApplication1View::OnProcessMedianfilter()
{
	// TODO: 在此加入您的命令處理常式程式碼
	if (DispImg.IsNull()) {
        CString fmt;
        fmt = "Please load image first";
        ::AfxMessageBox(fmt);
        return ;
    }
	struct  IMAGEPARAMENT P;
    GetImageParament(&DispImg, &P);
	int byte = P.nBytesPerPixel;

	if(byte==3)
		CMFCApplication1View::OnImageToyuv();
    
    ImageCopy(&AnsImg, &DispImg);
    
    int h = DispImg.GetHeight();
    int w = DispImg.GetWidth();
    
    BYTE **ImgO;
    ImgO = (BYTE**) Create2DList(&DispImg);
    
    BYTE **ImgP;
    ImgP = (BYTE**) Create2DList(&AnsImg);
    
    //
    int fh = 3;
    int fw = 3;
    
    int adjustX = (fw % 2) ? 1 : 0;
    int adjustY = (fh % 2) ? 1 : 0;
    int xBound = (int)(fw / 2);
    int yBound = (int)(fh / 2);
    
    
    
    int* arr = (int*)malloc(fh * fw * sizeof(int));
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
        
            int cnt = 0;
            for (int v = -yBound; v != yBound + adjustY; ++v) {
                for (int u = -xBound; u != xBound + adjustX; ++u) {
                    // check boundary
                    if (j + u < 0 || i + v < 0 || j + u >= w || i + v >= h) {
                        continue;
                    }
                    
                    arr[cnt++] = ImgO[i + v][j + u];
                }
            }
            
            qsort((void *)arr, cnt, sizeof(arr[0]), compare);
            
            int  median;
            if (cnt % 2) // if count is an odd number
                median = arr[(int)(cnt / 2)];
            else
                median = (int)((arr[(int)(cnt / 2) - 1] + arr[(int)(cnt / 2)]) / 2);
                
            ImgP[i][j] = median;
            //mfImg->SetPixel(x, y, Color::FromArgb(median, median, median));
        }
    }
    /*
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            ImgD[i][j] = (double)ImgI[i][j]/2;
        }
    }
    */
    //
    ImageCopy(&DispImg, &AnsImg);
    if(byte==3)
		CMFCApplication1View::OnImageBackrgb();
    Invalidate();
    
    Release2DList(ImgO);
    Release2DList(ImgP);
}

int min3( int a, int b, int c) {
    int ary[3] = {a, b, c};
    qsort((void *)ary, 3, sizeof(ary[0]), compare);
    return ary[0];
}
int max3( int a, int b, int c) {
    int ary[3] = {a, b, c};
    qsort((void *)ary, 3, sizeof(ary[0]), compare);
    return ary[2];
}

int MAXMIN (int a, int b, int c, int d, int e) {
    return max3( min3(a, b, c), min3(b, c, d), min3(c, d, e));
}

int MINMAX (int a, int b, int c, int d, int e) {
    return min3( max3(a, b, c), max3(b, c, d), max3(c, d, e));
}

double PMED (int a, int b, int c, int d, int e) {
    return 0.5 * (MAXMIN(a, b, c, d, e) + MINMAX(a, b, c, d, e) );
}

void CMFCApplication1View::OnNoisePmed()
{
	// TODO: 在此加入您的命令處理常式程式碼
	if (DispImg.IsNull()) {
        CString fmt;
        fmt = "Please load image first";
        ::AfxMessageBox(fmt);
        return ;
    }
	struct  IMAGEPARAMENT P;
    GetImageParament(&DispImg, &P);
	int byte = P.nBytesPerPixel;

	if(byte==3)
		CMFCApplication1View::OnImageToyuv();
    
    ImageCopy(&AnsImg, &DispImg);
    
    int h = DispImg.GetHeight();
    int w = DispImg.GetWidth();
    
    BYTE **ImgO;
    ImgO = (BYTE**) Create2DList(&DispImg);
    
    BYTE **ImgP;
    ImgP = (BYTE**) Create2DList(&AnsImg);
    
    //
    /*
    int fh = 5;
    int fw = 5;
    
    int adjustX = (fw % 2) ? 1 : 0;
    int adjustY = (fh % 2) ? 1 : 0;
    int xBound = (int)(fw/2);
    int yBound = (int)(fh/2);
    
    int* arr = (int*)malloc(fh * fw * sizeof(int));
    */
    int Psize = 7;
    int Phsize = Psize / 2;
    double PMEDs;
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int cnt = 0;
            
            if (j - Phsize < 0 || i - Phsize < 0 || j + Phsize >= w || i + Phsize >= h) {
                continue;
            }
            
            PMEDs = (PMED(ImgO[i - 2][j], ImgO[i - 1][j], ImgO[i][j], ImgO[i + 1][j], ImgO[i + 1][j]) +
                     PMED(ImgO[i][j - 2], ImgO[i][j - 1], ImgO[i][j], ImgO[i][j + 1], ImgO[i][j + 2])) / 2;
                     
                     
            ImgP[i][j] = PMEDs;
            //mfImg->SetPixel(x, y, Color::FromArgb(median, median, median));
        }
    }
    
    //
    ImageCopy(&DispImg, &AnsImg);
	   if(byte==3)
		CMFCApplication1View::OnImageBackrgb();
    Invalidate();
    
    Release2DList(ImgO);
    Release2DList(ImgP);
}
