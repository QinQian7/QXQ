
// EX12_4View.h : CEX12_4View 类的接口
//

#pragma once


class CEX12_4View : public CView
{
protected: // 仅从序列化创建
	CEX12_4View();
	DECLARE_DYNCREATE(CEX12_4View)

// 特性
public:
	CEX12_4Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CEX12_4View();
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

#ifndef _DEBUG  // EX12_4View.cpp 中的调试版本
inline CEX12_4Doc* CEX12_4View::GetDocument() const
   { return reinterpret_cast<CEX12_4Doc*>(m_pDocument); }
#endif

