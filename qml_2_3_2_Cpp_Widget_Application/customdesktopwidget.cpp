#include "customdesktopwidget.h"
#include <QVBoxLayout>
#include <QLineEdit>
#include <QApplication>  // qApp

CustomDesktopWidget::CustomDesktopWidget( QWidget* parent )
: QWidget { parent }
{
   QVBoxLayout* layout = new QVBoxLayout( this );
   m_widget            = new QListWidget( this );
   layout->addWidget( m_widget );

   m_edit = new QLineEdit( this );
   layout->addWidget( m_edit );

   m_button = new QPushButton( "&Quit", this );
   layout->addWidget( m_button );

   setLayout( layout );

   QStringList cities;
   cities
       << "Amsterdam"
       << "Barcelona"
       << "Berlin"
       << "Brussels"
       << "Lissabon"
       << "..."
       << "London"
       << "Helsinki"
       << "Madrid"
       << "Manchester"
       << "Munich"
       << "Nueremberg"
       << "Paris"
       << "---"
       << "Praha"
       << "Oslo"
       << "Roma"
       << "Rotterdam"
       << "Roth"
       << "Stockholm"
       << "Vienna"
       << "Warszaw"
       << "xxxx"
       ;
   foreach ( QString const& city, cities )
   {
      m_widget->addItem( city );
   }

   connect(
       m_widget, SIGNAL( itemClicked(QListWidgetItem*) ), this, SLOT( itemClicked(QListWidgetItem*) ) );
   connect(
       m_edit, SIGNAL( editingFinished() ), this, SLOT( updateItem() ) );
   connect(
       m_button, SIGNAL( clicked(bool) ), qApp, SLOT( quit() ) );
}

void CustomDesktopWidget::itemClicked(
    QListWidgetItem* item )
{
   Q_ASSERT( item );
   m_edit->setText( item->text( ) );
}

void CustomDesktopWidget::updateItem( )
{
   QListWidgetItem* item = m_widget->currentItem( );
   if ( item )
   {
      item->setText( m_edit->text( ) );
   }
}
