#include "Cn2CnKeyForm.h"
#include "ui_Cn2CnKeyForm.h"

CCn2CnKeyForm::CCn2CnKeyForm(QWidget *parent) :
QWidget(parent),
ui(new Ui::CCn2CnKeyForm)
{
	ui->setupUi(this);
}

CCn2CnKeyForm::~CCn2CnKeyForm()
{
	delete ui;
}
