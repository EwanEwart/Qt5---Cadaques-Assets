#ifndef CUSTOMDRAWINGSHAPEWIDGET_H
#define CUSTOMDRAWINGSHAPEWIDGET_H

#include <QWidget>

#include <QGraphicsView>
#include <QGraphicsScene>

class CustomDrawingShapeWidget : public QWidget
{
   Q_OBJECT

   QGraphicsView* m_view;
   QGraphicsScene* m_scene;

 public:
   explicit CustomDrawingShapeWidget( QWidget* parent = nullptr );

 signals:
};

#endif  // CUSTOMDRAWINGSHAPEWIDGET_H
