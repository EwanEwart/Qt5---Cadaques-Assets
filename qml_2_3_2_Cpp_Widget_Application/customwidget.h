#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <QWidget>
// #include <QtWidget>

class CustomWidget : public QWidget
{
   Q_OBJECT
 public:
   explicit CustomWidget( QWidget* parent = nullptr );
   void paintEvent(QPaintEvent * event);
   void mousePressEvent(QMouseEvent* event);
   void mouseMoveEvent(QMouseEvent* event);

 private:
   QPoint m_lastPos;

 // signals:
};

#endif  // CUSTOMWIDGET_H
