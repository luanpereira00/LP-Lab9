#ifndef _PILHA_H_
#define _PILHA_H_

#include <iostream>
using std::cout;
using std::endl;

/** 
 * @class 	pilha stack.h
 * @brief 	Classe que representa uma pilha de dados
 * @details Os atributos de uma pilha sao o vetor e o tamanho do vetor 
 */
template <typename T>
class Pilha{
private:
	T *vetor; /**< O vetor que contem a pilha*/
	int tam; /**< O tamanho da pilha*/

public:

	/** 
	* @brief Construtor parametrizado 
	* @param *v O vetor 
	* @param t O tamanho do vetor 
	*/
	Pilha(T *v, int t){
		//construtor parametrizado
		setVetor(v);
		setTam(t);
	}

	/** @brief Construtor padrao*/
	Pilha(){
		//construtor padrao
	}

	/** @brief Destrutor padrao */
	~Pilha(){
		if(getTam()>0) delete[] vetor;
		tam=0;
	}

	/** @return Retorna o tamanho do vetor */
	int getTam(){
		return tam;
	}

	/** 
	* @brief Modifica o tamanho do vetor 
	* @param t O tamanho do vetor 
	*/

	void setTam(int t){
		tam = t;
	}

	/** 
	* @brief Modifica o ponteiro do vetor 
	* @param *v O ponteiro do vetor 
	*/
	void setVetor(T *v){
		vetor = v;
	}

	/** @return Retorna o ponteiro do vetor */
	T* getVetor(){
		return vetor;
	}

	/** 
	* @brief Adiciona um elemento a pilha 
	* @param elemento O elemento que sera adicionado
	*/
	void push(T elemento){
		T *antigo = vetor;
		
		T *novo = new T[getTam()+1];
		for (int  i=0; i<getTam(); i++) novo[i]=antigo[i];
		novo[getTam()]=elemento;
		setTam(getTam()+1);
		setVetor(novo);
		if(getTam()>0) delete[] antigo;
	}

	/** @return Retorna o elemento do topo da pilha */
	T top(){ 
		if(getTam()>0){
			return vetor[getTam()-1];
		}
		else cout << "Pilha vazia! Retornando 0 por default..." << endl;
		return 0;
	}

	/** @brief Remove o elemento do topo da pilha */
	void pop(){
		if(getTam()>0) {
			T *antigo = vetor;
			T *novo = new T[getTam()-1];
			for (int  i=0; i<getTam()-1; i++) novo[i]=antigo[i];
			setTam(getTam()-1);
			setVetor(novo);
			delete[] antigo;
		}
	}

	
};

#endif