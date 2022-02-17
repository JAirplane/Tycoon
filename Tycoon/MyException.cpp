#include "MyException.h"
string MyException::GetError() const
{
	return errorMessage;
}
void MyException::AddToLogFile() const
{
	if(!errorMessage.empty())
	{
		ofstream logFile;
		logFile.open("Logs.txt", ios_base::out | ios_base::app );
		logFile << errorMessage << endl;
		errorMessage.clear();
	}
}