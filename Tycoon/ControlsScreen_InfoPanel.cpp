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