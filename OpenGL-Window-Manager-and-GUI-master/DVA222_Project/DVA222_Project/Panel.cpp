#include "stdafx.h"
#include "Panel.h"

//Contructor
Panel::Panel()
{
	SetBackground(Color(207, 216, 220));

}

//Desctructor
Panel::~Panel()
{
}



//Looks
void Panel::SetBackground(Color background)
{
	this->background = background;
}

Color Panel::GetBackground()
{
	return background;
}

//ControlBase Overrides
void Panel::OnPaint()
{
	//Set background color
	SetColor(background.R, background.G, background.B);
	
	//Paint panel
	FillRectangle(X+zeroPoint.X, Y+zeroPoint.Y, Width, Height);
	
	//Paint elements
	PaintElements();
}

//Custom SetZeroPointForControls
void Panel::SetZeroPointForControls()
{
	int length = controls.size();
	for (size_t i = 0; i < length; i++)
	{
		//Set Zero Point for control
		controls.at(i)->SetZeroPoint(Point(zeroPoint.X + X, zeroPoint.Y + Y));
		
		//Set Zero Point for controls children
		controls.at(i)->SetZeroPointForControls();
	}
}

//Helper function for painting panel elements
void Panel::PaintElements()
{
	//For for Z
	std::sort(controls.begin(), controls.end(), [](const UIControl* a, const UIControl* b)
	{ return a->GetZ() < b->GetZ(); });
	
	//Paint controls
	int length = controls.size();
	for (size_t i = 0; i < length; i++)
	{
		controls.at(i)->OnPaint();
	}
}

