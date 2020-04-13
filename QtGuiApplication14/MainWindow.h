#pragma once
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




class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = Q_NULLPTR);

	void aktar();

	

public slots:

	void aktarma();

private:
	Ui::MainWindow ui;

};
