#include "helpdialog.h"
#include "ui_helpdialog.h"

HelpDialog::HelpDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::HelpDialog)
{
	ui->setupUi(this);
}

HelpDialog::~HelpDialog()
{
	delete ui;
}

void HelpDialog::load_helpfile(QString filename)
{
	QFile file(filename);
	if (file.exists())
	{
		QTextBrowser *viewer = this->findChild<QTextBrowser*>(QString("viewer"));
		viewer->setSource(*new QUrl(filename));
	}
}
