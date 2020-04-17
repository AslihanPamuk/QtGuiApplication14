#include "QtGuiApplication14.h"
#include "QtGuiClass.h"
#include "QtGuiClass2.h"
#include "QtGuiClass3.h"


QtGuiApplication14::QtGuiApplication14(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
    dosya();   //Main fonksiyonunda dosya fonksiyonunu döndürür.
  
}

void QtGuiApplication14::dosya()
{
    connect(ui.actionICD, SIGNAL(triggered()), this, SLOT(dosyaGetir()));  //Create New ICD butonuna basıldığında dosyaGetir fonksiyonunu çağırır.
    connect(ui.importICD, SIGNAL(triggered()), this, SLOT(dosyaAl()));     // Import ICD butonuna basıldığında dosyaAl fonksiyonunu çağırır.
    connect(ui.actionInformation, SIGNAL(triggered()), this, SLOT(dosyaBilgi())); //Information->Export & Import File butonuna basıldığında dosyaBilgi fonksiyonunu çağırır.

}

void QtGuiApplication14::dosyaGetir() //QtGuiClass.ui adlı QDialog Gui ekranının açılmasını sağlar.
{
    QtGuiClass mdialog;
    mdialog.setModal(true); //Modal dialog oluşturulur.(Modal oluşturmak demek dialog penceresi açıldığı zaman diğer pencelerede bir işlem yapamayacağın anlamına geliyor.)
    mdialog.exec(); //Modal dialog gösterilir. 
 
}

void QtGuiApplication14::dosyaAl()  ////QtGuiClass2.ui adlı QDialog2 Gui ekranının açılmasını sağlar.
{
    QtGuiClass2 mdialog2;
    mdialog2.setModal(true); //Modal dialog oluşturulur.(Modal oluşturmak demek dialog penceresi açıldığı zaman diğer pencelerede bir işlem yapamayacağın anlamına geliyor.)
    mdialog2.exec(); //Modal dialog gösterilir.
}

void QtGuiApplication14::dosyaBilgi()   //QtGuiClass3.ui adlı QDialog3 Gui ekranının açılmasını sağlar.
{
    QtGuiClass3 mdialog3;
    mdialog3.setModal(true); //Modal dialog oluşturulur.(Modal oluşturmak demek dialog penceresi açıldığı zaman diğer pencelerede bir işlem yapamayacağın anlamına geliyor.)
    mdialog3.exec(); //Modal dialog gösterilir.
}





