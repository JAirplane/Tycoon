#pragma once
#include <exception>
using namespace std;
class InfoPanel;
class MyException : public exception
{
private:
	InfoPanel* infoPanel_ptr;
public:
	MyException(const char* msg, InfoPanel* ip_ptr) : exception(msg)
	{
		infoPanel_ptr = ip_ptr;
	}
	~MyException()
	{}
	InfoPanel* GetPanelPointer() const;
};
