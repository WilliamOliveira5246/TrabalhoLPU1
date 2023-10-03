#include <iostream>
#include "aluno.hpp"

using namespace std;

int main(){

lerArquivo();


while(true){

    int selecao;

    cout << "O que você deseja fazer?" << endl;
    cout << "1 - Cadastrar aluno"<< endl;
    cout << "2 - Excluir aluno"<< endl;
    cout << "3 - listar aluno"<< endl;
    cout << "4 - Calcular media"<< endl;
    cout << "5 - sair "<< endl;

    cin >> selecao;

    if(selecao  == 1){

        string nome;
        float nota1, nota2, nota3;
        cout << "Nome: ";
        cin >> nome;

        //getline(cin, nome);
        cout << "Notas: ";
        cin >> nota1 >> nota2 >> nota3;
        cadastarAlunos(nome, nota1, nota2, nota3);


    }else if(selecao  == 2){
        string nome;
        cout << "Nome: ";
        cin >> nome;
        excluirAluno(nome);

    }else if(selecao  == 3){
        listarAlunos();

    }else if(selecao  == 4){
        string nome;
        cout << "Nome: ";
        cin >> nome;
        cout << "Media: " << calcularMedia(nome);
 
    }
    else{
        salvarAlunos();
        break;
    }



}

    return 0;
}