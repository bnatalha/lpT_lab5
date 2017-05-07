#ifndef JOGADOR_H
#define JOGADOR_H

#include "header.h"

#include <ctime>	// para time(), srand() e rand();

enum a_situacao { Jogando = 0, Perdeu, Ganhou };
enum a_escolha { Jogar = 0, Parar };

class Jogador
{	
	//Atriubutos
	private:
		string nome;
		int pontuacao;
		situação_jogador situacao;
		escolha_jogador escolha;
	public:
		//Construtor
		Jogador( string players_name )
			: nome(players_name), pontuação(0), situacao(Jogando) {}	//escolha devia começar com algo?

		//Destrutor (?)

		//Funções
		void escolher(escolha_jogador x);	// Muda a escolha do jogador
		void jogar_dados();	// Joga os dados para saber qual a pontuação da vez
		void atualizar_situacao();	// Atualiza a situaão do jogador com relação a sua pontuação

		string get_nome();	// Retorna o nome do Jogador;
		int get_pontuacao();	// Retorna a pontuacao agregada do Jogador;
		situação_jogador get_situacao();	// Retorna a situação do jogador (Jogando, Ganhou ou Perdendo);
		escolha_jogador get_escolha();	// Retorna a escolha do jogador pra esta rodada (Jogar ou Parar);

		//Sobrecarga de operadores
		friend ostream& operator<< (ostream& out, Jogador& x);
};

#endif