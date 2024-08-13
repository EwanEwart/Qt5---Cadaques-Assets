#include <QCoreApplication>
#include <QTimer>
#include <QtCore/QtCore>

// text stream is text-codec aware
QTextStream cout(stdout,QIODevice::WriteOnly);

void stringHandling() {
   // string handling
   QString s1 ("String");
   QString s2 ("Handling");
   QString s = s1 + " " + s2 + " !";
   cout << s << Qt::endl;
}

void listAndIterator () {

   QString s1 {"list_item_no_1"};
   QString s2 {"list_item_no_2"};
   QList<QString> list;

   // stream into container
   list << s1 << s2;

   // iterator
   QListIterator<QString> it(list);
   while(it.hasNext()) {
      cout << it.next();
      if (it.hasNext()) {
         cout << " ";
      }
   }
   cout << " !!!" << Qt::endl;
}

void listShorthand() {
   // iteration shorthand alternative
   QString s1 {"Filia"};
   QString s2 {"Kitty"};
   QList<QString> list;
   list << s1 << s2;
   QString ss = list.join(" and ") + " !!!!!!";
   cout << ss << Qt::endl;
}

// file I/O
void readCSVData(QList<QStringList>& data, QString const& filename="", QString const& seperator=";") {

   // file operations
   QFile file(filename);
   if(file.open(QIODevice::ReadOnly)){
      QTextStream textStream(&file);
      // macro
      forever {
         QString line = textStream.readLine();
         // test for null string String(): done
         if(line.isNull()) {
            break;
         }
         // test for empty string QString(""): an empty line
         if(line.isEmpty()) {
            continue;
         }
         QStringList row;
         // for-each loop to iterate over a container, cell by cell
         foreach (/* var */QString const & cell, /* container*/ line.split(seperator)) {
            row.append(cell.trimmed());
         }
         data.append(row);
      }
   }
}

// container
void printCSVData( QList<QStringList>& data ) {

   cout << Qt::endl;

   QListIterator<QStringList> records(data);
   while(records.hasNext()) {
      // QStringList record = records.next();
      QListIterator<QString> fields(records.next());
      while(fields.hasNext()) {
         cout << fields.next();
         if (fields.hasNext()) {
            cout << " -- ";
         }
      }
      cout << Qt::endl;
   }
   cout << Qt::endl;
}

// container
void printCSVData2( QList<QStringList>& data ) {

   cout << Qt::endl;

   QListIterator<QStringList> records(data);
   while(records.hasNext()) {
      // QStringList record = records.next();
      // QString ss = record.join(" --- ");
      QString qs = records.next().join(" --- ");
      cout << qs << Qt::endl;
   }
   cout << Qt::endl;
}

int main( int argc, char* argv[] )
{
   QCoreApplication app( argc, argv );
   /*
   Set up code that uses the Qt event loop here.
   Call a.quit() or a.exit() to quit the application.
   A not very useful example would be including
   #include <QTimer>
   near the top of the file
   and calling
*/
   // QTimer::singleShot(5000, &app, &QCoreApplication::quit);
/*
   which quits the application after 5 seconds.
   If you do not need a running Qt event loop, remove the call
   to a.exec() or use the Non-Qt Plain C++ Application template.
   */

   stringHandling();

   listAndIterator();

   listShorthand();

   // file I/O
   QList<QStringList> data;
   QString const filename = "E:/dev/Qt5---Cadaques-Assets/qml_2_3_1_Console/cities.csv";
   readCSVData(data, filename);

   // container
   // printCSVData(data);
   printCSVData2(data);



   // use event loop
   cout << "The application won't wait for further events after 5 minutes flat.\n" << Qt::endl;
   QTimer::singleShot(5000, &app, &QCoreApplication::quit);
   return app.exec( );

   // don't use event loop
   // return 0;
}
