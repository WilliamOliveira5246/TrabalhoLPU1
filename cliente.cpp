#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include "cliente.hpp"
#include "geral.hpp"

using namespace std;


void addSanduicheCarrinho(string nome)
{
  carrinho[nome] = sanduiches[nome];
}

void addSucoCarrinho(string nome)
{
  carrinho[nome] = sucos[nome];
}

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

void excluirItemCarrinho(string nome)
{
    carrinho.erase(nome);
}

float calcularValorCarrinho()
{
    float valorTotal = 0;
    map<string,float>::iterator it;
    for (it = carrinho.begin(); it != carrinho.end(); it++){
        valorTotal += it->second;
    }
    return valorTotal;
}
