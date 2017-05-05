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

void Empresa::add_funcionario(Funcionario &employee)
{
	lista_f.push_back(employee);
}

void Empresa::add_funcionario(list<Funcionario> &employee_list)
{
	for (list<Funcionario>::iterator it = employee_list.begin(); it != employee_list.end(); it++)
	{
		lista_f.push_back(*it);
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

	string dummy_data;
	string dummy_nome;
	string dummy_sala;
	int lines = 0;

	//contar linhas
	while ( getline(in_stream, dummy_data) ) lines++;

//? //extrair dados
	in_stream.seekg(0); //Volta buffer pro início do stream
	for (int i = 0; i < lines; ++i)
	{
		// extraindo data de adimissão de Funcionario[i]...
		in_stream.ignore(1); // ignora o primeiro '\"'
		getline( in_stream, dummy_data, '\"');

		// extraindo nome de Funcionario[i]...
		in_stream.ignore(2); //	ignora ';' e '\"'
		getline( in_stream, dummy_nome, '\"');

		// extraindo salário de Funcionario[i]...
		in_stream.ignore(1); //	ignora ';'
		getline( in_stream, dummy_sala, '\"');

//?		//atribuindo
		lista_f.push_back(	Funcionario(	dummy_data, dummy_nome, std::stof(	dummy_sala	)	)	);	//Atribuindo um Funcionario rvalue
	}

	in_stream.close();

}

void Empresa::add_funcionario(string &filename)	//Chamar um método de dentro de outro método (?)
{
	// Empresa::add_funcionario(filename.c_str());
	add_funcionario(filename.c_str());
}

//? iterator
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


unsigned int Empresa::qtd_funcionario()
{
	return lista_f.size();
}