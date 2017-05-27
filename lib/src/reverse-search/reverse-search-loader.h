#ifndef REVERSE_SEARCH_LOADER_H
#define REVERSE_SEARCH_LOADER_H

#include <QSettings>
#include <QList>


class ReverseSearchEngine;

class ReverseSearchLoader
{
	public:
		ReverseSearchLoader(QSettings *settings);
		QMap<int, ReverseSearchEngine> getAllReverseSearchEngines() const;

	private:
		QSettings *m_settings;
};

#endif // REVERSE_SEARCH_LOADER_H
