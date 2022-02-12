#include "ConstructionInfoScreen.h"
void ConstructionInfoScreen::CreateDeconstructButton()
{
	RectangleSymbols* constrictionInfoButtonBorderSymbols_ptr = new RectangleSymbols(ConstructionOptions::GetAllOptions()->GetConstructionInfoButtonVerticalSymbol(),
		ConstructionOptions::GetAllOptions()->GetConstructionInfoButtonHorizontalSymbol(), ConstructionOptions::GetAllOptions()->GetConstructionInfoButtonUpperLeftSymbol(),
		ConstructionOptions::GetAllOptions()->GetConstructionInfoButtonUpperRightSymbol(), ConstructionOptions::GetAllOptions()->GetConstructionInfoButtonBottomLeftSymbol(),
		ConstructionOptions::GetAllOptions()->GetConstructionInfoButtonBottomRightSymbol());
	color borderForegroundColor = ConstructionOptions::GetAllOptions()->GetConstructionInfoButtonBorderForegroundColor();
	color borderBackgroundColor = ConstructionOptions::GetAllOptions()->GetConstructionInfoButtonBorderBackgroundColor();
	BorderAppearance* constructionInfoButtonBorder_ptr = new BorderAppearance(constrictionInfoButtonBorderSymbols_ptr, borderForegroundColor, borderBackgroundColor);
	color buttonLetterColor = ConstructionOptions::GetAllOptions()->GetConstructionInfoButtonLetterColor();
	color buttonShadingColor = ConstructionOptions::GetAllOptions()->GetConstructionInfoButtonShadingColor();
	int buttonWidthAdd = ConstructionOptions::GetAllOptions()->GetConstructionInfoButtonWidthAdd();
	int buttonHeightAdd = ConstructionOptions::GetAllOptions()->GetConstructionInfoButtonHeightAdd();
	int rightXScreen = GetUpperLeft().Get_x() + GetWidthAddition();
	int topYButton = GetUpperLeft().Get_y() + 2;
	int leftXButton = rightXScreen - buttonWidthAdd - 2;
	deconstruct_ptr = new Button(PointCoord(leftXButton, topYButton), buttonHeightAdd, buttonWidthAdd, constructionInfoButtonBorder_ptr, buttonLetterColor, buttonShadingColor,
		ConstructionOptions::GetAllOptions()->GetDeconstructButtonTitle(), GetDrawPointer(), GetCursor());
}
void ConstructionInfoScreen::CreateConstructionIcon()
{
	RectangleSymbols* iconSymbols_ptr = new RectangleSymbols(ConstructionOptions::GetAllOptions()->GetConstructionInfoScreenIconVerticalSymbol(),
		ConstructionOptions::GetAllOptions()->GetConstructionInfoScreenIconHorizontalSymbol(), ConstructionOptions::GetAllOptions()->GetConstructionInfoScreenIconUpperLeftSymbol(),
		ConstructionOptions::GetAllOptions()->GetConstructionInfoScreenIconUpperRightSymbol(), ConstructionOptions::GetAllOptions()->GetConstructionInfoScreenIconBottomLeftSymbol(),
		ConstructionOptions::GetAllOptions()->GetConstructionInfoScreenIconBottomRightSymbol());
	color iconBorderForegroundColor = ConstructionOptions::GetAllOptions()->GetConstructionInfoButtonBorderForegroundColor();
	color iconBorderBackgroundColor = ConstructionOptions::GetAllOptions()->GetConstructionInfoButtonBorderBackgroundColor();
	BorderAppearance* iconBorder = new BorderAppearance(iconSymbols_ptr, iconBorderForegroundColor, iconBorderBackgroundColor);
	color iconLetterColor = ConstructionOptions::GetAllOptions()->GetConstructionInfoScreenIconLetterColor();
	color iconShadingColor = ConstructionOptions::GetAllOptions()->GetConstructionInfoScreenIconShadingColor();
	//
	PointCoord iconLocation = PointCoord(GetUpperLeft().Get_x() + 2, GetUpperLeft().Get_y() + 1);
	int iconHeightAdd = ConstructionOptions::GetAllOptions()->GetMenuIconHeightAdd();	//always equal to menu icon
	int iconWidthAdd = ConstructionOptions::GetAllOptions()->GetMenuIconWidthAdd();	//always equal to menu icon
	MyRectangle* menuIcon_ptr = new MyRectangle(iconLocation, iconHeightAdd, iconWidthAdd, iconBorder, iconLetterColor, iconShadingColor, GetDrawPointer(), GetCursor());
}
void ConstructionInfoScreen::DisplayConstructionInfo()
{
	if (choosen_ptr != nullptr)
	{
		constructionIcon_ptr->DrawBorder();
		GetDrawPointer()->DrawConstruction(constructionIcon_ptr->GetUpperLeft().Get_x() + 1, constructionIcon_ptr->GetUpperLeft().Get_y() + 1,
			constructionIcon_ptr->GetUpperLeft().Get_x() + constructionIcon_ptr->GetWidthAddition() - 1,
			constructionIcon_ptr->GetUpperLeft().Get_y() + constructionIcon_ptr->GetHeightAddition() - 1, choosen_ptr->GetDescriptor()->GetIconSymbol(),
			choosen_ptr->GetDescriptor()->GetForegroundColor(), choosen_ptr->GetDescriptor()->GetBackgroundColor());
		deconstruct_ptr->Display();
		set_cursor_pos(constructionIcon_ptr->GetUpperLeft().Get_x() + constructionIcon_ptr->GetWidthAddition() + 2,
			constructionIcon_ptr->GetUpperLeft().Get_y() + constructionIcon_ptr->GetHeightAddition() + 1);
		cout << "Visitors: " << choosen_ptr->GetVisitorsCount() << endl;
		int profit = choosen_ptr->GetProfit();
		if (profit != -1)
		{
			cout << "Overall profit: " << choosen_ptr->GetProfit();
		}
	}
	else
	{
		set_cursor_pos(GetUpperLeft().Get_x() + 2, GetUpperLeft().Get_y() + 1);
		cout << "Choose construction to get data";
	}
}
