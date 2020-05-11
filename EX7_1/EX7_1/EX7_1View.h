
// EX7_1View.h : CEX7_1View 类的接口
//

#pragma once


class CEX7_1View : public CView
{
protected: // 仅从序列化创建
	CEX7_1View();
	DECLARE_DYNCREATE(CEX7_1View)

// 特性
public:
	CEX7_1Doc* GetDocument() const;

// 操作
public:
	int t;
	bool set;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CEX7_1View();
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

#ifndef _DEBUG  // EX7_1View.cpp 中的调试版本
inline CEX7_1Doc* CEX7_1View::GetDocument() const
   { return reinterpret_cast<CEX7_1Doc*>(m_pDocument); }
#endif

