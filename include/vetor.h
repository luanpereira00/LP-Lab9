/**
 * @file	vetor.h
 * @brief	Declaracao de funcoes que fazem trocas de valores A e B
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

/**@brief Namespace para EDB1 */
namespace EDB1{
	/** @brief Declaracao de template para o tipo T (int, float, double...)*/
	template <class T>

	/**
	* @brief Responsavel por imprimir um vetor
	* @param *V Apontador para um vetor de inteiros
	* @param N Tamanho do vetor
	* @return Sem retorno
	*/
	void printVetor(T *V, int N){
		cout << "V = {";
		for (int i=0; i<N; i++) {
			if((i>0)&&(i<N)) cout << ", ";
			cout << V[i];
		}
		cout << "}\n" << endl;
		return;
	}

	/** @brief Declaracao de template para o tipo T (int, float, double...)*/
	template<class T>

	/**
	*@brief Funcao que troca dois valores
	*@param a Valor 1
	*@param b Valor 2
	*@return Sem tipo de retorno
	*/
	void troca(T *a, T *b){
		(*a)=(*a)+(*b);
		(*b)=(*a)-(*b);
		(*a)=(*a)-(*b);
	}

	/** @brief Declaracao de template para o tipo T (int, float, double...)*/
	template <class T>

	/**
	* @brief Responsavel por atribuir um vetor ao outro
	* @param *V Apontador para o vetor final de inteiros
	* @param *Vtemp Apontador para o vetor que sera atribuido ao final
	* @param N Tamanho dos vetores
	* @return Sem retorno
	*/
	void trocaVetor(T *V, T *Vtemp, int N){
		for (int i=0; i<N; i++) V[i]=Vtemp[i];
	}

	/** @brief Declaracao de template para o tipo T (int, float, double...)*/
	template <class T>

	/**
	* @brief Responsavel por inicializar um vetor com um valor
	* @param *V Apontador para o vetor de inteiros
	* @param N Tamanho dos vetores
	* @param valor Valor a ser inicializado no vetor
	* @return Sem retorno
	*/
	void initVetor(T *V, int N, T valor){
		for (int i=0; i<N; i++) V[i]=valor;
	}

	/** @brief Declaracao de template para o tipo T (int, float, double...)*/
	template <class T>

	/**
	* @brief Responsavel por inicializar um vetor com um valor
	* @param *V Apontador para o vetor de inteiros
	* @param N Tamanho dos vetores
	* @param valor Valor a ser inicializado no vetor
	* @return Sem retorno
	*/
	void createVetor(T *V, int N){
		
		for (int i=0; i<N; i++) V[i]=rand()%N;
	}

	/** @brief Declaracao de template para o tipo T (int, float, double...)*/
	template <class T>

	/**
	* @brief Responsavel por verificar se um vetor esta ordenado de forma crescente
	* @param *V Apontador para o vetor de inteiros
	* @param N Tamanho dos vetores
	* @return Sem retorno
	*/
	bool isOrdered(T *V, int N){
		for (int i=0; i<N-1; i++) {
			if(V[i]>V[i+1]) return false;
		}
		return true;
	}
}


#endif