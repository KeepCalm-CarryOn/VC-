
// appDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "app.h"
#include "appDlg.h"
#include "afxdialogex.h"
#include "mwic_32.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)    //::作用域运算符，在CAboutDlg类外定义这个函数，加上::表示此函数是类的成员函数。
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CappDlg 对话框




CappDlg::CappDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CappDlg::IDD, pParent)
	, m_count(0)
	, m_ok(0)
	, m_nok(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CappDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_list2);
	DDX_Text(pDX, IDC_EDIT1, m_count);
	DDX_Text(pDX, IDC_EDIT2, m_ok);
	DDX_Text(pDX, IDC_EDIT3, m_nok);
}

BEGIN_MESSAGE_MAP(CappDlg, CDialogEx)     //为消息处理函数添加入口
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CappDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CHECK1, &CappDlg::OnBnClickedCheck1)
END_MESSAGE_MAP()


// CappDlg 消息处理程序

BOOL CappDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	// 设置字体 大小
	m_editFont.CreatePointFont(120, _T("楷体"));
	m_list2.SetFont(&m_editFont);

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CappDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CappDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CappDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//开始测试的按键处理程序
void CappDlg::OnBnClickedButton1()
{
 
 
 unsigned char data_buffer[10] = {0,0,0,0,0,0,0,0,0,0};
 unsigned char data[8] = {0x11,0x22,0x33,0x44,0x55,0x66,0x77,0xff};
 unsigned char config[10] = {0,0,0,0,0,0,0,0,0,0};
 unsigned char key[3] = {0x34,0x34,0x34};
 unsigned char res = 0; 
 unsigned char last_value[1]={0};
 list2=0;                                                  
 list3=0;     

 m_list2.ResetContent();                                   //清空测试内容中的显示
 GetLocalTime(&tim); 
 str_tim.Format("                             %2d:%2d:%2d",tim.wHour,tim.wMinute,tim.wSecond);
 /*获取卡片状态*/
 m_list2.InsertString(list2,"1 连接卡片");
 list2++;
 st=get_status(icdev,&status);
 if (st<0) 
 {
    nRes = MessageBox(_T("获取读卡器状态失败"),_T("错误！"),MB_RETRYCANCEL|MB_ICONSTOP);
   if(IDCANCEL==nRes)
	   return;
	goto end;
 }
 else
 {  
	 if(status==0)
	 {
	  //弹出错误信息
	   nRes = MessageBox(_T("未检测到卡片"),_T("错误！"),MB_RETRYCANCEL|MB_ICONSTOP);
       if(IDCANCEL==nRes)
	   return;
       //goto end1;
	  }
	 if(status==1)
	 {
	   //检测到卡片即算作一次测试
	   UpdateData(TRUE);
	    m_count+=1;
	   UpdateData(FALSE);
	 }
	 
 }
 
 //卡片复位
  m_list2.InsertString(list2,"2 卡片复位");
  list2++;
  res=reset_1608(icdev,4,data_buffer);
  if(res==0)
  {
    for(int i=0;i<4;i++)
     {
       s1.Format(_T("%x"),data_buffer[i]);
       str_rst+=s1; 
      }
    //str_rst.Empty();  //显示完之后就清空
  }
  else
  {
     nRes = MessageBox(_T("卡片复位失败"),_T("错误！"),MB_RETRYCANCEL|MB_ICONSTOP);
     if(IDCANCEL==nRes)
	  return;
      goto end1;
 
  }
  
 //向用户区写数据
   m_list2.InsertString(list2,"3 向用户区0写6字节数据");
   list2++;
   res=swr_1608(icdev,0,0,7,data);
   if(res!=0)
   {
   
     nRes = MessageBox(_T("写0用户区失败"),_T("错误！"),MB_RETRYCANCEL|MB_ICONSTOP);
     if(IDCANCEL==nRes)
	  return;
      goto end1;

   }

 //读用户数据
   m_list2.InsertString(list2,"4 从用户区0读6字节数据");
   list2++;
   res=srd_1608(icdev,0,0,6,data_buffer);
   if(res==0)
   {
    for(int i=0;i<6;i++)
   { 
	 s2.Format(_T("%x"),data_buffer[i]);
     str_dat+=s2;
	 //若读出数据正确，则写会默认值
	 if(data_buffer[i]==data[i])
	 swr_1608(icdev,0,i,7,(data+7)); 
    }
    str_dat.Empty();
   }
   else{
    
     
     nRes = MessageBox(_T("读0用户区失败"),_T("错误！"),MB_RETRYCANCEL|MB_ICONSTOP);
     if(IDCANCEL==nRes)
	  return;
      goto end1;
   
   }
  //对07区写口令进行校验
  //校验读写密码。0写 / 1读
  m_list2.InsertString(list2,"5 对07区写口令校验");
  list2++;
  res = csc_1608(icdev,7,3,0,key);
  if(res!=0)
  {	   
    nRes = MessageBox(_T("校验07区写口令失败"),_T("错误！"),MB_RETRYCANCEL|MB_ICONSTOP);
    if(IDCANCEL==nRes)
	  return;
      goto end1;
	rsct_1608(icdev,7,3,0,last_value);
	str_valu.Format(_T("%x"),last_value[0]);
   }


  //读设置区内容
  m_list2.InsertString(list2,"6 读设置区内容");
  list2++;
   m_list2.InsertString(list2,"");
  list2++;
     m_list2.InsertString(list2,"");
  list2++;
     m_list2.InsertString(list2,"");
  list2++;
  res=srdconfig_1608(icdev,0,10,config);
  if(res==0)
  {
  for(int i=0;i<10;i++)
  {
     s3.Format(_T("%x"),config[i]);
     str_info+=s3;
  } 
   str_info.Empty();
  

  //记录成功的测试次数并打印
  m_ok+=1;
  ok+=1;
  str_ok.Format(_T("%d"),ok);
  //打印时间
 m_list2.InsertString(list2,str_tim);
 list2++;
  //更新成功计数
    UpdateData(TRUE);
	  m_ok += 1 ;
	 UpdateData(FALSE);
  //弹出成功提示框
  nRes = MessageBox(_T(" 第 ")+str_ok+_T(" 片测试通过"),_T("完成"),MB_OK|MB_ICONINFORMATION);
    if(IDCANCEL==nRes)
	return;
    goto end;
  }
  else{
  
	  goto end1;
	 
  
  
  
  }




end1:  nRes = MessageBox(_T(" 第 ")+str_ok+_T(" 片测试失败"),_T("错误"),MB_OK|MB_ICONSTOP);
       if(IDCANCEL==nRes)
	   return;
      UpdateData(TRUE);
	  m_nok+=1;
	  UpdateData(FALSE); ;
end: ;
}


