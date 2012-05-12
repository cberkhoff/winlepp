#ifndef POOL_H_
#define POOL_H_

/*!
 * Esta clase auxiliar define las bases para crear pozos de estructuras de datos (triangulos y
 * vertices) a fin de que el proceso de crearlas masivamente sea mas rapido.
 */
template <class T>
class Pool
{
protected:
	/*!
	 * Arreglo con los items prealocados
	 */
	T** pool;
	/*!
	 * Indica la posicion actual dentro del pozo
	 */
	int current;
	/*!
	 * Tamaño del pozo
	 */
	int size;
	/*!
	 * Inicializa todas las estructuras de datos. Sin tener el tipo de datos no se puede
	 * simplemente construir asi qeu se deja definida la interfaz
	 */
	virtual void initialize()=0;
public:
	/*!
	 * Constructor
	 * \param size tamaño del pozo
	 */
	Pool(int s){
		current = s;
		size = s;
		pool = new T*[size];
	};
	/*!
	 * Destructor
	 */
	virtual ~Pool(){
		for(int i=current;i<size;i++)
			delete pool[i];
		delete[] pool;
	};
	/*!
	 * Obtiene un elemento del pozo. Si se queda sin elementos se crean nuevos
	 */
	T * fetch(){
		if(current==size){
			initialize();
			current = 0;
		}

		T* r = pool[current];
		pool[current] = 0;
		current++;

		return r;
	};
};

#endif /*POOL_H_*/
