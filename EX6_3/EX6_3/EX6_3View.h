
// EX6_3View.h : CEX6_3View 类的接口
//

#pragma once


class CEX6_3View : public CView
{
protected: // 仅从序列化创建
	CEX6_3View();
	DECLARE_DYNCREATE(CEX6_3View)

// 特性
public:
	CEX6_3Doc* GetDocument() const;

// 操作
public:
	bool set;
	int r,l;
	CRect a, cr;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CEX6_3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // EX6_3View.cpp 中的调试版本
inline CEX6_3Doc* CEX6_3View::GetDocument() const
   { return reinterpret_cast<CEX6_3Doc*>(m_pDocument); }
#endif

