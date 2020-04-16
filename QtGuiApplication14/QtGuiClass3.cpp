#include "QtGuiClass3.h"
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

//Action bardaki information butonuna tıklandığında program hakkında bilgi vermek amacıyla bir sayfa açılır. Actionbarda bulunan selectionlar hakkında kısa bilgiler verir.

QtGuiClass3::QtGuiClass3(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

QtGuiClass3::~QtGuiClass3()
{
}
