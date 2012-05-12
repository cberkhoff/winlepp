#include "mainwindow.h"
#include "angleselectiondialog.h"
#include "refinementdialog.h"
#include "concurrencyoptionsdialog.h"
#include <string>
#include "../../core/util/m2dmeshloader.h"
#include "../../core/util/m2dmeshsaver.h"
#include "../../core/refinement/refinementalgorithms/leppbisection.h"
#include "../../core/refinement/refinementalgorithms/concurrentleppbisection.h"
#include "../../core/refinement/refinementalgorithms/refinementalgorithm.h"
#include "../../core/refinement/selectioncriterions/selectioncriterion.h"
#include "../../core/refinement/selectioncriterions/subsetidcriterion.h"
#include "../../core/refinement/selectioncriterions/selectallcriterion.h"
#include "../../core/refinement/selectioncriterions/anglecriterion.h"
#include "../../core/refinement/selectioncriterions/randomcriterion.h"
#include <iostream>
#include <QtGlobal>
#include <QtGui>

mainwindow::mainwindow(QWidget *parent): QMainWindow(parent){
	ui.setupUi(this);

	scene = 0;
	mesh = 0;

	setOptions();
	setActions();
	setPanels();

	ui.textEdit->insertHtml(QString("<h1>Bienvenido a Winlepp</h1><br>"));
	ui.textEdit->insertHtml(
			QString("Carge una malla del menú para empezar ") +
			QString("(Siempre que carge mallas pasará automáticamente a modo consola)<br><br>")
			);
}

mainwindow::~mainwindow(){
	delete scene;
	delete mesh;
}

void mainwindow::loadMesh(){
	QString nombre_archivo = QFileDialog::getOpenFileName(
			this,
			tr("Abrir malla"),
			NULL,
			tr("Mesh 2d (*.m2d)"));
	if(nombre_archivo!=0){
		delete mesh;
		M2DMeshLoader M2Dloader;
		mesh = M2Dloader.load(nombre_archivo.toStdString().c_str());

		logMeshLoad(nombre_archivo);
		currentMode = CONSOLE;
		setPanels();
	}
}

void mainwindow::refine(){
	SelectionCriterion *sc = 0;
	RefinementAlgorithm *ra = 0;

	switch(currentMode){
	case UI:
		sc = new SubSetIdCriterion(scene->getSelectedTriangles());
		break;
	case CONSOLE:
		switch(ui.selectionCriterionComboBox->currentIndex()){
		case 0:
			sc = new SelectAllCriterion();
			break;
		case 1:
			Q_ASSERT(mesh!=0);
			AngleSelectionDialog *asd = new AngleSelectionDialog();
			if(asd->exec()){
				sc = new AngleCriterion(asd->getDistance(),mesh);
			} else {
				return;
			}
			delete asd;
			break;
		case 2:
			sc = new RandomCriterion(50);
			break;
		case 3:
			sc = new RandomCriterion(10);
			break;
		case 4:
			sc = new RandomCriterion(5);
			break;
		case 5:
			sc = new RandomCriterion(3);
			break;
		case 6:
			sc = new RandomCriterion(1);
			break;
		}
		break;
	default:
		Q_ASSERT(false);
	}

	if(enableConcurrency){
		ra = new ConcurrentLeppBisection(mesh,sc);
	} else {
		ra = new LeppBisection(mesh,sc);
	}
	RefinementDialog *rd = new RefinementDialog(ra,this);
	rd->exec();

	if(currentMode==UI)
		refreshUI();

	delete ra;
	delete sc;

	logMeshInfo();
}

void mainwindow::sceneScaleChanged(const QString &scale){
    double newScale = scale.left(scale.indexOf(tr("%"))).toDouble() / 100.0;
    QMatrix oldMatrix = ui.graphicsView->matrix();
    ui.graphicsView->resetMatrix();
    ui.graphicsView->translate(oldMatrix.dx(), oldMatrix.dy());
    ui.graphicsView->scale(newScale, newScale);
}

void mainwindow::setConcurrencyOptions(){
	ConcurrencyOptionsDialog *cod = new ConcurrencyOptionsDialog(
			this,
			enableConcurrency,
			QThreadPool::globalInstance()->maxThreadCount());
	if(cod->exec()){
		enableConcurrency = cod->getConcurrency();
		QThreadPool::globalInstance()->setMaxThreadCount(cod->getNumberOfThreads());
	}
	delete cod;
}

void mainwindow::selectBasedOnAngles(){
	Q_ASSERT(scene!=0);
	Q_ASSERT(mesh!=0);
	AngleSelectionDialog *asd = new AngleSelectionDialog;
	if(asd->exec()){
		SelectionCriterion *sc = new AngleCriterion(asd->getDistance(),mesh);
		scene->selectUsingCriterion(sc);
	}
	delete asd;
}

