#ifndef ANGLESELECTIONDIALOG_H
#define ANGLESELECTIONDIALOG_H

#include <QtGui/QDialog>
#include "../../ui_angleselectiondialog.h"

class AngleSelectionDialog : public QDialog
{
    Q_OBJECT

public:
    AngleSelectionDialog(QWidget *parent = 0);
    ~AngleSelectionDialog();
    int getDistance();
private:
    Ui::AngleSelectionDialog ui;
};

#endif // ANGLESELECTIONDIALOG_H
