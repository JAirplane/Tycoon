#include "FindByPoint.h"
FindByPoint* FindByPoint::CreateElementSearcherByPoint()
{
	return new FindByPoint();
}
FindByPoint* FindByPoint::GetElementSearcherByPoint()
{
	return elementSearcherByPoint;
}
FindByPoint* FindByPoint::elementSearcherByPoint = CreateElementSearcherByPoint();