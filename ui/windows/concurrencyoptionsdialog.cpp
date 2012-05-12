#include "concurrencyoptionsdialog.h"

ConcurrencyOptionsDialog::ConcurrencyOptionsDialog(QWidget *parent,bool concurrencyStatus,int nthreads)
    : QDialog(parent)
{
	ui.setupUi(this);
	ui.concurrencyCheckBox->setChecked(concurrencyStatus);
	ui.idealThreadNumberLineEdit->setText(QString::number(QThread::idealThreadCount()));
	ui.threadNumberSpinBox->setValue(nthreads);
}

ConcurrencyOptionsDialog::~ConcurrencyOptionsDialog()
{

}

bool ConcurrencyOptionsDialog::getConcurrency(){
	return ui.concurrencyCheckBox->isChecked();
}

int ConcurrencyOptionsDialog::getNumberOfThreads(){
	return ui.threadNumberSpinBox->value();
}
