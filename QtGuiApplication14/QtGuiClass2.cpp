#include "QtGuiClass2.h"
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
#include <qtguiglobal.h>

QtGuiClass2::QtGuiClass2(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	al(); //Main fonksiyonunda al fonksiyonunu döndürür.
}

QtGuiClass2::~QtGuiClass2()
{
}

void QtGuiClass2::al()
{
 connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(aldim())); //Import as XML butonuna tıklandığında aldim fonksiyonunu çağırır.
 connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(aldim2())); //Import as CSV butonuna tıklandığında aldim2 fonksiyonunu çağırır.
}

void QtGuiClass2::aldim2()
{


    QString filename = QFileDialog::getOpenFileName( //Bilgisayardaki herhangi bir yerdeki dosyayı açmak için yazılmıştır.
        this,
        tr("Open Document"), //Açılan dosyanın başlığında Save Document yazar.
        QDir::currentPath(), //Dosyanın alınacağı yer anlık olarak seçilir.
        tr("Comma Separated Values Spreadsheet (*.csv);;")); //Açılan dosya biçimi olarak Comma Separated Values Spreadsheet (*.csv) yazar. (save as type)

    QFile f(filename); //CSV formatında okunacak olan dosya oluşturulur. 
    {

        if (f.open(QTemporaryFile::ReadOnly | QFile::Truncate)) //Dosyayı okuma işleminin gerçekleşmesi için. Filename'in içindekiler string formatında f'in içerisinde tutulur. (Temporaryfile: unique dosyalar oluşturur, truncate: yazdırdığı dosyada daha önceden bulunan şeyleri siler, temiz bir yazım yapmak için kullanılır.
        {
            QTextStream in(&f); //QTextStream metin yazmak için uygun bir arayüz sağlar.
            while (!in.atEnd())
            {
                QString line = in.readLine(); //Açılan dosyadaki her bir line'ı oku ve string formatında line'a kaydet.
                ui.plainTextEdit->appendPlainText(line); //plainTextEdit'e tuttuğun lineları yazdır.(her bir satıra ayrı olarak yazdırır.
            }
        }
    }
}

void QtGuiClass2::aldim()
{
    QString filename = QFileDialog::getOpenFileName( //Bilgisayardaki herhangi bir yerdeki dosyayı açmak için yazılmıştır.
        this,
        tr("Open Document"), //Açılan dosyanın başlığında Save Document yazar.
        QDir::currentPath(), //Dosyanın alınacağı yer anlık olarak seçilir.
        tr("Extensible Markup Language Spreadsheet (*.xml);;")); //Açılan dosya biçimi olarak Extensible Markup Language Spreadsheet (*.xml) yazar. (save as type)

    QFile f(filename); //XML formatında okunacak olan dosya oluşturulur.

    if (f.open(QTemporaryFile::ReadOnly | QFile::Truncate)) //Dosyayı okuma işleminin gerçekleşmesi için.
    {
        QXmlStreamReader reader(&f); //Yazılan bilgiyi okuyabilmek için kullanılır.

        if (reader.readNextStartElement())
        {
            if (reader.name() == "root") //Eğer root kelimesi görürsen;
            {
                while (reader.readNextStartElement()) //Bir sonraki elemente git
                {
                    if (reader.name() == "A") //Eğer bir sonraki elementte childA yazıyorsa
                    {
                        QString s = reader.readElementText(); //İki element arasındaki texti string formatında s'in içinde tut

                        ui.plainTextEdit->appendPlainText(qPrintable(s)); //s'in içinde tuttuğun değeri plainTextEdit'e yazdır.
                    }
                    else
                        reader.skipCurrentElement(); //Eğer childA yok ise bir sonraki elemente git.
                }
            }
            else
                reader.raiseError(QObject::tr("Incorrect file")); //Eğer root diye bir başlık yoksa yanlış dosyadasın.
        }
    }
}

