#include "ElementIndexSearcher.h"
ElementIndexSearcher* ElementIndexSearcher::CreateIndexSearcher()
{
	return new ElementIndexSearcher();
}
ElementIndexSearcher* ElementIndexSearcher::GetElementIndexSearcher()
{
	return indexSearcher;
}
ElementIndexSearcher* ElementIndexSearcher::indexSearcher = ElementIndexSearcher::CreateIndexSearcher();