#pragma once
#include <map>
#include "XMLDownloader.h"
class DTOCollector
{
private:
	map<string, RectangleConstantsXML*> figureDTOCollection;
protected:
	static DTOCollector* dataCollector;
public:
	DTOCollector()
	{
		dataCollector = nullptr;
	}
	virtual ~DTOCollector()
	{
		figureDTOCollection.clear();
		delete dataCollector;
	}
	static DTOCollector* CreateCollector();
	static DTOCollector* GetCollector();
	virtual void DownloadAllData();
	RectangleConstantsXML* GetFigureConstants(string figureName) const;
	/*	suitable names:
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
			//
			infoPanelMenuScreenControlsButton
			infoPanelMenuScreenMessagesAndInfoButton
			constructionInfoScreenDeconstructButton
			newGameButton
			continueButton
			exitButton
	*/
};