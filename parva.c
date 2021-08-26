typedef struct{
	int arr[MAX];
	int cantidad;
}parva;

//vamos a implementar una parva de maximo
//en parva el arreglo comienza en 1

void intercambio(int* x, int* y){
	int aux = *x;
	*x = *y;
	*y = aux;
}

void flotar(int arr[], int i){
	int padre = floor(i/2);

	if(i == 1 || arr[i] <= arr[padre])
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

void hundir(parva p, int i){
	int left = 2*i;
	int right = 2*i + 1;

	if(left > p.cantidad)
		return;

	else{
		if(p.arr[left] > p.arr[i] || p.arr[right] > p.arr[i]){
			if(p.arr[left] > p.arr[right]){
				intercambio(p.arr[i], p.arr[left]);
				hundir(p, left);
			}
			else{
				intercambio(p.arr[i], p.arr[right]);
				hundir(p, right);
			}
		}
	}
}

bool evocacion(parva p){
	if(p.cantidad == 0)
		return false;

	else{
		int aux = p.arr[1];
		p.arr[1] = p.arr[p.cantidad];
		p.cantidad--;
		hundir(p, 1);
		print(aux); //tambien se podria retornar en un puntero
		return true;
	}
}

/*

IMPORTANTE: PARVA ACEPTA ELEMENTOS REPETIDOS!!!!

CAMBIOS PARA PASAR DE MAXIMO A MINIMO

FLOTAR:
	CAMBIAR CONDICION SI PADRE ES MAS PEQUEÑO -> SI PADRE ES MAS GRANDE

HUNDIR:
	SI LO QUE ESTOY VIENDO ES MAS PEQUEÑO QUE SUS HIJOS -> SI LO QUE ESTOY VIENDO ES MAS GRANDE QUE SUS HIJOS
	ELIJO HIJO MAS GRANDE -> ELIGO HIJO MAS PEQUEÑO

*/