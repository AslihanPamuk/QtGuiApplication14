#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGuiApplication14.h"
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



class QtGuiApplication14 : public QMainWindow
{
	Q_OBJECT

public:
	QtGuiApplication14(QWidget *parent = Q_NULLPTR);

	void dosya();
	void dosya2();
	

public slots:
	void dosyaGetir();
	void dosyaAl();
	

private:
	Ui::QtGuiApplication14Class ui;
	
};
