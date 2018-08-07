
// appDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "app.h"
#include "appDlg.h"
#include "afxdialogex.h"
#include "mwic_32.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)    //::���������������CAboutDlg���ⶨ���������������::��ʾ�˺�������ĳ�Ա������
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CappDlg �Ի���




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

BEGIN_MESSAGE_MAP(CappDlg, CDialogEx)     //Ϊ��Ϣ������������
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CappDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CHECK1, &CappDlg::OnBnClickedCheck1)
END_MESSAGE_MAP()


// CappDlg ��Ϣ�������

BOOL CappDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
	// �������� ��С
	m_editFont.CreatePointFont(120, _T("����"));
	m_list2.SetFont(&m_editFont);

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CappDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CappDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//��ʼ���Եİ����������
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

 m_list2.ResetContent();                                   //��ղ��������е���ʾ
 GetLocalTime(&tim); 
 str_tim.Format("                             %2d:%2d:%2d",tim.wHour,tim.wMinute,tim.wSecond);
 /*��ȡ��Ƭ״̬*/
 m_list2.InsertString(list2,"1 ���ӿ�Ƭ");
 list2++;
 st=get_status(icdev,&status);
 if (st<0) 
 {
    nRes = MessageBox(_T("��ȡ������״̬ʧ��"),_T("����"),MB_RETRYCANCEL|MB_ICONSTOP);
   if(IDCANCEL==nRes)
	   return;
	goto end;
 }
 else
 {  
	 if(status==0)
	 {
	  //����������Ϣ
	   nRes = MessageBox(_T("δ��⵽��Ƭ"),_T("����"),MB_RETRYCANCEL|MB_ICONSTOP);
       if(IDCANCEL==nRes)
	   return;
       //goto end1;
	  }
	 if(status==1)
	 {
	   //��⵽��Ƭ������һ�β���
	   UpdateData(TRUE);
	    m_count+=1;
	   UpdateData(FALSE);
	 }
	 
 }
 
 //��Ƭ��λ
  m_list2.InsertString(list2,"2 ��Ƭ��λ");
  list2++;
  res=reset_1608(icdev,4,data_buffer);
  if(res==0)
  {
    for(int i=0;i<4;i++)
     {
       s1.Format(_T("%x"),data_buffer[i]);
       str_rst+=s1; 
      }
    //str_rst.Empty();  //��ʾ��֮������
  }
  else
  {
     nRes = MessageBox(_T("��Ƭ��λʧ��"),_T("����"),MB_RETRYCANCEL|MB_ICONSTOP);
     if(IDCANCEL==nRes)
	  return;
      goto end1;
 
  }
  
 //���û���д����
   m_list2.InsertString(list2,"3 ���û���0д6�ֽ�����");
   list2++;
   res=swr_1608(icdev,0,0,7,data);
   if(res!=0)
   {
   
     nRes = MessageBox(_T("д0�û���ʧ��"),_T("����"),MB_RETRYCANCEL|MB_ICONSTOP);
     if(IDCANCEL==nRes)
	  return;
      goto end1;

   }

 //���û�����
   m_list2.InsertString(list2,"4 ���û���0��6�ֽ�����");
   list2++;
   res=srd_1608(icdev,0,0,6,data_buffer);
   if(res==0)
   {
    for(int i=0;i<6;i++)
   { 
	 s2.Format(_T("%x"),data_buffer[i]);
     str_dat+=s2;
	 //������������ȷ����д��Ĭ��ֵ
	 if(data_buffer[i]==data[i])
	 swr_1608(icdev,0,i,7,(data+7)); 
    }
    str_dat.Empty();
   }
   else{
    
     
     nRes = MessageBox(_T("��0�û���ʧ��"),_T("����"),MB_RETRYCANCEL|MB_ICONSTOP);
     if(IDCANCEL==nRes)
	  return;
      goto end1;
   
   }
  //��07��д�������У��
  //У���д���롣0д / 1��
  m_list2.InsertString(list2,"5 ��07��д����У��");
  list2++;
  res = csc_1608(icdev,7,3,0,key);
  if(res!=0)
  {	   
    nRes = MessageBox(_T("У��07��д����ʧ��"),_T("����"),MB_RETRYCANCEL|MB_ICONSTOP);
    if(IDCANCEL==nRes)
	  return;
      goto end1;
	rsct_1608(icdev,7,3,0,last_value);
	str_valu.Format(_T("%x"),last_value[0]);
   }


  //������������
  m_list2.InsertString(list2,"6 ������������");
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
  

  //��¼�ɹ��Ĳ��Դ�������ӡ
  m_ok+=1;
  ok+=1;
  str_ok.Format(_T("%d"),ok);
  //��ӡʱ��
 m_list2.InsertString(list2,str_tim);
 list2++;
  //���³ɹ�����
    UpdateData(TRUE);
	  m_ok += 1 ;
	 UpdateData(FALSE);
  //�����ɹ���ʾ��
  nRes = MessageBox(_T(" �� ")+str_ok+_T(" Ƭ����ͨ��"),_T("���"),MB_OK|MB_ICONINFORMATION);
    if(IDCANCEL==nRes)
	return;
    goto end;
  }
  else{
  
	  goto end1;
	 
  
  
  
  }




end1:  nRes = MessageBox(_T(" �� ")+str_ok+_T(" Ƭ����ʧ��"),_T("����"),MB_OK|MB_ICONSTOP);
       if(IDCANCEL==nRes)
	   return;
      UpdateData(TRUE);
	  m_nok+=1;
	  UpdateData(FALSE); ;
end: ;
}


//���Ӷ�������checkbox �������
void CappDlg::OnBnClickedCheck1()
{
  CButton* but = (CButton*)GetDlgItem(IDC_CHECK1);	
  if(but->GetCheck())
	 {
	  port = 0;
      baud  = 9600; 
      status = 0;
      //���ӳɹ��󣬽���Ƭ����������Ϊ0

	  UpdateData(TRUE);
	   m_count = 0;
	   m_ok = 0;
	   m_nok =0;
	  UpdateData(FALSE);
     
	  ok = 0;
	  nok = 0;
	  //���� ������
	 icdev=ic_init(port,baud);          // ���Ӷ����� icdev   handle����  ���ӳɹ��� 276  ���Ӳ��ɹ���������ֵ
	 str_div.Format(_T("%d"),icdev);
	 if(icdev<0)
	  {
	   //����������Ϣ
	   nRes = MessageBox(_T("����ʧ��"),_T("����"),MB_RETRYCANCEL|MB_ICONSTOP);
	   if(IDCANCEL==nRes)
		   return;
	   goto end;
	  }
	  if(icdev>0)
	  {
		//����������Ϣ
	   nRes = MessageBox(_T("���ӳɹ�"),_T("  The dev is:")+str_div,MB_OK|MB_ICONINFORMATION);
	   if(IDCANCEL==nRes)
		   return;
	   goto end;
	  }

	  
	 }
 else
	 {
	  //�Ͽ�������
	   st=ic_exit(icdev);
	   nRes = MessageBox(_T("���ӶϿ�"),_T("The dev is:")+str_div,MB_OK|MB_ICONINFORMATION);
	   if(IDCANCEL==nRes)
		   return;
	   goto end;
	 
	 
	 }




end: ;	

}
