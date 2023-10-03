#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include "aluno.hpp"

using namespace std;

map<string, notas> aluno;

void lerArquivo(){
  vector<string> linhas;
  fstream arquivo;
  arquivo.open("dados.txt", ios::in);
  string temp;
  while(getline(arquivo, temp)){
    linhas.push_back(temp);
  }
  arquivo.close();
  if(linhas.empty()){
    cout << "Arquivo vazio!!!" <<endl;
  }else{
    for(int i = 0; i < linhas.size(); i+=4){
      aluno[linhas[i]].nota01 = stof(linhas[i+1]);
      aluno[linhas[i]].nota02 = stof(linhas[i+2]);
      aluno[linhas[i]].nota03 = stof(linhas[i+3]);
    }
  }
}

void cadastarAlunos(string nome, float n1, float n2, float n3){
    aluno[nome].nota01 = n1;
    aluno[nome].nota02 = n2;
    aluno[nome].nota03 = n3;
   cout << "\n#####################################" << endl;
    cout << "    Aluno cadastrado com sucesso!    " << endl;
    cout << "#####################################" << endl << endl;
}

void excluirAluno(string nome){
    aluno.erase(nome);
}

float calcularMedia(string nome){
    float media = (aluno[nome].nota01 + aluno[nome].nota02 + aluno[nome].nota03)/3;
    return media;
}


void listarAlunos(){
    map<string, notas>::iterator it;
    cout << "\n#####################################" << endl;
    for(it = aluno.begin(); it != aluno.end(); it++){ 
        cout << "Aluno: " << it->first << endl;
        cout << "Nota 01: " << it->second.nota01 << endl;
        cout << "Nota 02: " << it->second.nota02 << endl;
        cout << "Nota 03: " << it->second.nota03 << endl;
      cout << "#####################################" << endl;
    }
  cout << endl;
}

void salvarAlunos(){
    fstream arquivo;
    arquivo.open("dados.txt", ios::out);
    map<string, notas>::iterator it;
    for(it = aluno.begin(); it != aluno.end(); it++){ 
        arquivo << it->first << endl;
        arquivo << it->second.nota01 << endl;
        arquivo << it->second.nota02 << endl;
        arquivo << it->second.nota03 << endl;
    }
}

