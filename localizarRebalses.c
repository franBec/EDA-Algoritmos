int hash(int x){
	
	int i;

	/*
	Matematicas que usan x
	para devolver un entero i 
	*/

	return x%10

	return i;
}

int hashRART(int x, int k){
	
	int i;

	/*
	Matematicas que usan x y k
	para devolver un entero i 
	*/

	return i;
}

int avanceLineal(int i){
	int n = lo que quiera avanzar linealmente;
	return i+=n;
}

int avanceRandom(int x){
	
	int i;

	/*
	Matematicas que usan x
	para devolver un entero i 
	*/

	return i;
}












//Rebalse separado
boolean localizar(int x, rebalse T){
	int i = hash(x);
	puntero p = T[i];

	while(p != NULL && p.dato != x)
		p = p->next;

	return (p.dato != NULL);
}

/*
En cualquier Rebasle Abierto todas las celdas
deben arrancar con un atributo virgen = true
*/

//Rebalse abierto lineal
boolean localizar(int x, rebalse T){

	int i = hash(x);
	
	while (T[i].virgen == false && T[i] != x)
 		i = i++ % M;

	return (T[i].virgen == false);
}

//Rebalse abierto cuadratico
boolean localizar(int x, rebale T){

	int i = hash(x);
	int k = 1;

	while(T[i].virgen == false && T[i] != x){
		i = (i+k) % M;
		k++; 
	}

	return (T[i].virgen == false);
}

//Rebalse abierto paso realeatorizado
boolean localizar(int x, rebale T){

	int i = hash(x);
	int k = avanceRandom(x);

	while(T[i].virgen == false && T[i] != x)
		i = (i+k) % M; 
	
	return (T[i].virgen == false);
}

//Rebalse abierto realeatorizado total
boolean localizar(int x, rebale T){

	int k = 1;
	int i = hashRART(x,k);

	while(T[i].virgen == false && T[i] != x){
		k++;
		i = hashRART(x, k);
	}

	return (T[i].virgen == false);
}