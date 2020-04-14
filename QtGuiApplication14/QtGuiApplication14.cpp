#include "QtGuiApplication14.h"
#include "QtGuiClass.h"
#include "QtGuiClass2.h"


QtGuiApplication14::QtGuiApplication14(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
    dosya();   
    dosya2();
}

void QtGuiApplication14::dosya()
{
    connect(ui.actionICD, SIGNAL(triggered()), this, SLOT(dosyaGetir()));   
}

void QtGuiApplication14::dosya2()
{
    connect(ui.importICD, SIGNAL(triggered()), this, SLOT(dosyaAl()));
}

void QtGuiApplication14::dosyaAl()
{
    QtGuiClass2 mdialog2;
    mdialog2.setModal(true);
    mdialog2.exec();
}

void QtGuiApplication14::dosyaGetir()
{
    QtGuiClass mdialog;
    mdialog.setModal(true);
    mdialog.exec();
} 






