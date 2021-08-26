void recorridoNivel(arbol a){
	cola colaAux;
	nodo nodoAux;
	agregarCola(colaAux, a.raiz);

	while(!isEmpty(colaAux)){
		nodoAux = pullCola(colaAux);
		printNodo(nodoAux);
		
		if(nodoAux->left != NULL)
			agregarCola(nodoAux->left);

		if(nodoAux->right != NULL)
			agregarCola(nodoAux->right);
	}
}