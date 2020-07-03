
// EX11_2View.h : CEX11_2View 类的接口
//

#pragma once


class CEX11_2View : public CView
{
protected: // 仅从序列化创建
	CEX11_2View();
	DECLARE_DYNCREATE(CEX11_2View)

// 特性
public:
	CEX11_2Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CEX11_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPopout();
};

#ifndef _DEBUG  // EX11_2View.cpp 中的调试版本
inline CEX11_2Doc* CEX11_2View::GetDocument() const
   { return reinterpret_cast<CEX11_2Doc*>(m_pDocument); }
#endif

