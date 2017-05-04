#include "empresa.h"

void Empresa::add_funcionario(Funcionario &employee)

void Empresa::add_funcionario(list<Funcionario> *&employee_list)

void Empresa::add_funcionario(const char *filename)
{
	// Leitura por csv
	ifstream in_stream(filename);

	if(!in_stream)
	{
		cerr << "Não foi possível encontrar '" << filename << "'." << endl;
		exit(1);
	}



}

void Empresa::add_funcionario(string &filename)	//Chamar um método de dentro de outro método (?)
{
	// Empresa::add_funcionario(filename.c_str());
	add_funcionario(filename.c_str());
}


unsigned int Empresa::qtd_funcionarios()
{
	return lista_p.size();
}

#endif
