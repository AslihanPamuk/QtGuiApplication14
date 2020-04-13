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
	
public slots:
	void cek();

public slots:
	void at();

private:
	Ui::QtGuiClass ui;
};
