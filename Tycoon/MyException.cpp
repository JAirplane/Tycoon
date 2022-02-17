#include "MyException.h"
string MyException::GetError() const
{
	return errorMessage;
}
void MyException::AddToLogFile()
{
	if(!errorMessage.empty())
	{
		ofstream logFile("Logs.txt", ofstream::out, ios_base::out | ios_base::app );
		logFile << errorMessage << endl;
		errorMessage.clear();
	}
}