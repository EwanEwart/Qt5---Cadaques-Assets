// #include "mainwindow.h" // EE--
#include "customwidget.h"         // EE++ 1.
#include "customdesktopwidget.h"  // EE++ 2.
#include "customdrawingshapewidget.h" // EE++ 3.

#include <QApplication>
#include <QTimer>

int main( int argc, char* argv[] )
{
   int run_widget_no = 3;

   // Custom Widget
   if ( run_widget_no == 1 )
   {
      // pos square by click / move the mouse pointer

      // widget 1
      QApplication a( argc, argv );

      // MainWindow w;
      QScopedPointer<QWidget> w( new CustomWidget( ) );

      // w.resize(400,300);
      w->resize( 400, 300 );

      // w.show( );
      w->show( );

      QTimer::singleShot( 30000, &a, &QApplication::quit );

      return a.exec( );
   }

   // Desktop Custom Widget
   else if ( run_widget_no == 2 )
   {
      // edit a list of cities

      // widget 2
      QApplication a( argc, argv );
      QScopedPointer<QWidget> w( new CustomDesktopWidget( ) );
      w->resize( 400, 300 );
      w->show( );

      QTimer::singleShot( 30000, &a, &QApplication::quit );

      return a.exec( );
   }

   //
   else if( run_widget_no == 3 ) {

      // Drawing Shapes

      // widget 3
      QApplication a( argc, argv );
      QScopedPointer<QWidget> w( new CustomDrawingShapeWidget( ) );
      w->resize( 400, 300 );
      w->show( );

      QTimer::singleShot( 30000, &a, &QApplication::quit );

      return a.exec( );
   }
}
