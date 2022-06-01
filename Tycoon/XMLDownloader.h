#pragma once
#include <codecvt>
#include "RectangleConstantsXML.h"
class XMLDownloader
{
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
	pugi::xml_document CreateDocument(string docName); //format: docName.xml
	virtual ConstructionConstantsXML DownloadConstructionConstants(string constructionType);
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
			sideMenuElement
			menuElementIcon
			sideMenuGameStats
			sideMenu
			playingField
			infoPanel
			infoPanelMenuScreen
			infoPanelControlsScreen
			infoPanelMessagesAndInfoScreen
			infoPanelConstructionInfoScreen
			constructionInfoScreenConstructionIcon
			infoPanelMessagesScreen
			startScreen
			pressAnyKey
			mainMenuScreen
	*/
	virtual RectangleConstantsXML* DownloadButtonConstants(string buttonType);
	/*	suitable button names:
			infoPanelMenuScreenControlsButton
			infoPanelMenuScreenMessagesAndInfoButton
			constructionInfoScreenDeconstructButton
			newGameButton
			continueButton
			exitButton
	*/
	virtual RectangleConstantsXML* DownloadFigureConstants(string figureName);
};