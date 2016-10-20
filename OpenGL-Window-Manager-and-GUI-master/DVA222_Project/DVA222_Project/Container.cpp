#include "stdafx.h"
#include "Container.h"

//Contructor
Container::Container()
{
	
}

//Desctructor
Container::~Container()
{
}

//ControlBase Overrides
void Container::OnLoaded()
{
	int length = controls.size();
	for (size_t i = 0; i < length; i++)
	{
		controls.at(i)->OnLoaded();
	}
}

void Container::OnPaint()
{
	//Paint controls
	int length = controls.size();
	for (size_t i = 0; i < length; i++)
	{
		controls.at(i)->OnPaint();
	}
}


void Container::OnKeyboard(unsigned char key, int x, int y)
{
	int length = controls.size();
	for (size_t i = 0; i < length; i++)
	{
		controls.at(i)->OnKeyboard(key, x, y);
	}
}

void Container::OnMouseUp(int button, int x, int y)
{
	int length = controls.size();
	for (size_t i = 0; i < length; i++)
	{
		controls.at(i)->OnMouseUp(button, x, y);
	}
}

void Container::OnMouseDown(int button, int x, int y)
{
	int length = controls.size();
	for (size_t i = 0; i < length; i++)
	{
		controls.at(i)->OnMouseDown(button, x, y);
	}
}

void Container::OnMouseMove(int button, int x, int y)
{
	int length = controls.size();
	for (size_t i = 0; i < length; i++)
	{
		controls.at(i)->OnMouseMove(button, x, y);
	}
}

void Container::OnResize(int width, int height)
{
	int length = controls.size();
	for (size_t i = 0; i < length; i++)
	{
		controls.at(i)->OnResize(width, height);
	}
}

//Add element to panel
void Container::Add(UIControl* element)
{
	//Set Zero Point for new control
	element->SetZeroPoint(Point(X + zeroPoint.X, Y + zeroPoint.Y));

	//Add element
	controls.push_back(element);
}
