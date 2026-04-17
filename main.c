#include <stdio.h>
#include <stdlib.h>

int main(){
//variaveis definidas
int tentativa;
int chance = 3;
float saldo = 200.00;
float valorSaque, valorDp, sub;
int opcao;
int senha = 3388;

//tela inicial para escolher as opções
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

//o switch serve para que as opções realmente funcionem na hora de serem escolhidas
switch(opcao){
case 1:
    printf("->Consultar Saldo<-\n");
    while(chance > 0){ //enquanto a quantiade de chances for maior que "0", você pode tentar digitar sua senha
        printf("digite sua senha: ");
        scanf("%d", &tentativa);
        if(tentativa == senha){ //se a senha digitada for correta, você consegue verificar saldo
            printf("senha correta!\n");
            printf("seu saldo é de: R$ %.2f\n", saldo);
            break;
        }else{
        chance--; //se você errar a senha, você perde uma chance
        if(chance > 0){
        printf("senha incorreta! tente novamente:\n");
            }else{
            printf("acesso bloqueado!"); //se as 3 chances acabarem, você não pode verificar seu saldo
            return 0;
            }
        }
    }
    break;
case 2:
    printf("->Realizar Saque<-\n");
    printf("notas disponiveis [2, 5, 10, 20, 50, 100, 200]\n");
    printf("digite o valor do saque: R$");
    scanf("%f", &valorSaque); //digitar o valor de saque
    if(valorSaque > saldo){ //se você tentar digitar um valor maior do que você tem na sua conta, não irá funcionar
        printf("saldo insuficiente... :(");
        return 0;
        }
    while(chance > 0){
        printf("digite sua senha: ");
        scanf("%d", &tentativa);
        if (tentativa == senha){
            printf("senha correta!\n");
            break;
        }else{
        chance--;
        if(chance > 0){
            printf("SENHA INCORRETA! tente novamente:\n");
        }else{
            printf("ACESSO BLOQUEADO!\n\n");
        return 0;
        }
        }
    }

    sub = saldo - valorSaque; //diminui a quantidade que você sacou do seu saldo
printf("saldo atual: R$%2.f\n",sub);

//a partir de agora, é a maquina escolhendo as notas que vai te entregar, de acordo com o valor do saque
// como não é possível dividir um valor float com um valor int, criei uma variável int para armazenar o valor do float
int saqueInt = (int)valorSaque;
if(saqueInt == 0){
    printf("não ha cedula para sacar\n");
}else{
    printf("valor para cliente: R$%.2f\n", valorSaque);
    printf("distribuicao de notas:\n");

//apenas demarcando quais notas são possíveis sacar
    int notas[]={200, 100, 50, 20, 10, 5, 2};
    int i = 0;
    int quantidadeNotas;
    for(i = 0; i < 7; i++){ // o 7 aparece pois são 7 tipos de notas diferentes
            quantidadeNotas = saqueInt/notas[i];//divide o valor do saque de acordo com as notas
    if(quantidadeNotas > 0){
        printf("%d nota(s) de R$%d\n", quantidadeNotas, notas[i]);
    }
    saqueInt = saqueInt%notas[i]; //mostra quantas notas de qual valor é preciso entregar para ser equivalente a quantiade de saque
    }
    if (saqueInt > 0){
        printf("restaram: R$%d(entregue em moeda)", saqueInt);
    }
    printf("agradecemos a preferencia!");
}
    break;
case 3:
    printf("->DEPOSITO<-\n");
    printf("digite a quantia de deseja depositar: R$");
    scanf("%f", &valorDp);//adicionar valor que deseja depositar

    if(valorDp < 2){//se você tentar depositar 1 real ou menos, você será barrado!
        printf("você não pode depositar essa quantia!\n");
        break;
    }
    while(chance > 0){
        printf("digite sua senha: ");
        scanf("%d", &tentativa);
        if ( tentativa == senha){
            printf("senha correta! deposito feito!\n");
            saldo = valorDp + saldo; //quantia adicionada ao seu saldo
            printf("seu saldo atual é de: R$%.2f\n", saldo);
            break;
        }else{
            chance--;
            if(chance > 0){
                printf("SENHA INCORRETA! tente novamente: ");
            }else{
                printf("ACESSO BLOQUEADO!");
            }
        }
    }
    break;

case 4:
    printf("ate breve!\n");
    printf("fechando...\n\n");
    exit(0);
}
return 0;
}
