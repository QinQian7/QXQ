#pragma once


// Plus �Ի���

class Plus : public CDialogEx
{
	DECLARE_DYNAMIC(Plus)

public:
	Plus(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Plus();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	
	int x;
	int y;
	int r;

	afx_msg void OnBnClickedButton1();
};
