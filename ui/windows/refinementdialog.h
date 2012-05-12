#ifndef REFINEMENTDIALOG_H
#define REFINEMENTDIALOG_H

#include <QtGui/QDialog>
#include <QtCore/QTimer>
#include <QtCore/QTime>
#include "../../ui_refinementdialog.h"
#include "../../core/refinement/refinementalgorithms/refinementalgorithm.h"

class RefinementDialog : public QDialog
{
    Q_OBJECT
protected:
	RefinementAlgorithm *ra;
	QTimer timer;
	QTime elapsedTime;
	int segundos;
	int n_ant;
public:
    RefinementDialog(RefinementAlgorithm *ra,QWidget *parent = 0);
    ~RefinementDialog();
private:
    Ui::RefinementDialogClass ui;
private slots:
	void update();
	void done();
};

#endif // REFINEMENTDIALOG_H
