#include "stdafx.h"
#include "UIControl.h"

//Contructor
UIControl::UIControl()
{
	//Default values
	SetLocation(Point(0, 0));
	SetSize(Size(0, 0));
	SetZeroPoint(Point(0, 0));
	SetZ(0);
}

//Destructor
UIControl::~UIControl()
{

}

//Location
Point UIControl::GetLocation()
{
	return Point(X, Y);
}

void UIControl::SetLocation(Point location)
{
	X = location.X;
	Y = location.Y;
	SetZeroPointForControls();
}


//Size
Size UIControl::GetSize()
{
	return Size(Width, Height);
}

void UIControl::SetSize(Size size)
{
	Width = size.Width;
	Height = size.Height;
}

//Relative location start point
void UIControl::SetZeroPoint(Point zeroPoint)
{
	this->zeroPoint.X = zeroPoint.X;
	this->zeroPoint.Y = zeroPoint.Y;
}

void UIControl::SetZeroPointForControls()
{
	
}

//Z
void UIControl::SetZ(int z)
{
	this->z = z;
}
int UIControl::GetZ() const
{
	return z;
}
