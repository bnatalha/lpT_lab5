#ifndef JOGO_H
#define JOGO_H

#include "header.h"
#include "jogador.h"

class Jogo
{
	private:
		//Atributos
		list<Jogador> jogadores;	// Lista de Jogador iniciais;
		list<Jogador> jogadores_aptos;	// Lista de Jogador que será modificada ao decorrer da rodada;
		unsigned int n_jogadores;	// Número de jogadores aptos inicialmente;
	public:
		//Construtor
		Jogo(int &meu_n, list<Jogador> &j)
			: N(meu_n), jogadores(j), jogadores_aptos(j)
		{
			n_jogadores = jogadores.size();
		}

		//Destrutor
		//...

		//Funções
		bool existe_jogador_jogando();

		void jogar_rodada();
		void finalizar_rodada();

		void iniciar_rodada();


		//Sobrecarga de operadores
		//friend ostream& operator<< (ostream& out, Jogo &x);

		//Membros statico
		static int N;	// Valor que será usado como referência para ser acalçado durante o os Jogos.
		static int get_N();
};

#endif