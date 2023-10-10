#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include "gerente.hpp"
#include "geral.hpp"

using namespace std;

//adiciona um novo sanduiche ou altera o preco de um sanduiche pre-existente em map sanduiches
void addAltSanduiche(string nome, float preco)
{
  sanduiches[nome] = preco;
}

//exclui um sanduiche do map sanduiches a partir de uma chave
void excluirSanduiche(string nome)
{
  sanduiches.erase(nome);
}

//persiste em "Cardapio_sanduiches.txt", cada par chave-valor presente em map sanduiches,
//onde cada informacao é inserida em uma linha diferente, mesmo as chaves e seus respectivos valores
void salvarSanduiches()
{
  fstream arquivo;
  arquivo.open("Cardapio_sanduiches.txt", ios::out);
  map<string, float>::iterator it;
  for (it = sanduiches.begin(); it != sanduiches.end(); it++)
  {
    arquivo << it->first << endl;
    arquivo << it->second << endl;
  }
  arquivo.close();
}

//adiciona um novo suco ou altera o preco de um suco pre-existente em map sucos
void addAltSuco(string nome, float preco)
{
  sucos[nome] = preco;
}

//exclui um suco do map sucos a partir de uma chave
void excluirSuco(string nome)
{
  sucos.erase(nome);
}

//persiste em "Cardapio_sucos.txt", cada par chave-valor presente em map sucos,
//onde cada informacao é inserida em uma linha diferente, mesmo as chaves e seus respectivos valores
void salvarSucos()
{
  fstream arquivo;
  arquivo.open("Cardapio_sucos.txt", ios::out);
  map<string, float>::iterator it;
  for (it = sucos.begin(); it != sucos.end(); it++)
  {
    arquivo << it->first << endl;
    arquivo << it->second << endl;
  }
  arquivo.close();
}