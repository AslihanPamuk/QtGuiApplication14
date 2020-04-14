#pragma once

#include <QDialog>
#include "ui_QtGuiClass2.h"

class QtGuiClass2 : public QDialog
{
	Q_OBJECT

public:
	QtGuiClass2(QWidget *parent = Q_NULLPTR);
	~QtGuiClass2();

	void al();

public slots:

	void aldim();



private:
	Ui::QtGuiClass2 ui;
};
