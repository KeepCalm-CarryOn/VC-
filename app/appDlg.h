
// appDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CappDlg 对话框
class CappDlg : public CDialogEx
{



// 构造
public:
	CappDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	 int st;   
	 unsigned short port;
     unsigned long baud; 
     __int16 status;   
	 int list2,list3;  //用于改变操作信息的显示位置
	 int ok,nok;       //用于记录测试成功 和失败的次数
     INT_PTR nRes;     //用于返回错误提示消息
	 HANDLE icdev;     //读卡器设备的句柄
	 CFont m_editFont; //用于设置字体。
     CString s1;       //用于 复位信息      整数的转化
     CString s2;       //用于 用户区数据    整数的转化
     CString s3;       //用于 配置区数据    整数的转化
     CString str_div;  //用于 显示设备号
     CString str_rst;  //用于 显示复位信心
     CString str_dat;  //用于 显示用户区数据
     CString str_info; //用于 显示配置区数据
	 CString str_valu; //用于 显示密码计数器的值
	 CString str_ok;   //用于 显示测试成功的卡片数量
	 CString str_nok;  //用于 显示测试失败的卡片数量
	 CString str_tim;  //用于 显示时间 
	 SYSTEMTIME tim; 
	//int device_id;
             
	enum { IDD = IDD_APP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
