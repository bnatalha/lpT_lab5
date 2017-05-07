/**
* @file	main.cpp
* @brief Arquivo principal do Programa 1
* @author Natália Azevedo de Brito (https://github.com/bnatalha/)
* @since 04/04/2017
* @date 07/05/2017
* @sa http://www.cplusplus.com/ , http://en.cppreference.com/ 
*/

#include "header.h"
#include "funcionario.h"
#include "empresa.h"

/** 
* @brief Funcao principal 
* @detail Demonstra as funcionalidades da classe Empresa e Funcionario
*/
int main(int argc, char const *argv[])
{
	//CRIAÇÃO DE FUNCIONARIO
	cout << "Criando Funcionarios...";
	Funcionario a("Marcos", "05/03/2016", 12.0);	/*< Funcionário Marcos, admitido em 05/03/2016, com salário de R$12.0 */
	Funcionario b("Marcos", "05/03/2016", 12.0);
	Funcionario c("Beto", "05/03/2017", 12.0);
	Funcionario d("Bolota", "03/05/2017");
	Funcionario e("Joaquina", "24/04/2017");
	Funcionario f("Ladrão", "21/02/2017", 100);
	cout << "Pronto" << endl;

	//LITAS DE FUNCIONARIOS PARA TESTE
	cout << "Criando listas de Funcionarios...";
	list <Funcionario> l_1;
	l_1.push_back(a); l_1.push_back(b); l_1.push_back(c);

	list <Funcionario> l_2;
	l_2.push_back(d); l_2.push_back(e);
	cout << "Pronto" << endl;

	//CRIÇÃO DE EMPRESA
	cout << "Criando Empresas...";
	Empresa A("Ética","07.736.667/001-04");
	Empresa B("Boticário","11.726.431/001-01", l_1);
	cout << "Pronto" << endl;
	cout <<"\n\t\tEmpresa A\n" << A << endl;
	cout <<"\n\t\tEmpresa B\n" << B << endl << endl;

	//	Dar aumento
	cout << "|\tDando aumento para Funcionarios da empressa B de 7,5%...";
	B.dar_aumento_a_todos(7.5);
	cout << "Pronto" << endl;
	cout << "\n\t\tEmpresa B\n" << B << endl << endl;

	//	Adicionar funcionario
	string path_csv("data/my_employees_B.csv");	//	caminho para o arquivo armazenado em string

	cout << "Adicionando Funcionarios...";
	A.add_funcionario(f);
	A.add_funcionario(l_1);
	A.add_funcionario(e);
	A.add_funcionario("data/my_employees_A.csv");
	A.add_funcionario(path_csv);
	cout << "Pronto" << endl;
	cout <<"\n\t\tEmpresa A\n" << A << endl << endl;

	//	Imprimir em experiencia
	A.mostrar_funcionario_em_experiencia();
	cout << endl;
	
	//FIM DOS TESTES
	cout << "FIM\n";
	return 0;
}