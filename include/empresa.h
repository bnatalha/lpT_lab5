#ifndef EMPRESA_H
#define EMPRESA_H

#include "header.h"
#include "funcionario.h"

// O que define um funcionário ser igual ao outro? nome e admissão ou só nome?
// Como medir qual o dia atual? Pergunta ao funcionário ou ao sistema?

class Empresa
{
	private:
		string nome;
		string cnpj;
		Funcionario * lista_funcionarios = NULL; //?? declara isso aqui?

	public:
		Empresa(string name, sring code) : nome(name), cnpj(code) {}
		Empresa(string name, sring code, Funcionario *& list) 
			: nome(name), cnpj(code), lista_funcionarios(list) {} //precisa ponto e virgula?

		~Empresa(){
			delete[] lista_funcionarios;
		}

		// Funções
		// Adicionar funcionários (o mesmo funcionário(?) não pode ter dois cadastros na mesma empresa)
		void adicionar_funcionario(Funcionario &employee);	// para adicionar um Funcionaro
		void adicionar_funcionario(Funcionario *&list);	// para adicionar ponteiro para Funcionario
		void adicionar_funcionario(string &filename);	// para adicionar a partir de um arquivo .csv
		//adicionar funcionario

		// sobrecarga de << imprime lista de funcionarios
		// Aumento de X% a todos funcionarios de uma vez
		// void dar_aumento_a_todos(float raise_rate);

		// Lista funcionarios cadastrados desde 90 dias atrás (?)
		// void mostrar_funcionario_em_experiencia( void );
}

#include "empresa.cpp"

#endif
