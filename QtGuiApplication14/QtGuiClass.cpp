#include "QtGuiClass.h"
#include <qdebug.h>
#include <QFile>
#include <qtablewidget.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qstring.h>
#include <qmenu.h>
#include <qfiledialog.h>
#include <qdir.h>
#include <qtemporaryfile.h>
#include <qdatastream.h>
#include <qmenu.h>
#include <qaction.h>
#include <qdialog.h>
#include <QtXml/qxml.h>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <qplaintextedit.h>
#include <qtguiglobal.h>

//Bu kodlar csv ve xml dosyası oluşturup, bilgisayarda herhangi bir yere farklı kaydetmek amacıyla yazılmıştır.

QtGuiClass::QtGuiClass(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	enter();
	bas();
    aktar();
    al();
}

QtGuiClass::~QtGuiClass()
{
}

void QtGuiClass::enter()
{
    connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(at()));
}


void QtGuiClass::bas()
{
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(cek()));
}

void QtGuiClass::aktar()
{
    connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(aktarilan()));
}

void QtGuiClass::al()
{
    connect(ui.pushButton_4, SIGNAL(clicked()), this, SLOT(aldim()));
}


void QtGuiClass::cek()
{
	ui.tableWidget->setItem(0, 0, new QTableWidgetItem(QString(ui.comboBox->currentText())));
	ui.tableWidget->setItem(0, 1, new QTableWidgetItem(QString(ui.comboBox_2->currentText())));
	ui.tableWidget->setItem(1, 0, new QTableWidgetItem(QString(ui.comboBox_3->currentText())));
	ui.tableWidget->setItem(1, 1, new QTableWidgetItem(QString(ui.comboBox_4->currentText())));
}

void QtGuiClass::at()
{
    //Farklı kaydetmek için 
    QString filename = QFileDialog::getSaveFileName(
        this,
        tr("Save Document"),
        QDir::currentPath(),
        tr("Comma Separated Values Spreadsheet (*.csv);;"));
    

    QFile f(filename);

    if (f.open(QTemporaryFile::WriteOnly | QFile::Truncate))
    {
        QTextStream data(&f);
        QStringList strList;
        strList.clear();

        for (int c = 0; c < ui.tableWidget->columnCount(); ++c)
        {
            strList << ui.tableWidget->horizontalHeaderItem(c)->data(Qt::DisplayRole).toString();

        }

        data << strList.join(",") + "\n";

        for (int r = 0; r < ui.tableWidget->rowCount(); ++r)
        {
            strList.clear();
            for (int c = 0; c < ui.tableWidget->columnCount(); ++c)
            {
                strList << ui.tableWidget->item(r, c)->text();

            }
            data << strList.join(",") + "\n";
        }

        f.flush();
        f.close();
    }

}

void QtGuiClass::aktarilan()
{
    QString filename = QFileDialog::getSaveFileName(
        this,
        tr("Save Document"),
        QDir::currentPath(),
        tr("Extensible Markup Language Spreadsheet (*.xml);;"));

    QFile f(filename);

    if (f.open(QTemporaryFile::WriteOnly | QFile::Truncate))
    {
        QXmlStreamWriter xmlWriter(&f);
            xmlWriter.setAutoFormatting(true);
            xmlWriter.writeStartDocument();
        for (int c = 0; c < ui.tableWidget->columnCount(); ++c)
        {
            xmlWriter.writeStartElement(ui.tableWidget->horizontalHeaderItem(c)->data(Qt::DisplayRole).toString());

            for (int r = 0; r < ui.tableWidget->rowCount(); ++r)
            {
                xmlWriter.writeTextElement(ui.tableWidget->horizontalHeaderItem(c)->data(Qt::DisplayRole).toString(), ui.tableWidget->item(r, c)->text());
               
            }   
            xmlWriter.writeEndElement();
        }
       
        f.flush();
        f.close();
    }

}
void QtGuiClass::aldim()
{
    
    QString filename = QFileDialog::getOpenFileName(
        this,
        tr("Open Document"),
        QDir::currentPath(),
        tr("Extensible Markup Language Spreadsheet (*.xml);;"));
    QFile f(filename);
        
    if (f.open(QTemporaryFile::ReadOnly | QFile::Truncate))
    {
        QXmlStreamReader reader(&f);
        
            if (reader.readNextStartElement())
            {
                if (reader.name() == "root")
                {
                    while (reader.readNextStartElement())
                    {
                        if (reader.name() == "childA")
                        {
                            QString s = reader.readElementText();
                            ui.plainTextEdit->appendPlainText(qPrintable(s));

                        }
                        
                        else
                            reader.skipCurrentElement();
                    }

                }
                else
                    reader.raiseError(QObject::tr("Incorrect file"));
            }
           
        
    }
    
}

            
    
   


   





