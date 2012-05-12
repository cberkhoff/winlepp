#include "angleselectiondialog.h"

AngleSelectionDialog::AngleSelectionDialog(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
}

AngleSelectionDialog::~AngleSelectionDialog()
{

}

int AngleSelectionDialog::getDistance(){
	return ui.distanceSlider->value();
}
