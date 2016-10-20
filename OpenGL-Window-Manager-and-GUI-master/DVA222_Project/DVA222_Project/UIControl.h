#pragma once
#include "ControlBase.h"
#include "Graphix.h"
class UIControl :
	public ControlBase
{
protected:
	//Relative location start point
	Point zeroPoint;

	//Order of display
	int z;

public:
	//Contructor
	UIControl();
	
	//Destructor
	~UIControl();

	//Location
	virtual Point GetLocation();
	virtual void SetLocation(Point location);

	//Size
	virtual Size GetSize();
	virtual void SetSize(Size size);

	//Relative location start point
	virtual void SetZeroPoint(Point zeroPoint);
	virtual void SetZeroPointForControls();

	//Z
	virtual void SetZ(int z);
	virtual int GetZ() const;

};

