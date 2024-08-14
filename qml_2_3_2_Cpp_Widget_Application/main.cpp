// #include "mainwindow.h" // EE--
#include "customwidget.h" // EE++
#include "customdesktopwidget.h" // EE++

#include <QApplication>
#include <QTimer>

int main( int argc, char* argv[] )
{
    int run_widget_no = 2;

    if ( run_widget_no == 1 ) {

        // widget 1
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
    else if (run_widget_no == 2) {
        // widget 2
        QApplication a(argc,argv);
        QScopedPointer<QWidget> w2(new CustomDesktopWidget());
        w2->resize(400,300);
        w2->show();

        QTimer::singleShot(30000, &a, &QApplication::quit);

        return a.exec( );
    }

}
