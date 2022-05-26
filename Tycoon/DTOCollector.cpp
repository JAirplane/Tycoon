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
	figureDTOCollection.insert(make_pair("camera", XMLDownloader::GetDownloader()->DownloadFigureConstants("camera")));
	figureDTOCollection.insert(make_pair("sideMenuElement", XMLDownloader::GetDownloader()->DownloadFigureConstants("sideMenuElement")));
	figureDTOCollection.insert(make_pair("menuElementIcon", XMLDownloader::GetDownloader()->DownloadFigureConstants("menuElementIcon")));
	figureDTOCollection.insert(make_pair("sideMenuGameStats", XMLDownloader::GetDownloader()->DownloadFigureConstants("sideMenuGameStats")));
	figureDTOCollection.insert(make_pair("sideMenu", XMLDownloader::GetDownloader()->DownloadFigureConstants("sideMenu")));
	figureDTOCollection.insert(make_pair("playingField", XMLDownloader::GetDownloader()->DownloadFigureConstants("playingField")));
	figureDTOCollection.insert(make_pair("infoPanel", XMLDownloader::GetDownloader()->DownloadFigureConstants("infoPanel")));
	figureDTOCollection.insert(make_pair("infoPanelMenuScreen", XMLDownloader::GetDownloader()->DownloadFigureConstants("infoPanelMenuScreen")));
	figureDTOCollection.insert(make_pair("infoPanelControlsScreen", XMLDownloader::GetDownloader()->DownloadFigureConstants("infoPanelControlsScreen")));
	figureDTOCollection.insert(make_pair("infoPanelMessagesAndInfoScreen", XMLDownloader::GetDownloader()->DownloadFigureConstants("infoPanelMessagesAndInfoScreen")));
	figureDTOCollection.insert(make_pair("infoPanelConstructionInfoScreen", XMLDownloader::GetDownloader()->DownloadFigureConstants("infoPanelConstructionInfoScreen")));
	figureDTOCollection.insert(make_pair("constructionInfoScreenConstructionIcon", XMLDownloader::GetDownloader()->DownloadFigureConstants("constructionInfoScreenConstructionIcon")));
	figureDTOCollection.insert(make_pair("infoPanelMessagesScreen", XMLDownloader::GetDownloader()->DownloadFigureConstants("infoPanelMessagesScreen")));
	figureDTOCollection.insert(make_pair("startScreen", XMLDownloader::GetDownloader()->DownloadFigureConstants("startScreen")));
	figureDTOCollection.insert(make_pair("pressAnyKey", XMLDownloader::GetDownloader()->DownloadFigureConstants("pressAnyKey")));
	figureDTOCollection.insert(make_pair("mainMenuScreen", XMLDownloader::GetDownloader()->DownloadFigureConstants("mainMenuScreen")));
	//
	figureDTOCollection.insert(make_pair("infoPanelMenuScreenControlsButton", XMLDownloader::GetDownloader()->DownloadFigureConstants("infoPanelMenuScreenControlsButton")));
	figureDTOCollection.insert(make_pair("infoPanelMenuScreenMessagesAndInfoButton", XMLDownloader::GetDownloader()->DownloadFigureConstants("infoPanelMenuScreenMessagesAndInfoButton")));
	figureDTOCollection.insert(make_pair("constructionInfoScreenDeconstructButton", XMLDownloader::GetDownloader()->DownloadFigureConstants("constructionInfoScreenDeconstructButton")));
	figureDTOCollection.insert(make_pair("newGameButton", XMLDownloader::GetDownloader()->DownloadFigureConstants("newGameButton")));
	figureDTOCollection.insert(make_pair("continueButton", XMLDownloader::GetDownloader()->DownloadFigureConstants("continueButton")));
	figureDTOCollection.insert(make_pair("exitButton", XMLDownloader::GetDownloader()->DownloadFigureConstants("exitButton")));
}
RectangleConstantsXML* DTOCollector::GetFigureConstants(string figureName) const
{
	map<string, RectangleConstantsXML*>::const_iterator constantsIter;
	constantsIter = figureDTOCollection.find(figureName);
	if (constantsIter == figureDTOCollection.end())
	{
		throw MyException("DTOCollector::GetFigureConstants(string figureName) const figureName was not found in map");
	}
	else
	{
		return constantsIter->second;
	}
}
DTOCollector* DTOCollector::dataCollector = DTOCollector::CreateCollector();