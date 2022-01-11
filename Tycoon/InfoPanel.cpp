#include "InfoPanel.h"
void InfoPanel::DrawInfoPanelBorders()
{
	draw_ptr->DrawRectangle(GetUpperLeft().Get_x(), GetUpperLeft().Get_y(), GetUpperLeft().Get_x() + GetWidthAddition(), GetUpperLeft().Get_y() + GetHeightAddition(),
		infoPanelBorderSymbols_ptr->GetVerticalSymbol(), infoPanelBorderSymbols_ptr->GetHorizontalSymbol(), infoPanelBorderSymbols_ptr->GetUpperLeftSymbol(),
		infoPanelBorderSymbols_ptr->GetUpperRightSymbol(), infoPanelBorderSymbols_ptr->GetBottomLeftSymbol(), infoPanelBorderSymbols_ptr->GetBottomRightSymbol(),
		ConstructionOptions::GetAllOptions()->GetInfoPanelColor());
}
void InfoPanel::DrawInfoPanelSplashScreen(color foreground, color background)
{
	draw_ptr->DrawInfoPanelInitial(GetUpperLeft().Get_x(), GetUpperLeft().Get_y(), foreground, background);
}