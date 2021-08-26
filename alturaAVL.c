typedef struct {
	int valor
	int peso 
	/*
	-2 = doble izquierda
	-1 = izquierda
	0 = balanceado
	1 = derecha
	2 = doble derecha
	*/
	nodo* left;
	nodo* right;
}nodo;

typedef struct{
	nodo raiz;
	*nodo actual;
	*nodo padre;
}AVL;


int mayorAltura(AVL a){
	nodo aux = a.raiz;
	int altura = 0;

	while(aux != NULL){
		switch(aux){
			case -1: //izquierda
				aux = aux->left;
				altura++;
			break;
			
			case 0: //balanceado
			//como es indiferente, tomo el de la izquierda porque soy zurdo
				aux = aux->left;
				altura++

			case 1: //derecha
				aux = aux->right;
				altura++;
			break;
		}
	}

	return altura;
}