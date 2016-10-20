#include "stdafx.h"
#include "Button.h"

//Constructor
Button::Button()
{
	//Mouse event bools
	hit = pressed = false;

	//Looks
	background_normal = Color(96, 125, 139);
	border_normal = Color(114, 114, 114);
	text_normal = Color(256, 256, 256);

	background_hover = Color(69, 90, 100);
	border_hover = Color(114, 114, 114);
	text_hover = Color(182, 182, 182);

	background_click = Color(158, 158, 158);
	border_click = Color(114, 114, 114);
	text_click = Color(33, 33, 33);

	background = background_normal;
	border = border_normal;
	text = text_normal;

	SetSize(Size(100, 30));

}

//Destructor
Button::~Button()
{

}

//ControlBase Override
void Button::OnPaint()
{
	if (pressed){
		background = background_click;
		border = border_click;
		text = text_click;
	}else if (hit){
		background = background_hover;
		border = border_hover;
		text = text_hover;
	}else{
		background = background_normal;
		border = border_normal;
		text = text_normal;
	}
	Draw();
}

void Button::OnLoaded()
{
	buttonText.OnLoaded();
}

void Button::OnMouseMove(int button, int x, int y)
{
	if (x>X + zeroPoint.X && x < X + zeroPoint.X + Width && y>Y + zeroPoint.Y && y < Y + zeroPoint.Y + Height)
		hit = true;
	else
	{
		pressed = hit = false;
	}
}

void Button::OnMouseDown(int button, int x, int y)
{
	if (hit && button == MOUSE_LEFT)
		pressed = true;
}

void Button::OnMouseUp(int button, int x, int y)
{
	pressed = false;
}

//Custom SetZeroPointForControls
void Button::SetZeroPointForControls()
{
	//Set Zero Points
	buttonText.SetZeroPoint(Point(X + zeroPoint.X, Y + zeroPoint.Y));
	buttonText.SetZeroPointForControls();

	//Center label
	buttonText.SetLocation(Point(8, Height / 2 - 5));
}

//Label
void Button::SetButtonText(std::string text)
{
	buttonText.setText(text);
}

std::string Button::GetButtonText()
{
	return buttonText.getText();
}

//Helper functions
void Button::Draw()
{
	//Draw Button
	SetColor(background.R, background.G, background.B);
	FillRectangle(X + zeroPoint.X, Y + zeroPoint.Y, Width, Height);
	SetColor(border.R, border.G, border.B);
	DrawRectangle(X + zeroPoint.X, Y + zeroPoint.Y, Width, Height);

	//Draw Label
	buttonText.setColor(text);
	buttonText.OnPaint();
}

//Looks
void Button::SetColorNormal(Color background, Color border, Color text)
{
	background_normal = background;
	border_normal = border;
	text_normal = text;
}
void Button::SetColorHover(Color background, Color border, Color text)
{
	background_hover = background;
	border_hover = border;
	text_hover = text;
}
void Button::SetColorClick(Color background, Color border, Color text)
{
	background_click = background;
	border_click = border;
	text_click = text;
}