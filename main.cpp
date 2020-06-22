#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <set>

/*
Disciplina : Estruturas de Dados
Assunto : Arquivos texto
Professor : José Alberto Matioli
Aluno(s) : Guilherme da Costa Guatura
Data : 22/06/2020
*/

using namespace std;

bool processa(char *nomearq){
    if(strstr( nomearq, ".txt")!=nullptr)
        cout<<"Alunos presentes em "<<  nomearq <<" :\n";
    else return false;

    return true;
}

void PrintNames(vector<string>names){
    for (int j = 0; j < names.size(); ++j) {
        if(names[j] != "ProfMatioli") {
            for (int i = 0; i < names[j].size() ; ++i) {
                if(isupper(names[j][i+1])){
                    cout<<names[j][i]<<" ";
                }
                else{
                    cout<<names[j][i];
                }
            }
            cout << "\n";
        }
    }
}

void LoadNames(vector<string> result, vector<string> * namesArray){
    vector<string> names;
    //atribui os caracteres a uma string name e da um push no vector names com o nome
    for (int i = 0; i < result.size() ; ++i) {
        string name;
        for (char c : result[i]) {
            if(c!=':'){
                if(isalpha(c)){
                    name+=c;
                }
            }
            else break;
        }
        names.push_back(name);

    }
    *namesArray = names;
}

void ReadFile(string filename, vector<string>* result){
    ifstream File(filename);
    string fileText;
    vector<string> names;
// Use a while loop together with the getline() function to read the file line by line
    while (getline (File, fileText)) {
        // Output the text from the file
        names.push_back(fileText);
    }

// Close the file
    File.close();
    *result = names;
}

int main(int argc, char **argv)
{
    vector<string> names;
    vector<string> res;

    cout << "\nNome: Guilherme da Costa Guatura;\nRA: 19126\n\n";

    if(argc<2){
        cout<<"Erro: Falta argumento <nomearq>!\n";
        exit(0);
    }

    if(!processa(argv[1])){
       cout<<"Falha ao processar o arquivo "<< argv[1]<<"\n";
    }

    // le o arquivo e insere cada linha em um item no vetor res;
    ReadFile(argv[1], &res);

    //le o vetor res, faz a separação dos nomes e altera cada item do vetor names para conter somente nomes
    LoadNames(res, &names);

    // elimina os nomes iguais
    set<string> s( names.begin(), names.end() );
    names.assign( s.begin(), s.end() );

    //adiciona os espaços entre o nome e sobrenome de cada nome no vetor names;
    PrintNames(names);

    return 0;
}