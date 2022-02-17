#pragma once
#include <fstream>
#include <exception>
#include <string>
using namespace std;
class MyException : public exception
{
private:
	string errorMessage;
public:
	MyException(string error) : exception()
	{
		errorMessage = error;
	}
	~MyException()
	{}
	string GetError() const;
	void AddToLogFile();
};
