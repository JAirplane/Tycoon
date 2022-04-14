#include "ParkLevelConstants.h"
int Level::GetLvlNumber() const
{
	return lvlNumber;
}
int Level::GetMaxBuildings() const
{
	return maxBuildings;
}
int Level::GetMaxVisitors() const
{
	return maxVisitors;
}
int Level::GetVisitorMoneyFormulaValue() const
{
	return visitorMoneyFormulaValue;
}
//Park Level Constants
ParkLevelConstants* ParkLevelConstants::UploadParkConstants()
{
	try
	{
		return new ParkLevelConstants();
	}
	catch (MyException& somethingOccured)
	{
		somethingOccured.AddToLogFile();
	}
}
const ParkLevelConstants* ParkLevelConstants::GetConstantsPointer()
{
	return parkConstants;
}
const vector<Level*> ParkLevelConstants::GetAllConstants() const
{
	return lvls;
}
ParkLevelConstants* ParkLevelConstants::parkConstants = ParkLevelConstants::UploadParkConstants();
