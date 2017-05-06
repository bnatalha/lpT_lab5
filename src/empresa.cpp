/**
*
* @sa std::list (http://www.cplusplus.com/reference/list/list/list/)
*/

#include "empresa.h"

//sobrecarga de <<
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
	string dummy_admi;
	string dummy_nome;
	
	while ( in_stream.tellg() != -1) // algo q possa usar .end
	{
		// ex linha :  "14/12/2016";"Marcos Ninja";5

		// extraindo data de adimissão de Funcionario[i]...
		in_stream.ignore(1); // ignora o primeiro '\"'
		getline( in_stream, dummy_admi, '\"');
		// atribuindo a funcionário  dummy
		dummy.change_admissao(dummy_admi); 
		
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


// Função baseada em Exemplo de http://www.cplusplus.com/reference/chrono/system_clock/from_time_t/
int Empresa::dias_desde_entrada(Funcionario &employee)
{
	using namespace std::chrono;

	string dia(employee.get_admissao().begin(),   employee.get_admissao().begin()+2);	// armazena dia de admissão
	string mes(employee.get_admissao().begin()+3, employee.get_admissao().begin()+5);	// armazena mês de admissão
	string ano(employee.get_admissao().begin()+6, employee.get_admissao().end());	// armazena ano de admissão

	// cria um std::tm com informações do dia de admissão
	std::tm timeinfo = std::tm();	// ?
	timeinfo.tm_year = stoi(ano) - 1900;	// 0 = 1900, 1 = 1901...
	timeinfo.tm_mon = stoi(mes) - 1;	// 0 = janeiro, 1 = fevereiro...
	timeinfo.tm_mday = stoi(dia);	// 1 = 1º dia do mês, 2 = 2º dia do mês...
	std::time_t tt = std::mktime (&timeinfo);	// converte de std::tm para time_t

	system_clock::time_point tp = system_clock::from_time_t (tt);
	system_clock::duration d = system_clock::now() - tp;

	// converte tempo de duração para dias
	typedef duration<int,std::ratio<60*60*24>> days_type;
	days_type ndays = duration_cast<days_type> (d);

	return ndays.count();
}


void Empresa::mostrar_funcionario_em_experiencia()
{

	cout << "Lista de funcionários em período de experiência da empresa " << nome <<":\n{\n";
	for (list<Funcionario>::iterator it = lista_f.begin(); it != lista_f.end(); it++)
	{
		if(dias_desde_entrada(*it) <= 90) cout << "\t"<< (*it) << endl;
	}
	cout << "}";
}
