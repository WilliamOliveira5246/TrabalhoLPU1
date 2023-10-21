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
    map<string, vector<float>>::iterator it = carrinho.find(nome);
    if (it != carrinho.end()){ //repeticoes de itens
        it->second[1] += 1.0f;
    } else {
        carrinho[nome] = {sanduiches[nome], 1.0f}; // primeiro item
    }
}

//adiciona par chave-valor do map sucos em map carrinho a partir de uma chave
void addSucoCarrinho(string nome)
{
    map<string, vector<float>>::iterator it = carrinho.find(nome);
    if (it != carrinho.end()){ //repeticoes de itens
        it->second[1] += 1.0f;
    } else {
        carrinho[nome] = {sucos[nome], 1.0f}; // primeiro item
    }
}

//realiza varredura em map carrinho e imprime cada par chave-valor
void verCarrinho()
{
    map<string, vector<float>>::iterator it;
    if (sucos.size() == 0)
    {
        cout << "Carrinho vazio.\n";
    }
    for (it = carrinho.begin(); it != carrinho.end(); it++)
    {
        cout << it->second[1] << "x ";
        cout << it->first;
        cout << " - R$" << it->second[0] << "\n";
    }
}

//exclui par chave-valor do map carrinho a partir de uma chave
void excluirItemCarrinho(string nome)
{
    map<string, vector<float>>::iterator it = carrinho.find(nome);
    if (it != carrinho.end() && it->second[1] > 1){ //se houverem multiplos itens, retira 1
        it->second[1] -= 1.0f;
    } else {
        carrinho.erase(nome); //apenas 1, apaga
    }
}

//realiza varredura do map carrinho e faz um somatorio de todos os valores encontrados
float calcularValorCarrinho()
{
    float valorTotal = 0;
    map<string,vector<float>>::iterator it;
    for (it = carrinho.begin(); it != carrinho.end(); it++){
        valorTotal += it->second[0]*it->second[1];
    }
    return valorTotal;
}
