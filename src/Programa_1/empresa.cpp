/**
* @file	empresa.cpp
* @brief Implementação dos métodos da classe Empresa
* @author Natália Azevedo de Brito (https://github.com/bnatalha/)
* @since 04/04/2017
* @date 07/05/2017
* @sa std::list (http://www.cplusplus.com/reference/list/list/list/)
*/

#include "empresa.h"

/**
* @param out Referência para um objeto ostream
* @param a Referência para um objeto Empresa
* @return Referência para o objeto ostream out
*/
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

/**
* @param employee funcionário procurado
* @return True se já existir na lista da empresa, False caso contrário.
*/
bool Empresa::funcionario_ja_existe(Funcionario &employee)
{
	for (list<Funcionario>::iterator it = lista_f.begin(); it != lista_f.end(); it++)
	{
		if( (*it) == employee ) return true;
	}
	return false;
}

/**
* @param employee Funcionário a ser adicionados à lista da empresa
*/
void Empresa::add_funcionario(Funcionario &employee)
{
	if(funcionario_ja_existe(employee) == false) lista_f.push_back(employee);
}

/**
* @param employee_list Lista de funcionários a serem adicionados à lista da empresa
*/
void Empresa::add_funcionario(list<Funcionario> &employee_list)
{
	for (list<Funcionario>::iterator it = employee_list.begin(); it != employee_list.end(); it++)
	{
		if(funcionario_ja_existe(*it) == false) lista_f.push_back(*it);
	}
}

/**
* @details O arquivo .csv a ser lido deve conter em \b cada linha: "NOME_FUNCIONÁRIO";"DATA/DE/ADMISSAO";SALARIO 
* @param filename String no estilo C com o caminho para o arquivo .csv com os dados dos funcionários a serem adicionados
*/
void Empresa::add_funcionario(const char *filename)
{
	ifstream in_stream(filename); /*< stream de entrada para o arquivo a ser lido */

	if(!in_stream)
	{
		cerr << "Não foi possível encontrar '" << filename << "'." << endl;
		exit(1);
	}

	//else

	Funcionario dummy;	/*< Armazena informações do funcionário extraídas do stream */
	float dummy_sala;	/*< Armazenará o salário do funcionário extraído do stream */
	string dummy_admi;	/*< Armazenará a data de admissão do funcionário extraído do stream */
	string dummy_nome;	/*< Armazenará o nome do funcionário extraído do stream */
	
	while ( in_stream.tellg() != -1)
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

/**
* @param filename String com o caminho para o arquivo .csv com os dados dos funcionários a serem adicionados
*/
void Empresa::add_funcionario(string &filename)	//Chamar um método de dentro de outro método (?)
{
	add_funcionario(filename.c_str());
}

/**
* @param raise_rate float com a porcentagem de quanto será aumentado
*/
void Empresa::dar_aumento_a_todos(float raise_rate)
{
	float total_raise; /*< Armazena o valor do salário após reajuste */

	for (list<Funcionario>::iterator it = lista_f.begin(); it != lista_f.end(); it++)
	{
		total_raise = (*it).get_salario() * raise_rate / 100.0 + (*it).get_salario();
		(*it).change_salario(total_raise);
	}
}

/**
* @return Tamanho da lista de funcionários da empresa
*/
unsigned int Empresa::qtd_funcionario()
{
	return lista_f.size();
}

/**
* @return Inteiro equivalendo a quantidade de dias entre hoje e o dia que o funcionário foi admitido na empresa
* @sa Baseada nesta função (http://www.cplusplus.com/reference/chrono/system_clock/from_time_t/)
*/
int Empresa::dias_desde_entrada(Funcionario &employee)
{
	using namespace std::chrono;

	string dia(employee.get_admissao().begin(),   employee.get_admissao().begin()+2);	/*< Armazena dia de admissão do funcionário */
	string mes(employee.get_admissao().begin()+3, employee.get_admissao().begin()+5);	/*< Armazena mês de admissão do funcionário */
	string ano(employee.get_admissao().begin()+6, employee.get_admissao().end());	/*< Armazena ano de admissão do funcionário */

	std::tm timeinfo = std::tm();	/*< Inicializa uma estrutura tm com seu construtor */
	timeinfo.tm_year = stoi(ano) - 1900;	/*< 0 = 1900, 1 = 1901... */
	timeinfo.tm_mon = stoi(mes) - 1;	/*< 0 = janeiro, 1 = fevereiro... */
	timeinfo.tm_mday = stoi(dia);	/*< 1 = 1º dia do mês, 2 = 2º dia do mês... */
	std::time_t tt = std::mktime (&timeinfo);	/*< converte de std::tm para time_t */

	system_clock::time_point tp = system_clock::from_time_t (tt); /*< Converte timeinfo para time_t */
	system_clock::duration d = system_clock::now() - tp;	/*< Calcula a diferença de tempo 'd' entre a admissão do funcionário e agora*/

	// converte tempo de duração para dias
	typedef duration<int,std::ratio<60*60*24>> days_type;
	days_type ndays = duration_cast<days_type> (d);	/*< Transforma 'd' em dias e armazena em 'ndays' */

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
