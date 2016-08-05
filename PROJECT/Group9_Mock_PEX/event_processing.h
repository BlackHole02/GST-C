#pragma once

#include"hdc_controller.h"
#include"bitmap.h"

#define EVENT_LIST  ON_COMMAND(ID_BUTTON32771, &CEventProcessing::VeDuongThang)\
					ON_COMMAND(ID_BUTTON32772, &CEventProcessing::VeHinhCN)\
					ON_WM_LBUTTONDOWN()\
					ON_WM_LBUTTONUP()\
					ON_WM_MOUSEMOVE()


class CEventProcessing :
	public CView
{
public:
	void VeDuongThang();
	void VeHinhCN();
	void mouseDown(UINT nFlags, CPoint point);
	CEventProcessing();
	~CEventProcessing();
};

