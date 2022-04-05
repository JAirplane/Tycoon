#pragma once
#include <list>
#include "Dijkstra.h"
class ElementIndexSearcher
{
public:
	static ElementIndexSearcher* indexSearcher;
	ElementIndexSearcher() {}
	~ElementIndexSearcher()
	{
		delete indexSearcher;
	}
	template <class T>
	static int GetElementIndex(list<T*> container, T* element);
};
template <class T>
int ElementIndexSearcher::GetElementIndex(list<T*> container, T* element)
{
	int index = 0;
	for (T* everyElement : container)
	{
		if (everyElement == element)
		{
			return index;
		}
		++index;
	}
	return -1;
}