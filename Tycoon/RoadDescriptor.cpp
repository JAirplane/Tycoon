#include "RoadDescriptor.h"
wstring RoadDescriptor::GetConstructionSymbol(int mask)
{
	switch (mask)
	{
	case none: {return wstring(L"\u2551"); }
	case leftside: {return wstring(L"\u2550"); }
	case topside: {return wstring(L"\u2551"); }
	case rightside: {return wstring(L"\u2550"); }
	case bottomside: {return wstring(L"\u2551"); }
	case vertical: {return wstring(L"\u2551"); }
	case horizontal: {return wstring(L"\u2550"); }
	case lefttop_angle: {return wstring(L"\u255D"); }
	case righttop_angle: {return wstring(L"\u255A"); }
	case leftbottom_angle: {return wstring(L"\u2557"); }
	case rightbottom_angle: {return wstring(L"\u2554"); }
	case right_T: {return wstring(L"\u2560"); }
	case left_T: {return wstring(L"\u2563"); }
	case top_T: {return wstring(L"\u2569"); }
	case bottom_T: {return wstring(L"\u2566"); }
	case cross: {return wstring(L"\u256C"); }
	default: {throw MyException("RoadDescriptor::GetConstructionSymbol(int mask) received bad mask."); }
	}
}