#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QtGui/QFileDialog>
#include "../../ui_mainwindow.h"
#include "../../core/geom/mesh.h"
#include "../meshscene.h"

class mainwindow : public QMainWindow
{
    Q_OBJECT
private slots:
    void loadMesh();
    void sceneScaleChanged(const QString &scale);
    void refine();
    void about();
    void saveMesh();
    void selectAll();
    void clearSelection();
    void selectBasedOnAngles();
    void setUI();
    void setConsole();
    void setConcurrencyOptions();
public:
    mainwindow(QWidget *parent = 0);
    ~mainwindow();
protected:
	enum mode{ MESH_SELECTION, UI, CONSOLE};
	int currentMode;
	bool enableConcurrency;

	void setOptions();
	void setPanels();
	void setActions();
	void logMeshInfo();
	void logMeshLoad(QString filename);
	void refreshUI();

    Ui::mainwindowClass ui;
    Mesh * mesh;
    MeshScene *scene;
};

#endif // MAINWINDOW_H
