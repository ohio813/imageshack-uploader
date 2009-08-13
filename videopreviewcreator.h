#ifndef VIDEOPREVIEWCREATOR_H
#define VIDEOPREVIEWCREATOR_H

#include <QPair>
#include <QImage>
#include <QObject>
#include <QByteArray>
extern "C"
{
#include "ffmpeg_fas.h"
}

class VideoPreviewCreator : public QObject
{
public:
    VideoPreviewCreator();
    QByteArray getImageData(fas_raw_image_type *);
    QImage getPreview(QString);
    QVector<int> getHistogram(QImage);
    QVector<int> getMedian(QVector<QPair<QVector<int>, int> >);
    QPair<QVector<int>, int> getClosest(QVector<QPair<QVector<int>, int> > hists, QVector<int> median);
};

#endif // VIDEOPREVIEWCREATOR_H
