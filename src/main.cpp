/**
 * @file	main.cpp
 * @brief	Responsável por executar buscas, ordenacoes e criacoes de TADs genericos
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	18/03/2017
 * @date	18/03/2017
 */
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "lista.h"
#include "deque.h"
#include "fila.h"
#include "pilha.h"
#include "vetor.h"
#include "sort.h"
#include "busca.h"

using namespace EDB1;
/**@brief Funcao principal */
int main(){

	Lista<int> ll;
	Deque<int> deq;
	Fila<int> fi;
	Pilha<int> pil;

	cout << ll.temAlgo() << endl;
	cout << deq.temAlgo() << endl;
	cout << fi.temAlgo() << endl;
	cout << pil.temAlgo() << endl;
	cout << endl;
	
	int X[50];

	createVetor(X, 50);
	printVetor(X, 50);
	bubbleSort(X, 50);
	printVetor(X, 50);
	cout << "======================================" << endl;
	createVetor(X, 50);
	printVetor(X, 50);
	insertionSort(X, 50);
	printVetor(X, 50);
	cout << "======================================" << endl;
	createVetor(X, 50);
	printVetor(X, 50);
	selectionSort(X, 50);
	printVetor(X, 50);
	cout << "======================================" << endl;
	createVetor(X, 50);
	printVetor(X, 50);
	mergeSort(X, 50);
	printVetor(X, 50);
	cout << "======================================" << endl;
	createVetor(X, 50);
	printVetor(X, 50);
	quickSort(X, 50);
	printVetor(X, 50);
	cout << "======================================" << endl;
	createVetor(X, 50);
	printVetor(X, 50);
	decimalSort(X, 50);
	printVetor(X, 50);
	
	
	int V[5] = {1, 2, 4, 5, 8};
	printVetor(V, 5);

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
