#include "stdafx.h"
#include "EllipseEx.h"


CEllipseEx::CEllipseEx(void)
{
}


CEllipseEx::~CEllipseEx(void)
{
}

void CEllipseEx::SetPoint(CPoint p1, CPoint p2)
{
	CShapeEx::SetPoint(p1,p2);
}

void CEllipseEx::Put4Pixel(HDC hdc,int x, int y, int x0, int y0, COLORREF color)
{
	SetPixel(hdc,x + x0, y + y0, color);
    SetPixel(hdc,x - x0, y + y0, color);
    SetPixel(hdc,x + x0, -y + y0, color);
    SetPixel(hdc,x - x0, -y + y0, color);
}


bool CEllipseEx::Draw(HDC hdc)
{
	if(_nLeft==_nRight || _nTop == _nBottom)
		return false;
	Ellipse(hdc,_nLeft,_nTop,_nRight,_nBottom);

	//COLORREF color= 0;

	//int A = (_nRight - _nLeft)/2, B = (_nBottom - _nTop)/2;
	//int A2, B2, p, Const1, Const2, Delta1, Delta2, MaxX, MaxY;

	//int x0 = (_nLeft + _nRight)/2, y0 = (_nTop + _nBottom)/2;

	//A2 = A * A;
	//B2 = B * B;

	//if(A==0)
	//	return false;

	//int xc=x0,yc=y0;
	//
	//int c1=(B2)/(A2);

	//if(c1==0)
	//	return false;

 //   int c2=1/c1;
	//int x=0,y=B;
	//p=2*c1-2*B+1;

	//while(c1*(x/y)<=1)
 //   {
 //       Put4Pixel(hdc,xc,yc,x,y,color);
 //       if(p<0)
 //           p=p+2*c1*(2*x+3);
 //       else
 //       {
 //           p=p+4*(1-y)+2*c1*(2*x+3);
 //           y--;
 //       }
 //       x++;
 //   }
 //   x=A;
 //   y=0;
 //   p=2*c2-2*A+1;
 //   while(c2*(y/x)<1)
 //   {
 //       Put4Pixel(hdc,xc,yc,x,y,color);
 //       if(p<0)
 //           p=p+2*c2*(2*y+3);
 //       else
 //       {
 //           p=p+4*(1-x)+2*c2*(2*y+3);
 //           x--;
 //       }
 //       y++;
 //   }

	///*MaxX = (int)(W2 / sqrt(W2 + H2)+0.5);
	//MaxY = (int)(H2 / sqrt(W2 + H2)+0.5);

	//p = H2 - W2 * H + W2 / 4;
	//Const1 = 2 * H2;
	//Const2 = 2 * W2;

	//x = 0;
	//y = H;

	//Delta1 = H2 * (2 * x + 3);
	//Delta2 = 2 * W2 * (1 - y) + H2 * (2 * x + 3);

	//Put4Pixel(hdc,x, y,x0, y0, color);

	//while (x < MaxX)
	//{
	//	if (p >= 0)
	//	{
	//		p += Delta2;
	//		Delta2 += Const2;
	//		y--;
	//	}
	//	else
	//		p += Delta1;

	//	Delta2 += Const1;
	//	Delta1 += Const1;
	//	x++;

	//	Put4Pixel(hdc,x, y, x0, y0, color);

	//}*/
	return true;
}



//void CEllipseEx::Put4Pixel(HDC hdc,int x, int y, int x0, int y0, COLORREF color)
//{
//    SetPixel(hdc,x + x0, y + y0, color);
//    SetPixel(hdc,-x + x0, y + y0, color);
//    SetPixel(hdc,x + x0, -y + y0, color);
//    SetPixel(hdc,-x + x0, -y + y0, color);
//}
bool CEllipseEx::IsSelected(int x, int y)
{
	return true;
}
