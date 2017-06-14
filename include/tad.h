/**
 * @file	lista.h
 * @brief	Definicao da classe lista para representar uma lista ligada ordenada duplamente encadeada de dados
 * @details Os atributos de uma lista sao as sentinelas de inicio e de fim
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	17/05/2017
 * @date	17/05/2017
 */
#ifndef LISTA_H
#define LISTA_H

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

/** @brief Declaracao de template para o tipo T (int, float, double...)*/
template <typename T>

/** 
* struct node lista.h
* @brief Um struct para representar os nos de lista ligada
*/
struct nodeDeque{
	T dado; /**< Elemento generico do no*/
	nodeDeque* prox; /**< Apontador para o proximo no*/
	nodeDeque* anter; /**< Apontador para o no anterior*/
};

/** 
 * @class 	lista lista.h
 * @brief 	Classe que representa uma lista ligada ordenada duplamente encadeada de dados
 * @details Os atributos de uma lista sao as sentinelas de inicio e de fim 
 */
template <typename T>
class deque{
private:
	nodeDeque<T>* inicio; /**< Sentinela de inicio da lista*/
	nodeDeque<T>* fim; /**< Sentinela de fim da lista*/

public:
	/** @brief Construtor padrao */
	deque(){
		inicio = new struct nodeDeque<T>;
		fim = new struct nodeDeque<T>;

		inicio->dado=0;
		inicio->prox=fim;
		inicio->anter=NULL;

		fim->dado=0;
		fim->prox=NULL;
		fim->anter=inicio;
	}
	/** @brief Destrutor padrao */
	~deque(){
		nodeDeque<T>* tmp = new nodeDeque<T>;
		nodeDeque<T>* aux = inicio;
		tmp->prox=inicio->prox;
		while(tmp->prox->prox){
			delete aux;
			aux = tmp->prox;
			tmp->prox=tmp->prox->prox;
		}
		delete aux;
		delete tmp->prox;;
		delete tmp;
	}

	/** @return Retorna a sentinela de inicio da lista ligada*/
	nodeDeque<T>* getInicio(){
		return inicio;
	}

	/** @return Retorna a sentinela de fim da lista ligada*/
	nodeDeque<T>* getFim(){
		return fim;
	}

	/** 
	* @brief Insere um elemento ordenadamente na lista
	* @param el O elemento que sera inserido na lista 
	*/
	void inserir(T el){
		//cout << "Inserindo o elemento " << el << endl;
		nodeDeque<T>* it = buscar(el);
		nodeDeque<T>* tmp = new nodeDeque<T>;
		tmp->dado=el;
		tmp->prox=it->prox;
		tmp->anter=it;

		it->prox->anter=tmp;
		it->prox=tmp;
	}

	/** 
	* @brief Remove um elemento da lista ligada. (Informa também caso o elemento nao exista)
	* @param el O elemento que sera removido da lista 
	*/
	void remover(T el){
		//cout << endl;
		//cout << "Removendo o elemento " << el << endl;
		nodeDeque<T>* it = buscar(el);
		if(it->prox->dado==el){
			nodeDeque<T>* tmp = new nodeDeque<T>;
			tmp->prox=it->prox->prox;
			tmp->anter=it;

			delete it->prox; 

			it->prox=tmp->prox;
			it->prox->anter=tmp->anter;

			delete tmp; 
		}
		else cerr << "ERRO: Impossivel remover o elemento " << el << " (nao existe na lista)! ...Continuando operacoes" << endl;
	}

	/** @brief Imprime toda a lista ligada*/
	void imprimir(){
		nodeDeque<T>* it = inicio;
		if(it->prox->prox){
			cout << "-----------------------" << endl;
			cout << "Lista: " << endl;
		}
		while(it->prox->prox){
			cout << it->prox->dado << endl;
			it=it->prox;
		}
		if(it->prox->prox) cout << "-----------------------" << endl;
	}

	/** 
	* @brief Busca na lista ligada (usado para inserir e remover apenas!)
	* @param el O elemento que sera removido da lista 
	*/
	nodeDeque<T>* buscar(T el){
		nodeDeque<T>* it = inicio;
		while(it->prox->prox && it->prox->dado<el){
			it=it->prox;
		}
		return it;
	}
};

