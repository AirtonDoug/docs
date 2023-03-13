#include <iostream>
#include <string>
#include "Node.h"
#include "SparseMatrix.h"

SparseMatrix::SparseMatrix(int m, int n){//construtor COmplexidade O(n)
    if(m > 0 && n > 0){
        m_head = new Node(0,0,nullptr,nullptr,0.0);// m_head inicializa com valores zerados e apontando pra ele mesmo.
        m_head->next = m_head;
        m_head->below = m_head;
        i_size = m;// i_size representa o numero de linhas
        j_size = n;// j_size representa o numero de colunas
        j_head = new Node(0,1,m_head,nullptr,0.0);
        j_head->below = j_head;
        i_head = new Node(1,0,nullptr,m_head,0.0);
        i_head->next = i_head;

        Node *auxc = j_head;//auxiliar para percorrer colunas
        Node *auxl = i_head;//auxiliar para percorrer linhas

        for(int i = 2; i <= m-1; i++){//cria os nós cabeças pra cada linha
           auxl->below = new Node(i,0,nullptr,nullptr,0.0);
           auxl->below = auxl->below;
           auxl->below->next = auxl->below;
           auxl = auxl->below;
        }
        auxl->below = new Node(m,0,nullptr,m_head,0.0); // coloca o ultimo nó apontando para o nó cabeça
        auxl->below->next = auxl->below;
        for(int j = 2; j <= n-1; j++){ //cria os nós cabeças de cada coluna
          auxc->next = new Node(0,j,nullptr,nullptr,0.0);
          auxc->next = auxc->next;
          auxc->next->below = auxc->next;
          auxc = auxc->next;
        }
        auxc->next = new Node(0,n,m_head,nullptr,0.0); // o mesmo da linha 22 só que para o nó das colunas
        auxc->next->below = auxc->next;
    }else{
        std::runtime_error("A matriz nao pode ser criada valores de tamanho invalidos");
    }
}

void SparseMatrix::insert(double val,int i, int j){ // Complexidade O(n)
    if(i > i_size || j > j_size){
    throw std::runtime_error("posicao invalida");

}else if (val != 0){// para o valor ser inserido ele deve ser diferente de zero
    Node *auxl = i_head;
    Node *auxc = j_head;
    // os whiles ajustam os nós auxiliares para antes da posição do novo nó se ele não estiver vazio e para a posição exata do já existente
    while(auxl->linha < i){
        auxl = auxl->below;
    }
    
    while(auxl->next->coluna <= j && auxl->next->coluna > auxl->coluna){
        auxl = auxl->next;
    }

    while(auxc->coluna < j){
        auxc = auxc->next;
    }
    while(auxc->below->linha <= i && auxc->below->linha > auxc->linha){
      
        auxc=auxc->below;
    }
    if(auxl==auxc){// se existir já existir um nó na posição onde se quer inserir um novo muda o valor do nó existente
        auxl->valor = val;

  
    }else{//senao ou seja se a posição do nó a ser inserido não existe o Node auxl sera o anterior do novo nó e o auxc será o acima do novo nó.
        Node *novo = new Node(i,j,auxl->next,auxc->below,val);// o proximo do novo nó é o proximo do anterior a ele e o abaixo dele é o abaixo do acima dele
        auxl->next = novo;
        auxc->below = novo;
   }

    /* 
    teste feito a priori para ver se os nós estavam enderaçados corretamente  
    auxc->below = novo;
    auxl->next = novo;
    novo->next = auxl;
    novo->below = auxc;
    */ 
}else{

    return;
}

}

 void SparseMatrix::print(){ // complexidade O(n^2)
    Node * aux; // auxiliar que vai percorrer as colunas
    Node * aux1 = i_head;//auxiliar que vai percorrer as linhas começa na primeira linha

    for(int j = 1; j <= j_size ; j++){
        aux=aux1->next;//aux das colunas começa na posição (j,1)
        for(int i = 1; i <= i_size;i++){
            if(aux->coluna == i){//se a coluna corresponde ao indice do for significa que está na posição correta imprime o valor e vai pro proximo
                std::cout  << aux->valor << " ";
                aux = aux->next;
            }else{//senão está vazio esse espaço então imprime 0
                std::cout << "0" << " ";
            }
        
        }
        std::cout << "\n";
        aux1=aux1->below; //auxiliar das linhas vai pra proxima linha
    }  

}

double SparseMatrix::get(int i, int j){
    if( (i > i_size || i < 1) || (j > j_size || j < 1 )){
      throw  std::runtime_error("posicao invalida nao possivel acessar");
    }
    Node *auxl = i_head;
   
    for(int lin = 1 ; lin < i; lin++){
        auxl=auxl->below;
    }
   for(int col = 0;col < j;col++){
        if(auxl->next->coluna == col+1)
            auxl=auxl->next;
        else
            continue;
   }
    if(auxl->linha == i && auxl->coluna == j)
        return auxl->valor;
    else
        return 0;
}

SparseMatrix::~SparseMatrix(){//Destrutor
    Node * aux1;
    Node * aux2 = i_head->next;
    for(int i = 1;i <= i_size;i++){
        while(aux2->coluna != 0){
            aux1 = aux2->next;
            delete aux2;
            aux2=aux1;
        
        }
    aux2=aux2->below->next;
    }

    
    aux1 = m_head;
    aux2 = i_head;
    while(aux1->below != m_head){ // destroi os Nodes cabeca de cada linha
        
        aux1->below = aux2->below;
        delete aux2;
        aux2 = aux1->below;

    }
    aux2 = j_head;

    while(aux1->next != m_head){ // destroi os nodes cabecas de cada coluna
        
        aux1->next = aux2->next;
        delete aux2;
        aux2 = aux1->next;

    }
    delete m_head;// destroi m_head


}
