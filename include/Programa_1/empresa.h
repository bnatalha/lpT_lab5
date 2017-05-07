/**
* @file	empresa.h
* @brief Onde fica a definição da classe Empresa
* @author Natália Azevedo de Brito (https://github.com/bnatalha/)
* @since 04/04/2017
* @date 07/05/2017
* @sa http://www.cplusplus.com/ , http://en.cppreference.com/ 
*/

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
// O que define um funcionário ser igual ao outro? nome e admissão ou só nome? R: tudo
// Como medir qual o dia atual? Pergunta ao funcionário ou ao sistema?
//		http://www.cplusplus.com/reference/chrono/system_clock/

/**
* @class Empresa empresa.h
*/
class Empresa
{
	private:
		string nome;	/**< Nome da empresa */
		string cnpj;	/**< CNPJ da empresa */
		list<Funcionario> lista_f;	/**< Lista de funcionários da empresa */

	public:

		/**
		* @brief Constroi um objeto Empresa sem precisar de uma lista
		* @param name Será o nome da empresa
		* @param code Será o CNPJ da empresa
		*/
		Empresa(string name, string code)
			: nome(name), cnpj(code) {}

		/**
		* @brief Constroi um objeto Empresa com todos os atributos
		* @param name Será o nome da empresa
		* @param code Será o CNPJ da empresa
		* @param employee_list Será a lista de funcionários da empresa
		*/
		Empresa(string name, string code, list<Funcionario> &employee_list) /**< Constroi passando todos atributos */
			: nome(name), cnpj(code), lista_f(employee_list) {}

		// Função de sobrecarga
		friend ostream& operator<< (ostream &out, Empresa &a);	/**< Sobrecarga do operador << */

		// Filtro para adicionar funcionários
		bool funcionario_ja_existe(Funcionario &employee);	/**< Só adiciona o funcionário se já não estiver presente na lista */

		// Adicionar funcionários
		void add_funcionario(Funcionario &employee);	/**< Adiciona um funcionario à lista da empresa */
		void add_funcionario(list<Funcionario> &employee_list);	/**< Adiciona uma lista de funcionários à lista da empresa */
		void add_funcionario(const char *filename);	/**< Adiciona funcionários à lista da empresa partir de um arquivo .csv */
		void add_funcionario(string &filename);	/**< Adiciona funcionários à lista da empresa partir de um arquivo .csv */

		void dar_aumento_a_todos(float raise_rate); /**< Aumento de X% a todos funcionarios de uma vez */

		// Lista funcionarios cadastrados desde 90 dias atrás
		int dias_desde_entrada(Funcionario &employee); /**< Retorna há quantos dias um funcionário está na empresa */
		void mostrar_funcionario_em_experiencia(); /**< Lista funcionarios cadastrados desde 90 dias atrás */

		//Funções auxiliares
		unsigned int qtd_funcionario();	/**< Retorna a quantidade de funcionários na empresa */

};

#endif
