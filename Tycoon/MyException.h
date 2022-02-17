#pragma once
#include <exception>
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
	void AddToLogFile() const;
};
