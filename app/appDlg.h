
// appDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CappDlg �Ի���
class CappDlg : public CDialogEx
{



// ����
public:
	CappDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	 int st;   
	 unsigned short port;
     unsigned long baud; 
     __int16 status;   
	 int list2,list3;  //���ڸı������Ϣ����ʾλ��
	 int ok,nok;       //���ڼ�¼���Գɹ� ��ʧ�ܵĴ���
     INT_PTR nRes;     //���ڷ��ش�����ʾ��Ϣ
	 HANDLE icdev;     //�������豸�ľ��
	 CFont m_editFont; //�����������塣
     CString s1;       //���� ��λ��Ϣ      ������ת��
     CString s2;       //���� �û�������    ������ת��
     CString s3;       //���� ����������    ������ת��
     CString str_div;  //���� ��ʾ�豸��
     CString str_rst;  //���� ��ʾ��λ����
     CString str_dat;  //���� ��ʾ�û�������
     CString str_info; //���� ��ʾ����������
	 CString str_valu; //���� ��ʾ�����������ֵ
	 CString str_ok;   //���� ��ʾ���Գɹ��Ŀ�Ƭ����
	 CString str_nok;  //���� ��ʾ����ʧ�ܵĿ�Ƭ����
	 CString str_tim;  //���� ��ʾʱ�� 
	 SYSTEMTIME tim; 
	//int device_id;
             
	enum { IDD = IDD_APP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CListBox m_list2;
	afx_msg void OnBnClickedCheck1();
	UINT m_count;
	UINT m_ok;
	UINT m_nok;
};
