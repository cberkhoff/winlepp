#include "m2dmeshloader.h"
#include <fstream>
#include <sstream>

//TODO: Que no se caiga cuando la maya esta mala

Mesh *  M2DMeshLoader::load(const char* filename){
	Mesh *mesh = new Mesh();

    std::ifstream fin(filename);
    std::string line;

    while (getline(fin, line))
    {
    	// Trim comments.
    	std::string::size_type pos = line.find_first_of('#');
	    if (pos != std::string::npos) line = line.substr(0, pos);

	    // Trim ending spaces.
	    pos = line.find_last_not_of(' ');
	    if (pos != std::string::npos) line = line.substr(0, pos + 1);

	    // Trim beggining spaces.
	    pos = line.find_first_not_of(' ');
	    if (pos != std::string::npos) line = line.substr(pos, line.length());

	    // Skipping empty lines.
	    if (line.size() == 0) continue;

	    // Now let's process the line as a stream.
	    std::stringstream sin(line);

	    char type;
	    int id;

	    // Obtaining line type and id.
	    sin >> type >> id;

	    // Creating the specified type.
	    if (type == 'v' || type == 'V') // Vertex.
	    {
	    	float x, y;
	    	sin >> x >> y;
	    	Vertex *v = new Vertex(id, x, y);
	    	mesh->setVertex(id,v);
	    }
	    else if (type == 't' || type == 'T') // Triangle.
	    {
	    	int v1, v2, v3;
	        sin >> v1 >> v2 >> v3;

	        Triangle *t = new Triangle(
	        	id,
	        	mesh->getVertex(v1),
	        	mesh->getVertex(v2),
	        	mesh->getVertex(v3));
	        mesh->setTriangle(id,t);
	    }
	    else if (type == 'n' || type == 'N') // Neighbor
	    {
	    	int n1, n2, n3;
	        sin >> n1 >> n2 >> n3;
	        mesh->getTriangle(id)->setNeighbors(mesh->getTriangle(n1), mesh->getTriangle(n2), mesh->getTriangle(n3));
	    }
	    else
	    {
	    	std::cout << "Linea no reconocida:" << std::endl;
	    	std::cout << "\t '" << line << "'" << std::endl;
	    }
    }

	return mesh;

}
