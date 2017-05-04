#include "header.h"
#include "funcionario.h"
//#include "empresa.h"

int main(int argc, char const *argv[])
{
	//CRIAÇÃO DE FUNCIONARIO
	Funcionario a("Marcos", "05/03/2016", 12.0);
	Funcionario b("Marcos", "05/03/2016", 12.0);
	Funcionario c("Beto", "05/03/2017", 12.0);

	cout << (a==b?"s":"n") << " ";	//s
	cout << (b==a?"s":"n") << " ";	//s
	cout << (a==c?"s":"n") << " ";	//n
	cout << (c==a?"s":"n") << " " << endl;	//n

	cout << a << endl << b << endl << c << endl;



	//CRIÇÃO DE EMPRESA
	//Funcionario *lista_a = new Funcionario[3];
	//Funcionario *lista_b = new Funcionario[3];

	

	cout << "FIM\n";
	return 0;
}