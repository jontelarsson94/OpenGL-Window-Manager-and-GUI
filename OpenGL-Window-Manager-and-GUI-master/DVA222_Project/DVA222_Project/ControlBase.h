#pragma once
#include <string>
#include <stdlib.h>

#include "glut.h"

using namespace std;

//===================================
//
//  C A N ' T   T O U C H   T H I S
//
//===================================


//This is the Base class for all the controls that you develop. This is the Mother of all Controls

class ControlBase
{
public:
	ControlBase();
    ControlBase(int x, int y, int w, int h);
	~ControlBase(void);

    //Event Handlers
	virtual void OnLoaded();
	virtual void OnPaint(void);		
	virtual void OnKeyboard(unsigned char key, int x, int y);	
	virtual void OnMouseDown(int button, int x, int y);
	virtual void OnMouseUp(int button, int x, int y);
	virtual void OnMouseMove(int button, int x, int y);
	virtual void OnResize(int width, int height);
protected:
    int X,Y;
	int Width;
	int Height;
	friend void resize(int w, int h);
};