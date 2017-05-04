#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "header.h"

class Funcionario
{
	private:	
		string nome; //? pode colocar const e alterar na criação?
		float salario;
		unsigned int admissao; //vale a pena não colocaar esse de int?
	public:
		Funcionario(string name, unsigned int admission, int salary = 0.0 ):
			nome(name), salario(salary), admissao(admission) {}

		~Funcionario(){}

		//alterar salario

}


#endif