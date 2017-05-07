/**
* @file	funcionario.h
* @brief Declaração da classe Funcionario
* @author Natália Azevedo de Brito (https://github.com/bnatalha/)
* @since 04/04/2017
* @date 07/05/2017
* @sa http://www.cplusplus.com/ , http://en.cppreference.com/ 
*/

#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "header.h"

/**
* @class Funcionario funcionario.h
*/
class Funcionario
{
	private:	

		string nome;	/*< Nome do funcionário */
		float salario;	/*< Salário do funcionário */
		string admissao;	/*< Data de admissão do funcionário (dd/mm/aaaa) */
	public:

		/**
		* @brief Constrói funcionário passando seus atributos na ordem 'nome', 'admissao' e 'salario'
		* @param name Será o nome do funcionário
		* @param admission Será a data de admissão do funcionário
		* @param salary float que será o salário do funcionário (padrão é 0)
		*/
		Funcionario(string 		&name, string 	  &admission,float salary = 0 ):
			nome(name), salario(salary), admissao(admission) {}

		/**
		* @brief Constrói funcionário passando seus atributos na ordem 'nome', 'admissao' e 'salario'
		* @param name Uma string de C que será o nome do funcionário
		* @param admission Uma string que será a data de admissão do funcionário
		* @param salary float que será o salário do funcionário (padrão é 0)
		*/
		Funcionario(const char* name, string 	  &admission, float salary = 0 ):
			nome(name), salario(salary), admissao(admission) {}

		/**
		* @brief Constrói funcionário passando seus atributos na ordem 'nome', 'admissao' e 'salario'
		* @param name Uma string de C que será o nome do funcionário
		* @param admission Uma string de C que será a data de admissão do funcionário
		* @param salary float que será o salário do funcionário (padrão é 0)
		*/
		Funcionario(const char* name, const char* admission, float salary = 0 ):
			nome(name), salario(salary), admissao(admission) {}

		
		Funcionario(){}	/*< Constrói um Funcionario vazio */

		//verificar dados
		string get_nome();	/*< Autoexplicativo */
		float get_salario();	/*< Autoexplicativo */
		string get_admissao();	/*< Autoexplicativo */

		//alterar dados
		void change_nome(string &new_name);	/*< Muda o nome do funcionário */
		void change_salario(float &new_salary);	/*< Muda o salário do funcionário */
		void change_admissao(string &new_admission); /*< Muda a data de admissão do funcionário */

		//Sobrecarga de operadores
		friend ostream& operator<< (ostream &out, Funcionario const a); /*< Sobrecarga do operador de inserção em stream */
		bool operator== (Funcionario &a);	/*< Sobrecarga do operador == de comparação entre objetos */

};


#endif