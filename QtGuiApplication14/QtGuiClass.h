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
	void al();

	
	
	
public slots:
	void cek();
	void at();
	void aktarilan();
	void aldim();


private:
	Ui::QtGuiClass ui;
};
