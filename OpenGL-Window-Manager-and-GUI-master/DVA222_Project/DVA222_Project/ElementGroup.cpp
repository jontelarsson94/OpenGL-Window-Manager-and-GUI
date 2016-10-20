#include "stdafx.h"
#include "ElementGroup.h"

//Constructor
ElementGroup::ElementGroup()
{
	SetBorderColor(Color(96, 125, 139));
	title = new Label();
	title->setText("Group");
	Add(title);
}

//Destructor
ElementGroup::~ElementGroup()
{
	delete title;
}

//Looks
void ElementGroup::SetBorderColor(Color color)
{
	border = color;
}

Color ElementGroup::GetBorderColor()
{
	return border;
}

//ControlBase Override
void ElementGroup::OnPaint()
{
	SetColor(background.R, background.G, background.B);
	FillRectangle(X + zeroPoint.X, Y + zeroPoint.Y, Width, Height);
	SetColor(border.R, border.G, border.B);
	DrawRectangle(X + zeroPoint.X, Y + zeroPoint.Y, Width, Height);
	PaintElements();

}

//Helper
void ElementGroup::PaintElements()
{
	int length = controls.size();
	for (size_t i = 0; i < length; i++)
	{
		controls.at(i)->SetLocation(Point(10, 20 * i+10));
		controls.at(i)->OnPaint();
	}
}

//Title
void ElementGroup::SetTitle(std::string title)
{
	this->title->setText(title);
}

std::string ElementGroup::GetTitle()
{
	return title->getText();
}