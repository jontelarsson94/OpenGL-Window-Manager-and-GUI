#include "stdafx.h"
#include "Window.h"

//Constructor
Window::Window()
{
	//Title
	titleBarHeight = 30;

	//Mouse event bools
	pressed = hit = moving = false;
	clickLocation = Point(0, 0);
	
	//Panel
	panel = new Panel();

	//Looks
	SetBackground(Color(207, 216, 220));
	SetBorderColor(Color(0, 0, 0));

	//Title
	title = new Label();
	title->setColor(Color(256, 256, 256));

}

//Destructor
Window::~Window()
{

}

//ControlBase Overrides
void Window::OnLoaded()
{
	panel->OnLoaded();
	title->OnLoaded();
	SetZeroPointForControls();
}

void Window::OnPaint()
{
	SetColor(border.R, border.G, border.B);
	DrawRectangle(X, Y-1, Width+1, Height+1);

	//Looks
	SetColor(96, 125, 139);

	//Title bar
	FillRectangle(X, Y, Width, titleBarHeight);
	title->OnPaint();

	//Main panel
	panel->OnPaint();
}

void Window::OnKeyboard(unsigned char key, int x, int y)
{
	//Foreward
	panel->OnKeyboard(key, x, y);
	title->OnKeyboard(key, x, y);
}

void Window::OnMouseUp(int button, int x, int y)
{
	pressed = moving = false;

	//Foreward
	panel->OnMouseUp(button, x, y);
	title->OnMouseUp(button, x, y);
}

void Window::OnMouseDown(int button, int x, int y)
{
	if (hit)
	{
		//Register click
		pressed = true;
	}

	//Foreward
	panel->OnMouseDown(button, x, y);
	title->OnMouseDown(button, x, y);
}

void Window::OnMouseMove(int button, int x, int y)
{
	if (x>X && x < X + Width && y>Y && y < Y + titleBarHeight)
		hit = true;
	else
	{
		//Reset
		pressed = hit = false;
	}
	if (pressed)
	{
		if (moving)
		{

		}
		else{
			moving = true;

			//Set initial mouse click point
			clickLocation = Point(x, y);
		}
		
	}
	if (moving)
	{
		//Set new window location
		SetLocation(Point(X+x-clickLocation.X, Y+y-clickLocation.Y));
		
		//Save current mouse location
		clickLocation = Point(x, y);
	}

	//Foreward
	panel->OnMouseMove(button, x, y);
	title->OnMouseMove(button, x, y);
}

void Window::OnResize(int width, int height)
{
	//Foreward
	panel->OnResize(width, height);
	title->OnResize(width, height);
}

//Title
void Window::setTitle(std::string text)
{
	title->setText(text);

}

std::string Window::getTitle()
{
	return title->getText();
}

//Looks
void Window::SetBackground(Color color)
{
	panel->SetBackground(color);
}

Color Window::GetBackground()
{
	return panel->GetBackground();
}

void Window::SetBorderColor(Color color)
{
	this->border = color;
}
Color Window::GetBorderColor()
{
	return border;
}



//Add elements
void Window::Add(UIControl* element)
{
	panel->Add(element);
}

//Custom SetZeroPointForControls
void Window::SetZeroPointForControls()
{
	//Main panel
	panel->SetZeroPoint(Point(X, Y + titleBarHeight));
	panel->SetZeroPointForControls();

	//Window title
	title->SetZeroPoint(Point(X + 10, Y + titleBarHeight/2-5));
	title->SetZeroPointForControls();
}

//Size override
void Window::SetSize(Size size)
{
	UIControl::SetSize(size);

	//Set panel size
	Size panelSize;
	panelSize.Height = Height - titleBarHeight;
	panelSize.Width = Width;
	panel->SetSize(panelSize);
}