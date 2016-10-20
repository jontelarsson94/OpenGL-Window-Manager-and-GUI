#include "StdAfx.h"
#include "ControlBase.h"


//===================================
//
//  C A N ' T   T O U C H   T H I S
//
//===================================

ControlBase::ControlBase()
{			 	
}

ControlBase::ControlBase(int x, int y, int w, int h)
{
    X = x;
    Y = y;
    Width = w;
    Height = h;
}
ControlBase::~ControlBase(void)
{
}

void ControlBase::OnLoaded(void)
{

}

void ControlBase::OnPaint(void)
{
	
}


void ControlBase::OnKeyboard(unsigned char key, int x, int y)
{
}

void ControlBase::OnMouseUp(int button, int x, int y)
{	
}

void ControlBase::OnMouseDown(int button, int x, int y)
{	
}

void ControlBase::OnMouseMove(int button, int x, int y)
{	
}

void ControlBase::OnResize(int width, int height)
{
}

