#pragma once

#include <QDialog>
#include "ui_QtGuiClass3.h"

class QtGuiClass3 : public QDialog
{
	Q_OBJECT

public:
	QtGuiClass3(QWidget *parent = Q_NULLPTR);
	~QtGuiClass3();

private:
	Ui::QtGuiClass3 ui;
};
