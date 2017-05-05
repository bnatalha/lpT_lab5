/**
*
* @sa std::list (http://www.cplusplus.com/reference/list/list/list/)
*/

#include "empresa.h"

ostream& operator<< (ostream &out, Empresa &a)
{

	out << "Empresa: " << a.nome 
		<< " CNPJ: " << a.cnpj 
		<< "\nFuncionarios: " << a.qtd_funcionario();
	if(a.qtd_funcionario() > 0u)	
	{
		out << "\n{\n";
		for (list<Funcionario>::iterator it = a.lista_f.begin(); it != a.lista_f.end(); it++)
		{
			out << "\t[ " << *it << " ]" << endl;
		}
		out << "}";
	}

	return out;
}

//auxilia em adicionar funcionarios
bool Empresa::funcionario_ja_existe(Funcionario &employee)
{
	for (list<Funcionario>::iterator it = lista_f.begin(); it != lista_f.end(); it++)
	{
		if( (*it) == employee ) return true;
	}
	return false;
}

//adicionar funcionarios
void Empresa::add_funcionario(Funcionario &employee)
{
	if(funcionario_ja_existe(employee) == false) lista_f.push_back(employee);
}

void Empresa::add_funcionario(list<Funcionario> &employee_list)
{
	for (list<Funcionario>::iterator it = employee_list.begin(); it != employee_list.end(); it++)
	{
		if(funcionario_ja_existe(*it) == false) lista_f.push_back(*it);
	}
}

void Empresa::add_funcionario(const char *filename)
{
	// Leitura por csv
	ifstream in_stream(filename);

	if(!in_stream)
	{
		cerr << "Não foi possível encontrar '" << filename << "'." << endl;
		exit(1);
	}

	//else

	Funcionario dummy;
	float dummy_sala;
	string dummy_data;
	string dummy_nome;
	
	while ( in_stream.tellg() != -1) // algo q possa usar .end
	{
		// ex linha :  "14/12/2016";"Marcos Ninja";5

		// extraindo data de adimissão de Funcionario[i]...
		in_stream.ignore(1); // ignora o primeiro '\"'
		getline( in_stream, dummy_data, '\"');
		// atribuindo a funcionário  dummy
		dummy.change_admissao(dummy_data); 
		
		// extraindo nome de Funcionario[i]...
		in_stream.ignore(2); //	ignora ';' e '\"'
		getline( in_stream, dummy_nome, '\"');
		// atribuindo a funcionário  dummy
		dummy.change_nome(dummy_nome); 

		// extraindo salário de Funcionario[i]...
		in_stream.ignore(1); //	ignora ';'
		in_stream >> dummy_sala;
		// atribuindo a funcionário  dummy
		dummy.change_salario(dummy_sala); 

		// ignora '\n' (remasce no buffer por usar ">>" na linha 78 e não getline)
		in_stream.ignore(1);	

		//atribuindo FUNCIONARIO a lista de funcionarios da empresa

		if(funcionario_ja_existe(dummy) == false) lista_f.push_back( dummy );		
	}

	in_stream.close();
}

void Empresa::add_funcionario(string &filename)	//Chamar um método de dentro de outro método (?)
{
	add_funcionario(filename.c_str());
}

//modifica salario de todos
void Empresa::dar_aumento_a_todos(float raise_rate)
{
	float total_raise;

	for (list<Funcionario>::iterator it = lista_f.begin(); it != lista_f.end(); it++)
	{
		// salario_atual
		total_raise = (*it).get_salario() * raise_rate / 100.0 + (*it).get_salario();
		(*it).change_salario(total_raise);
	}
}

//retorna quantidade de funcionarios cadastrados
unsigned int Empresa::qtd_funcionario()
{
	return lista_f.size();
}