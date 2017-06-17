#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "busca.h"
#include "deque.h"
#include "fila.h"
#include "lista.h"
#include "pilha.h"

int main(){
	int V[5] = {1, 2, 4, 5, 8};
	cout << "BBR: " << buscaBinariaR(V, 5, 0) << endl;
	cout << "BBR: " << buscaBinariaR(V, 5, 1) << endl;
	cout << "BBR: " << buscaBinariaR(V, 5, 3) << endl;
	cout << "BBR: " << buscaBinariaR(V, 5, 4) << endl;
	cout << "BBR: " << buscaBinariaR(V, 5, 9) << endl;
	cout << endl;
	cout << "BBI: " << buscaBinariaI(V, 5, 0) << endl;
	cout << "BBI: " << buscaBinariaI(V, 5, 2) << endl;
	cout << "BBI: " << buscaBinariaI(V, 5, 6) << endl;
	cout << "BBI: " << buscaBinariaI(V, 5, 8) << endl;
	cout << "BBI: " << buscaBinariaR(V, 5, 10) << endl;
	cout << endl;
	cout << "BSR: " << buscaSequencialR(V, 5, 0) << endl;
	cout << "BSR: " << buscaSequencialR(V, 5, 1) << endl;
	cout << "BSR: " << buscaSequencialR(V, 5, 3) << endl;
	cout << "BSR: " << buscaSequencialR(V, 5, 4) << endl;
	cout << "BSR: " << buscaSequencialR(V, 5, 9) << endl;
	cout << endl;
	cout << "BSI: " << buscaSequencialI(V, 5, 0) << endl;
	cout << "BSI: " << buscaSequencialI(V, 5, 2) << endl;
	cout << "BSI: " << buscaSequencialI(V, 5, 6) << endl;
	cout << "BSI: " << buscaSequencialI(V, 5, 8) << endl;
	cout << "BSI: " << buscaSequencialR(V, 5, 10) << endl;
	cout << endl;
	cout << "BTR: " << buscaTernariaR(V, 5, 0) << endl;
	cout << "BTR: " << buscaTernariaR(V, 5, 1) << endl;
	cout << "BTR: " << buscaTernariaR(V, 5, 3) << endl;
	cout << "BTR: " << buscaTernariaR(V, 5, 4) << endl;
	cout << "BTR: " << buscaTernariaR(V, 5, 9) << endl;
	cout << endl;
	cout << "BTI: " << buscaTernariaI(V, 5, 0) << endl;
	cout << "BTI: " << buscaTernariaI(V, 5, 2) << endl;
	cout << "BTI: " << buscaTernariaI(V, 5, 6) << endl;
	cout << "BTI: " << buscaTernariaI(V, 5, 8) << endl;
	cout << "BTI: " << buscaTernariaI(V, 5, 10) << endl;
	cout << endl;
	return 0;
}