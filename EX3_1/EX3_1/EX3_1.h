
// EX3_1.h : EX3_1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CEX3_1App:
// �йش����ʵ�֣������ EX3_1.cpp
//

class CEX3_1App : public CWinAppEx
{
public:
	CEX3_1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CEX3_1App theApp;
