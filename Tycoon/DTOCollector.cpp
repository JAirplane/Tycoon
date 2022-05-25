#include "DTOCollector.h"
DTOCollector* DTOCollector::CreateCollector()
{
	return new DTOCollector();
}
DTOCollector* DTOCollector::GetCollector()
{
	return dataCollector;
}
void DTOCollector::DownloadAllData()
{
	camera = XMLDownloader::GetDownloader()->DownloadRectangleConstants("camera");
	sideMenuElement = XMLDownloader::GetDownloader()->DownloadRectangleConstants("sideMenuElement");
	menuElementIcon = XMLDownloader::GetDownloader()->DownloadRectangleConstants("menuElementIcon");
	sideMenuGameStats = XMLDownloader::GetDownloader()->DownloadRectangleConstants("sideMenuGameStats");
	sideMenu = XMLDownloader::GetDownloader()->DownloadRectangleConstants("sideMenu");
	playingField = XMLDownloader::GetDownloader()->DownloadRectangleConstants("playingField");
	infoPanel = XMLDownloader::GetDownloader()->DownloadRectangleConstants("infoPanel");
	infoPanelMenuScreen = XMLDownloader::GetDownloader()->DownloadRectangleConstants("infoPanelMenuScreen");
	infoPanelControlsScreen = XMLDownloader::GetDownloader()->DownloadRectangleConstants("infoPanelControlsScreen");
	infoPanelMessagesAndInfoScreen = XMLDownloader::GetDownloader()->DownloadRectangleConstants("infoPanelMessagesAndInfoScreen");
	infoPanelConstructionInfoScreen = XMLDownloader::GetDownloader()->DownloadRectangleConstants("infoPanelConstructionInfoScreen");
	constructionInfoScreenConstructionIcon = XMLDownloader::GetDownloader()->DownloadRectangleConstants("constructionInfoScreenConstructionIcon");
	infoPanelMessagesScreen = XMLDownloader::GetDownloader()->DownloadRectangleConstants("infoPanelMessagesScreen");
	startScreen = XMLDownloader::GetDownloader()->DownloadRectangleConstants("startScreen");
	pressAnyKey = XMLDownloader::GetDownloader()->DownloadRectangleConstants("pressAnyKey");
	mainMenuScreen = XMLDownloader::GetDownloader()->DownloadRectangleConstants("mainMenuScreen");
	//
	infoPanelMenuScreenControlsButton = XMLDownloader::GetDownloader()->DownloadButtonConstants("infoPanelMenuScreenControlsButton");
	infoPanelMenuScreenMessagesAndInfoButton = XMLDownloader::GetDownloader()->DownloadButtonConstants("infoPanelMenuScreenMessagesAndInfoButton");
	constructionInfoScreenDeconstructButton = XMLDownloader::GetDownloader()->DownloadButtonConstants("constructionInfoScreenDeconstructButton");
	newGameButton = XMLDownloader::GetDownloader()->DownloadButtonConstants("newGameButton");
	continueButton = XMLDownloader::GetDownloader()->DownloadButtonConstants("continueButton");
	exitButton = XMLDownloader::GetDownloader()->DownloadButtonConstants("exitButton");
}
RectangleConstantsXML DTOCollector::GetCameraConstants() const
{
	return camera;
}
RectangleConstantsXML DTOCollector::GetSideMenuElementConstants() const
{
	return sideMenuElement;
}
RectangleConstantsXML DTOCollector::GetMenuElementIconConstants() const
{
	return menuElementIcon;
}
RectangleConstantsXML DTOCollector::GetSideMenuGameStatsConstants() const
{
	return sideMenuGameStats;
}
RectangleConstantsXML DTOCollector::GetSideMenuConstants() const
{
	return sideMenu;
}
RectangleConstantsXML DTOCollector::GetPlayingFieldConstants() const
{
	return playingField;
}
RectangleConstantsXML DTOCollector::GetInfoPanelConstants() const
{
	return infoPanel;
}
RectangleConstantsXML DTOCollector::GetInfoPanelMenuScreenConstants() const
{
	return infoPanelMenuScreen;
}
RectangleConstantsXML DTOCollector::GetInfoPanelControlsScreenConstants() const
{
	return infoPanelControlsScreen;
}
RectangleConstantsXML DTOCollector::GetInfoPanelMessagesAndInfoScreenConstants() const
{
	return infoPanelMessagesAndInfoScreen;
}
RectangleConstantsXML DTOCollector::GetInfoPanelConstructionInfoScreenConstants() const
{
	return infoPanelConstructionInfoScreen;
}
RectangleConstantsXML DTOCollector::GetConstructionInfoScreenConstructionIconConstants() const
{
	return constructionInfoScreenConstructionIcon;
}
RectangleConstantsXML DTOCollector::GetInfoPanelMessagesScreenConstants() const
{
	return infoPanelMessagesScreen;
}
RectangleConstantsXML DTOCollector::GetStartScreenConstants() const
{
	return startScreen;
}
RectangleConstantsXML DTOCollector::GetPressAnyKeyConstants() const
{
	return pressAnyKey;
}
RectangleConstantsXML DTOCollector::GetMainMenuScreenConstants() const
{
	return mainMenuScreen;
}
//
ButtonConstantsXML DTOCollector::GetInfoPanelMenuScreenControlsButtonConstants() const
{
	return infoPanelMenuScreenControlsButton;
}
ButtonConstantsXML DTOCollector::GetInfoPanelMenuScreenMessagesAndInfoButtonConstants() const
{
	return infoPanelMenuScreenMessagesAndInfoButton;
}
ButtonConstantsXML DTOCollector::GetConstructionInfoScreenDeconstructButtonConstants() const
{
	return constructionInfoScreenDeconstructButton;
}
ButtonConstantsXML DTOCollector::GetNewGameButtonConstants() const
{
	return newGameButton;
}
ButtonConstantsXML DTOCollector::GetContinueButtonConstants() const
{
	return continueButton;
}
ButtonConstantsXML DTOCollector::GetExitButtonConstants() const
{
	return exitButton;
}
DTOCollector* DTOCollector::dataCollector = DTOCollector::CreateCollector();