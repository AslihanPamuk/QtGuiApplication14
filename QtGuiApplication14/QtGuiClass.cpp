#include "QtGuiClass.h"
#include <qdebug.h>
#include <QFile>
#include <qstring.h>
#include <qfiledialog.h>
#include <qdir.h>
#include <qtemporaryfile.h>
#include <qdatastream.h>
#include <qdialog.h>
#include <QtXml/qxml.h>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <qplaintextedit.h>
#include <qtguiglobal.h>

QtGuiClass::QtGuiClass(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	enter(); //Main fonksiyonunda enter fonksiyonunu döndürür.
}

QtGuiClass::~QtGuiClass()
{
}

void QtGuiClass::enter()
{

    connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(cek())); //Enter butonuna basıldığında çek fonksiyonunu çağırır.
    connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(at()));   // Export as CSV butonuna basıldığında at fonksiyonunu çağırır.
    connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(aktarilan())); // Export as XML butonuna basıldığunda aktarilan fonksiyonunu çağırır. 
}

void QtGuiClass::cek() //Comboboxlardaki her bir değerin tableWidget'a aktarılması için yazılmıştır.
{
	ui.tableWidget->setItem(0, 0, new QTableWidgetItem(QString(ui.comboBox->currentText())));
	ui.tableWidget->setItem(0, 1, new QTableWidgetItem(QString(ui.comboBox_2->currentText())));
	ui.tableWidget->setItem(1, 0, new QTableWidgetItem(QString(ui.comboBox_3->currentText())));
	ui.tableWidget->setItem(1, 1, new QTableWidgetItem(QString(ui.comboBox_4->currentText())));
}

void QtGuiClass::at()
{
    QString filename = QFileDialog::getSaveFileName(  //Bilgisayardaki herhangi bir yere farklı kaydet işlemi yapmak için yazılmıştır.
        this,
        tr("Save Document"),  //Açılan dosyanın başlığında Save Document yazar. (caption)
        QDir::currentPath(), //Dosyanın kaydedileceği yer anlık olarak seçilir.
        tr("Comma Separated Values Spreadsheet (*.csv);;"));  //Kaydetme dosya biçimi olarak Comma Separated Values Spreadsheet (*.csv) yazar. (save as type)  
    
    QFile f(filename); //CSV formatında yazılacak olan dosya oluşturulur.Filename içerisine yazılanlar f'de tutulur.

        if (f.open(QTemporaryFile::WriteOnly | QFile::Truncate)) //Dosyaya yazma işleminin gerçekleşmesi için. (Temporaryfile: unique dosyalar oluşturur, truncate: yazdırdığı dosyada daha önceden bulunan şeyleri siler, temiz bir yazım yapmak için kullanılır.
    {
        QTextStream data(&f); //QTextStream metin yazmak için uygun bir arayüz sağlar.
        QStringList strList; //Stringleri listelemek için.
        strList.clear();

        for (int c = 0; c < ui.tableWidget->columnCount(); ++c) //Kolonlardaki değerleri çeker.
        {
            strList << ui.tableWidget->horizontalHeaderItem(c)->data(Qt::DisplayRole).toString(); //Kolondaki başlıkları alır.

        }
        data << strList.join(",") + "\n"; //Kolondaki başlıkların CSV formatında yazılmasını sağlar.

        for (int r = 0; r < ui.tableWidget->rowCount(); ++r) //Satırdaki değerleri çeker.
        {
            strList.clear();
            for (int c = 0; c < ui.tableWidget->columnCount(); ++c)
            {
                strList << ui.tableWidget->item(r, c)->text(); //Satır ve sütun değerlerini oluşturur.
            }
            data << strList.join(",") + "\n"; //CSV formatında yazdırır.
            
        }
        

        f.flush(); //Yazma işlemi olduğu için dosya bir miktar bekletilir.
        f.close(); //Dosya kapatılır.
    }

}
void QtGuiClass::aktarilan()
{
    QString filename = QFileDialog::getSaveFileName(  //Bilgisayardaki herhangi bir yere farklı kaydet işlemi yapmak için yazılmıştır.
        this,
        tr("Save Document"), //Açılan dosyanın başlığında Save Document yazar.
        QDir::currentPath(), //Dosyanın kaydedileceği yer anlık olarak seçilir.
        tr("Extensible Markup Language Spreadsheet (*.xml);;")); //Kaydetme dosya biçimi olarak Extensible Markup Language Spreadsheet (*.xml) yazar. (save as type:)

    QFile f(filename); //XML formatında yazılacak olan dosya oluşturulur. Filename içerisine yazılanlar string formatında f'in içinde tutulur.

    if (f.open(QTemporaryFile::WriteOnly | QFile::Truncate)) //Dosyaya yazma işleminin gerçekleşmesi için.
    {
        QXmlStreamWriter xmlWriter(&f); 
        xmlWriter.setAutoFormatting(true); //Otomatik formatlamayı sağlar.
        xmlWriter.writeStartDocument(); //Yazmaya başladığı dosyanın en başına "<?xml version="1.0" encoding="UTF-8"?>" ibaresini ekler. 

        for (int c = 0; c < ui.tableWidget->columnCount(); ++c) //Kolonlardaki değerleri çeker.
        {
         xmlWriter.writeStartElement(ui.tableWidget->horizontalHeaderItem(c)->data(Qt::DisplayRole).toString()); //XML formatındaki dosyanın başlığı için kolonlardaki başlıkları çeker.

          for (int r = 0; r < ui.tableWidget->rowCount(); ++r) //Satırdaki değerleri çeker.
            {
              xmlWriter.writeTextElement(ui.tableWidget->horizontalHeaderItem(c)->data(Qt::DisplayRole).toString(), ui.tableWidget->item(r, c)->text()); //Satır ve sütundaki değerleri çeker.
               
            }   
              xmlWriter.writeEndElement(); //XML formatındaki son elementi yazdırır.
        }
       
        f.flush(); //Yazma işlemi olduğu için dosya bir miktar bekletilir.
        f.close(); //Dosya kapatılır.
       
    }
}

            
    
   


   





