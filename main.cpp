#include <iostream>
#include "geral.hpp"
#include "gerente.hpp"
#include "cliente.hpp"
#include <map>

using namespace std;

int main(){

    clear();

    int selecao = 0;
    string senha = "";
    string const SENHAVALIDA = "admin";
    int perfil = 0;
    int sair = 0;
    string nome;
    float preco;

    map<string, float> sanduiches;
    map<string, float> sucos;
    map<string, float> carrinho;

    abrirCardapioSanduiches();
    abrirCardapioSucos();
    
    while (selecao != 3){

        cout << "============================================" << endl;
        cout << "||     Com qual perfil deseja acessar?    ||" << endl;
        cout << "============================================" << endl;
        cout << "|| 1 - Gerente                            ||" << endl;
        cout << "|| 2 - Cliente                            ||" << endl;
        cout << "|| 3 - Sair                               ||" << endl;
        cout << "============================================" << endl;

        cout << "Por favor, escolha uma opção válida (1-3): ";
    
        while (!(cin >> selecao)) {
            cout << "Opção inválida. Por favor, escolha uma opção válida (1-3): ";
            cin.clear();
            while (cin.get() != '\n') {}
        }

        switch (selecao) {
            case 1:
                cout << "Perfil [GERENTE] selecionado.\n";
                cout << "Digite a senha: ";
                cin >> senha;
                if (senha == SENHAVALIDA)
                {
                    perfil = 1;
                    selecao = 3;
                } else {
                    cout << "Senha inválida!\n";
                }
                break;
            case 2: 
                cout << "Perfil [CLIENTE] selecionado.\n";
                perfil = 2;
                selecao = 3;
                break;
            case 3:
                clear();
                cout << "Saindo do programa. Até mais!" << endl;
                pressQualquer();
                break;
        }

    };

    selecao = 0;

    while (perfil == 1 && selecao != 7){

        cout << "============================================" << endl;
        cout << "||        O que você deseja fazer?        ||" << endl;
        cout << "============================================" << endl;
        cout << "|| 1 - Ler o cardápio de sanduíches       ||" << endl;
        cout << "|| 2 - Adicionar/Alterar um sanduíche     ||" << endl;
        cout << "|| 3 - Excluir um sanduíche do cardápio   ||" << endl;
        cout << "|| 4 - Ler o cardápio de sucos            ||" << endl;
        cout << "|| 5 - Adicionar/Alterar um suco          ||" << endl;
        cout << "|| 6 - Excluir um suco do cardápio        ||" << endl;
        cout << "|| 7 - Sair                               ||" << endl;
        cout << "============================================" << endl;

        cout << "Por favor, escolha uma opção válida (1-7): ";
    
        while (!(cin >> selecao)) {
            cout << "Opção inválida. Por favor, escolha uma opção válida (1-9): ";
            cin.clear();
            while (cin.get() != '\n') {}
        }

        switch (selecao) {
            case 1:
                clear();
                cout << "[Ler o cardápio de sanduíches]\n";
                listarSanduiches();
                pressQualquer();
                break;
            case 2:
                clear();
                cout << "[Adicionar/Alterar um sanduíche]\n";
                cout << "\nDigite o nome do sanduiche: ";
                cin >> nome;
                cout << "Digite o preco: R$";
                cin >> preco;
                addAltSanduiche(nome, preco);
                pressQualquer();
                break;
            case 3:
                clear();
                cout << "[Excluir um sanduíche do cardápio]\n";
                cout << "\nDigite o nome do sanduiche: ";
                cin >> nome;
                excluirSanduiche(nome);
                cout << nome << " excluido." << endl;
                pressQualquer();
                break;
            case 4:
                clear();
                cout << "[Ler o cardápio de sucos]\n";
                listarSucos();
                pressQualquer();
                break;
            case 5:
                clear();
                cout << "[Adicionar/Alterar um suco]\n";
                cout << "\nDigite o nome do suco: ";
                cin >> nome;
                cout << "Digite o preco: R$";
                cin >> preco;
                addAltSuco(nome, preco);
                pressQualquer();
                break;
            case 6:
                clear();
                cout << "[Excluir um suco do cardápio]\n";
                cout << "\nDigite o nome do suco: ";
                cin >> nome;
                excluirSuco(nome);
                cout << nome << " excluido." << endl;
                pressQualquer();
                break;
            case 7:
                salvarSanduiches();
                salvarSucos();
                clear();
                cout << "Saindo do programa. Até mais!" << endl;
                pressQualquer();
                break;
            default:
                cout << "Opção inválida. Por favor, escolha uma opção válida (1-7)." << endl;
        }
    }

    while (perfil == 2 && selecao != 8){
        
        abrirCarrinho();

        cout << "============================================" << endl;
        cout << "||        O que você deseja fazer?        ||" << endl;
        cout << "============================================" << endl;
        cout << "|| 1 - Ler o cardápio de sanduíches       ||" << endl;
        cout << "|| 2 - Adicionar um sanduíche             ||" << endl;
        cout << "|| 3 - Ler o cardápio de sucos            ||" << endl;
        cout << "|| 4 - Adicionar um suco                  ||" << endl;
        cout << "|| 5 - Ver carrinho                       ||" << endl;
        cout << "|| 6 - Excluir item do carrinho           ||" << endl;
        cout << "|| 7 - Ver valor total do carrinho        ||" << endl;
        cout << "|| 8 - Sair                               ||" << endl;
        cout << "============================================" << endl;

        cout << "Por favor, escolha uma opção válida (1-8): ";
    
        while (!(cin >> selecao)) {
            cout << "Opção inválida. Por favor, escolha uma opção válida (1-8): ";
            cin.clear();
            while (cin.get() != '\n') {}
        }

        switch (selecao) {
            case 1:
                clear();
                cout << "[Ler o cardápio de sanduíches]\n";
                listarSanduiches();
                pressQualquer();
                break;
            case 2:
                clear();
                cout << "[Adicionar um sanduíche]\n";
                cout << "\nDigite o nome do sanduiche: ";
                cin >> nome;
                addSanduicheCarrinho(nome);
                pressQualquer();
                break;
            case 3:
                clear();
                cout << "[Ler o cardápio de sucos]\n";
                listarSucos();
                pressQualquer();
                break;
            case 4:
                clear();
                cout << "[Adicionar um suco]\n";
                cout << "\nDigite o nome do suco: ";
                cin >> nome;
                addSucoCarrinho(nome);
                pressQualquer();
                break;
            case 5:
                clear();
                cout << "[Carrinho]\n";
                verCarrinho();
                pressQualquer();
                break;
            case 6:
                clear();
                cout << "[Excluir um item do carrinho]\n";
                cout << "\nDigite o nome do item: ";
                cin >> nome;
                excluirItemCarrinho(nome);
                cout << nome << " excluido." << endl;
                pressQualquer();
                break;
            case 7:
                clear();
                salvarCarrinho();
                cout << "[Ver valor total do carrinho]\n";
                cout << "Valor: " << calcularValorCarrinho();
                pressQualquer();
                break;
            case 8:
                salvarCarrinho();
                clear();
                cout << "Saindo do programa. Até mais!" << endl;
                pressQualquer();
                break;
            default:
                cout << "Opção inválida. Por favor, escolha uma opção válida (1-8)." << endl;
        }
    }

    return 0;
}