#pragma once

#include <QDialog>
#include "ui_QtGuiClass.h"


class QtGuiClass : public QDialog
{
	Q_OBJECT

public:
	QtGuiClass(QWidget *parent = Q_NULLPTR);
	~QtGuiClass();
	void enter();
	void bas(); 
	void aktar();


public slots:
	void cek();
	void at();
	void aktarilan();



private:
	Ui::QtGuiClass ui;
};
