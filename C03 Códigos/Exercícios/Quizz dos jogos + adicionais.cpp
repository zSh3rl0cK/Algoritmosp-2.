#include <iostream>
#include <string>
#include <locale.h>
using namespace std;

// Estrutura para representar uma conta de jogador
struct Conta {
    string gamertag;
    string senha;
    string dataNascimento;
};

int main() {
    setlocale(LC_ALL, "Portuguese"); // Definindo o locale para Portugu�s
    
    int pontos = 0;
    
    // Cria��o de uma conta
    Conta jogador;
    
    cout << "Bem-vindo ao Quizz de Jogos Vers�o 1.2.0!" << endl;
    cout << "Para come�ar, crie sua conta." << endl;
    
    // Criando uma nova conta
    cout << "Digite sua gamertag: ";
    cin >> jogador.gamertag;
    
    cout << "Digite sua senha: ";
    cin >> jogador.senha;
    
    cout << "Digite sua data de nascimento (DD/MM/AAAA): ";
    cin >> jogador.dataNascimento;
    
    bool loginSucesso = false; // Vari�vel para verificar se o login foi bem-sucedido
    
    while (!loginSucesso) {
        // Autentica��o do jogador
        string gamertagDigitada, senhaDigitada, dataNascimentoDigitada;
        cout << "\nPara jogar, fa�a login com sua gamertag, senha e data de nascimento." << endl;
        
        cout << "Gamertag: ";
        cin >> gamertagDigitada;
        
        cout << "Senha: ";
        cin >> senhaDigitada;
        
        cout << "Data de Nascimento (DD/MM/AAAA): ";
        cin >> dataNascimentoDigitada;
        
        // Verifica se as informa��es de login est�o corretas
        if (gamertagDigitada == jogador.gamertag && senhaDigitada == jogador.senha && dataNascimentoDigitada == jogador.dataNascimento) {
            cout << "\nLogin bem-sucedido! Vamos come�ar o jogo." << endl;
            loginSucesso = true; // Define loginSucesso como true para sair do loop
        } else {
            cout << "\nLogin falhou. Verifique suas informa��es de login." << endl;
        }
    }
    
    cout << "Responda �s seguintes perguntas para ganhar pontos. Voc� pode pedir uma dica para cada pergunta pressionando 'F':" << endl;

    // Pergunta 1: Qual � o nome do est�dio de desenvolvimento dos jogos da s�rie Batman Arkham?
    cout << "Pergunta 1: Qual � o nome do est�dio de desenvolvimento dos jogos da s�rie Batman Arkham?" << endl;
    cout << "a) Rocksteady Studios\nb) Naughty Dog\nc) CD Projekt Red\nd) Bioware" << endl;
    char resposta1;
    cin >> resposta1;

    if (resposta1 == 'f' || resposta1 == 'F') {
        cout << "Dica: A resposta � 'a'." << endl;
        cout << "Agora, escolha sua resposta: ";
        cin >> resposta1;
    }

    if (resposta1 == 'a' || resposta1 == 'A') {
        pontos++;
    }

    // Pergunta 2: Qual � o t�tulo do primeiro jogo da s�rie Batman Arkham lan�ado em 2009?
    cout << "Pergunta 2: Qual � o t�tulo do primeiro jogo da s�rie Batman Arkham lan�ado em 2009?" << endl;
    cout << "a) Batman: Arkham Asylum\nb) Batman: Arkham City\nc) Batman: Arkham Knight\nd) Batman: Arkham Origins" << endl;
    char resposta2;
    cin >> resposta2;

    if (resposta2 == 'f' || resposta2 == 'F') {
        cout << "Dica: A resposta � 'a'." << endl;
        cout << "Agora, escolha sua resposta: ";
        cin >> resposta2;
    }

    if (resposta2 == 'a' || resposta2 == 'A') {
        pontos++;
    }

    // Pergunta 3: Quem � o criador original do personagem Batman?
    cout << "Pergunta 3: Quem � o criador original do personagem Batman?" << endl;
    cout << "a) Bob Kane\nb) Stan Lee\nc) Jack Kirby\nd) Steve Ditko" << endl;
    char resposta3;
    cin >> resposta3;

    if (resposta3 == 'f' || resposta3 == 'F') {
        cout << "Dica: A resposta � 'a'." << endl;
        cout << "Agora, escolha sua resposta: ";
        cin >> resposta3;
    }

    if (resposta3 == 'a' || resposta3 == 'A') {
        pontos++;
    }

    // Pergunta 4: Adicione a pergunta original 1 aqui
    cout << "Pergunta 4: Quem � o membro mais absolutista do grupo?" << endl;
    cout << "a) Bia\nb) Pedro\nc) Maria\nd) Felipe" << endl;
    char resposta4;
    cin >> resposta4;

    if (resposta4 == 'f' || resposta4 == 'F') {
        cout << "Dica: A resposta � 'a'." << endl;
        cout << "Agora, escolha sua resposta: ";
        cin >> resposta4;
    }

    if (resposta4 == 'a' || resposta4 == 'A') {
        pontos++;
    }

    // Pergunta 5: Adicione a pergunta original 2 aqui
    cout << "Pergunta 5: Qual o presente que voc� comprou pro seu pai?" << endl;
    cout << "a) God of War Ragnarok\nb) The Legend of Zelda: Breath of the Wild\nc) Super Mario Odyssey\nd) Red Dead Redemption 2" << endl;
    char resposta5;
    cin >> resposta5;

    if (resposta5 == 'f' || resposta5 == 'F') {
        cout << "Dica: A resposta � 'a'." << endl;
        cout << "Agora, escolha sua resposta: ";
        cin >> resposta5;
    }

    if (resposta5 == 'a' || resposta5 == 'A') {
        pontos++;
    }

    // Pergunta 6: Adicione a pergunta original 3 aqui
    cout << "Pergunta 6: Por que voc� t� jogando isso?" << endl;
    cout << "a) Porque o Pedro mandou o c�digo\nb) Porque eu quero\nc) Porque parece interessante\nd) Foda-se o por que, acaba logo" << endl;
    char resposta6;
    cin >> resposta6;

    if (resposta6 == 'f' || resposta6 == 'F') {
        cout << "Dica: A resposta � 'a'." << endl;
        cout << "Agora, escolha sua resposta: ";
        cin >> resposta6;
    }

    if (resposta6 == 'a' || resposta6 == 'A') {
        pontos++;
    }

    // Exibir resultado
    cout << "Voc� marcou " << pontos << " pontos de um total de 6." << endl;
    if (pontos == 6) {
        cout << "Parab�ns! Voc� acertou todas as perguntas, mesmo com as dicas." << endl;
    } else {
        cout << "Voc� fez um bom esfor�o! Essas perguntas eram dif�ceis." << endl;
    }

	cout << "No final isso tudo foi s� uma enrola��o pra eu mandar um feliz anivers�rio." << endl;
	cout << "N�o podia faltar isso n�, o texto gigante da minha empresa l� � so uma fachada que eu sempre fa�o" << endl;
	cout << "E sim, eu ja to mandando agora porque ja ta pronto n� � foda" << endl;
	cout << endl;
	cout << "Feliz Anivers�rio aaaaaaahaaaaaaaahaaaaaaahaaaaaaaaaahaaaaaaaaa" << endl;
	cout << "Bora fingir que n�o tem prova de c�lculo daqui v�rios dias e s� pensar no jutel," << endl;
	cout << "que eu provavelmente n�o vou ent�o vou ficar devendo essa" << endl;
	cout << "Era necess�rio tudo isso? N�o. Mas pq nao fazer se � legal?" << endl;
	
    return 0;
}
