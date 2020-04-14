#include "QtGuiApplication14.h"
#include "QtGuiClass.h"


QtGuiApplication14::QtGuiApplication14(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
    dosya();
  
   
}

void QtGuiApplication14::dosya()
{
    connect(ui.actionICD, SIGNAL(triggered()), this, SLOT(dosyaGetir()));
    

}

void QtGuiApplication14::dosyaGetir()
{
    QtGuiClass mdialog;
    mdialog.setModal(true);
    mdialog.exec();
}






