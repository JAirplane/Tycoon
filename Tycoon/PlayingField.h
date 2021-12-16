#pragma once
#include "GlobalObject.h"
/////////////PlayingField Class/////////////
class PlayingField : public GlobalObject
{
private:
	char verticalBorderSymbol;
	char horizontalBorderSymbol;
	char upperLeftBorderSymbol;
	char upperRightBorderSymbol;
	char bottomLeftBorderSymbol;
	char bottomRightBorderSymbol;
public:
	PlayingField(PointCoord ul, unsigned int heightadd, unsigned int widthadd, char verticalsymbol, char horizontalsymbol, char ulsymbol, char ursymbol, char blsymbol, char brsymbol) :
		GlobalObject(ul, heightadd, widthadd)
	{
		verticalBorderSymbol = verticalsymbol;
		horizontalBorderSymbol = horizontalsymbol;
		upperLeftBorderSymbol = ulsymbol;
		upperRightBorderSymbol = ursymbol;
		bottomLeftBorderSymbol = blsymbol;
		bottomRightBorderSymbol = brsymbol;
	}
	~PlayingField() {}
	char GetVerticalSymbol() const;
	char GetHorizontalSymbol() const;
	char GetUpperLeftSymbol() const;
	char GetUpperRightSymbol() const;
	char GetBottomLeftSymbol() const;
	char GetBottomRightSymbol() const;
};