#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include "gerente.hpp"

using namespace std;

map<string, float> sanduiches;
map<string, float> sucos;

void lerCardapioSanduiches(){
  vector<string> linhas;
  fstream arquivo;
  arquivo.open("Cardapio_sanduiches.txt", ios::in);
  string linha;
  while(getline(arquivo, linha)){
    linhas.push_back(linha);
  }
  arquivo.close();
  if(linhas.empty()){
    cout << "Arquivo vazio!!!" <<endl;
  }else{
    for(int i = 0; i < linhas.size(); i+=2){
      sanduiches[linhas[i]] = stof(linhas[i+1]);
    }
  }
}

void lerCardapioSucos(){
  vector<string> linhas;
  fstream arquivo;
  arquivo.open("Cardapio_sucos.txt", ios::in);
  string linha;
  while(getline(arquivo, linha)){
    linhas.push_back(linha);
  }
  arquivo.close();
  if(linhas.empty()){
    cout << "Arquivo vazio!!!" <<endl;
  }else{
    for(int i = 0; i < linhas.size(); i+=2){
      sucos[linhas[i]] = stof(linhas[i+1]);
    }
  }
}


void adicionarSanduiche(string nome, float preco){
    sanduiches[nome] = preco;
    cout << "\n#####################################" << endl;
    cout << "    Sanducihe cadastrado com sucesso!    " << endl;
    cout << "#####################################" << endl << endl;
    salvarSanduiches();
}

void adicionarSuco(string nome, float preco){
    sucos[nome] = preco;
    cout << "\n#####################################" << endl;
    cout << "    Suco cadastrado com sucesso!    " << endl;
    cout << "#####################################" << endl << endl;
    salvarSucos();
}


void alterarPrecoSanduiche(std::string nome, float preco){
    sanduiches[nome] = preco;
    salvarSanduiches();
}

void alterarPrecoSuco(std::string nome, float preco){
    sucos[nome] = preco;
    salvarSucos();
}


void excluirSanduiche(string nome){
    sanduiches.erase(nome);
    salvarSanduiches();
}

void excluirSuco(string nome){
    sucos.erase(nome);
    salvarSucos();
}


void listarSanduiches(){
    map<string, float>::iterator it;
    for(it = sanduiches.begin(); it != sanduiches.end(); it++){ 
        cout << it->first;
        cout << " - R$" << it->second << "\n\n";
    }
  cout << endl;
}

void listarSucos(){
    map<string, float>::iterator it;
    for(it = sucos.begin(); it != sucos.end(); it++){ 
        cout << it->first;
        cout << " - R$" << it->second << "\n\n";
    }
  cout << endl;
}


void salvarSanduiches(){
    fstream arquivo;
    arquivo.open("Cardapio_sanduiches.txt", ios::out);
    map<string, float>::iterator it;
    for(it = sanduiches.begin(); it != sanduiches.end(); it++){ 
        arquivo << it->first << endl;
        arquivo << it->second << endl;
    }
    arquivo.close();
}

void salvarSucos(){
    fstream arquivo;
    arquivo.open("Cardapio_sucos.txt", ios::out);
    map<string, float>::iterator it;
    for(it = sucos.begin(); it != sucos.end(); it++){ 
        arquivo << it->first << endl;
        arquivo << it->second << endl;
    }
    arquivo.close();
}