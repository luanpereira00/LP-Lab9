#ifndef _LISTA_H_
#define _LISTA_H_

#include "deque.h"

/** @brief Declaracao de template para o tipo T (int, float, double...)*/
template <typename T>

/** 
* struct node lista.h
* @brief Um struct para representar os nos de lista ligada
*/
struct nodeLista{
	T dado; /**< Elemento generico do no*/
	nodeLista* prox; /**< Apontador para o proximo no*/
};

/** 
 * @class 	lista lista.h
 * @brief 	Classe que representa uma lista ligada ordenada duplamente encadeada de dados
 * @details Os atributos de uma lista sao as sentinelas de inicio e de fim 
 */
template <typename T>
class Lista{
private:
	nodeLista<T>* inicio; /**< Sentinela de inicio da lista*/

public:
	/** @brief Construtor padrao */
	Lista(){
		inicio = new struct nodeLista<T>;

		inicio->dado=0;
		inicio->prox=NULL;
	}

	/** @brief Destrutor padrao */
	~Lista(){
		nodeLista<T>* aux = inicio;
		if(aux->prox){
			nodeLista<T>* tmp = new nodeLista<T>;
			tmp->prox=inicio->prox;
			while(tmp->prox->prox){
				delete aux;
				aux = tmp->prox;
				tmp->prox=tmp->prox->prox;
			}
			delete tmp->prox;;
			delete tmp;
		}
		delete aux;
	}

	/** @return Retorna a sentinela de inicio da lista ligada*/
	nodeDeque<T>* getInicio(){
		return inicio;
	}

	/** 
	* @brief Insere um elemento ordenadamente na lista
	* @param el O elemento que sera inserido na lista 
	*/
	void inserir(T el){
		//cout << "Inserindo o elemento " << el << endl;
		//nodeDeque<T>* it = buscar(el);
		nodeLista<T>* it = inicio;
		nodeLista<T>* tmp = new nodeLista<T>;
		tmp->dado=el;
		tmp->prox=it->prox;

		it->prox=tmp;
	}

	/** 
	* @brief Remove um elemento da lista ligada. (Informa também caso o elemento nao exista)
	* @param el O elemento que sera removido da lista 
	*/
	void remover(){
		//cout << endl;
		//cout << "Removendo o elemento " << el << endl;
		//nodeDeque<T>* it = buscar(el);
		nodeLista<T>* it = inicio;
		if(it->prox){
			nodeLista<T>* tmp = new nodeLista<T>;
			tmp->prox=it->prox->prox;

			delete it->prox; 

			it->prox=tmp->prox;

			delete tmp; 
		}
		else cerr << "ERRO: Impossivel remover elementos da lista (LISTA VAZIA!) ...Continuando operacoes" << endl;
	}

	/** @brief Imprime toda a lista ligada*/
	void imprimir(){
		nodeLista<T>* it = inicio;
		if(it->prox){
			cout << "-----------------------" << endl;
			cout << "Lista: " << endl;
			while(it->prox){
				cout << it->prox->dado << endl;
				it=it->prox;
			}
			cout << "-----------------------" << endl;
		}
		
	}

	/** 
	* @brief Busca na lista ligada (usado para inserir e remover apenas!)
	* @param el O elemento que sera removido da lista 
	*/
	nodeLista<T>* buscar(T el){
		nodeLista<T>* it = inicio;
		while(it->prox){
			if(it->prox->dado==el) return it->prox;
			it=it->prox;
		}
		return it;
	}

	bool temAlgo(){
		if(inicio->prox) return true;
		else return false;
	}
};

#endif