#pragma once
#include "ControlBase.h"
#include "Label.h"
#include "Header.h"
#include "RadioButtonGroup.h"
class RadioButton :
	public UIControl
{
protected:
	//Label
	Label buttonText;

	//Mouse event bools
	bool hit;
	bool fillButton;

	//Looks
	Color button;
	
	//Group
	RadioButtonGroup *parent;
	bool inGroup;

public:
	//Constructor
	RadioButton();
	RadioButton(RadioButtonGroup* group);

	//Desctructor
	~RadioButton();
	
	//ControlBase Override
	virtual void OnLoaded();
	virtual void OnPaint(void);
	virtual void OnMouseDown(int button, int x, int y);
	virtual void OnMouseUp(int button, int x, int y);
	virtual void OnMouseMove(int button, int x, int y);

	//Custom SetZeroPointForControls
	virtual void SetZeroPointForControls();

	//Label
	virtual void setText(std::string text);
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

