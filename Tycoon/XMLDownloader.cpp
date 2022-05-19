#include "XMLDownloader.h"
XMLDownloader* XMLDownloader::CreateConstructionConstantsDownloader()
{
	return new XMLDownloader();
}
XMLDownloader* XMLDownloader::GetDownloader()
{
	return constructionConstantsDownload;
}
pugi::xml_document XMLDownloader::CreateDocument(string docName)
{
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(docName.c_str());
	if (!result)
	{
		string msg = "XML [ConstructionConstants.xml] parsed with errors. ";
		msg.append("Error description: ");
		msg.append(result.description());
		throw MyException(msg);
	}
	else
	{
		return doc;
	}
}
ConstructionConstantsXML XMLDownloader::DownloadConstructionConstants(string constructionType)
{
	pugi::xml_document doc = CreateDocument("ConstructionConstants.xml");
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	pugi::xml_node constructionConstants = doc.child("constructionConstants");
	for (pugi::xml_node construction = constructionConstants.child("construction"); construction; construction = construction.next_sibling("construction"))
	{
		if (construction.attribute("name").as_string() == constructionType)
		{
			ConstructionConstantsXML constructionConstants = ConstructionConstantsXML(atoi(construction.child_value("heightAdd")),
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
	throw MyException("XMLDownloader::DownloadConstructionConstants(string constructionType) failed to find constants in XML");
}
RectangleConstantsXML XMLDownloader::DownloadRectangleConstants(string rectangleName)
{
	pugi::xml_document doc = CreateDocument("RectangleConstants.xml");
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	pugi::xml_node rectangleConstants = doc.child("rectangleConstants");
	for (pugi::xml_node rectangle = rectangleConstants.child("rectangle"); rectangle; rectangle = rectangle.next_sibling("rectangle"))
	{
		if (rectangle.attribute("name").as_string() == rectangleName)
		{
			RectangleConstantsXML rectangleConstants = RectangleConstantsXML(atoi(rectangle.child_value("heightAdd")), atoi(rectangle.child_value("widthAdd")),
				StringToColor::GetStringToColorConverter()->Convert(rectangle.child_value("borderForegroundColor")),
				StringToColor::GetStringToColorConverter()->Convert(rectangle.child_value("borderBackgroundColor")),
				StringToColor::GetStringToColorConverter()->Convert(rectangle.child_value("letterColor")),
				StringToColor::GetStringToColorConverter()->Convert(rectangle.child_value("shadingColor")), converter.from_bytes(rectangle.child_value("verticalBorderSymbol")),
				converter.from_bytes(rectangle.child_value("horizontalBorderSymbol")), converter.from_bytes(rectangle.child_value("upperLeftBorderSymbol")),
				converter.from_bytes(rectangle.child_value("upperRightBorderSymbol")), converter.from_bytes(rectangle.child_value("bottomLeftBorderSymbol")),
				converter.from_bytes(rectangle.child_value("bottomRightBorderSymbol")));
			return rectangleConstants;
		}
	}
	throw MyException("XMLDownloader::DownloadRectangleConstants(string rectangleName) failed to find constants in XML");
}
XMLDownloader* XMLDownloader::constructionConstantsDownload = XMLDownloader::CreateConstructionConstantsDownloader();