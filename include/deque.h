/**
 * @file	deque.h
 * @brief	Definicao da classe Deque para representar uma lista ligada duplamente encadeada de dados
 * @details Os atributos de uma Deque sao as sentinelas de inicio e de fim
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	17/05/2017
 * @date	17/05/2017
 */
#ifndef _DEQUE_H_
#define _DEQUE_H_

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

/**@brief Namespace para EDB1 */
namespace EDB1{
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

	/** @brief Declaracao de template para o tipo T (int, float, double...)*/
	template <typename T>

	/** 
	 * @class 	Deque deque.h
	 * @brief 	Classe que representa uma lista ligada duplamente encadeada de dados
	 * @details Os atributos de um Deque sao as sentinelas de inicio e de fim 
	 */
	class Deque{
	private:
		nodeDeque<T>* inicio; /**< Sentinela de inicio da lista*/
		nodeDeque<T>* fim; /**< Sentinela de fim da lista*/

	public:
		/** @brief Construtor padrao */
		Deque(){
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
		~Deque(){
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
		void inserirInicio(T el){
			//cout << "Inserindo o elemento " << el << endl;
			//nodeDeque<T>* it = buscar(el);
			nodeDeque<T>* it = inicio;
			nodeDeque<T>* tmp = new nodeDeque<T>;
			tmp->dado=el;
			tmp->prox=it->prox;
			tmp->anter=it;

			it->prox->anter=tmp;
			it->prox=tmp;
		}

		/** 
		* @brief Insere um elemento ordenadamente na lista
		* @param el O elemento que sera inserido na lista 
		*/
		void inserirFim(T el){
			//cout << "Inserindo o elemento " << el << endl;
			//nodeDeque<T>* it = buscar(el);
			nodeDeque<T>* it = fim;
			nodeDeque<T>* tmp = new nodeDeque<T>;
			tmp->dado=el;
			tmp->prox=it;
			tmp->anter=it->anter;

			it->anter->prox=tmp;
			it->anter=tmp;
		}

		/** 
		* @brief Remove um elemento da lista ligada. (Informa também caso o elemento nao exista)
		* @param el O elemento que sera removido da lista 
		*/
		void removerInicio(){
			//cout << endl;
			//cout << "Removendo o elemento " << el << endl;
			//nodeDeque<T>* it = buscar(el);
			nodeDeque<T>* it = inicio;
			if(it->prox->prox){
				nodeDeque<T>* tmp = new nodeDeque<T>;
				tmp->prox=it->prox->prox;
				tmp->anter=it;

				delete it->prox; 

				it->prox=tmp->prox;
				it->prox->anter=tmp->anter;

				delete tmp; 
			}
			else cerr << "ERRO: Impossivel remover elementos do deque (DEQUE VAZIO!) ...Continuando operacoes" << endl;
		}

		/** 
		* @brief Remove um elemento da lista ligada. (Informa também caso o elemento nao exista)
		* @param el O elemento que sera removido da lista 
		*/
		void removerFim(){
			//cout << endl;
			//cout << "Removendo o elemento " << el << endl;
			//nodeDeque<T>* it = buscar(el);
			nodeDeque<T>* it = fim;
			if(it->anter->anter){
				nodeDeque<T>* tmp = new nodeDeque<T>;
				tmp->anter=it->anter->anter;
				tmp->prox=it;

				delete it->anter; 

				it->anter=tmp->anter;
				it->anter->prox=tmp->prox;

				delete tmp; 
			}
			else cerr << "ERRO: Impossivel remover elementos do deque (DEQUE VAZIO!) ...Continuando operacoes" << endl;
		}

		/** @brief Imprime toda a lista ligada*/
		void imprimir(){
			nodeDeque<T>* it = inicio;
			if(it->prox->prox){
				cout << "-----------------------" << endl;
				cout << "Deque: " << endl;
			}
			while(it->prox->prox){
				cout << it->prox->dado << endl;
				it=it->prox;
			}
			if(it->prox->prox) cout << "-----------------------" << endl;
		}

		bool temAlgo(){
			if(inicio->prox->prox) return true;
			else return false;
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
}
#endif