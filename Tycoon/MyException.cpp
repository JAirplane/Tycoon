#include "MyException.h"

string MyException::GetError() const
{
	return errorMessage;
}
void MyException::AddToLogFile()
{
	if(!errorMessage.empty())
	{
		ofstream logFile;
		logFile.open("Logs.txt", ofstream::out | ofstream::app);
		if (!logFile.is_open())
		{
			cout << "Failed to open file";
		}
		logFile << errorMessage << endl;
		errorMessage.clear();
	}
}