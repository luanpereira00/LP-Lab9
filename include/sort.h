/**
 * @file	sort.h
 * @brief	Declaracao de funcões que fazem ordenacões de vetores
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	23/03/2017
 * @date	23/03/2017
 */


#ifndef _SORT_H_
#define _SORT_H_
#include <iostream>
using std::cout;
using std::endl;

#include <cmath>

#include "vetor.h"

/**@brief Namespace para EDB1 */
namespace EDB1{

	/** @brief Declaracao de template para o tipo T (int, float, double...)*/
	template <class T>

	/**
	* @brief Responsavel por executar uma ordenacao do tipo Bubble(Bolha)
	* @param *V Apontador para um vetor de inteiros
	* @param N Tamanho do vetor
	* @return Sem retorno
	*/
	void bubbleSort(T *V, int N){
		int i, j, k=N;
		
		for(j=0; j<N; j++){
			
			for(i=0; i<k-1; i++){
				if(V[i]>V[i+1]) troca(&V[i], &V[i+1]);
			}	
			//printVetor(V, N);
		}
	}
	
	/** @brief Declaracao de template para o tipo T (int, float, double...)*/
	template <class T>
	
	/**
	* @brief Responsavel por executar uma ordenacao do tipo Decimal
	* @param *V Apontador para um vetor de inteiros
	* @param N Tamanho do vetor
	* @param dec Responsavel por indicar a funcao qual casa decimal ordenar (unid, dezen, cent...)
	* @return Sem retorno
	*/
	void decimalSort(T *V, int N, int dec = 0){
		int i, aux;
		T *Vtemp = new T[N];
		T *Vsimb = new T[N];
		T *Voffset= new T[N];
		
		//printVetor(V, N);
		initVetor(Vsimb, N, 0);
		initVetor(Voffset, N, 0);
		
							//Vsimb[27/1 = 27%10 = 7]
		for(i=0; i<N; i++) {
			aux=int(V[i]/pow(10, dec))%10;
			Vsimb[aux]++;
		}

							//Voffset[1]=Voffset[0]+Vsimb[0];
		for(i=1; i<10; i++) {
			Voffset[i]=Voffset[i-1]+Vsimb[i-1];
		}
		for(i=0; i<N; i++){
			aux=int(V[i]/pow(10, dec))%10;
			Vtemp[Voffset[aux]]=V[i];
			Voffset[aux]++;
		}
		trocaVetor(V, Vtemp, N);
		
		
		if(isOrdered(V, N)){
			//printVetor(V, N);
			return;
		}
		else decimalSort(V, N, ++dec);
		
		delete[] Vtemp;
		delete[] Vsimb;
		delete[] Voffset;
	}

	/** @brief Declaracao de template para o tipo T (int, float, double...)*/
	template <class T>
	
	/**
	* @brief Responsavel por executar uma ordenacao do tipo Insertion(Insercao)
	* @param *V Apontador para um vetor de inteiros
	* @param N Tamanho do vetor
	* @return Sem retorno
	*/
	void insertionSort(T *V, int N){
		int i, j, x;
		
		for (i=1; i<N; i++){	
			
			x=V[i];
			j=i-1;
			while((j>=0) && (x<V[j])){
				V[j+1]=V[j];
				j--;
			}
			V[j+1]=x;
			//cout << "Ordenado ";
			//printVetor(V, i);
			//cout << " e Nao-Ordenado ";
			//printVetor(&V[i], (N-i));
		}
	}
	
	/** @brief Declaracao de template para o tipo T (int, float, double...)*/
	template<class T>
	
	/**
	* @brief Responsavel por executar uma ordenacao do tipo Selection(Selecao)
	* @param *V Apontador para um vetor de inteiros
	* @param N Tamanho do vetor
	* @return Sem retorno
	*/
	void selectionSort(T *V, int N){
		int min, i, j;
		for(i=0; i<N-1; i++){
			min=i;
			
			for(j=i+1; j<N; j++){
				if (V[min]>V[j]) min=j;
			}
			if(min!=i) troca(&V[min], &V[i]);
			//cout << "Ordenado ";
			//printVetor(V, i);
			//cout << " e Nao-Ordenado ";
			//printVetor(&V[i], (N-i));	
		}
	}

	/** @brief Declaracao de template para o tipo T (int, float, double...)*/
	template <class T>
	
	/**
	* @brief Responsavel por executar uma intercalacao para o MergeSort
	* @param *V Apontador para um vetor de inteiros
	* @param N Tamanho do vetor
	* @return Sem retorno
	*/
	void intercalar(T *V, int N){
		int i=0, k=N/2, j=0;
		
		T *Vtemp = new T[N];
		
		while((i< (N/2)) && (k < N)){
			if(V[i] <= V[k]) Vtemp[j++]=V[i++];
			else Vtemp[j++]=V[k++];		
		}
		while (i<N/2)Vtemp[j++]=V[i++];
		while(k < N) Vtemp[j++]=V[k++];
		
		trocaVetor(V, Vtemp, N);
		delete[] Vtemp;
	}

	/** @brief Declaracao de template para o tipo T (int, float, double...)*/
	template<class T>
	
	/**
	* @brief Responsavel por executar uma ordenacao do tipo Merge(Mescla)
	* @param *V Apontador para um vetor de inteiros
	* @param N Tamanho do vetor
	* @return Sem retorno
	*/
	void mergeSort(T *V, int N){
		if(N<=1) return;
		if(N==2){
			if(V[0]<V[1]) return;
			else {
				troca(&V[0], &V[1]);
				return;
			}
		}
		int k=N/2;
		
		//printVetor(V, N);
		
		mergeSort(V, k);
		mergeSort(&V[k], N-k);
		intercalar(V, N);
		//printVetor(V, N);
	}

	/** @brief Declaracao de template para o tipo T (int, float, double...)*/
	template<class T>
	
	/**
	* @brief Responsavel por executar uma ordenacao do tipo Quick(Rapida)
	* @param *V Apontador para um vetor de inteiros
	* @param N Tamanho do vetor
	* @return Sem retorno
	*/
	void quickSort(T *V, int N){
		if(N<=1) return;
		int i=0, j=N-1, pivot;
		pivot=V[(i+j)/2];
		//cout << "Pivot: " << pivot << endl;
		//printVetor(V, N);
		while (i<j){
			while (V[i] <= pivot){
				i++;
			}
			while (V[j] > pivot){
				j--;
			}
			if(i<j){
				troca(&V[i], &V[j]);
			}
			i++;
			j--;
		}
		
		if(j>0) quickSort(V, j);
		if(i<N-1) quickSort(&V[j], N-j);
		//printVetor(V, N);
	}
}
#endif