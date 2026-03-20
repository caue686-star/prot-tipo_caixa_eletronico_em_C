#include <stdio.h>
#include <stdlib.h>

int main(){

int tentativa;
int chance = 3;
float saldo = 200.00;
float valorSaque, sub;
int opcao;
int senha = 3388;

printf("--------------------------\n");
printf("bem vindo(a) a este banco!\n");
printf("--------------------------\n");
printf("1- consultar saldo\n");
printf("2- realizar saque\n");
printf("3- depositar\n");
printf("4- sair\n");
printf("--------------------------\n");
printf("escolha uma: ");
scanf("%d", &opcao);

switch(opcao){
case 1:
    printf("->Consultar Saldo<-\n");
    while(chance > 0){
        printf("digite sua senha: ");
        scanf("%d", &tentativa);
        if(tentativa == senha){
            printf("senha correta!\n");
            printf("seu saldo é de: R$ %.2f\n", saldo);
            break;
        }else{
        chance--;
        if(chance > 0){
        printf("senha incorreta! tente novamente:\n");
            }else{
            printf("acesso bloqueado!");
            return 0;
            }
        }
    }

case 2:
    printf("->Realizar Saque<-\n");
    printf("notas disponiveis [2, 5, 10, 20, 50, 100, 200]\n");
    printf("digite o valor do saque: R$");
    scanf("%f", &valorSaque);
    if(valorSaque > saldo){
        printf("saldo insuficiente... :(");
        return 0;
        }
    while(chance > 0){
        printf("digite sua senha: ");
        -scanf("%d", &tentativa);
        if (tentativa == senha){
            printf("senha correta!\n");
            break;
        }else{
        chance--;
        if(chance > 0){
            printf("SENHA INCORRETA! tente novamente:\n");
        }else{
            printf("ACESSO BLOQUEADO!");
        return 0;
        }
        }
    }

    sub = saldo - valorSaque;
printf("saldo atual: R$%2.f\n",sub);

int saqueInt = (int)valorSaque;
if(saqueInt == 0){
    printf("não ha cedula para sacar\n");
}else{
    printf("valor para cliente: R$%.2f\n", valorSaque);
    printf("distribuicao de notas:\n");


    int notas[]={200, 100, 50, 20, 10, 5, 2};
    int i = 0;
    int quantidadeNotas;
    for(i = 0; i < 7; i++){
            quantidadeNotas = saqueInt/notas[i];
    if(quantidadeNotas > 0){
        printf("%d nota(s) de R$%d\n", quantidadeNotas, notas[i]);
    }
    saqueInt = saqueInt%notas[i];
    }
    if (saqueInt > 0){
        printf("restaram: R$%d(entregue em moeda)", saqueInt);
    }
    printf("agradecemos a preferencia!");
}

case 3:
    printf("no momento ainda estou trabalhando nisso. desculpa!!!!");

case 4:
    printf("ate breve!\n");
    printf("fechando...\n\n");
    exit(0);
}
return 0;
}
