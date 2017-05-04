#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "header.h"

class Funcionario
{
	private:	
		const string nome; //? pode colocar const e alterar na criação?
		float salario;
		const string admissao; //vale a pena não colocaar esse de int?
	public:
		Funcionario(string 		name, string 	  admission, float salary = 0.0 ):
			nome(name), salario(salary), admissao(admission) {}
		Funcionario(const char* name, string 	  admission, float salary = 0.0 ):
			nome(name), salario(salary), admissao(admission) {}
		Funcionario(const char* name, const char* admission, float salary = 0.0 ):
			nome(name), salario(salary), admissao(admission) {}

		~Funcionario(){}

		//alterar salario
		string get_nome() {return nome;}
		float get_salario() {return salario;}
		string get_admissao() {return admissao;}

};


#endif