#include "refinementdialog.h"
#include <QtCore/QThread>
#include <QtCore/QThreadPool>

RefinementDialog::RefinementDialog(RefinementAlgorithm *ra,QWidget *parent)
    : QDialog(parent)
{
	this->ra = ra;
	ui.setupUi(this);
	n_ant = 0;
	ui.statusLabel->setText(QString("Refinamiento en Proceso"));
	ui.progressBar->setMaximum(ra->getTotal());
	ui.progressBar->reset();
	segundos=0;
	//Qtimer timer(this);
	connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
	connect(ra, SIGNAL(finished()), this, SLOT(done()));
	elapsedTime.start();
	timer.start(1000);
	ra->start();
}

RefinementDialog::~RefinementDialog(){}

void RefinementDialog::update(){
	int done = ra->getDone();
	segundos++;
	ui.progressBar->setValue(done);
	ui.timeLabel->setText(
			QString("Tiempo Transcurrido: ") +
			QString::number(segundos) +
			QString(" [seg]"));
	ui.threadNumberLabel->setText(
			QString("Threads Activos: ") +
			QString::number(QThreadPool::globalInstance()->activeThreadCount()) +
			QString(" / ") +
			QString::number(QThread::idealThreadCount()));
	int v = done - n_ant;
	n_ant = done;
	ui.triangleLabel->setText(
			QString("Triángulo: ") +
			QString::number(done) +
			QString(" / ") +
			QString::number(ui.progressBar->maximum()) +
			QString(" ( ") +
			QString::number(v) +
			QString(" [triangulos/seg] )"));
}

void RefinementDialog::done(){
	timer.stop();
	ui.progressBar->setValue(ui.progressBar->maximum());
	ui.statusLabel->setText(QString("Refinamiento Concluido"));
	ui.timeLabel->setText(
			QString("Tiempo Total: ") +
			QString::number((double)elapsedTime.elapsed()/1000,'c',3) +
			QString(" [seg]"));
	ui.threadNumberLabel->setText(
			QString("Threads Activos: -"));
	ui.okButton->setEnabled(true);
	ui.triangleLabel->setText(
			QString("Velocidad Promedio: ") +
			QString::number((double)(ra->getTotal())/(elapsedTime.elapsed()/1000),'c',3) +
			QString(" [triangulos/seg]"));
}
