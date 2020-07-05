#pragma once


// Combine 对话框

class Combine : public CDialogEx
{
	DECLARE_DYNAMIC(Combine)

public:
	Combine(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Combine();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString s1;
	int x;
	CString s2;
	afx_msg void OnBnClickedButton1();
};
