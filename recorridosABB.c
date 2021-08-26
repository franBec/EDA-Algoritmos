void preorden(Nodo nodo){
	if(nodo == NULL)
		return;
	nodo.print();
	preorden(nodo.left);
	preorden(nodo.right);
}

void inorden(Nodo nodo){
	//Imprime arbol de manera creciente
	if(nodo==NULL)
		return;
	inorden(nodo.left);
	nodo.print();
	inorden(nodo.right);
}

void postorden(Nodo nodo){
	if(nodo==NULL)
		return;
	postorden(nodo.left);
	postorden(nodo.right);
	nodo.print();
}

void recorridoNivel(Nodo nodo){
	Queue queue;
	Nodo nodoAux;
	queue.add(nodo);

	while(!queue.isEmpty()){
		nodoAux = queue.poll();
		nodoAux.print();
		
		if(nodoAux.left != NULL)
			queue.add(nodoAux.left);

		if(nodoAux.right != NULL)
			queue.add(nodoAux.right);
	}
}

int getAltura(Nodo nodo){
	if(nodo == NULL)
		return 0;
	else{
		int alturaLeft = getAltura(nodo.left);
		int alturaRight = getAltura(nodo.right);

		if(alturaLeft > alturaRight)
			return alturaLeft + 1;
		else
			return alturaRight + 1;
	}
}