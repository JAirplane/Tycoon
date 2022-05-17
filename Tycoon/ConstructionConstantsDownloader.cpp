#include "ConstructionConstantsDownloader.h"
ConstructionConstantsDownloader* ConstructionConstantsDownloader::CreateConstructionConstantsDownloader()
{
	return new ConstructionConstantsDownloader();
}
ConstructionConstantsDownloader* ConstructionConstantsDownloader::GetDownloader()
{
	return constructionConstantsDownload;
}
ConstructionConstantsXMLDownload* ConstructionConstantsDownloader::DownloadConstants(string constructionType)
{
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("ConstructionConstants.xml");
	if (!result)
	{
		string msg = "XML [ParkLevelConstants.xml] parsed with errors. ";
		msg.append("Error description: ");
		msg.append(result.description());
		throw MyException(msg);
	}
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	pugi::xml_node constructionConstants = doc.child("constructionConstants");
	for (pugi::xml_node construction = constructionConstants.child("construction"); construction; construction = construction.next_sibling("construction"))
	{
		if (construction.attribute("name").as_string() == constructionType)
		{
			ConstructionConstantsXMLDownload* constructionConstants = new ConstructionConstantsXMLDownload(atoi(construction.child_value("heightAdd")),
				atoi(construction.child_value("widthAdd")), atoi(construction.child_value("cost")), atoi(construction.child_value("dailyExpences")),
				construction.child_value("description"), converter.from_bytes(construction.child_value("drawingSymbol")),
				converter.from_bytes(construction.child_value("iconSymbol")), atoi(construction.child_value("hasToilet")), atoi(construction.child_value("satisfiesHunger")),
				atoi(construction.child_value("visitPrice")), atoi(construction.child_value("entertainmentValue")), atoi(construction.child_value("isExit")),
				atoi(construction.child_value("maxVisitors")), atoi(construction.child_value("visitTime")),
				StringToColor::GetStringToColorConverter()->Convert(construction.child_value("foregroundColor")),
				StringToColor::GetStringToColorConverter()->Convert(construction.child_value("backgroundColorConnected")),
				StringToColor::GetStringToColorConverter()->Convert(construction.child_value("backgroundColorDisconnected")),
				StringToColor::GetStringToColorConverter()->Convert(construction.child_value("backgroundColorChosen")));
			return constructionConstants;
		}
	}
	throw MyException("ConstructionConstantsDownloader::DownloadConstants(string constructionType) failed to find constants in XML");
}
ConstructionConstantsDownloader* ConstructionConstantsDownloader::constructionConstantsDownload = ConstructionConstantsDownloader::CreateConstructionConstantsDownloader();