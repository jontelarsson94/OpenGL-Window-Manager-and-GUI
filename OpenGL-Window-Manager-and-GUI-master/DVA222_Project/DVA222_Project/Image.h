#include "StdAfx.h"
#include "Graphix.h"
#include "glut.h"
#include "UIControl.h"

using namespace std;

class Image : public UIControl
{
protected:
	//Bitmap
	Bitmap *bitmap;
	std::string path;
	//Mouse event bools
	bool hit;
	bool pressed;

public:
    //Constructor
	Image(std::string path);

	//Destructor
	~Image();

    //ControlBase Override
	virtual void OnPaint();
	virtual void OnLoaded();
};