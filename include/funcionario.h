#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "header.h"

//nada alocado dinamicamente
class Funcionario
{
	private:	
		string nome; 
		float salario;
		string admissao; 
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

		//alterar dados
		void change_nome(string &new_name);
		void change_salario(float &new_salary);
		void change_admissao(string &new_admission);

		//Sobrecarga de operadores
		friend ostream& operator<< (ostream &out, Funcionario const a);
		bool operator== (Funcionario &a);
		Funcionario& operator= (Funcionario const &a);	//pra que?

};


#endif