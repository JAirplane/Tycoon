#include "MyException.h"

string MyException::GetError() const
{
	return errorMessage;
}
void MyException::AddToLogFile()
{
	cout << errorMessage;
	if(!errorMessage.empty())
	{
		ofstream logFile("Logs.txt", ofstream::out, ios_base::out | ios_base::app );
		if (!logFile.is_open())
		{
			cout << "Failed to open file";
		}
		logFile << errorMessage << endl;
		errorMessage.clear();
	}
}