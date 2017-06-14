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
all: init exec
debug: CFLAGS += -g -O0
debug: exec

linux: EDB1.a EDB1.so prog_estatico prog_dinamico

EDB1.a: $(INC_DIR)/busca.h $(INC_DIR)/vetor.h $(INC_DIR)/sort.h $(INC_DIR)/tad.h
#	$(CC) $(CFLAGS) -c $(SRC_DIR)/funcoes1.cpp -o $(OBJ_DIR)/funcoes1.o
#	$(CC) $(CFLAGS) -c $(SRC_DIR)/funcoes2.cpp -o $(OBJ_DIR)/funcoes2.o
	$(AR) rcs $(LIB_DIR)/$@ $(INC_DIR)/busca.h $(INC_DIR)/vetor.h $(INC_DIR)/sort.h $(INC_DIR)/tad.h
	@echo "++++ [Biblioteca dinamica criada em $(LIB_DIR)/$@] +++" 

EDB1.so: $(INC_DIR)/busca.h $(INC_DIR)/vetor.h $(INC_DIR)/sort.h $(INC_DIR)/tad.h
#	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/funcoes1.cpp -o $(OBJ_DIR)/funcoes1.o
#	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/funcoes2.cpp -o $(OBJ_DIR)/funcoes2.o
	$(CC) -shared -fPIC -o $(LIB_DIR)/$@ $(INC_DIR)/busca.h $(INC_DIR)/vetor.h $(INC_DIR)/sort.h $(INC_DIR)/tad.h
	@echo "++++ [Biblioteca dinamica criada em $(LIB_DIR)/$@] +++" 

prog_estatico:
	$(CC) $(CFLAGS) $(LIB_DIR)/EDB1.a -o $(OBJ_DIR)/$@

prog_dinamico:
	$(CC) $(CFLAGS) $(LIB_DIR)/EDB1.so -o $(OBJ_DIR)/$@

init:
	@mkdir -p $(BIN_DIR)/
	@mkdir -p $(OBJ_DIR)/

# Alvo (target) para a construcao do executavel
# Define os arquivos main.o, busca.o, sort.o, troca.o e vetor.o como dependencias
exec: $(OBJ_DIR)/main.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel 'exec' criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto area.o
# Define os arquivos main.cpp, busca.cpp, sort.cpp, vetor.cpp, busca.h, vetor.h e sort.h como dependencias.
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp $(INC_DIR)/busca.h $(INC_DIR)/vetor.h $(INC_DIR)/sort.h $(INC_DIR)/tad.h
	$(CC) -c $(CFLAGS) -o $@ $<	

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