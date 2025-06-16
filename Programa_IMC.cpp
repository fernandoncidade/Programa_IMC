/*
Cálculo IMC Situação
Abaixo de 18 Você está abaixo do peso normal!
Entre 18 e 24 Parabéns, você está em seu peso normal!
Entre 25 e 29 Você está acima de seu peso (sobrepeso)
Entre 30 e 34 Obesidade grau I
Entre 35 e 39 Obesidade grau II
40 e acima Obesidade grau III

Faça um programa que leia do usuário o peso e altura de vários indivíduos e exiba uma mensagem
indicando a situação de cada um, conforme a tabela acima. O programa termina quando for digitado
um par de valores em que um deles seja nulo.
O cálculo do IMC deve ser feito pela função calcIMC, que recebe como parâmetros o peso e altura
de uma pessoa e retorna o valor do IMC.
Deve também ser criada e usada no programa principal a função exibeSituacao que recebe
como parâmetro um valor de IMC e mostra na tela a mensagem correspondente conforme a tabela.
Esta função não retorna nenhum valor.
*/

#include<iostream>
#include<locale>

using namespace std;

float calcIMC (float peso, float altura){
    float IMC;
    IMC = peso / (altura*altura);
    return IMC;
}

void ExibeSituacao (float IMC){
    if (IMC < 18)
        wcout << L"Você está abaixo do peso normal!";
    else if (IMC >= 18 && IMC <= 24)
        wcout << L"Parabéns, você está em seu peso normal!";
    else if (IMC >= 25 && IMC <= 29)
        wcout << L"Você está acima de seu peso (sobrepeso).";
    else if (IMC >=30 && IMC <= 34)
        wcout << L"Obesidade grau I";
    else if (IMC >= 35 && IMC <= 39)
        wcout << L"Obesidade grau II";
    else
        wcout << L"Obesidade grau III";
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    int contaIndividuo = 1;
    float Peso, Altura, IMC;

    wcout << L"Digite os pares de valores de peso e altura, respectivamente, para cada indivíduo (para encerrar, digite um par cujo um dos valores é nulo): ";

    cin >> Peso >> Altura;
    while ((Peso != 0) && (Altura != 0)){
        IMC = calcIMC(Peso, Altura);
        wcout << L"Indivíduo " << contaIndividuo << " - ";
        ExibeSituacao(IMC);
        wcout << endl;

        contaIndividuo++;
        cin >> Peso >> Altura;
    }
    return 0;
}
