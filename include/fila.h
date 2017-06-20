/**
 * @file	fila.h
 * @brief 	Classe que representa uma Fila de dados
 * @details Os atributos de uma Fila sao as sentinelas de inicio e de fim  
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	17/05/2017
 * @date	17/05/2017
 */

#ifndef _FILA_H_
#define _FILA_H_

/**@brief Namespace para EDB1 */
namespace EDB1{
	/** @brief Declaracao de template para o tipo T (int, float, double...)*/
	template <typename T>

	/** 
	* struct node lista.h
	* @brief Um struct para representar os nos de lista ligada
	*/
	struct nodeFila{
		T dado; /**< Elemento generico do no*/
		nodeFila* prox; /**< Apontador para o proximo no*/
		nodeFila* anter; /**< Apontador para o no anterior*/
	};

	/** @brief Declaracao de template para o tipo T (int, float, double...)*/
	template <typename T>

	/** 
	 * @class 	Fila fila.h
	  * @brief 	Classe que representa uma Fila de dados
 	  * @details Os atributos de uma Fila sao as sentinelas de inicio e de fim 
	 */
	class Fila{
	private:
		nodeFila<T>* inicio; /**< Sentinela de inicio da lista*/
		nodeFila<T>* fim; /**< Sentinela de fim da lista*/

	public:
		/** @brief Construtor padrao */
		Fila(){
			inicio = new struct nodeFila<T>;
			fim = new struct nodeFila<T>;

			inicio->dado=0;
			inicio->prox=fim;
			inicio->anter=NULL;

			fim->dado=0;
			fim->prox=NULL;
			fim->anter=inicio;
		}
		/** @brief Destrutor padrao */
		~Fila(){
			nodeFila<T>* tmp = new nodeFila<T>;
			nodeFila<T>* aux = inicio;
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
		nodeFila<T>* getInicio(){
			return inicio;
		}

		/** @return Retorna a sentinela de fim da lista ligada*/
		nodeFila<T>* getFim(){
			return fim;
		}

		/** 
		* @brief Insere um elemento ordenadamente na lista
		* @param el O elemento que sera inserido na lista 
		*/
		void inserir(T el){
			//cout << "Inserindo o elemento " << el << endl;
			//nodeFila<T>* it = buscar(el);
			nodeFila<T>* it = fim;
			nodeFila<T>* tmp = new nodeFila<T>;
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
		void remover(){
			//cout << endl;
			//cout << "Removendo o elemento " << el << endl;
			//nodeFila<T>* it = buscar(el);
			nodeFila<T>* it = inicio;
			if(it->prox->prox){
				nodeFila<T>* tmp = new nodeFila<T>;
				tmp->prox=it->prox->prox;
				tmp->anter=it;

				delete it->prox; 

				it->prox=tmp->prox;
				it->prox->anter=tmp->anter;

				delete tmp; 
			}
			else cerr << "ERRO: Impossivel remover elementos da fila (FILA VAZIA!) ...Continuando operacoes" << endl;
		}

		/** @brief Imprime toda a lista ligada*/
		void imprimir(){
			nodeFila<T>* it = inicio;
			if(it->prox->prox){
				cout << "-----------------------" << endl;
				cout << "Fila: " << endl;
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
		nodeFila<T>* buscar(T el){
			nodeFila<T>* it = inicio;
			while(it->prox->prox && it->prox->dado<el){
				it=it->prox;
			}
			return it;
		}

		bool temAlgo(){
			if(inicio->prox->prox) return true;
			else return false;
		}
	};
}

#endif