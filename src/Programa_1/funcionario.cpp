/**
* @file	funcionario.cpp
* @brief Implementação dos métodos da classe Funcionario
* @author Natália Azevedo de Brito (https://github.com/bnatalha/)
* @since 04/04/2017
* @date 07/05/2017
* @sa http://www.cplusplus.com/ , http://en.cppreference.com/ 
*/

#include "funcionario.h"

// =================================== verificar dados ===================================
//

/** 
* @brief Funcao Funcionario::get_nome 
* @return Retorna uma string com o nome do Funcionario
*/
string Funcionario::get_nome()
{
	return nome;
}

float Funcionario::get_salario()
{
	return salario;
}

string Funcionario::get_admissao()
{
	return admissao;
}

//alterações
void Funcionario::change_salario(float &new_salary) 
{ 
	salario = new_salary; 
}

void Funcionario::change_nome(string &new_name)
{
	nome = new_name; 
}

void Funcionario::change_admissao(string &new_admission)
{	
	admissao = new_admission; 
}	

//sobrecarga de operadores
ostream& operator<< (ostream &out, Funcionario const a)
{
	out << "Nome: " << a.nome
		<< " Admissao: " << a.admissao
		<< " Salario: R$" << a.salario;
	return out;
}

bool Funcionario::operator== (Funcionario &a)
{
	if (nome == a.nome and 
		admissao == a.admissao and 
		salario == a.salario)
		return true;
	return false;
}

Funcionario& Funcionario::operator= (Funcionario const &a)
{
	nome = a.nome;
	salario = a.salario;
	admissao = a.admissao;
	return *this;
}