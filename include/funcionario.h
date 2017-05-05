#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "header.h"

class Funcionario
{
	private:	
		const string nome; 
		float salario;
		const string admissao; 
	public:
		Funcionario(string 		&name, string 	  &admission,float salary = 0 ):
			nome(name), salario(salary), admissao(admission) {}
		Funcionario(const char* name, string 	  &admission, float salary = 0 ):
			nome(name), salario(salary), admissao(admission) {}
		Funcionario(const char* name, const char* admission, float salary = 0 ):
			nome(name), salario(salary), admissao(admission) {}
		Funcionario(){}

		//verificar dados
		string get_nome();
		float get_salario();
		string get_admissao();

		//alterar salario
		void change_salario(float &new_salary);

		//Sobrecarga de operadores
		friend ostream& operator<< (ostream &out, Funcionario const a);
		bool operator== (Funcionario &a);

};


#endif