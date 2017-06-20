# Makefile, separando os diferentes elementos da aplicacao
# como codigo (src), cabecalhos (include), executaveis (build), bibliotecas (lib), etc.
# Cada elemento e alocado em uma pasta especifica, organizando melhor seu codigo fonte.
#
# Algumas variaveis sao usadas com significado especial:
#
# $@ nome do alvo (target)
# $^ lista com os nomes de todos os pre-requisitos sem duplicatas
# $< nome do primeiro pre-requisito
#

# Comandos do sistema operacional
# Linux: rm -rf 
# Windows: cmd //C del 
RM = rm -rf 

# Compilador
CC=g++ 

# Variaveis para os subdiretorios
LIB_DIR=./lib
INC_DIR=./include
SRC_DIR=./src
OBJ_DIR=./build
BIN_DIR=./bin
DOC_DIR=./doc
TEST_DIR=./test

# Opcoes de compilacao
CFLAGS=-Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR)

ARCHIVE = ar

# Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome
.PHONY: all init clean doxy debug doc

# Define o alvo (target) para a compilacao completa.
# Ao final da compilacao, remove os arquivos objeto.
all: init linux windows
debug: CFLAGS += -g -O0
debug: exec

#linux
linux: luan.a luan.so prog_estatico prog_dinamico

luan.a: $(SRC_DIR)/main.cpp $(INC_DIR)/busca.h $(INC_DIR)/vetor.h $(INC_DIR)/sort.h $(INC_DIR)/pilha.h $(INC_DIR)/fila.h $(INC_DIR)/deque.h $(INC_DIR)/lista.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.cpp -o $(OBJ_DIR)/main.o
	$(AR) rcs $(LIB_DIR)/$@ $(OBJ_DIR)/main.o
	@echo "++++ [Biblioteca estatica criada em $(LIB_DIR)/$@] +++" 

luan.so: $(SRC_DIR)/main.cpp $(INC_DIR)/busca.h $(INC_DIR)/vetor.h $(INC_DIR)/sort.h $(INC_DIR)/pilha.h $(INC_DIR)/fila.h $(INC_DIR)/deque.h $(INC_DIR)/lista.h
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/main.cpp -o $(OBJ_DIR)/main.o
	$(CC) -shared -fPIC -o $(LIB_DIR)/$@ $(OBJ_DIR)/main.o
	@echo "++++ [Biblioteca dinamica criada em $(LIB_DIR)/$@] +++" 

prog_estatico:
	$(CC) $(CFLAGS) $(SRC_DIR)/main.cpp $(LIB_DIR)/luan.a -o $(OBJ_DIR)/$@

prog_dinamico:
	$(CC) $(CFLAGS) $(SRC_DIR)/main.cpp $(LIB_DIR)/luan.so -o $(OBJ_DIR)/$@

#windows
windows: luan.lib luan.dll prog_estatico.exe prog_dinamico.exe

luan.lib: $(SRC_DIR)/main.cpp $(INC_DIR)/busca.h $(INC_DIR)/vetor.h $(INC_DIR)/sort.h $(INC_DIR)/pilha.h $(INC_DIR)/fila.h $(INC_DIR)/deque.h $(INC_DIR)/lista.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.cpp -o $(OBJ_DIR)/main.o
	$(AR) rcs $(LIB_DIR)/$@ $(OBJ_DIR)/main.o
	@echo "++++ [Biblioteca estatica criada em $(LIB_DIR)/$@] +++"

luan.dll: $(SRC_DIR)/main.cpp $(INC_DIR)/busca.h $(INC_DIR)/vetor.h $(INC_DIR)/sort.h $(INC_DIR)/pilha.h $(INC_DIR)/fila.h $(INC_DIR)/deque.h $(INC_DIR)/lista.h        
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/main.cpp -o $(OBJ_DIR)/main.o
	$(CC) -shared -o $(LIB_DIR)/$@ $(OBJ_DIR)/main.o
	@echo "++++ [Biblioteca dinamica criada em $(LIB_DIR)/$@] +++"

prog_estatico.exe:
	$(CC) $(CFLAGS) $(SRC_DIR)/main.cpp $(LIB_DIR)/luan.lib -o $(OBJ_DIR)/$@

prog_dinamico.exe:
	$(CC) $(CFLAGS) $(SRC_DIR)/main.cpp $(LIB_DIR)/luan.dll -o $(OBJ_DIR)/$@

init:
	@mkdir -p $(BIN_DIR)/
	@mkdir -p $(OBJ_DIR)/

# Alvo (target) para a geração automatica de documentacao usando o Doxygen.
# Sempre remove a documentacao anterior (caso exista) e gera uma nova.
doxy:
	$(RM) $(DOC_DIR)/*
	doxygen -g

doc:
	doxygen

# Alvo (target) usado para limpar os arquivos temporarios (objeto)
# gerados durante a compilacao, assim como os arquivos binarios/executaveis.
clean:
	$(RM) $(BIN_DIR)/* 
	$(RM) $(OBJ_DIR)/*	
	$(RM) $(DOC_DIR)/*	
