#pragma once
#include "GlobalObject.h"
/////////////PlayingField Class/////////////
class PlayingField : public GlobalObject
{
private:
	wchar_t verticalBorderSymbol;
	wchar_t horizontalBorderSymbol;
	wchar_t upperLeftBorderSymbol;
	wchar_t upperRightBorderSymbol;
	wchar_t bottomLeftBorderSymbol;
	wchar_t bottomRightBorderSymbol;
public:
	PlayingField(PointCoord ul, unsigned int heightadd, unsigned int widthadd, wchar_t verticalsymbol, wchar_t horizontalsymbol, wchar_t ulsymbol, wchar_t ursymbol, wchar_t blsymbol, wchar_t brsymbol) :
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
	wchar_t GetVerticalSymbol() const;
	wchar_t GetHorizontalSymbol() const;
	wchar_t GetUpperLeftSymbol() const;
	wchar_t GetUpperRightSymbol() const;
	wchar_t GetBottomLeftSymbol() const;
	wchar_t GetBottomRightSymbol() const;
};