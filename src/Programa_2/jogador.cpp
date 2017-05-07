#include "jogador.h"

void Jogador::escolher(escolha_jogador x)	// Muda a escolha do jogador
{
	a_escolha x;
	cout << "Informe qua sua escolha ('0' joga os dados e '1' para): "
	cin >> x;
	cout << nome << " escolheu "
		<< (x.escolha == Jogar?"Jogar.":"Parar.") << endl;
}

void Jogador::jogar_dados()	// Joga os dados para saber qual a pontuação da vez
{
	if(escolha == Jogar)
	{
		cout << "Jogando dados...";
		srand(time(NULL));	// número pseudoaleatorio usando a tempo corrente;
		int d6_1 = (rand() % 6) + 1;	// valor do 1º dado D6;
		int d6_2 = (rand() % 6) + 1;	// valor do 2º dado D6;
		cout << "Pronto." << endl;
		pontuacao = d6_1 + d6_2;	// pontuação da jogada.
		cout << nome << " tirou " << d6_1 << " e " << d6_2 << ", totalizando "
			 << pontuacao << "para esta rodada." << endl;
	}
	else cout << nome << " não joga dados desta vez." << endl;
}

void Jogador::atualizar_situacao(int &valor_N)	// Atualiza a situação do jogador com relação a sua pontuação
{
	if( potuacao == N ) situacao = a_situacao::Ganhou;
	if( potuacao < N ) situacao = a_situacao::Jogando;
	if( potuacao > N ) situacao = a_situacao::Perdeu;
}

string Jogador::get_nome()	// Retorna o nome do Jogador;
{
	return nome;
}

int Jogador::get_pontuacao()	// Retorna a pontuacao agregada do Jogador;
{
	return pontuacao;
}


situação_jogador Jogador::get_situacao()	// Retorna a situação do jogador (Jogando, Ganhou ou Perdendo);
{
	return situacao;
}

escolha_jogador Jogador::get_escolha()	// Retorna a escolha do jogador pra esta rodada (Jogar ou Parar);
{
	return escolha;
}

//Sobrecarga de operadores
friend ostream& operator<< (ostream& out, Jogador& x)
{
	out << "Jogador '" << x.nome << "' tem " << x.pontuacao << " pontos. "
		<< "Situação: "
		<< (x.situacao == Jogando?
			 (x.escolha == Jogar?"Jogando e vai escolher":"Jogando e parou"):
			 (x.situacao == Ganhou?"Ganhou":"Perdeu"))
		<< ".";
	return out;
}