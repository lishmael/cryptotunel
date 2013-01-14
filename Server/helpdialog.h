#ifndef HELPDIALOG_H
#define HELPDIALOG_H

#include <QDialog>
#include <QFile>

namespace Ui {
		class HelpDialog;
	}

class HelpDialog : public QDialog
{
		Q_OBJECT

	public:
		explicit HelpDialog(QWidget *parent = 0);
		~HelpDialog();

	private:
		Ui::HelpDialog *ui;
	public slots:
		void load_helpfile(QString filename);
};

#endif // HELPDIALOG_H
