#pragma once
#include "UIControl.h"
#include "StdAfx.h"
#include "Graphix.h"
#include "glut.h"
#include "Label.h"
#include "Header.h"
#include <string>
#include <stdlib.h>

class Button :
	public UIControl
{
protected:
	//Label
	Label buttonText;

	//Looks
	Color background;
	Color border;
	Color text;

	Color background_normal;
	Color border_normal;
	Color text_normal;

	Color background_hover;
	Color border_hover;
	Color text_hover;

	Color background_click;
	Color border_click;
	Color text_click;

	//Mouse event bools
	bool hit;
	bool pressed;

	//Helper functions
	virtual void Draw();

public:
	//Constructor
	Button();

	//Destructor
	~Button();

	//ControlBase Override
	virtual void OnPaint();
	virtual void OnLoaded();
	virtual void OnMouseMove(int button, int x, int y);
	virtual void OnMouseDown(int button, int x, int y);
	virtual void OnMouseUp(int button, int x, int y);

	//Custom SetZeroPointForControls
	virtual void SetZeroPointForControls();

	//Label
	virtual void SetButtonText(std::string text);
	virtual std::string GetButtonText();
	 
	//Looks
	virtual void SetColorNormal(Color background, Color border, Color text);
	virtual void SetColorHover(Color background, Color border, Color text);
	virtual void SetColorClick(Color background, Color border, Color text);
	
};

