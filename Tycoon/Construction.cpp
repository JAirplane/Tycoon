#include "Construction.h"
///////////////Construction Class: GlobalObject derived///////////////
void Construction::GraphStatusAttach(GraphStatusObserverInterface* observer) {}
void Construction::GraphStatusDetach(GraphStatusObserverInterface* observer) {}
void Construction::GraphStatusNotify(vector<pair<pair<int, int>, Direction> > edges) {}
void Construction::GraphStatusNotify(int constructionIndex) {}
//
const ConstructionDescriptor* Construction::GetDescriptor() const //no setter here
{
	return describe_ptr;
}
bool Construction::GetRoadConnectionStatus() const
{
	return connectedToRoad;
}
void Construction::SetRoadConnectionStatus(bool connected)
{
	connectedToRoad = connected;
}
bool Construction::GetChosenStatus() const
{
	return isChosen;
}
void Construction::SetChosenStatus(bool chosen)
{
	isChosen = chosen;
}
wstring Construction::GetEntranceSymbol() const
{
	return wstring(L"");
}
color Construction::GetBackgroundColor() const
{
	color background = cBLACK;
	if (GetChosenStatus()) // GetChosenStatus() has an exception
	{
		background = GetDescriptor()->GetChosenBackgroundColor();
	}
	else
	{
		if (!GetRoadConnectionStatus())
		{
			background = GetDescriptor()->GetBackgroundColor();
		}
		else
		{
			background = GetDescriptor()->GetConnectedBackgroundColor();
		}
	}
	return background;
}
PointCoord Construction::GetPotentialConnectedRoadPoint() const
{
	return PointCoord(0, 0);
}
void Construction::CopyRotationProperties(Construction* another_ptr)
{
	this->SetWidthAddition(another_ptr->GetWidthAddition());
	this->SetHeightAddition(another_ptr->GetHeightAddition());
}
void Construction::CorrectConstructionCoordsForDraw(int cameraLeftX, int cameraTopY, int cameraRightX, int cameraBottomY, int& leftX, int& topY, int& rightX, int& bottomY) const
{
	//do nothing
}
void Construction::DrawObject(const wstring drawingSymbol) const
{
	GetPainter()->DrawConstruction(GetUpperLeft().Get_x(), GetUpperLeft().Get_y(), GetUpperLeft().Get_x() + GetWidthAddition(), GetUpperLeft().Get_y() + GetHeightAddition(),
		drawingSymbol, GetDescriptor()->GetForegroundColor(), GetBackgroundColor());
}
int Construction::GetVisitorsCount() const
{
	return visitorsCount;
}
void Construction::SetVisitorsCount(int visitorsCount)
{
	this->visitorsCount = visitorsCount;
}
bool Construction::IsBreakable() const
{
	return true;
}