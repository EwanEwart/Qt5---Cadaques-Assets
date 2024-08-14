#ifndef CUSTOMDESKTOPWIDGET_H
#define CUSTOMDESKTOPWIDGET_H

#include <QWidget>

#include <QListWidget>
#include <QListWidgetItem>
#include <QPushButton>

class CustomDesktopWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CustomDesktopWidget(QWidget *parent = nullptr);

signals:

private slots:
    void itemClicked(QListWidgetItem* item);
    void updateItem();
private:
    QListWidget* m_widget;
    QLineEdit* m_edit;
    QPushButton* m_button;
};

#endif // CUSTOMDESKTOPWIDGET_H
