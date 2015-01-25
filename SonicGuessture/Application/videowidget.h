#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H
#include <QLabel>
#include <QImage>

class VideoWidget: public QLabel {
Q_OBJECT

public:
    VideoWidget(QWidget*);

public slots: //Eingehend
    void setImage(const QImage& input);

public:
    QString label;
};

#endif // VIDEOWIDGET_H
