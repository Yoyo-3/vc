
// ʵ��7.2��3��View.cpp : Cʵ��72��3��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ʵ��7.2��3��.h"
#endif

#include "ʵ��7.2��3��Doc.h"
#include "ʵ��7.2��3��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cʵ��72��3��View

IMPLEMENT_DYNCREATE(Cʵ��72��3��View, CView)

BEGIN_MESSAGE_MAP(Cʵ��72��3��View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// Cʵ��72��3��View ����/����

Cʵ��72��3��View::Cʵ��72��3��View()
{
	// TODO: �ڴ˴���ӹ������

}

Cʵ��72��3��View::~Cʵ��72��3��View()
{
}

BOOL Cʵ��72��3��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cʵ��72��3��View ����

void Cʵ��72��3��View::OnDraw(CDC* pDC)
{
	Cʵ��72��3��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect cr;
	GetClientRect(&cr);
	pDoc->re.top = cr.bottom / 2 - 50;
	pDoc->re.bottom = cr.bottom / 2 + 50;
	pDC->Ellipse(pDoc->re);
	if(pDoc->set) {
		SetTimer(0, 100, NULL);
	}
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cʵ��72��3��View ���

#ifdef _DEBUG
void Cʵ��72��3��View::AssertValid() const
{
	CView::AssertValid();
}

void Cʵ��72��3��View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cʵ��72��3��Doc* Cʵ��72��3��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cʵ��72��3��Doc)));
	return (Cʵ��72��3��Doc*)m_pDocument;
}
#endif //_DEBUG


// Cʵ��72��3��View ��Ϣ�������


void Cʵ��72��3��View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Cʵ��72��3��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->a = 1;
	CView::OnLButtonDown(nFlags, point);
}





void Cʵ��72��3��View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Cʵ��72��3��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->a = 0;
	CView::OnLButtonDblClk(nFlags, point);
}


void Cʵ��72��3��View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Cʵ��72��3��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect cr;
	
	GetClientRect(&cr);
	if (pDoc->a&&pDoc->re.right <= cr.right && !pDoc->b) {
		pDoc->re.left += 5; pDoc->re.right += 5;
		Invalidate();
	}
	if (pDoc->re.right >= cr.right) pDoc->b = 1;
	if (pDoc->a&&pDoc->re.left >= 0 && pDoc->b) {
		pDoc->re.left -= 5; pDoc->re.right -= 5;
		Invalidate();
	}
	if (pDoc->re.left <= 0) pDoc->b = 0;
	CView::OnTimer(nIDEvent);
}