/** 
* struct node lista.h
* @brief Um struct para representar os nos de lista ligada
*/
template <typename T>
struct nodeLista{
	T dado; /**< Elemento generico do no*/
	nodeLista* prox; /**< Apontador para o proximo no*/
};

/** 
 * @class 	lista lista.h
 * @brief 	Classe que representa uma lista ligada ordenada duplamente encadeada de dados
 * @details Os atributos de uma lista sao as sentinelas de inicio 
 */
template <typename T>
class lista{
private:
	nodeLista<T>* inicio; /**< Sentinela de inicio da lista*/

public:
	/** @brief Construtor padrao */
	lista(){
		inicio = new struct nodeLista<T>;

		inicio->dado=0;
		inicio->prox=NULL;
	}
	/** @brief Destrutor padrao */
	~lista(){
		nodeLista<T>* tmp = new nodeLista<T>;
		nodeLista<T>* aux = inicio;
		tmp->prox=inicio->prox;
		while(tmp->prox->prox){
			delete aux;
			aux = tmp->prox;
			tmp->prox=tmp->prox->prox;
		}
		delete aux;
		delete tmp;
	}

	/** @return Retorna a sentinela de inicio da lista ligada*/
	nodeLista<T>* getInicio(){
		return inicio;
	}

	/** 
	* @brief Insere um elemento ordenadamente na lista
	* @param el O elemento que sera inserido na lista 
	*/
	void inserir(T el){
		//cout << "Inserindo o elemento " << el << endl;
		//nodeLista<T>* it = buscar(el);
		nodeLista<T>* tmp = new nodeLista<T>;
		tmp->dado=el;
		tmp->prox=inicio;

		inicio=tmp;
	}

	/** 
	* @brief Remove um elemento da lista ligada. (Informa também caso o elemento nao exista)
	* @param el O elemento que sera removido da lista 
	*/
	void remover(T el){
		//cout << endl;
		//cout << "Removendo o elemento " << el << endl;
		nodeLista<T>* it = buscar(el);
		if(it->prox->dado==el){
			nodeLista<T>* tmp = new nodeLista<T>;
			tmp->prox=it->prox->prox;
			delete it->prox; 
			it->prox=tmp->prox;
			delete tmp; 
		}
		else cerr << "ERRO: Impossivel remover o elemento " << el << " (nao existe na lista)! ...Continuando operacoes" << endl;
	}

	/** @brief Imprime toda a lista ligada*/
	void imprimir(){
		nodeLista<T>* it = inicio;
		if(it->prox->prox){
			cout << "-----------------------" << endl;
			cout << "Lista: " << endl;
		}
		while(it->prox->prox){
			cout << it->prox->dado << endl;
			it=it->prox;
		}
		if(it->prox->prox) cout << "-----------------------" << endl;
	}

	/** 
	* @brief Busca na lista ligada (usado para inserir e remover apenas!)
	* @param el O elemento que sera removido da lista 
	*/
	nodeLista<T>* buscar(T el){
		nodeLista<T>* it = inicio;
		while(it->prox->prox && it->prox->dado<el){
			it=it->prox;
		}
		return it;
	}
};


/** 
 * @class 	pilha stack.h
 * @brief 	Classe que representa uma pilha de dados
 * @details Os atributos de uma pilha sao o vetor e o tamanho do vetor 
 */
template <typename T>
class pilha{
private:
	T *vetor; /**< O vetor que contem a pilha*/
	int tam; /**< O tamanho da pilha*/

public:

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
		return vetor[getTam()-1];
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

	/** 
	* @brief Construtor parametrizado 
	* @param *v O vetor 
	* @param t O tamanho do vetor 
	*/
	pilha(T *v, int t){
		//construtor parametrizado
		setVetor(v);
		setTam(t);
	}

	/** @brief Construtor padrao*/
	pilha(){
		//construtor padrao
	}

	/** @brief Destrutor padrao */
	~pilha(){
		if(getTam()>0) delete[] vetor;
		tam=0;
	}
};

#endif
