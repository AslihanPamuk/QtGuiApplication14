#include "QtGuiClass2.h"
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
#include <qbytearray.h>

QtGuiClass2::QtGuiClass2(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	al();
    al2();
}

QtGuiClass2::~QtGuiClass2()
{
}

void QtGuiClass2::al()
{
	
 connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(aldim()));
	

}

void QtGuiClass2::al2()
{
    connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(aldim2()));
}

void QtGuiClass2::aldim2()
{
    QString filename = QFileDialog::getOpenFileName(
        this,
        tr("Open Document"),
        QDir::currentPath(),
        tr("Comma Separated Values Spreadsheet (*.csv);;"));
    QFile f(filename);

    if (f.open(QTemporaryFile::ReadOnly | QFile::Truncate))
    {
        QTextStream in(&f);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            ui.plainTextEdit->appendPlainText(line);
        }
    }
}

void QtGuiClass2::aldim()
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
