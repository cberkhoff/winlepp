#include "m2dmeshsaver.h"
#include <fstream>
#include <QtCore/QMap>



void M2DMeshSaver::save(Mesh *mesh,const char* filename){
	std::ofstream outfile;
	outfile.open(filename);

	outfile << "# Archivo generado por WinLepp" << std::endl;
	outfile << "# Vertices" << std::endl;

	QMap<int,Vertex*>::iterator v_i;
	for(v_i=mesh->getVertexs()->begin();v_i!=mesh->getVertexs()->end();v_i++){
		Vertex *v = v_i.value();
		outfile << "v " << v->getId() << " " << v->getX() << " " << v->getY() << std::endl;
	}

	outfile << "# Triangulos" << std::endl;

	QMap<int,Triangle*>::iterator t_i;
	for(t_i=mesh->getTriangles()->begin();t_i!=mesh->getTriangles()->end();t_i++){
		Triangle *t = t_i.value();
		outfile << "t " << t->getId() << " ";
		for(int k=0;k<3;k++){
			outfile << t->getVertex(k)->getId() << " ";
		}
		outfile <<  std::endl;
	}

	outfile << "# Vecinos" << std::endl;
	for(t_i=mesh->getTriangles()->begin();t_i!=mesh->getTriangles()->end();t_i++){
		Triangle *t = t_i.value();
		outfile << "n " << t->getId() << " ";
		for(int k=0;k<3;k++){
			Triangle *n = t->getNeighbor(k);
			outfile << (n!=0?n->getId():0) << " ";
		}
		outfile << std::endl;
	}

	outfile.close();
}
