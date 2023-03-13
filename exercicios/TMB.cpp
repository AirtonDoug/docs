#include <iostream>
using namespace std;

double calc_TMB(double fator,double peso,double altura, double idade,char sexo){
    if(sexo == 'M')
    return fator*(66+((13.7*peso)+(5*altura)-(6.8*idade)));
    if(sexo == 'F')
    return fator*(66+((13.7*peso)+(5*altura)-(6.8*idade)));
}

int main(){
    int op;
    char sexo;
    double altura,peso,idade,fator;

    cout << "Calculo de Metabolismo Basal:" << endl
         << "Qual sua taxa de atividade?(digite numero da opcao) \n"
         << "1-Sedentario(pouco ou nenhum exercicio) \n"
         << "2-Levemente ativo(exercicio leve 1 a 3 dias por semana)\n"
         << "3-Moderadamente ativo(exercicio moderado,faz esportes 3 a 5 dias por semana)\n"
         << "4-ALtamente ativo (exercicio pesado de 5 a 6 dias por semana)\n"
         << "5-Extremamente ativo (exercicio pesado diariamente ate 2 vezes por dia)\n";
         cin >> op;
         switch(op){
            case 1:
                fator = 1.2;
                break;
            case 2:
                fator = 1.35;
                break;
            case 3:
                fator = 1.55;
                break;
            case 4:
                fator = 1.725;
                break;
            case 5:
                fator = 1.9;
                break;
            default:
                cout << "opcao invalida" << endl;                
         }
    cout << "Qual seu peso?(kg)" << endl;
    cin >> peso;
    cout << "Qual sua altura?(cm)" << endl;
    cin >> altura;
    cout << "Qual sua idade?" << endl;
    cin >> idade;
    cout << "Qual seu sexo?(M/F)" << endl;
    cin >> sexo;

    cout << "Sua taxa de metabolismo basal: " << calc_TMB(fator,peso,altura,idade,sexo) << " calorias" << endl;

}