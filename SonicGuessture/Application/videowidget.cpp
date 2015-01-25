#include "videowidget.h"

//#include <QPalette>

VideoWidget::VideoWidget(QWidget *parent)
    : QLabel(parent)
{
    setAlignment(Qt::AlignCenter);
    /*
    setAutoFillBackground(true);
    QPalette palette;
    palette.setColor(QPalette::Background, Qt::black);
    setPalette(palette);
    */
}


void VideoWidget::setImage(const QImage& input){
    //Bild skalieren und ausgeben
    QPixmap pixmap = QPixmap::fromImage(input);
    pixmap = pixmap.scaled(this->size(), Qt::KeepAspectRatio);
    setPixmap(pixmap);
}