//连接读卡器的checkbox 处理程序
void CappDlg::OnBnClickedCheck1()
{
  CButton* but = (CButton*)GetDlgItem(IDC_CHECK1);	
  if(but->GetCheck())
	 {
	  port = 0;
      baud  = 9600; 
      status = 0;
      //连接成功后，将卡片测试数量置为0

	  UpdateData(TRUE);
	   m_count = 0;
	   m_ok = 0;
	   m_nok =0;
	  UpdateData(FALSE);
     
	  ok = 0;
	  nok = 0;
	  //连接 读卡器
	 icdev=ic_init(port,baud);          // 连接读卡器 icdev   handle类型  连接成功是 276  连接不成功则是其他值
	 str_div.Format(_T("%d"),icdev);
	 if(icdev<0)
	  {
	   //弹出错误信息
	   nRes = MessageBox(_T("连接失败"),_T("错误！"),MB_RETRYCANCEL|MB_ICONSTOP);
	   if(IDCANCEL==nRes)
		   return;
	   goto end;
	  }
	  if(icdev>0)
	  {
		//弹出错误信息
	   nRes = MessageBox(_T("连接成功"),_T("  The dev is:")+str_div,MB_OK|MB_ICONINFORMATION);
	   if(IDCANCEL==nRes)
		   return;
	   goto end;
	  }

	  
	 }
 else
	 {
	  //断开读卡器
	   st=ic_exit(icdev);
	   nRes = MessageBox(_T("连接断开"),_T("The dev is:")+str_div,MB_OK|MB_ICONINFORMATION);
	   if(IDCANCEL==nRes)
		   return;
	   goto end;
	 
	 
	 }




end: ;	

}
