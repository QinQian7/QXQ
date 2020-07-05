
// EX13_1View.h : CEX13_1View 类的接口
//

#pragma once


class CEX13_1View : public CView
{
protected: // 仅从序列化创建
	CEX13_1View();
	DECLARE_DYNCREATE(CEX13_1View)

// 特性
public:
	CEX13_1Doc* GetDocument() const;

// 操作
public:
	CString filename;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CEX13_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);

	afx_msg void OnPopout();
};

#ifndef _DEBUG  // EX13_1View.cpp 中的调试版本
inline CEX13_1Doc* CEX13_1View::GetDocument() const
   { return reinterpret_cast<CEX13_1Doc*>(m_pDocument); }
#endif

