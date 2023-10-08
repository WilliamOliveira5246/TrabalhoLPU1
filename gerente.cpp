#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include "gerente.hpp"
#include "geral.hpp"

using namespace std;

void addAltSanduiche(string nome, float preco)
{
  sanduiches[nome] = preco;
}

void excluirSanduiche(string nome)
{
  sanduiches.erase(nome);
}

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


void addAltSuco(string nome, float preco)
{
  sucos[nome] = preco;
}

void excluirSuco(string nome)
{
  sucos.erase(nome);
}

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