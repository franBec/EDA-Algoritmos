//ejercicio a

typedef struct{
	char nombre;
	int prioridad; //parva usa este campo
}nupla;

typedef struct{
	int arr[MAX];
	int cantidad;
}parva;

void hundir(parva p, int i){
	int left = 2*i;
	int right = 2*i + 1;

	if(left > p.cantidad)
		return;

	else{
		if(p.arr[left] < p.arr[i] || p.arr[right] < p.arr[i]){
			if(p.arr[left] < p.arr[right]){
				intercambio(p.arr[i], p.arr[left]);
				hundir(p, left);
			}
			else{
				intercambio(p.arr[i], p.arr[right]);
				hundir(p, right);
			}
		}
		return;
	}
}

void flotar(int arr[], int i){
	int padre = floor(i/2);

	if(i == 1 || arr[i] >= arr[padre])
		return;
	else{
		intercambio(arr[i], arr[padre]);
		flotar(arr, padre);
	}
}

bool insertar(parva p, int i){
	if(p.cantidad == MAX)
		return false;
	
	else{
		p.cantidad++;
		p.arr[p.cantidad] = i;
		flotar(p.arr, p.cantidad);
		return true;
	}
}

bool modificarPrioridad(parva p, char elemento, int nuevaPrioridad){
	int posicion;
	bool exito;

	Localizar(in elemento, out posicion, out exito)
	if(exito){
		int aux = p.arr[posicion].prioridad;
		p.arr[posicion].prioridad = nuevaPrioridad;

		//se esta trabajando una parva de minimo
		if(aux < nuevaPrioridad)
			hundir(p, posicion);
		
		else
			flotar(p, posicion);
		
		return true;
	}
	else
		return false;
}

//ejercicio b
 
//asumiendo que ya estan mis datos cargados
void printHeapSort(parva p){
	while(p.cantidad != 0)
		print(aux = eliminar(p));
}