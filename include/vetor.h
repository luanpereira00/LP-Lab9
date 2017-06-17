/**
 * @file	vetor.h
 * @brief	Declaração de funções que fazem trocas de valores A e B
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	18/03/2017
 * @date	18/03/2017
 */


#ifndef _VETOR_H_
#define _VETOR_H_

#include <iostream>
using std::cout;
using std::endl;

#include <cstdlib>
#include <ctime>


/**
* @brief Responsável por imprimir um vetor
* @param *V Apontador para um vetor de inteiros
* @param N Tamanho do vetor
* @return Sem retorno
*/
template <class T>
void printVetor(T *V, int N){
	cout << "V = {";
	for (int i=0; i<N; i++) {
		if((i>0)&&(i<N)) cout << ", ";
		cout << V[i];
	}
	cout << "}\n" << endl;
	return;
}

template<class T>
void troca(T *a, T *b){
	(*a)=(*a)+(*b);
	(*b)=(*a)-(*b);
	(*a)=(*a)-(*b);
}

/**
* @brief Responsável por atribuir um vetor ao outro
* @param *V Apontador para o vetor final de inteiros
* @param *Vtemp Apontador para o vetor que será atribuido ao final
* @param N Tamanho dos vetores
* @return Sem retorno
*/
template <class T>
void trocaVetor(T *V, T *Vtemp, int N){
	for (int i=0; i<N; i++) V[i]=Vtemp[i];
}


/**
* @brief Responsável por inicializar um vetor com um valor
* @param *V Apontador para o vetor de inteiros
* @param N Tamanho dos vetores
* @param valor Valor à ser inicializado no vetor
* @return Sem retorno
*/
template <class T>
void initVetor(T *V, int N, T valor){
	for (int i=0; i<N; i++) V[i]=valor;
}

/**
* @brief Responsável por inicializar um vetor com um valor
* @param *V Apontador para o vetor de inteiros
* @param N Tamanho dos vetores
* @param valor Valor à ser inicializado no vetor
* @return Sem retorno
*/
template <class T>
void createVetor(T *V, int N){
	
	for (int i=0; i<N; i++) V[i]=rand()%N;
}

/**
* @brief Responsável por verificar se um vetor está ordenado de forma crescente
* @param *V Apontador para o vetor de inteiros
* @param N Tamanho dos vetores
* @return Sem retorno
*/
template <class T>
bool isOrdered(T *V, int N){
	for (int i=0; i<N-1; i++) {
		if(V[i]>V[i+1]) return false;
	}
	return true;
}


#endif