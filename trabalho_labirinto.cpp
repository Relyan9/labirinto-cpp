#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std; 

/* Estrutura principal
O jogo começa com um menu (Iniciar, Regras, Sobre, Gabarito, Sair).

O herói tem atributos: forca, sorte, ouro, vida, além de movimentos.

O jogador escolhe direções (N, S, L, O) para se mover entre locais.

Cada local é tratado com um case dentro de um switch(localAtual).

Alguns locais são armadilhas (ex.: 16, 20, 18, 46, 45), onde o jogador pode morrer ou escapar dependendo da sorte.

O jogo termina quando: O herói chega ao local 24 (saída do labirinto).

Ou quando a vida chega a 0 (GAME OVER).

cada movimento tem uma chance aleatoria de rodar um dado e acontecer algum evento onde o jogador ganha ou perde atributo.

/*/
int main() {
    string nome;
    int forca = 10, sorte = 5, ouro = 0, vida = 3;
    int movimentos = 0;
    int opcaoMenu = 0;
    int localAtual;
    char direcao;
    string input;

    srand(time(NULL)); 

    bool jogando = true;
    while (opcaoMenu != 5) {
        system("cls");
        cout << "==== LABIRINTO ESCURO (M2) ====" << endl;
        cout << "1 - Iniciar Jogo" << endl;
        cout << "2 - Regras" << endl;
        cout << "3 - Sobre" << endl;
        cout << "4 - Gabarito." << endl;
        cout << "5 - Sair" << endl;
        

        cout << "Escolha: "; 
        getline(cin, input);

        if (input.length() > 0) {
            opcaoMenu = input[0] - '0';
        } else {
            cout << "Entrada vazia!\n";
            system("pause");
            continue;}

        if (opcaoMenu == 1) {
            jogando = true;
            cout << "\nDigite o nome do heroi: ";
            getline(cin, nome);// 🔥 evita bug no getline depois

            localAtual = 9; 
            vida = 3; ouro = 0; movimentos = 0; forca = 10; sorte = 5;

            while (localAtual != 24 && vida > 0 && jogando) {
                system("cls");

                cout << "==========================================" << endl;
                cout << " HEROI: " << nome << " | VIDA: " << vida << " | OURO: " << ouro << endl;
                cout << " FORCA: " << forca << " | SORTE: " << sorte << " | PASSO: " << movimentos << endl;
                cout << "==========================================" << endl;
                cout << " LOCAL ATUAL: " << localAtual << endl;

                switch (localAtual) {

                    case 9: {
                        cout << "\n[L] 15 | [S] 19 | [0] SAIR.\nEscolha: ";
                        getline(cin, input);
                        if (input == "0") {
                        jogando = false;
                        break;}
                                        
                        if (input.length() > 0) {
                            direcao = input[0];
                        } else {
                            cout << "Entrada vazia!\n";
                            system("pause");
                            continue;}

                        if (direcao == 'L' || direcao == 'l') localAtual = 15;
                        else if (direcao == 'S' || direcao == 's') localAtual = 19;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 15: {
                        cout << "\n[L] 26 | [O] 9 | [S] 51 | [0] SAIR.\nEscolha: ";
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;}

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;}

                        if (direcao == 'L' || direcao == 'l') localAtual = 26;
                        else if (direcao == 'O' || direcao == 'o') localAtual = 9;
                        else if (direcao == 'S' || direcao == 's') localAtual = 51; 
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}
                    
                    case 51: {
                        cout << "\n[N] 15 | [L] 35 | [0] SAIR.\nEscolha: ";
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;}

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;}

                        if (direcao == 'L' || direcao == 'l') localAtual = 35;
                        else if (direcao == 'N' || direcao == 'n') localAtual = 15;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 35:{
                        cout << "\n[O] 51 | [S] 40 | [0] SAIR.\nEscolha: ";
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;}

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;}

                        if (direcao == 'S' || direcao == 's') localAtual = 40;
                        else if (direcao == 'O' || direcao == 'o') localAtual = 51;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break; }

                    case 40:{
                        cout << "\n[O] 1 | [N] 35 | [0] SAIR.\nEscolha: ";
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;}

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;}

                        if (direcao == 'N' || direcao == 'n') localAtual = 35;
                        else if (direcao == 'O' || direcao == 'o') localAtual = 1;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 16: {
                        cout << "\nUma armadilha mortal foi ativada!\n";
                        int chance = rand() % 100;

                        if (chance < (sorte * 10)) {
                            cout << "Por pouco! Voce escapou!\n";
                            if (sorte > 0) sorte--;

                            localAtual = 1; // 👈 ESCAPOU PRA OUTRO LUGAR
                        } else {
                            cout << "VOCE MORREU! GAME OVER!\n";
                            vida = 0;}

                        system("pause");
                        break;}

                    case 26:{
                        cout << "\n[S] 42 | [O] 15 | [0] SAIR.\nEscolha: ";
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;}

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;}

                        if (direcao == 'O' || direcao == 'o') localAtual = 15;
                        else if (direcao == 'S' || direcao == 's') localAtual = 42;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 42:{
                        cout << "\n[O] 41 | [N] 26 | [0] SAIR.\nEscolha: ";
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;}

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;}

                        if (direcao == 'N' || direcao == 'n') localAtual = 26;
                        else if (direcao == 'O' || direcao == 'o') localAtual = 41;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 41:{
                        cout << "\n[N] 10 | [L] 42 | [0] SAIR.\nEscolha: ";
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;}

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;}

                        if (direcao == 'L' || direcao == 'l') localAtual = 42;
                        else if (direcao == 'N' || direcao == 'n') localAtual = 10;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 10:{
                        cout << "\n[O] 52 | [L] 18 | [S] 41 | [0] SAIR.\nEscolha: "; 
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;}

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;}
                                 
                        if (direcao == 'O' || direcao == 'o') localAtual = 52;
                        else if (direcao == 'L' || direcao == 'l') localAtual = 18;
                        else if (direcao == 'S' || direcao == 's') localAtual = 41;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 52:{
                        cout << "\n[S] 34 | [O] 20 | [L] 10 | [0] SAIR.\nEscolha: ";
                            
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;
                            }

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;
                            }
                        if (direcao == 'O' || direcao == 'o') localAtual =20;
                        else if (direcao == 'L' || direcao == 'l') localAtual = 10;
                        else if (direcao == 'S' || direcao == 's') localAtual = 34;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 20: {
                        cout << "\nUm corredor suspeito...\n";

                        int chance = rand() % 100;

                        if (chance < (sorte * 10)) {
                            cout << "Voce percebeu a armadilha e desviou!\n";
                            if (sorte > 0)
                            sorte--;

                             localAtual = 52;

                        } else {
                            cout << "Era uma armadilha escondida... GAME OVER!\n";
                            vida = 0;
                        }

                        system("pause");
                        break;
                    }

                    case 27:{
                        cout << "\n[L] 41 | [S] 2 | [0] SAIR.\nEscolha: ";
                            
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;
                            }

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;
                            }
                        if (direcao == 'L' || direcao == 'l') localAtual = 41;
                        else if (direcao == 'S' || direcao == 's') localAtual = 2;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 2:{
                        cout << "\n[N] 27 | [L] 32 | [0] SAIR.\nEscolha: ";
                            
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;
                            }

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;
                            }
                        if (direcao == 'N' || direcao == 'n') localAtual = 27;
                        else if (direcao == 'L' || direcao == 'l') localAtual = 32;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 32:{
                        cout << "\n[O] 2 | [L] 7\nEscolha: ";
                            
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;
                            }

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;
                            }
                        if (direcao == 'O' || direcao == 'o') localAtual = 2;
                        else if (direcao == 'L' || direcao == 'l') localAtual = 7;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 7:{
                        cout << "\n[O] 32 | [S] 28 | [0] SAIR.\nEscolha: ";
                            
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;
                            }

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;
                            }
                        if (direcao == 'O' || direcao == 'o') localAtual = 32;
                        else if (direcao == 'S' || direcao == 's') localAtual = 28;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 28:{
                        cout << "\n[N] 7 | [L] 43 | [0] SAIR.\nEscolha: ";
                            
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;
                            }

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;
                            }
                        if (direcao == 'N' || direcao == 'n') localAtual = 7;
                        else if (direcao == 'L' || direcao == 'l') localAtual = 43;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 43:{
                        cout << "\n[O] 28 | [N] 17 | [0] SAIR.\nEscolha: ";
                            
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;
                            }

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;
                            }
                        if (direcao == 'O' || direcao == 'o') localAtual = 28;
                        else if (direcao == 'N' || direcao == 'n') localAtual = 17;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 17:{
                        cout << "\n[S] 43 | [N] 18 | [0] SAIR.\nEscolha: ";
                            
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;
                            }

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;
                            }
                        if (direcao == 'S' || direcao == 's') localAtual = 43;
                        else if (direcao == 'N' || direcao == 'n') localAtual = 18;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 18: {
                        cout << "\nABISMO!\n";

                        int chance = rand() % 100;

                        if (chance < (sorte * 10)) {
                            cout << "Voce se segurou na borda e escapou!\n";
                            if (sorte > 0)
                            sorte--;

                             localAtual = 10; 

                        } else {
                            cout << "Voce caiu... GAME OVER!\n";
                            vida = 0;
                        }

                        system("pause");
                        break;
                    }
                    

                    case 19: {
                        cout << "\nCaminho sem saida...\n";
                        cout << "Voce tenta achar uma saida usando sua sorte...\n";

                        int tentativa = rand() % 100; // 0 a 99

                        if (tentativa < (sorte * 10)) {
                        cout << "\nSUA SORTE TE SALVOU!\n";
                        cout << "Voce conseguiu voltar para o ponto 9.\n";
                        localAtual = 9;

                        if (sorte > 0)
                            sorte--;// 👈 usa a sorte
                    } else {
                        cout << "\nVoce se perdeu completamente no labirinto...";
                        cout << "\nGAME OVER!\n";
                        vida = 0;
                    }

                        system("pause");
                        break;
                    }
                    case 1:{
                        cout << "\n[N] 16 | [L] 40 | [0] SAIR.\nEscolha: ";
                            
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;
                            }

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;
                            }
                        if (direcao == 'N' || direcao == 'n') localAtual = 16;
                        else if (direcao == 'L' || direcao == 'l') localAtual = 40;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 34:{
                        cout << "\n[O] 14 | [N] 52 | [0] SAIR.\nEscolha: ";
                            
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;
                            }

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;
                            }
                        if (direcao == 'N' || direcao == 'n') localAtual = 52;
                        else if (direcao == 'O' || direcao == 'o') localAtual = 14;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 14:{
                        cout << "\n[S] 36 | [L] 34 | [0] SAIR.\nEscolha: ";
                            
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;
                            }

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;
                            }
                        if (direcao == 'L' || direcao == 'l') localAtual = 34;
                        else if (direcao == 'S' || direcao == 's') localAtual = 36;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 36:{
                        cout << "\n[O] 8 | [N] 14 | [0] SAIR.\nEscolha: ";
                            
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;
                            }

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;
                            }
                        if (direcao == 'N' || direcao == 'n') localAtual = 14;
                        else if (direcao == 'O' || direcao == 'o') localAtual = 8;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 8:{
                        cout << "\n[S] 31 | [L] 36 | [0] SAIR.\nEscolha: ";
                            
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;
                            }

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;
                            }
                        if (direcao == 'L' || direcao == 'l') localAtual = 36;
                        else if (direcao == 'S' || direcao == 's') localAtual = 31;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 46: {
                        cout << "\nArmadilha ativada!\n";

                        int chance = rand() % 100;

                        if (chance < (sorte * 10)) {
                            cout << "Reflexos rapidos! Voce escapou!\n";
                            if (sorte > 0)
                            sorte--;

                            localAtual = 8;
                        } else {
                            cout << "Nao deu tempo... GAME OVER!\n";
                            vida = 0;
                        }

                        system("pause");
                        break;
                    }

                    case 31:{
                        cout << "\n[L] 4 | [N] 8 | [0] SAIR.\nEscolha: ";
                            
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;
                            }

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;
                            }
                        if (direcao == 'N' || direcao == 'n') localAtual = 8;
                        else if (direcao == 'L' || direcao == 'l') localAtual = 4;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 4:{
                        cout << "\n[N] 54 | [O] 31 | [0] SAIR.\nEscolha: ";
                            
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;
                            }

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;
                            }
                        if (direcao == 'O' || direcao == 'o') localAtual = 31;
                        else if (direcao == 'N' || direcao == 'n') localAtual = 54;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 45:{
                        cout << "\nUm gas toxico encheu o corredor... voce nao resistiu.\n";
                        vida = 0;
                        break;
                    }

                    case 54:{
                        cout << "\n[N] 59 | [S] 4 | [O] 45 | [0] SAIR.\nEscolha: ";
                            
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;
                            }

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;
                            }
                        if (direcao == 'S' || direcao == 's') localAtual = 4;
                        else if (direcao == 'N' || direcao == 'n') localAtual = 59;
                        else if (direcao == 'O' || direcao == 'o') localAtual = 45;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 59:{
                        cout << "\n[L] 44 | [S] 54 | [0] SAIR.\nEscolha: ";
                            
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;
                            }

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;
                            }
                        if (direcao == 'L' || direcao == 'l') localAtual = 44;
                        else if (direcao == 'S' || direcao == 's') localAtual = 54;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}
                    
                    case 44:{
                        cout << "\n[N] 3 | [O] 59 | [0] SAIR.\nEscolha: ";
                            
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;
                            }

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;
                            }
                        if (direcao == 'O' || direcao == 'o') localAtual = 59;
                        else if (direcao == 'N' || direcao == 'n') localAtual = 3;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 3:{
                        cout << "\n[L] 25 | [S] 44 | [0] SAIR.\nEscolha: ";
                            
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;
                            }

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;
                            }
                        if (direcao == 'S' || direcao == 's') localAtual = 44;
                        else if (direcao == 'L' || direcao == 'l') localAtual = 25;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 25:{
                        cout << "\n[S] 62 | [O] 3 | [0] SAIR.\nEscolha: ";
                            
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;
                            }

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;
                            }
                        if (direcao == 'S' || direcao == 's') localAtual = 62;
                        else if (direcao == 'O' || direcao == 'o') localAtual = 3;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 62:{
                        cout << "\n[O] 11 | [N] 25 | [0] SAIR.\nEscolha: ";
                            
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;
                            }

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;
                            }
                        if (direcao == 'N' || direcao == 'n') localAtual = 25;
                        else if (direcao == 'O' || direcao == 'o') localAtual = 11;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 11:{
                        cout << "\n[S] 21 | [L] 62 | [0] SAIR.\nEscolha: ";
                            
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;
                            }

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;
                            }
                        if (direcao == 'S' || direcao == 's') localAtual = 21;
                        else if (direcao == 'L' || direcao == 'l') localAtual = 62;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 29:{
                        cout << "\n[S] 49 | [L] 53 | [0] SAIR.\nEscolha: ";
                            
                            getline(cin, input);

                            if (input == "0") {
                            jogando = false;
                            break;
                            }

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;
                            }
                        if (direcao == 'S' || direcao == 's') localAtual = 49;
                        else if (direcao == 'L' || direcao == 'l') localAtual = 53;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 49:{
                        cout << "\n[L] 56 | [N] 29 | [0] SAIR.\nEscolha: ";
                            
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;
                            }

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;
                            }
                        if (direcao == 'N' || direcao == 'n') localAtual = 29;
                        else if (direcao == 'L' || direcao == 'l') localAtual = 56;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 56:{
                        cout << "\n[S] 23 | [L] 49 | [0] SAIR.\nEscolha: ";
                            
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;
                            }

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;
                            }
                        if (direcao == 'S' || direcao == 's') localAtual = 23;
                        else if (direcao == 'L' || direcao == 'l') localAtual = 49;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 23:{
                        cout << "\n[L] 47 | [N] 56 | [0] SAIR.\nEscolha: ";
                            
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;
                            }

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;
                            }
                        if (direcao == 'L' || direcao == 'l') localAtual = 47;
                        else if (direcao == 'N' || direcao == 'n') localAtual = 56;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 5:{
                        cout << "\n[L] 23 | [N] 58 | [0] SAIR.\nEscolha: ";
                            
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;
                            }

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;
                            }
                        if (direcao == 'L' || direcao == 'l') localAtual = 23;
                        else if (direcao == 'N' || direcao == 'n') localAtual = 58;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 58:{
                        cout << "\n[S] 5 | [O] 13 | [0] SAIR.\nEscolha: ";
                            
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;
                            }

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;
                            }
                        if (direcao == 'S' || direcao == 's') localAtual = 5;
                        else if (direcao == 'O' || direcao == 'o') localAtual = 13;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 13:{
                        cout << "\n[L] 58 | [S] 38 | [0] SAIR.\nEscolha: ";
                            
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;
                            }

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;
                            }
                        if (direcao == 'S' || direcao == 's') localAtual = 38;
                        else if (direcao == 'L' || direcao == 'l') localAtual = 58;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 38: {
                        cout << "\nVoce caiu em um buraco!\n";

                        int chance = rand() % 100;

                        if (chance < (sorte * 10)) {
                            cout << "Voce conseguiu se salvar!\n";
                            if (sorte > 0)
                            sorte--;

                            localAtual = 13;

                        } else {
                            cout << "Queda fatal... GAME OVER!\n";
                            vida = 0;
                        }

                        system("pause");
                        break;}
                

                    case 47:{
                        cout << "\n[N] 33 | [O] 23 | [0] SAIR.\nEscolha: ";
                            
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;
                            }

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;
                            }
                        if (direcao == 'N' || direcao == 'n') localAtual = 33;
                        else if (direcao == 'O' || direcao == 'o') localAtual = 23;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 33:{
                        cout << "\n[L] 6 | [S] 47 | [O] 57 | [0] SAIR.\nEscolha: ";
                            
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;
                            }

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;
                            }
                        if (direcao == 'L' || direcao == 'l') localAtual = 6;
                        else if (direcao == 'S' || direcao == 's') localAtual = 47;
                        else if (direcao == 'O' || direcao == 'o') localAtual = 57;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 57: {
                        cout << "\nATAQUE DE ARANHAS!\n";

                        int chance = rand() % 100;

                        if (chance < (sorte * 10)) {
                            cout << "Voce espantou as aranhas e fugiu!\n";
                            if (sorte > 0)
                            sorte--;

                             localAtual = 33;

                        } else {
                            cout << "As aranhas te dominaram... GAME OVER!\n";
                            vida = 0;
                        }

                        system("pause");
                        break;}

                    case 39:{
                        cout << "\n[N] 53 | [L] 21 | [0] SAIR.\nEscolha: ";
                            
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;
                            }

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;
                            }
                        if (direcao == 'N' || direcao == 'n') localAtual = 53;
                        else if (direcao == 'L' || direcao == 'l') localAtual = 21;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 53:{
                        cout << "\n[O] 29 | [S] 39 | [0] SAIR.\nEscolha: ";
                            
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;
                            }

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;
                            }
                        if (direcao == 'S' || direcao == 's') localAtual = 39;
                        else if (direcao == 'O' || direcao == 'o') localAtual = 29;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 21:{
                        cout << "\n[O] 39 | [N] 11 | [0] SAIR.\nEscolha: ";
                            
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;
                            }

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;
                            }
                        if (direcao == 'O' || direcao == 'o') localAtual = 39;
                        else if (direcao == 'N' || direcao == 'n') localAtual = 11;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 22:{
                        cout << "\n[O] 53 | [L] 30 | [0] SAIR.\nEscolha: ";
                            
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;
                            }

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;
                            }
                        if (direcao == 'O' || direcao == 'o') localAtual = 53;
                        else if (direcao == 'L' || direcao == 'l') localAtual = 30;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 30:{
                        cout << "\n[O] 22 | [N] 50 | [0] SAIR.\nEscolha: ";
                            
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;
                            }

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;
                            }
                        if (direcao == 'O' || direcao == 'o') localAtual = 22;
                        else if (direcao == 'N' || direcao == 'n') localAtual = 50;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 50:{
                        cout << "\nArmadilha fatal ativada! GAME OVER!";
                        vida = 0;
                        break;}

                    case 6:{
                        cout << "\n[S] 60 | [O] 33 | [0] SAIR.\nEscolha: ";
                            
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;
                            }

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;
                            }
                        if (direcao == 'O' || direcao == 'o') localAtual = 33;
                        else if (direcao == 'S' || direcao == 's') localAtual = 60;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 60:{
                        cout << "\nO FINAL ESTA PROXIMO!\n[N] 6 | [L] 24 | [0] SAIR.\nEscolha: ";
                            
                            getline(cin, input);
                            if (input == "0") {
                            jogando = false;
                            break;
                            }

                            if (input.length() > 0) {
                                direcao = input[0];
                            } else {
                                cout << "Entrada vazia!\n";
                                system("pause");
                                continue;
                            }
                        if (direcao == 'L' || direcao == 'l') localAtual = 24;
                        else if (direcao == 'N' || direcao == 'n') localAtual = 6;
                        else { cout << "Invalido!\n"; system("pause"); }
                        break;}

                    case 24: {
                        cout << "\nVoce encontrou a saida... mas algo esta errado...\n";

                        int chance = rand() % 100;

                        int poder = (forca * 2) + (sorte * 10) + (ouro * 5) + (vida * 15);

                        if (poder > 90) poder = 90;

                        if (chance < poder) {
                            cout << "\nVOCE SOBREVIVEU AO DESAFIO FINAL!\n";
                            cout << "Voce escapou do labirinto!\n";
                        } else {
                            cout << "\nUMA ARMADILHA FINAL TE PEGOU!\n";
                            vida = 0;
                        }

                        system("pause");
                        break;
                    }

                    default:
                        cout << "\nERRO: area " << localAtual << " nao implementada!";
                        system("pause");
                        break;
                }

                if (vida > 0 && localAtual != 24) {
                    movimentos++;

                    if (rand() % 100 < 30) { // 30% de chance por turno
                        int evento = rand() % 6; // 6 possibilidade // 0 ate 5 //

                        switch (evento) {
                            case 0:
                                cout << "\nPassou de raspao por uma armadilha! Voce perdeu 1 de vida!\n";
                                vida--;
                                break;

                            case 1:
                                cout << "\nSorte encontrada! +1 sorte.\n";
                                sorte++;
                                break;

                            case 2:
                                cout << "\nVoce encontrou ouro! +1 de Ouro.\n";
                                ouro++;
                                break;

                            case 3:
                                cout << "\nEncontrou uma pocao! +1 forca.\n";
                                forca++;
                                break;

                            case 4:
                                cout << "\nVoce foi picado por um bixo misterioso, ferimento leve... -1 vida\n";
                                vida--;
                                break;

                            case 5:
                                cout << "\nEncontrou uma fonte de agua! +1 vida\n";
                                vida++;
                                break;
                        }

                        system("pause");
                    }
                }
            }

            system("cls");

            if (!jogando) {
                cout << "Voce saiu do jogo.\n";
            }
            else if (vida <= 0) {
                cout << "GAME OVER, " << nome << endl;
            }
            else {
                cout << "VITORIA, " << nome << "!\n";
            }

            cout << "Movimentos: " << movimentos << endl;
            cout << "Ouro: " << ouro << endl;
            cout << "Vida: " << vida << endl;
            cout << "forca: " << forca << endl;
            cout << "Sorte: " << sorte << endl;


            system("pause");
        }

        else if (opcaoMenu == 2) {
            system("cls");
            cout << "--- REGRAS ---\n";
            cout << "1. Para se mover use as letras: N para NORTE, S para SUL, L para LESTE e O para o OESTE.\n";
            cout << "2. Tente evitar perigos mortais como abismos e o acougueiro. Acho dificil, pois voce estara no escuro hahahaha...\n";
            cout << "3. A cada turno voce tem chance de ganha ou perde vida, sorte, forca ouro.\n";
            cout << "4. Venca ao chegar ao ponto 24.\n";
            cout << "5. O jogo termina apenas ao escolher a opcao do menu 'Sair'.\n";

            system("pause");
        }

        else if (opcaoMenu == 3) {
            system("cls");
            cout << "--- SOBRE ---\n";
            cout << "Universidade do Vale do Itajai. (UNIVALI).\n";
            cout << "Curso: Ciencia da Computacao.\n";
            cout << "Disciplina: Algoritmos e Programacao.\n";
            cout << "Professor(a): Cristina Ono Horita.\n";
            cout << "Desenvolvedores: Helian e equipe.\n";

            system("pause");
        }

        else if (opcaoMenu == 4) {
            system("cls");
            cout << "--- GABARITO DO LABIRINTO ---\n";
            cout << "1 - Escolha sempre a primeira opcao.\n";
            cout << "2 - QUANDO APARECER A MSG 'O FINAL ESTA PROXIMO' ESCOLHA A SEGUNDA OPCAO. :3.\n";
            cout << "3 - Porem cuidado! o RNG do jogo pode te matar antes.";

            system("pause");
        }
        else if (opcaoMenu != 5) {
            cout << "\nValor invalido! Escolha uma das opcoes acima.\n";
            system("pause");
}
    }
    return 0;
}