
// EX12_1View.h : CEX12_1View 类的接口
//

#pragma once


class CEX12_1View : public CView
{
protected: // 仅从序列化创建
	CEX12_1View();
	DECLARE_DYNCREATE(CEX12_1View)

// 特性
public:
	CEX12_1Doc* GetDocument() const;

// 操作
public:
	CPoint p;
	int xu, yu, xd, yd, W, L;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CEX12_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
//	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
//	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // EX12_1View.cpp 中的调试版本
inline CEX12_1Doc* CEX12_1View::GetDocument() const
   { return reinterpret_cast<CEX12_1Doc*>(m_pDocument); }
#endif

