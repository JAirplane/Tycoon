#pragma once
#include <fstream>
#include <iostream>
#include <exception>
#include <string>
#include "msoftcon.h"
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
	virtual ~MyException()
	{}
	string GetError() const;
	void AddToLogFile();
};
