#include "jogo.h"

static int Jogo::get_N()
{
	return N;
}

bool Jogo::existe_jogador_jogando()
{
	for (list<Jogador>::iterator it = jogadores_aptos.begin() ; it != jogadores_aptos.end(); it++)
	{
		if( (*it).get_situacao() == a_situacao::Jogando ) return true;
	}
	return false;
}

void Jogo::remover_jogadores_nao_aptos()
{
	list<Jogador>::iterator it = jogadores_aptos.begin();
	list<Jogador>::iterator perdedor;
	while( it != jogadores_aptos.end() )
	{
		if( (*it).get_situacao() == a_situacao::Perdeu )
		{
			perdedor = it++;
			jogadores_aptos.remove(*perdedor);
		}
		else it++;
	}
}

void Jogo::jogar_rodada()
{
	do
	{
		// Por vez
		int vez = 0;
		unsigned int n_jogadores_aptos = jogadores_aptos.size();
		int maior_pontuacao_parado = 0;
		cout << "============== Jogada " << vez << " ==============\n";
		for (list<Jogador>::iterator it = jogadores_aptos.begin() ; it != jogadores_aptos.end(); it++)
		{
			cout << "-------------- Jogador: " << (*it).get_nome() << "--------------\n";
			
			(*it).escolher();

			if( (*it).get_escolha() == a_escolha::Jogar)	//Se jogador optou por jogar
			{
				(*it).jogar_dados();

				if ( (*it).get_pontuacao() > N ) //remove da lista de aptos
				{
					cout << (*it).get_nome() << " ultrapassou " << N << " e está fora do jogo. ):" << endl;
					(*it).
				}

				if ( (*it).get_pontuacao() == N ) //remove da lista de aptos
				{
					cout << (*it).get_nome() << " ultrapassou " << N << " e está fora do jogo. ):" << endl;
				}

				(*it).atualizar_situacao();
			}
		}
		cout << "============== FIM de Jogada " << vez << " ==============\n";
		cout << "Removendo jogadores que estouraram o valor" << N << "...";
		remover_jogadores_nao_aptos();
		cout << "Pronto" << endl;

		//Comparar pontuacoes.
			//se houver ganhadores, imprimmi-los, fim rodada.
			//senao. fim jogada
		
	} while(existe_jogador_jogando());

}

void Jogo::finalizar_rodada()
{
	//mostra valor agregado de todos
	//mostra campeão
}

void Jogo::iniciar_rodada()
{
	cout << "Valor de N = " << N << "." 
		<< "\nLista de Jogadores: [";

	for (list<Jogador>::iterator it = jogadores.begin() ; it != jogadores.end(); it++)
	{
		cout << "_" << (*it).get_nome();
	}
	cout << "_]." << endl

	cout << ">> Começa jogo." << endl;

	jogar_rodada();
	finalizar_rodada();
}