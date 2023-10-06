#include <iostream>
#include "gerente.hpp"

using namespace std;

int main(){

    int selecao;
    string nome;
    float preco;

    void lerCardapioSanduiches();
    void lerCardapioSucos();
    
    do{

        cout << "====================================" << endl;
        cout << "||        O que você deseja fazer?       ||" << endl;
        cout << "====================================" << endl;
        cout << "|| 1 - Ler o cardápio de sanduíches    ||" << endl;
        cout << "|| 2 - Adicionar um sanduíche ao cardápio ||" << endl;
        cout << "|| 3 - Alterar o preço de um sanduíche   ||" << endl;
        cout << "|| 4 - Excluir um sanduíche do cardápio  ||" << endl;
        cout << "|| 5 - Ler o cardápio de sucos          ||" << endl;
        cout << "|| 6 - Adicionar um suco ao cardápio     ||" << endl;
        cout << "|| 7 - Alterar o preço de um suco        ||" << endl;
        cout << "|| 8 - Excluir um suco do cardápio       ||" << endl;
        cout << "|| 9 - Sair                              ||" << endl;
        cout << "====================================" << endl;

        cin >> selecao;

        switch (selecao) {
            case 1:
                listarSanduiches();
                break;
            case 2:
                cout << "\nDigite o nome do sanduiche: ";
                cin >> nome;
                cout << "\nDigite o preco: R$";
                cin >> preco;
                adicionarSanduiche(nome, preco);
                break;
            case 3:
                cout << "\nDigite o nome do sanduiche: ";
                cin >> nome;
                cout << "\nDigite o preco: R$";
                cin >> preco;
                alterarPrecoSanduiche(nome, preco);
                break;
            case 4:
                cout << "\nDigite o nome do sanduiche: ";
                cin >> nome;
                excluirSanduiche(nome);
                break;
            case 5:
                listarSucos();
                break;
            case 6:
                cout << "\nDigite o nome do suco: ";
                cin >> nome;
                cout << "\nDigite o preco: R$";
                cin >> preco;
                adicionarSuco(nome, preco);
                break;
            case 7:
                alterarPrecoSuco(nome, preco);
                break;
            case 8:
                excluirSuco(nome);
                break;
            case 9:
                cout << "Saindo do programa. Até mais!" << endl;
                break;
            default:
                cout << "Opção inválida. Por favor, escolha uma opção válida (1-9)." << endl;
        }

    } while (selecao != 9);

    return 0;
}