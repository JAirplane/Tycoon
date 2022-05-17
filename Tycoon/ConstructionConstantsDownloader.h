#pragma once
#include <codecvt>
#include "ConstructionConstantsXMLDownload.h"
class ConstructionConstantsDownloader
{
protected:
	static ConstructionConstantsDownloader* constructionConstantsDownload;
public:
	ConstructionConstantsDownloader() {}
	virtual ~ConstructionConstantsDownloader()
	{
		delete constructionConstantsDownload;
	}
	static ConstructionConstantsDownloader* CreateConstructionConstantsDownloader();
	static ConstructionConstantsDownloader* GetDownloader();
	virtual ConstructionConstantsXMLDownload* DownloadConstants(string constructionType);
	/*	suitable types:
			road
			toilet
			iceCreamShop
			foodCourt
			carousel
			dumboRide
			ferrisWheel
			rollerCoaster
			bumperCars
			logRide
			exit
	*/
};