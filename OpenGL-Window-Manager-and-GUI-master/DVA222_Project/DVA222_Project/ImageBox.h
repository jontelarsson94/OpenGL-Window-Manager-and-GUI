#pragma once
#include "ControlBase.h"
#include "Label.h"
#include "StdAfx.h"
#include "glut.h"
#include "Header.h"
#include "Graphix.h"


class ImageBox :
	public UIControl
{
private:


public:
	Bitmap *normal;
	Bitmap *hover;
	Bitmap *press;

	bool hit;
	bool pressed;

	ImageBox();
	ImageBox(int locX, int locY, int width, int height);
	~ImageBox();

	//The class is overriding the following Event Handlres inherited from the base class 
	virtual void OnMouseMove(int button, int x, int y);
	virtual void OnPaint();
	virtual void OnLoaded();
	void OnMouseDown(int button, int x, int y);
	void OnMouseUp(int button, int x, int y);
};

