
// EX10_1View.h : CEX10_1View 类的接口
//

#pragma once


class CEX10_1View : public CView
{
protected: // 仅从序列化创建
	CEX10_1View();
	DECLARE_DYNCREATE(CEX10_1View)

// 特性
public:
	CEX10_1Doc* GetDocument() const;

// 操作
public:
	CString str;
	

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CEX10_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // EX10_1View.cpp 中的调试版本
inline CEX10_1Doc* CEX10_1View::GetDocument() const
   { return reinterpret_cast<CEX10_1Doc*>(m_pDocument); }
#endif

