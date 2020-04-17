#include "QtGuiClass3.h"
#include "QtGuiClass2.h"
#include <qdebug.h>



//Action bardaki information butonuna tıklandığında program hakkında bilgi vermek amacıyla bir sayfa açılır. Actionbarda bulunan selectionlar hakkında kısa bilgiler verir.

QtGuiClass3::QtGuiClass3(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

QtGuiClass3::~QtGuiClass3()
{
}
