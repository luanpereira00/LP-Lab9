/**
 * @file	busca.h
 * @brief	Declaracão de funcoes responsaveis por executar buscas de forma recursiva
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	18/03/2017
 * @date	18/03/2017
 */

#ifndef _BUSCA_H_
#define _BUSCA_H_

/**
* @brief Responsavel por realizar uma busca binaria e retornar boolean para caso o elemento buscado esteja ou não no vetor
* @param *V vetor para realizar a busca
* @param N Tamanho do vetor
* @param x Elemento a ser buscado no vetor
* @return boolean para o caso do elemento estar ou não no vetor
*/
template <class T>
int buscaBinariaR(T *V, int N, T x){
	if(N<=0) return -1;
	int k=N/2;
	if (V[k]==x) return k;
	if (x<V[k]) return buscaBinariaR(V, k, x);
	if (x>V[k]) return buscaBinariaR(&V[k+1], N-k-1, x);
	
	return -1;
}

/**
* @brief Responsavel por realizar uma busca binaria e retornar boolean para caso o elemento buscado esteja ou não no vetor
* @param *V vetor para realizar a busca
* @param N Tamanho do vetor
* @param x Elemento a ser buscado no vetor
* @return boolean para o caso do elemento estar ou não no vetor
*/
template <class T>
int buscaBinariaI(T *V, int N, T x){
	int esq, mid, dir;                             
  	esq = 0; 
  	dir = N-1;                         
   	while (esq <= dir) {                         
    	mid = (esq + dir)/2;                        
      	if (V[mid] == x) return mid;               
      	if (V[mid] < x) esq = mid + 1;              
      	else dir = mid - 1;                       
   	}                                       
   	return -1;        
}


/**
* @brief Responsavel por realizar uma busca ternaria e retornar boolean para caso o elemento buscado esteja ou não no vetor
* @param *vetor vetor para realizar a busca
* @param ini Início do vetor
* @param fim Final do vetor
* @param x Elemento a ser buscado no vetor
* @return boolean para o caso do elemento estar ou não no vetor
*/
template <class  T>
int buscaTernariaR(T *V, int N, T x, int esq = 0){
	int dir = N-1;
	int mid1 = (dir - esq)/3 + esq;    
    int mid2 = 2*(dir - esq)/3 + esq;  
	if (x==V[mid1]) return mid1;
	if (x==V[mid2]) return mid2; 
	if (x>=V[esq] and x<V[mid1]) return buscaTernariaR(V, mid1-1, x, esq+1);
	if (x>V[mid1] and x<V[mid2]) return buscaTernariaR(V, mid2, x, mid1);
	if (x>=V[mid2] and x<=V[dir]) return buscaTernariaR(V, N, x, mid2+1);
	
	return -1;
}

/**
* @brief Responsavel por realizar uma busca binaria e retornar boolean para caso o elemento buscado esteja ou não no vetor
* @param *V vetor para realizar a busca
* @param N Tamanho do vetor
* @param x Elemento a ser buscado no vetor
* @return boolean para o caso do elemento estar ou não no vetor
*/
template <class T>
int buscaTernariaI(T *V, int N, T x){
	int esq, mid1 = 0, mid2 = 1, dir;                             
  	esq = 0; 
  	dir = N-1;                         
   	while (esq <= dir) {                          
    	mid1 = (dir - esq)/3 + esq;    
    	mid2 = 2*(dir - esq)/3 + esq;                     
      	if (V[mid1] == x) return mid1; 
      	if (V[mid2] == x) return mid2;             
      	if (x < V[mid1]) dir = mid1 - 1;  
      	if (x > V[mid2]) esq = mid2 + 1;           
      	if (V[mid1] < x and x < V[mid2]) {
      		esq = mid1 + 1; 
      		dir = mid2 - 1;   
		}   
		//cout << esq << " " << mid1 << " " << mid2 << " " << dir << endl;                 
   	}                                         
   	return -1;        
}



/**
* @brief Responsavel por realizar uma busca sequencial e retornar boolean para caso o elemento buscado esteja ou não no vetor
* @param *V vetor para realizar a busca
* @param N Tamanho do vetor
* @param x Elemento a ser buscado no vetor
* @return boolean para o caso do elemento estar ou não no vetor
*/
template <class T>
int buscaSequencialI(T *V, int N, T x){
	for (int i=0; i<N; i++){
		if(x==V[i]) return i;
		if(x<V[i]) return -1;
	}
	
	return -1;
}

/**
* @brief Responsavel por realizar uma busca sequencial e retornar boolean para caso o elemento buscado esteja ou não no vetor
* @param *V vetor para realizar a busca
* @param N Tamanho do vetor
* @param x Elemento a ser buscado no vetor
* @return boolean para o caso do elemento estar ou não no vetor
*/
template <class T>
int buscaSequencialR(T *V, int N, T x, int pos = 0){
	if(N==0) return -1;
	else {
		if(V[0]==x) return pos;
		else return buscaSequencialR((V+1), N-1, x, pos+1);
	}	
	return -1;
}


#endif