#include "IngameObjectDescriptor.h"
int IngameObjectDescriptor::GetHeightAdd() const
{
	return heightAddition;
}
int IngameObjectDescriptor::GetWidthAdd() const
{
	return widthAddition;
}
color IngameObjectDescriptor::GetForegroundColor() const
{
	return foreground;
}
color IngameObjectDescriptor::GetBackgroundColor() const
{
	return background;
}