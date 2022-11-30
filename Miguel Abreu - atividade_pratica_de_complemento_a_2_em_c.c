#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int bvetor[8] = {0,0,0,0,0,0,0,0};
int b = 7;
void converter(int num, int b);
void complemento_a_1(int num, int b);
void complemento_a_2(int num, int b);
void manipulacao_binaria(int num, int b);
//////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
    setlocale(LC_ALL, "portuguese");
    complemento_a_1(3, b);
    printf("\n-------------------------------------------------------");
    complemento_a_1(4, b);
return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////

void converter(int num, int b){
    if(num == 1){
        bvetor[b] = num;
        return;
    }
    if(num == 0){
        bvetor[b] = num;
        return;
    }
    else{
        converter(num/2, b-1);
        if(num % 2 == 1){
        bvetor[b] = (num%2);
        }
        if(num % 2 == 0){
            bvetor[b] = (num%2);
        }
    }
}

void complemento_a_1(int num, int b){
    converter(num, b);
    int i;
    printf("\nO número abaixo é o número decimal %d em binario\n", num);

    for(i = 0; i <= b;i++){
        printf("%d ", bvetor[i]);
    }
    putchar('\n');
    printf("realizando complemento a 1...");
    putchar('\n');
    for(i = 0; i <= b; i++){
        if(bvetor[i] == 1){
            bvetor[i] = 0;
        }
        else{
            bvetor[i] = 1;
        }
    }
    for(i = 0; i <= b;i++){
        printf("%d ", bvetor[i]);
    }
    printf("\nrealizando complemento a 2...");
    complemento_a_2(num, b);
    putchar('\n');
    for(i = 0; i <= b;i++){
        printf("%d ", bvetor[i]);
    }
    int somatorio = 0;
    int a = 1;
    for(i = b; i > 0;i--){
        somatorio += bvetor[i]*a;
        a *= 2;
    }
    printf("\n\nValor em decimal obtido: ");
    printf("%d", somatorio);
    for(i = 0; i <= b;i++){
        bvetor[i] = 0;
    }
}

void complemento_a_2(int num, int b){
    if((bvetor[b] += 1) == 1){
        bvetor[b] = 1;
        return;
    }
    else{
        bvetor[b] = 0;
        complemento_a_2(num, b-1);
    }
}
