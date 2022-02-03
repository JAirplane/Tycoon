#include "ControlsScreen_InfoPanel.h"
void ControlsScreen::FillControlsDescriptions()
{
	controlsDescription.push_back(ConstructionOptions::GetAllOptions()->GetArrowsDescription());
	controlsDescription.push_back(ConstructionOptions::GetAllOptions()->GetTabDescription());
	controlsDescription.push_back(ConstructionOptions::GetAllOptions()->GetEnterDescription());
	controlsDescription.push_back(ConstructionOptions::GetAllOptions()->GetEscDescription());
	controlsDescription.push_back(ConstructionOptions::GetAllOptions()->GetHKeyDescription());
	controlsDescription.push_back(ConstructionOptions::GetAllOptions()->GetSKeyDescription());
	controlsDescription.push_back(ConstructionOptions::GetAllOptions()->GetRKeyDescription());
}
void ControlsScreen::DisplayControls()
{
	set_color(GetTextColor(), GetShadingColor());
	vector<string>::iterator controlsIter;
	int y = GetUpperLeft().Get_y() + 1;
	for (controlsIter = controlsDescription.begin(); controlsIter != controlsDescription.end(); controlsIter++)
	{
		if (y < GetUpperLeft().Get_y() + GetHeightAddition())
		{
			set_cursor_pos(GetUpperLeft().Get_x() + 1, y);
			cout << *(controlsIter);
			++y;
		}
		else
		{
			break;
		}
	}
	y = GetUpperLeft().Get_y() + 1;
	for (controlsIter; controlsIter != controlsDescription.end(); controlsIter++)
	{
		if (y < GetUpperLeft().Get_y() + GetHeightAddition())
		{
			set_cursor_pos(GetUpperLeft().Get_x() + (GetWidthAddition() + 1) / 2 + 1, y);
			cout << *(controlsIter);
			++y;
		}
		else
		{
			break;
		}
	}
}