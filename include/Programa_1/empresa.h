// O que define um funcionário ser igual ao outro? nome e admissão ou só nome? R: tudo
// Como medir qual o dia atual? Pergunta ao funcionário ou ao sistema?
//		http://www.cplusplus.com/reference/chrono/system_clock/
//

#ifndef EMPRESA_H
#define EMPRESA_H

//Meus arquivos de cabeçalho
#include "header.h"
#include "funcionario.h"

//Bibliotecas do STL
#include <fstream>

using std::ifstream;

#include <ctime>
#include <ratio>
#include <chrono>

class Empresa
{
	private:
		string nome;
		string cnpj;
		list<Funcionario> lista_f;

	public:
		//Construtores
		Empresa(string name, string code)
			: nome(name), cnpj(code) {}

		Empresa(string name, string code, list<Funcionario> &employee_list) 
			: nome(name), cnpj(code), lista_f(employee_list) {}

		//Destrutores
		~Empresa(){
		}

		// Funções

		// Sobrecarga de << imprime lista de funcionarios
		friend ostream& operator<< (ostream &out, Empresa &a);

		// Para auxiliar add_funcionario; 
		bool funcionario_ja_existe(Funcionario &employee);	// só adiciona o funcionario se já não estiver presente na lista;

		// Adicionar funcionários (o mesmo funcionário não pode ter dois cadastros na mesma empresa)
		void add_funcionario(Funcionario &employee);	// para adicionar um Funcionaro
		void add_funcionario(list<Funcionario> &employee_list);	// para adicionar ponteiro para Funcionario
		void add_funcionario(const char *filename);	// para adicionar a partir de um arquivo .csv
		void add_funcionario(string &filename);	// para adicionar a partir de um arquivo .csv

		// Aumento de X% a todos funcionarios de uma vez;
		void dar_aumento_a_todos(float raise_rate);

		// Lista funcionarios cadastrados desde 90 dias atrás
		int dias_desde_entrada(Funcionario &employee);
		void mostrar_funcionario_em_experiencia();

		//Funções auxiliares
		unsigned int qtd_funcionario();	//pra q

};

#endif