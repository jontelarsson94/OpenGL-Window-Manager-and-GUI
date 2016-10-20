#pragma once
#include "ControlBase.h"
#include "Label.h"
#include "Header.h"

class CheckBox :
	public UIControl
{
protected:
	//Label
	Label buttonText;
	
	//Looks
	Color buttonColor;
	
	//Mouse event bools
	bool checked;
	bool hit;

public:
	//Constructor
	CheckBox();

	//Destructor
	~CheckBox();

	//ControlBase Override
	virtual void OnPaint(void);
	virtual void OnMouseDown(int button, int x, int y);
	virtual void OnMouseUp(int button, int x, int y);
	virtual void OnMouseMove(int button, int x, int y);

	//Custom SetZeroPointForControls
	void SetZeroPointForControls();

	//Label
	virtual void setText(std::string);
	virtual void setTextColor(Color color);
	virtual std::string getText();
	virtual Color getTextColor();

	//Looks
	virtual void setColor(Color color);
	virtual Color getColor();

	//Status
	virtual void setStatus(bool checked);
	virtual bool getStatus();
};

