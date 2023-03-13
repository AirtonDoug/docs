#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include "SparseMatrix.h"

using namespace std;
// Soma duas matrizes e retorna uma matriz resultante complexidade : O(n^2)
SparseMatrix* sum (SparseMatrix* A,SparseMatrix* B){  
    if(A->i_size != B->i_size || A->j_size != B->j_size){
      throw std::runtime_error("Nao e possivel somar matrizes de tamanhos diferentes");
    }else{
    SparseMatrix * C = new SparseMatrix(A->i_size,A->j_size);
    for(int i = 1; i <= A->i_size;i++){
        for(int j=1; j <= A->j_size; j++){
            C->insert( ( A->get(i,j) + B->get(i,j)), i, j);
        }
    }
    return C;
    }
}

SparseMatrix* multiply(SparseMatrix* A, SparseMatrix * B){ // Complexidade O(n^3)
    if(A->i_size != B->j_size){
       throw std::runtime_error("Nao foi possivel fazer multiplicacao");
    }
    double aux1;
    double aux2;
    SparseMatrix *C = new SparseMatrix (A->i_size,B->j_size);

    for(int i = 1; i <= C->i_size; i++){
        for(int j = 1; j <= C->j_size; j++) {
            aux2 = 0;
            for(int k = 1; k <= A->j_size; k++){
                aux1 = A->get(i,k) * B->get(k,j);
                aux2+=aux1;
            }
            C->insert(aux2,i,j);
        }
    }
    return C;
    
}

SparseMatrix *ReadSparseMatrix(string file){// le um arquivo na pasta do programa passada como parametro complexidade O(n)
    ifstream arquivo;
    string linha;
    stringstream s;
    int numl,numc;
    double v;
    arquivo.open(file);
    if(arquivo.is_open()){// para a primeira linha do arquivo le dois valores para criação da matriz
        getline(arquivo,linha);
        s << linha;
        s >> numl >> numc;
        SparseMatrix *m = new SparseMatrix(numl,numc);//aloca dinamicamente uma matriz com o tamanho especificado noa arquivo
        while(getline(arquivo,linha)){//pega as coordenadas e valores das outras linhas para inserir na matriz
            s << linha;
            s >> numl >> numc;
            s >> v;
            m->insert(v,numl,numc);
        }
        return m;

    }else{
        cout << "Arquivo nao foi encontrado " << endl;
    }
            
       
}




int main(){
    vector <SparseMatrix*> matrizes;// vector de matrizes que armazena todas as matrizes criadas e ordena de 0 a n-1 onde n é o numero de matrizes criadas.
    
    cout <<"\t#######Sparse Matrix########"<< endl
         << "comandos:" << endl
         << "create i j - cria uma matriz com tamanho (ixj) onde i e j  > 0 " << endl
         << "show - mostra as matrizes criadas e seus respectivos indicies" << endl
         << "insert m i j v - insere na matriz m(int) nas cordenadas i(int) j(int) o valor v(double)" << endl
         << "sum A B - soma a matriz A com a matriz B e cria uma resultante" << endl
         << "multiply A B - multiplica matriz A com a matriz B e cria uma resultante" << endl
         << "read nome_do_arquivo.txt - recebe o nome do arquivo .txt e cria uma matriz e seta os valores especificados" << endl
         << "exit - encerra o programa" << endl;
    while(true){
        string comando, token;
		getline(cin, comando);
		stringstream ss{ comando };
        ss >> token;

        cout << "$" << ss.str() << endl;
        //cria matriz vazia com o tamanho especificado
        //exemplo:
        //create 3 3 cria uma matriz (3,3) vazia
        if(token == "create"){
            int m,n;
            ss >> m >> n;
            SparseMatrix *mat = new SparseMatrix(m,n);
            matrizes.push_back(mat);

        }
        //mostra todasas matrizes matrizes criadas
        else if(token == "show"){
            for(unsigned int i = 0; i < matrizes.size();i++){
                cout << "Matriz " << i << ": " << endl;
                matrizes[i]->print();
            }
        }
        //encerra o programa
        else if(token == "exit"){
            for(unsigned int i =0; i < matrizes.size(); i++){
                delete matrizes[i];
            }
            matrizes.clear();
            break;
        }
        // insere valor na matriz exemplo:
        // insert 0 3 3 5.5 insere na matriz 0 na posicao (3,3) o valor 5.5
        else if(token == "insert"){
            int i,j,m;              
            double v;
            ss >> m >> i >> j;
            ss >> v;
            matrizes[m]->insert(v,i,j);

        }
        //imprime o valor da matriz m na posicao i j exemplo:
        //get 0 3 1 pega da matriz zero o valor que está na posicao (3,1)
        else if(token == "get"){
            int m,i,j;
            ss >> m  >> i >> j;
            cout << "O valor na posicao ( "<< i << "," << j  << "): "<< matrizes[m]->get(i,j) << endl; 
        }
        //soma as matrizes a e b de mesmo tamanho e cria uma nova matriz a partir da resultante
        //exemplo entrada: sum 0 1 (soma as matrizes 0 e 1)
        else if(token == "sum"){
            int a,b;
            ss >> a >> b;
            if(a!=b && (a < (int)matrizes.size() && b < (int)matrizes.size())){
            SparseMatrix *m = new SparseMatrix(matrizes[a]->i_size,matrizes[a]->j_size);
            m = sum(matrizes[a],matrizes[b]);
            matrizes.push_back(m);
            }else{
               cout << "dados invalidos" << endl; 
            }

        }
        //multiplica as matrizes a e b de mesmo tamanho e cria uma nova matriz a partir da resultante
        //exemplo entrada: sum 0 1 (soma as matrizes 0 e 1)
        else if(token == "multiply"){
            int a,b;
            ss >> a >> b;
            if(a!=b && (a < (int)matrizes.size() && b < (int)matrizes.size())){
            SparseMatrix *m = new SparseMatrix(matrizes[a]->i_size,matrizes[b]->j_size);
            m = multiply(matrizes[a],matrizes[b]);
            matrizes.push_back(m);
            }else{
               cout << "dados invalidos" << endl; 
            }

        }else if(token == "read"){// le um arquivo passado com o nome exato
            string str;           // exemplo: read teste.txt
            ss >> str;
            matrizes.push_back(ReadSparseMatrix(str));
            

        }else{
            cout << "comando invalido" << endl;
        }  
                                




    }

    
}