#pragma once
#include "ElementIndexSearcher.h"
class FindByPoint
{
protected:
	static FindByPoint* elementSearcherByPoint;
public:
	FindByPoint() {}
	~FindByPoint()
	{
		delete elementSearcherByPoint;
	}
	static FindByPoint* CreateElementSearcherByPoint();
	static FindByPoint* GetElementSearcherByPoint();
	template <class T>
	static T* GetElementByPoint(const list<T*> container, PointCoord location);
	template <class T>
	static T* GetElementByPoint(const vector<T*> container, PointCoord location);
	template <class T>
	static vector<T*> GetAllElementsByPoint(const list<T*> container, PointCoord location);
	template <class T>
	static vector<T*> GetAllElementsByPoint(const vector<T*> container, PointCoord location);
};
template <class T>
T* FindByPoint::GetElementByPoint(const list<T*> container, PointCoord location)
{
	for (auto element : container)
	{
		for (int yCoord = element->GetUpperLeft().Get_y(); yCoord <= element->GetUpperLeft().Get_y() + element->GetHeightAddition(); yCoord++)
		{
			for (int xCoord = element->GetUpperLeft().Get_x(); xCoord <= element->GetUpperLeft().Get_x() + element->GetWidthAddition(); xCoord++)
			{
				if (PointCoord(xCoord, yCoord) == location)
				{
					return element;
				}
			}
		}
	}
	return nullptr;
}
template <class T>
T* FindByPoint::GetElementByPoint(const vector<T*> container, PointCoord location)
{
	for (auto element : container)
	{
		for (int yCoord = element->GetUpperLeft().Get_y(); yCoord <= element->GetUpperLeft().Get_y() + element->GetHeightAddition(); yCoord++)
		{
			for (int xCoord = element->GetUpperLeft().Get_x(); xCoord <= element->GetUpperLeft().Get_x() + element->GetWidthAddition(); xCoord++)
			{
				if (PointCoord(xCoord, yCoord) == location)
				{
					return element;
				}
			}
		}
	}
	return nullptr;
}
template <class T>
vector<T*> FindByPoint::GetAllElementsByPoint(const list<T*> container, PointCoord location)
{
	vector<T*> suitableElements;
	for (auto element : container)
	{
		for (int yCoord = element->GetUpperLeft().Get_y(); yCoord <= element->GetUpperLeft().Get_y() + element->GetHeightAddition(); yCoord++)
		{
			for (int xCoord = element->GetUpperLeft().Get_x(); xCoord <= element->GetUpperLeft().Get_x() + element->GetWidthAddition(); xCoord++)
			{
				if (PointCoord(xCoord, yCoord) == location)
				{
					suitableElements.push_back(element);
				}
			}
		}
	}
	return suitableElements;
}
template <class T>
vector<T*> FindByPoint::GetAllElementsByPoint(const vector<T*> container, PointCoord location)
{
	vector<T*> suitableElements;
	for (auto element : container)
	{
		for (int yCoord = element->GetUpperLeft().Get_y(); yCoord <= element->GetUpperLeft().Get_y() + element->GetHeightAddition(); yCoord++)
		{
			for (int xCoord = element->GetUpperLeft().Get_x(); xCoord <= element->GetUpperLeft().Get_x() + element->GetWidthAddition(); xCoord++)
			{
				if (PointCoord(xCoord, yCoord) == location)
				{
					suitableElements.push_back(element);
				}
			}
		}
	}
	return suitableElements;
}