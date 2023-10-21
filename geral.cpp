#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include "geral.hpp"

using namespace std;

//os maps podem ser consumidos por qualquer cpp que possuam include de geral.hpp, pois possuem definicao extern.
map<string, float> sanduiches;
map<string, float> sucos;
map<string, vector<float>> carrinho;

//resgata dados do arquivo Cardapio_sanduiches.txt para o map sanduiches
void abrirCardapioSanduiches()
{
  vector<string> linhas;
  fstream arquivo;
  arquivo.open("Cardapio_sanduiches.txt", ios::in);
  string linha;
  while (getline(arquivo, linha))
  {
    linhas.push_back(linha);
  }
  arquivo.close();
  if (linhas.empty())
  {
    cout << "Aviso: Cardapio_sanduiches.txt esta vazio." << endl;
  }
  else
  {
    for (int i = 0; i < linhas.size(); i += 2)
    {
      sanduiches[linhas[i]] = stof(linhas[i + 1]);
    }
  }
}

//resgata dados do arquivo Cardapio_sucos.txt para o map sanduiches
void abrirCardapioSucos()
{
  vector<string> linhas;
  fstream arquivo;
  arquivo.open("Cardapio_sucos.txt", ios::in);
  string linha;
  while (getline(arquivo, linha))
  {
    linhas.push_back(linha);
  }
  arquivo.close();
  if (linhas.empty())
  {
    cout << "Aviso: Cardapio_sucos.txt esta vazio." << endl;
  }
  else
  {
    for (int i = 0; i < linhas.size(); i += 2)
    {
      sucos[linhas[i]] = stof(linhas[i + 1]);
    }
  }
}

//imprime map sanduiches
void listarSanduiches()
{
  map<string, float>::iterator it;
  if (sanduiches.size() == 0)
  {
    cout << "Cardapio de sanduiches vazio.\n";
  }
  for (it = sanduiches.begin(); it != sanduiches.end(); it++)
  {
    cout << it->first;
    cout << " - R$" << it->second << "\n";
  }
}

//imprime map sucos
void listarSucos()
{
  map<string, float>::iterator it;
  if (sucos.size() == 0)
  {
    cout << "Cardapio de sucos vazio.\n";
  }
  for (it = sucos.begin(); it != sucos.end(); it++)
  {
    cout << it->first;
    cout << " - R$" << it->second << "\n";
  }
}

//limpa a tela
void clear()
{
  system("clear");
}

//Pausa o processo, esperando um caracter qualquer para dar seguimento
void pressQualquer()
{
  std::cout << "\nPressione qualquer tecla para continuar...\n";
  fflush(stdin);
  getchar();
  while (getchar() != '\n'){}
  clear();
}