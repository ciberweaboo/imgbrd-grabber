#include "reverse-search-loader.h"
#include "reverse-search-engine.h"
#include "functions.h"


ReverseSearchLoader::ReverseSearchLoader(QSettings *settings)
	: m_settings(settings)
{}

QMap<int, ReverseSearchEngine> ReverseSearchLoader::getAllReverseSearchEngines() const
{
	QMap<int, ReverseSearchEngine> ret;

	// Default groups
	if (!m_settings->childGroups().contains("WebServices"))
	{
		ret.insert(1, ReverseSearchEngine(QIcon(savePath("webservices/1.png")), "IQDB", "https://iqdb.org/?url={url}"));
		ret.insert(2, ReverseSearchEngine(QIcon(savePath("webservices/2.png")), "SauceNAO", "https://saucenao.com/search.php?db=999&url={url}"));
		ret.insert(3, ReverseSearchEngine(QIcon(savePath("webservices/3.png")), "Google", "https://www.google.com/searchbyimage?image_url={url}"));
		ret.insert(4, ReverseSearchEngine(QIcon(savePath("webservices/4.png")), "TinEye", "https://www.tineye.com/search/?url={url}"));
		ret.insert(5, ReverseSearchEngine(QIcon(savePath("webservices/5.png")), "Yandex", "https://yandex.ru/images/search?rpt=imageview&img_url={url}"));
		ret.insert(6, ReverseSearchEngine(QIcon(savePath("webservices/6.png")), "waifu2x", "http://waifu2x.udp.jp/index.html?url={url}"));
	}

	// Load groups
	m_settings->beginGroup("WebServices");
	for (QString group : m_settings->childGroups())
	{
		m_settings->beginGroup(group);
		QIcon icon(savePath("webservices/" + group + ".png"));
		ret.insert(group.toInt(), ReverseSearchEngine(icon, m_settings->value("name").toString(), m_settings->value("url").toString()));
		m_settings->endGroup();
	}
	m_settings->endGroup();

	return ret;
}
