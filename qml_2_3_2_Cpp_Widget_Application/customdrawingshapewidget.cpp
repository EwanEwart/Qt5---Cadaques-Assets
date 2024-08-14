#include "customdrawingshapewidget.h"

#include <QVBoxLayout>
#include <QGraphicsItem>

CustomDrawingShapeWidget::CustomDrawingShapeWidget( QWidget* parent )
: QWidget { parent }
{
   m_view  = new QGraphicsView( this );
   m_scene = new QGraphicsScene( this );
   m_view->setScene( m_scene );

   auto layout { new QVBoxLayout( this ) };
   // QVBoxLayout* layout = new QVBoxLayout(this);
   // layout->setMargin(4);
   layout->addWidget( m_view );
   setLayout( layout );

   QGraphicsItem* rect1 = m_scene->addRect( 0, 0, 40, 40, Qt::NoPen, QColor( 0xFF, 0xBB, 0x33 ) );
   rect1->setFlags( QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable );
}
