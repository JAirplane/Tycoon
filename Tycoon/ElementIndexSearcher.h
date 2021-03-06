#pragma once
#include <list>
#include "Dijkstra.h"
class ElementIndexSearcher
{
protected:
	static ElementIndexSearcher* indexSearcher;
public:

	ElementIndexSearcher() {}
	~ElementIndexSearcher()
	{
		delete indexSearcher;
	}
	static ElementIndexSearcher* CreateIndexSearcher();
	static ElementIndexSearcher* GetElementIndexSearcher();
	template <class T>
	int GetElementIndex(const list<T*> container, const T* element);
};
template <class T>
int ElementIndexSearcher::GetElementIndex(const list<T*> container, const T* element)
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