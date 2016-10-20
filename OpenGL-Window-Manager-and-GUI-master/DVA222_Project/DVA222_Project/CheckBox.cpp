#include "stdafx.h"
#include "CheckBox.h"
#include "Graphix.h"

//Constructor
CheckBox::CheckBox()
{
	hit = checked = false;
	buttonColor = Color(250, 50, 50);
	SetSize(Size(16, 16));
	setColor(Color(69, 90, 100));
}

//Destructor
CheckBox::~CheckBox()
{
}

//ControlBase Override
void CheckBox::OnPaint(void)
{
	SetColor(buttonColor.R, buttonColor.G, buttonColor.B);
	DrawRectangle(X+zeroPoint.X, Y+zeroPoint.Y, Width, Height);
	
	if (checked)
	{
		DrawLine(X + zeroPoint.X + 2, Y + zeroPoint.Y + 10, X + zeroPoint.X + 8, Y + zeroPoint.Y + 15);
		DrawLine(X + zeroPoint.X + 8, Y + zeroPoint.Y + 15, X + zeroPoint.X + 14, Y + zeroPoint.Y + 5);
	}

	buttonText.OnPaint();
}

void CheckBox::OnMouseDown(int button, int x, int y)
{
	if (hit && button == MOUSE_LEFT)
	{
		if (!checked)
			checked = true;
		else
			checked = false;
	}
}

void CheckBox::OnMouseUp(int button, int x, int y)
{

}

void CheckBox::OnMouseMove(int button, int x, int y)
{
	if (x > X+zeroPoint.X && x < X+zeroPoint.X + Width && y > Y+zeroPoint.Y && y < Y+zeroPoint.Y + Height)
		hit = true;
	else
	{
		hit = false;
	}
}

//Custom SetZeroPointForControls
void CheckBox::SetZeroPointForControls()
{
	buttonText.SetZeroPoint(Point(X + zeroPoint.X, Y + zeroPoint.Y));
	buttonText.SetZeroPointForControls();

	//Set label location
	buttonText.SetLocation(Point(Width + 8, Height/2 - 5));
}

//Label
void CheckBox::setText(std::string text)
{
	buttonText.setText(text);
}

std::string CheckBox::getText()
{
	return buttonText.getText();
}

void CheckBox::setTextColor(Color color)
{
	buttonText.setColor(color);
}

Color CheckBox::getTextColor()
{
	return buttonText.getColor();
}

//Looks
void CheckBox::setColor(Color color)
{
	buttonColor = color;
}

Color CheckBox::getColor()
{
	return buttonColor;
}

//Status
void CheckBox::setStatus(bool checked)
{
	this->checked = checked;
}

bool CheckBox::getStatus()
{
	return checked;
}