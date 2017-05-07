#include "jogo.h"

static int Jogo::get_N()
{
	return N;
}

bool Jogo::existe_jogador(a_situacao x);
{
	for (list<Jogador>::iterator it = jogadores_aptos.begin() ; it != jogadores_aptos.end(); it++)
	{
		if( (*it).get_situacao() == x ) return true;
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
			// procura o original(mesmo nome) na lista inicial. nao pode ter dois jogadores com o mesmo nome em um jogo.
				// atribui ao original o jogador
			// deleta perdedor da lista de aptos
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
		unsigned int faltam_decidir = jogadores_aptos.size();
		cout << "============== Jogada " << vez << " ==============\n";
		for (list<Jogador>::iterator it = jogadores_aptos.begin() ; it != jogadores_aptos.end(); it++, faltam_decidir--)
		{
			cout << "-------------- Jogador: " << (*it).get_nome() << "--------------\n";
			cout << "Restam: " << faltam_decidir << endl << endl;
			
			(*it).escolher();

			if( (*it).get_escolha() == a_escolha::Jogar)	//Se jogador optou por jogar
			{
				(*it).jogar_dados();

				if ( (*it).get_pontuacao() > N ) // marcajogador para ser excluido da lista de jogadores aptos
					cout << (*it).get_nome() << " ultrapassou " << N << " e está fora do jogo. ):" << endl;
	
				(*it).atualizar_situacao(N);	//Ganhou, Jogando ou Perdeu, com base em N (meta)
			}
		}
		cout << "============== FIM de Jogada " << vez << " ==============\n";
		cout << "Atualizando lista de jogadores aptos" << N << "...";
		remover_jogadores_nao_aptos();
		cout << "Pronto" << endl;

		cout << "Verificando se há vencedores..."
		if ( existe_jogador(a_situacao::Ganhou) )
		{
			cout << "Pronto." << endl;
			break;	// sai do loop while;
		}
		cout << "Pronto." << endl;

		vez++;

	} while(existe_jogador(a_situacao::Jogando));

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