void mainwindow::selectAll(){
	Q_ASSERT(scene!=0);
	SelectionCriterion *sc = new SelectAllCriterion();
	scene->selectUsingCriterion(sc);
}

void mainwindow::clearSelection(){
	Q_ASSERT(scene!=0);
	scene->unselectAll();
}

void mainwindow::about(){
	QMessageBox::information(
			this,
			QString("Acerca de WinLepp"),
			QString("WinLepp versión 1.0\n\n"
					"Winlepp es una aplicación con fines pedagógicos desarrollada para"
					" los cursos de CC50D-1 Taller de Algoritmos Geométricos Paralelos"
					" y CC51H-1 Programación Orientada al Objeto por Christian Berkhoff."
					"\n\nInvierno 2009"),
			QMessageBox::Ok);
}

void mainwindow::saveMesh(){
	QString nombre_archivo = QFileDialog::getSaveFileName(
			this,
			tr("Guardar malla"),
			NULL,
			tr("Mesh 2d (*.m2d)"));
	M2DMeshSaver saver;
	saver.save(mesh,nombre_archivo.toStdString().c_str());
}

void mainwindow::setUI(){
	currentMode = UI;
	setPanels();
}
void mainwindow::setConsole(){
	currentMode = CONSOLE;
	setPanels();
}

void mainwindow::refreshUI(){
	delete scene;
	scene = new MeshScene();
	scene->createScene(mesh);
	ui.graphicsView->setScene(scene);
}

void mainwindow::logMeshInfo(){
	ui.textEdit->insertHtml(
			QString("<h2>Información de la malla</h2><b>Triángulos:</b> ") +
			QString::number((int)mesh->getTriangles()->size()) +
			QString("<br><b>Vértices:</b> ") +
			QString::number((int)mesh->getVertexs()->size()) +
			QString("<br><br>")
			);
}

void mainwindow::logMeshLoad(QString filename){
	ui.textEdit->insertHtml(
			QString("Malla cargada satisfactoriamente del archivo: ") +
			filename +
			QString("<br><br>")
			);
	logMeshInfo();
}

void mainwindow::setPanels(){
	switch(currentMode){
	//TODO: ver la forma de que los botones queden down
	case MESH_SELECTION:
		ui.mainPanel->setEnabled(false);
		ui.consolePanel->setVisible(false);
		ui.uiPanel->setVisible(false);
		ui.textEdit->setVisible(true);
		ui.graphicsView->setVisible(false);
		break;
	case UI:
		refreshUI();
		ui.mainPanel->setEnabled(true);
		ui.consolePanel->setVisible(false);
		ui.uiPanel->setVisible(true);
		ui.uiButton->setEnabled(false);
		ui.consoleButton->setEnabled(true);
		ui.textEdit->setVisible(false);
		ui.graphicsView->setVisible(true);
		break;
	case CONSOLE:
		ui.mainPanel->setEnabled(true);
		ui.consolePanel->setVisible(true);
		ui.uiPanel->setVisible(false);
		ui.uiButton->setEnabled(true);
		ui.consoleButton->setEnabled(false);
		ui.textEdit->setVisible(true);
		ui.graphicsView->setVisible(false);
		break;
	default:
		Q_ASSERT(false);
	}
}

void mainwindow::setActions(){
	//menu
	connect(ui.actionCargar_Mesh,SIGNAL(triggered()), this, SLOT(loadMesh()));
	connect(ui.actionAcerca_de,SIGNAL(triggered()), this, SLOT(about()));
	connect(ui.actionGuardar_Malla,SIGNAL(triggered()), this, SLOT(saveMesh()));
	connect(ui.actionConcurrencia,SIGNAL(triggered()), this, SLOT(setConcurrencyOptions()));

	//main panel
	connect(ui.consoleButton, SIGNAL(clicked()),this, SLOT(setConsole()));
	connect(ui.uiButton, SIGNAL(clicked()),this, SLOT(setUI()));
	connect(ui.refineButton, SIGNAL(clicked()),this, SLOT(refine()));

	//ui panel
	connect(ui.sceneScaleCombo, SIGNAL(currentIndexChanged(const QString &)),this, SLOT(sceneScaleChanged(const QString &)));
	connect(ui.selectAllButton, SIGNAL(clicked()),this, SLOT(selectAll()));
	connect(ui.clearSelectionButton, SIGNAL(clicked()),this, SLOT(clearSelection()));
	connect(ui.selectAngleButton, SIGNAL(clicked()),this, SLOT(selectBasedOnAngles()));
}

void mainwindow::setOptions(){
	currentMode = MESH_SELECTION;
	enableConcurrency = true;
}
