#pragma once
#include <codecvt>
#include "RectangleConstantsXML.h"
class XMLDownloader
{
private:
	pugi::xml_document CreateDocument(string docName); //format: docName.xml
protected:
	static XMLDownloader* constructionConstantsDownload;
public:
	XMLDownloader() {}
	virtual ~XMLDownloader()
	{
		delete constructionConstantsDownload;
	}
	static XMLDownloader* CreateConstructionConstantsDownloader();
	static XMLDownloader* GetDownloader();
	virtual ConstructionConstantsXML* DownloadConstructionConstants(string constructionType);
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
	virtual RectangleConstantsXML* DownloadRectangleConstants(string constructionType);
	/*	suitable rectangle names:
			camera
			playingField
			sideMenu
			sideMenuGameStats
			sideMenuElement
			menuElementIcon
	*/
};