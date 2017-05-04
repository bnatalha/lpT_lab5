#include "header.h"
#include "empresa.h"


int main(int argc, char const *argv[])
{
	//CRIAÇÃO DE FUNCIONARIO
	Funcionario marcos("Marcos", "05/03/2016", 12.0);

	cout << "Nome: " << marcos.get_nome() 
		<< " Admissao:" << marcos.get_admissao()
		<< " Salario:" << marcos.get_salario() << endl;

	//CRIÇÃO DE EMPRESA
	Funcionario *lista_a = new Funcionario[3];
	Funcionario *lista_b = new Funcionario[3];

	

	cout << "FIM\n";
	return 0;
}