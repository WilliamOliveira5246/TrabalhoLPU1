#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include "cliente.hpp"
#include "geral.hpp"

using namespace std;

//adiciona par chave-valor do map saduiches em map carrinho a partir de uma chave
void addSanduicheCarrinho(string nome)
{
  carrinho[nome] = sanduiches[nome];
}

//adiciona par chave-valor do map sucos em map carrinho a partir de uma chave
void addSucoCarrinho(string nome)
{
  carrinho[nome] = sucos[nome];
}

//realiza varredura em map carrinho e imprime cada par chave-valor
void verCarrinho()
{
    map<string, float>::iterator it;
    if (sucos.size() == 0)
    {
        cout << "Carrinho vazio.\n";
    }
    for (it = carrinho.begin(); it != carrinho.end(); it++)
    {
        cout << it->first;
        cout << " - R$" << it->second << "\n";
    }
}

//exclui par chave-valor do map carrinho a partir de uma chave
void excluirItemCarrinho(string nome)
{
    carrinho.erase(nome);
}

//realiza varredura do map carrinho e faz um somatorio de todos os valores encontrados
float calcularValorCarrinho()
{
    float valorTotal = 0;
    map<string,float>::iterator it;
    for (it = carrinho.begin(); it != carrinho.end(); it++){
        valorTotal += it->second;
    }
    return valorTotal;
}
