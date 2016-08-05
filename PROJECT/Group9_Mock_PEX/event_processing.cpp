#include "stdafx.h"
#include"Group9_Mock_PEXView.h"
#include "event_processing.h"


CEventProcessing::CEventProcessing()
{
}
void CEventProcessing::VeHinhCN()
{

}

void CEventProcessing::VeDuongThang()
{
	CHdcController ctrl(ViewClass::hdcView);
	ctrl.DrawLine(0, 10, 10, 200, 200);

	ViewClass::Referesh();
}

void CEventProcessing::mouseDown(UINT nFlags, CPoint point)
{

}


CEventProcessing::~CEventProcessing()
{
}
