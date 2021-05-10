//Examen dia 7 de Mayo

//Arboles
int nodosNivel(Arbol r, int nivel) {
	int izq, der;

	if(!r) { return -1; }

	if(nivel == 0) { return 1; }

	izq = nodosNivel(r->izq, nivel - 1);
	der = nodosNivel(r->der, nivel - 1);

	return izq + der;
}


int nodosNivel(Arbol r, int nivel) {
	int i;

	if(!r) { return -1; }
	if(nivel < 0) { return -2; }
	if(nivel == 0) { i++; return i; }

	if(r->izq != NULL) { i += nodosNivel(r->izq, nivel - 1); }
	if(r->der != NULL) { i += nodosNivel(r->der, nivel - 1); }

	return i;
}

//Monticulos
void crearMonticulo(Monticulo *m) {
	for(int i = m->tamanno/2; i > 0; i--) {
		filtradoDescendente(m, i);
	}
}

//Grafos
int *clasificados(tipoGrafo *g) {
	Monticulo m;
	tipoelementoM x;
	int j;

	int *verticesOrdenados = (int *) calloc(g->orden, sizeof(int));

	ordenTop1(g);

	for(int i = 1; i <= g->orden; i++) {
		m.elemento[i].clave = g->directorio[i].ordenTop;
		m.elemento[i].informacion = i;
	}

	m.tamanno = g->orden;

	crearMonticulo(&m);

	while(!vacioMonticulo(m)) {
		eleminarMinimo(&m, &x);
		verticesOrdenados[i] = x.informacion;
		j++;
	}

	return verticesOrdenados;
}