#pragma once
#include "XMLDownloader.h"
class DTOCollector
{
private:
	RectangleConstantsXML camera;
	RectangleConstantsXML sideMenuElement;
	RectangleConstantsXML menuElementIcon;
	RectangleConstantsXML sideMenuGameStats;
	RectangleConstantsXML sideMenu;
	RectangleConstantsXML playingField;
	RectangleConstantsXML infoPanel;
	RectangleConstantsXML infoPanelMenuScreen;
	RectangleConstantsXML infoPanelControlsScreen;
	RectangleConstantsXML infoPanelMessagesAndInfoScreen;
	RectangleConstantsXML infoPanelConstructionInfoScreen;
	RectangleConstantsXML constructionInfoScreenConstructionIcon;
	RectangleConstantsXML infoPanelMessagesScreen;
	RectangleConstantsXML startScreen;
	RectangleConstantsXML pressAnyKey;
	RectangleConstantsXML mainMenuScreen;
	ButtonConstantsXML infoPanelMenuScreenControlsButton;
	ButtonConstantsXML infoPanelMenuScreenMessagesAndInfoButton;
	ButtonConstantsXML constructionInfoScreenDeconstructButton;
	ButtonConstantsXML newGameButton;
	ButtonConstantsXML continueButton;
	ButtonConstantsXML exitButton;
protected:
	static DTOCollector* dataCollector;
public:
	DTOCollector()
	{
		dataCollector = nullptr;
	}
	virtual ~DTOCollector()
	{
		delete dataCollector;
	}
	static DTOCollector* CreateCollector();
	static DTOCollector* GetCollector();
	virtual void DownloadAllData();
	RectangleConstantsXML GetCameraConstants() const;
	RectangleConstantsXML GetSideMenuElementConstants() const;
	RectangleConstantsXML GetMenuElementIconConstants() const;
	RectangleConstantsXML GetSideMenuGameStatsConstants() const;
	RectangleConstantsXML GetSideMenuConstants() const;
	RectangleConstantsXML GetPlayingFieldConstants() const;
	RectangleConstantsXML GetInfoPanelConstants() const;
	RectangleConstantsXML GetInfoPanelMenuScreenConstants() const;
	RectangleConstantsXML GetInfoPanelControlsScreenConstants() const;
	RectangleConstantsXML GetInfoPanelMessagesAndInfoScreenConstants() const;
	RectangleConstantsXML GetInfoPanelConstructionInfoScreenConstants() const;
	RectangleConstantsXML GetConstructionInfoScreenConstructionIconConstants() const;
	RectangleConstantsXML GetInfoPanelMessagesScreenConstants() const;
	RectangleConstantsXML GetStartScreenConstants() const;
	RectangleConstantsXML GetPressAnyKeyConstants() const;
	RectangleConstantsXML GetMainMenuScreenConstants() const;
	ButtonConstantsXML GetInfoPanelMenuScreenControlsButtonConstants() const;
	ButtonConstantsXML GetInfoPanelMenuScreenMessagesAndInfoButtonConstants() const;
	ButtonConstantsXML GetConstructionInfoScreenDeconstructButtonConstants() const;
	ButtonConstantsXML GetNewGameButtonConstants() const;
	ButtonConstantsXML GetContinueButtonConstants() const;
	ButtonConstantsXML GetExitButtonConstants() const;
};