#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "busca.h"
#include "deque.h"
#include "fila.h"
#include "lista.h"
#include "pilha.h"

int main(){
	int V[5] = {1, 2, 3, 4, 5};
	cout << buscaTernariaR(V, 0, 5, 4) << endl;

	return 0;
}