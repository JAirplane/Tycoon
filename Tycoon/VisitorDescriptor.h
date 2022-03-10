#pragma once
#include "IngameObjectDescriptor.h"
class VisitorDescriptor : public IngameObjectDescriptor
{
private:
	wstring visitorSymbol;
public:
	VisitorDescriptor(wstring visitorSymbol, color foreground, color background = cBLACK, int heightAddition = 0, int widthAddition = 0) :
		IngameObjectDescriptor(foreground, background, heightAddition, widthAddition)
	{
		this->visitorSymbol = visitorSymbol;
	}
	~VisitorDescriptor() {}
	wstring GetVisitorSymbol() const;
};
