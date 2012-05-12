#ifndef CONCURRENCYOPTIONSDIALOG_H
#define CONCURRENCYOPTIONSDIALOG_H

#include <QtGui/QDialog>
#include <QtCore/QThread>
#include "ui_concurrencyoptionsdialog.h"

class ConcurrencyOptionsDialog : public QDialog
{
    Q_OBJECT

public:
    ConcurrencyOptionsDialog(QWidget *parent = 0, bool concurrencyStatus = true, int nthreads = QThread::idealThreadCount());
    ~ConcurrencyOptionsDialog();
    bool getConcurrency();
    int getNumberOfThreads();

private:
    Ui::ConcurrencyOptionsDialogClass ui;
};

#endif // CONCURRENCYOPTIONSDIALOG_H
