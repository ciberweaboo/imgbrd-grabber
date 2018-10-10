#ifndef IMAGE_SIZE_H
#define IMAGE_SIZE_H

#include <QPixmap>
#include <QSize>
#include <QString>
#include <QUrl>


struct ImageSize
{
	~ImageSize();

	QSize size;
	int fileSize = 0;
	QRect rect;

	// Filesystem cache
	QString savePath() const;
	bool setTemporaryPath(const QString &path);
	bool setSavePath(const QString &path);

	// Pixmap cache
	QPixmap pixmap() const;
	const QPixmap &pixmap();
	void setPixmap(const QPixmap &pixmap);

	private:
		QString m_temporaryPath;
		QString m_savePath;
		QPixmap m_pixmap;
};

#endif // IMAGE_SIZE_H