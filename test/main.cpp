#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "deque.h"
#include "fila.h"
#include "lista.h"
#include "pilha.h"

int main(){
	Fila<int> ll;

	ll.imprimir();
	ll.inserir(5);
	ll.inserir(4);
	ll.inserir(3);
	ll.imprimir();
	ll.inserir(2);
	ll.inserir(1);
	ll.inserir(7);
	ll.imprimir();
	ll.remover();
	ll.remover();
	ll.imprimir();

	return 0;
}