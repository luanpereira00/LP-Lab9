/**
 * @file	main.cpp
 * @brief	Responsável por executar buscas ou ordenação de vetores
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	18/03/2017
 * @date	18/03/2017
 */


#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include "sort.h"
#include "busca.h"
#include "vetor.h"
#include "tad.h"
/** @brief Função principal */
int main (){
	int N=26, opcao=1, elemento;
	
	
	int V[26] = {2, 5, 9, 11, 13, 17, 22, 24, 33, 38, 39, 40, 45, 56, 71, 99, 110, 113, 132, 155, 166, 203, 211, 212, 230, 233};
	//int V[26] = {212, 5, 9, 155, 13, 17, 22, 24, 233, 38, 39, 45, 40, 56, 211, 99, 110, 113, 132, 11, 166, 203, 77, 2, 230, 33};
	int W[26] = {212, 5, 9, 155, 13, 17, 22, 24, 233, 38, 39, 45, 40, 56, 211, 99, 110, 113, 132, 11, 166, 203, 77, 2, 230, 33};
	//int V[6] = {212, 5, 9, 155, 13, 17};
	
	while(opcao != 0){
		do{
			cout << endl;
			cout << "As opções relativas à vetores são essas: " << endl;
			cout << " 1 - Ler Vetor" << endl;
			cout << " 2 - Imprimir Vetor" << endl;
			cout << " 3 - Busca Binaria Recursiva" << endl;
			cout << " 4 - Busca Ternaria Recursiva" << endl;
			cout << " 5 - Busca Sequencial Iterativa" << endl;
			cout << " 6 - BubbleSort" << endl;
			cout << " 7 - InsertionSort" << endl;
			cout << " 8 - SelectionSort" << endl;
			cout << " 9 - QuickSort" << endl;
			cout << "10 - MergeSort" << endl;
			cout << "11 - DecimalSort" << endl;
			cout << " 0 - Sair" << endl;
			cout << "Digite a sua opção: ";
			cin >> opcao;
			cout << endl;
		}while(opcao<0 or opcao>11);
		switch(opcao){
			case 1:
				trocaVetor<int>(V, W, N);
				break;

			case 2:
				printVetor<int>(V, N);
				break;

			case 3:
				if(!isOrdered<int>(V, N)) cout << "NÃO ORDENADO!" << endl;
				else {
					cout << "Digite o elemento à ser buscado: ";
					cin >> elemento;
					if(buscaBinariaR<int>(V, N, elemento)) cout << "O elemento " << elemento << " está presente no vetor!" << endl;
					else cout << "O elemento " << elemento << " não está presente no vetor!" << endl;
				}
				break;

			case 4:
				if(!isOrdered<int>(V, N)) cout << "NÃO ORDENADO!" << endl;
				else {
					cout << "Digite o elemento à ser buscado: ";
					cin >> elemento;
					if(buscaTernariaR<int>(V, 0, N, elemento)) cout << "O elemento " << elemento << " está presente no vetor!" << endl;
					else cout << "O elemento " << elemento << " não está presente no vetor!" << endl;
				}
				break;

			case 5:
				if(!isOrdered<int>(V, N)) cout << "NÃO ORDENADO!" << endl;
				else {
					cout << "Digite o elemento à ser buscado: ";
					cin >> elemento;
					if(buscaSequencialI<int>(V, N, elemento)) cout << "O elemento " << elemento << " está presente no vetor!" << endl;
					else cout << "O elemento " << elemento << " não está presente no vetor!" << endl;
				}
				break;

			case 6:
				if(isOrdered<int>(V, N)) cout << "JÁ ORDENADO!" << endl;
				else bubbleSort<int>(V, N);
				break;
			
			case 7:
				if(isOrdered<int>(V, N)) cout << "JÁ ORDENADO!" << endl;
				else insertionSort<int>(V, N);
				break;
				
			case 8:
				if(isOrdered<int>(V, N)) cout << "JÁ ORDENADO!" << endl;
				else selectionSort<int>(V, N);
				break;
			
			case 9:
				if(isOrdered<int>(V, N)) cout << "JÁ ORDENADO!" << endl;
				else quickSort<int>(V, N);
				break;				
				
			case 10:
				if(isOrdered<int>(V, N)) cout << "JÁ ORDENADO!" << endl;
				else mergeSort<int>(V, N);
				break;
			case 11:
				if(isOrdered<int>(V, N)) cout << "JÁ ORDENADO!" << endl;
				else decimalSort<int>(V, N);
				break;	

			case 0:
				//Sai do programa
				break;

			default:
				cout<<"OPÇÃO INVÁLIDA, POR FAVOR DIGITE UMA OPÇÃO VÁLIDA" << endl << endl;
				opcao = 2;
				break;		

		}
	}	
	
	
	
	return 0;
}