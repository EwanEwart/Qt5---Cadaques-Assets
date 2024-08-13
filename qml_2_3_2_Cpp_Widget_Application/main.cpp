// #include "mainwindow.h" // EE--
#include "customwidget.h" // EE++

#include <QApplication>
#include <QTimer>

int main( int argc, char* argv[] )
{
   QApplication a( argc, argv );

   // MainWindow w;
   QScopedPointer<QWidget> w(new CustomWidget());

   // w.resize(400,300);
   w->resize(400,300);

   // w.show( );
   w->show( );



   QTimer::singleShot(30000, &a, &QApplication::quit);

   return a.exec( );
}
