#include "customwidget.h"
#include <QPainter>
#include <QMouseEvent>

CustomWidget::CustomWidget( QWidget* parent )
: QWidget { parent }
{

}
void CustomWidget::paintEvent(QPaintEvent* event) {
   QPainter painter(this);

   QRect r1; // (x,y,w,h)
   r1 = rect().adjusted(10,10,-10,-10);
   // ( x + dx1, y + dy1, w + dx2, h + dy2)

   // painter.setPen(QColor("pink"));
   // painter.setPen(QColor("#33B5E5"));
   // painter.setPen(QColor(51,181,229)); // faster
   painter.setPen(QColor(0x33,0x3B,0xE5)); // faster

   painter.drawRect(r1);

   QRect r2(QPoint(0,0),QSize(40,40));

   if(m_lastPos.isNull()) {
      r2.moveCenter(r1.center());
   } else {
      r2.moveCenter(m_lastPos);
   }
   painter.fillRect(r2,QColor(0xFF,0xBB,0x33));

}
void CustomWidget::mousePressEvent(QMouseEvent* event) {
   m_lastPos = event->pos();
   update();
}
void CustomWidget::mouseMoveEvent(QMouseEvent* event) {
   m_lastPos = event->pos();
   update();
}
