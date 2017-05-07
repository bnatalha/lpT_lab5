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
* @return string com o nome do funcionário
*/
string Funcionario::get_nome()
{
	return nome;
}

/** 
* @return float com o salário do funcionário
*/
float Funcionario::get_salario()
{
	return salario;
}

/** 
* @return string com a data de adimissão do funcionário no fomato dd/mm/aaaa
*/
string Funcionario::get_admissao()
{
	return admissao;
}

// ======================================== alterações ======================================

/**
* @param new_salary Referência para um float que vai ser o novo salário do funcionário 
*/
void Funcionario::change_salario(float &new_salary) 
{ 
	salario = new_salary; 
}

/**
* @param new_nome Referência para um string que vai ser o novo nome do funcionário 
*/
void Funcionario::change_nome(string &new_name)
{
	nome = new_name; 
}

/**
* @param new_salary Referência para um string que vai ser a nova data de admissão do funcionário
*/
void Funcionario::change_admissao(string &new_admission)
{	
	admissao = new_admission; 
}	

// =============================== sobrecarga de operadores ================================

/**
* @param out Referência para um objeto ostream
* @param a Referência para um objeto Funcionario constante
* @return Referência para o objeto ostream out
*/
ostream& operator<< (ostream &out, Funcionario const a)
{
	out << "Nome: " << a.nome
		<< " Admissao: " << a.admissao
		<< " Salario: R$" << a.salario;
	return out;
}

/**
* @param a Referência para um objeto Funcionario
* @return True se os funcionários forem iguais em todos atributos; em outrocaso, False
*/
bool Funcionario::operator== (Funcionario &a)
{
	if (nome == a.nome and 
		admissao == a.admissao and 
		salario == a.salario)
		return true;
	return false;
}