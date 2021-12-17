#include <stdio.h>
#include <stdlib.h>
#include <math.h> //biblioteca para calculos e uso de "pow"

//PROJETO 2 
//Caio Sobrinho da Silva - 021
//RA: 211044156

//protóripo das funções
double produtorio(int max);
double potencia(int max);
double sobre_um(int max);
int p_esima(int max, double pi2);


int main(){
    //declaração de variáveis
    int p=0, aux = 1, contar=-1, outraVar = 0, numb = 0;
    double pi=0, resultado=0;

    do
    {
        printf("Digite um numero de 1 a 15: ");
        scanf("%d", &p); //recebe o valor de P para calculo da p-esima casa de pi
    } while (p<1 || p>15); //do while para verificar se p esta entre 1 e 15
    
    
    while(numb!=3) { 
        //laço de repetição para calcular pi e a precisão
        //numb é uma variavel para controlar a precisão e repetição a partir da casa p 
        pi += produtorio(aux - 2) * potencia(aux) * sobre_um(aux); //calcula pi chamando todas as funções 
        aux += 2; //aumenta de dois em dois, para manter como impar(2n-1)

        if(aux>3){ //if para não printar zeros continuos na casa decimal
            contar = p_esima(p, pi*6); 
            //var "contar" chama a função "p_esima" para controlar precisão da p-esima casa
        
        if (outraVar==contar){ 
            //se outraVar for igual a contar, é adicionado 1 a numb
            //quando numb for equivalente a 3, o laço de repetição while, se encerra, parando de calcular pi
            numb +=1;
        }
        else{ //caso o numero da casa P não se repita(outraVar!=contar), a var. numb zera, reiniciando a contagem
            numb = 0;
        }
        outraVar = contar;} //outraVar armazena o numero que foi repetido em pi, calculado por "contar"
        resultado = pi*6; //variavel para armazenar pi após o calculo final
    }
    printf("\n%.*lf\n\n", p,resultado); //printar o resultado(pi)
    
}
// calculo do primeiro termo da equação
// passagem de parâmetros, int max
double produtorio(int max) {
    int i = 1; //declarar i para usar no laço for
    double prod=1; //variavel para armazenar o resultado do calculo de prod 

    if(max <= 1) //se o numero maximo digitado for menor ou igual a um, retorna a 1/2
        return 0.5; //1/2

    for(i=1; i<=max; i+=2) //laço de repetição para calcular o resultado do produtorio
        prod *= (i / (i + 1.0)); //i+=2 para sempre dar ímpar

    return prod; //retornar o valor calculado na função
}
//calculo do terceiro termo da equação 1/2^max
double potencia(int max){ 
    double res = 0; //variavel para armazenar o resultado
    if (max == 1) //se o valor maximo digitado for equivalente a 1, retorna a 1
        return 1;
    else //se for diferente de 1, calcula o valor de res
        res = pow(0.5,max);

    return res; //retorna o resultado
}
double sobre_um(int max){ //função para calcular 1/n
    double result = 0; //variavel para armazenar o resultado

    result = (1.0 / max ); //calculo do valor do segundo termo

    return result; //retorna resultado
}
// pi2 recebe pi
// int max recebe p 
int p_esima(int max, double pi2){ //função para calcular a precisão de pi na P-esima casa para as ultimas 3 parcelas
    double val = 0; //var para armazenar o resultado
    val = pi2;  //armazena o valor de pi calculado na int main em "val"
    val = val*pow(10,max) - (unsigned long long)(val*pow(10, max-1))*10; //equação para calcular a repetição de valores de pi
    //novo valor de pi(val) =  pi*(10^p) - (pi*(10^p-1))*10;
    return val; //retorna o resultado
}