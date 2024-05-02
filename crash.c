#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void crash(){
    int saldo = 500; 
    int aposta,tentativas =0;
    char decisao;

    srand(time(NULL));

    printf("Bem-vindo ao jogo Crash!\n");

    do {
        printf("Saldo disponível: $%d\n", saldo);

        do {
            printf("Faça sua aposta(min. $25): ");
            scanf("%d", &aposta);
        } while (aposta < 25 || aposta > saldo);

        float multiplicador = 1;
        while (1) {
            printf("Multiplicador atual: %.2lf\n", multiplicador);
            printf("Digite 'c' para cash out ou 'r' para continuar: ");
            scanf(" %c", &decisao);
            if (decisao == 'c' && tentativas > 0) {
                saldo += aposta * multiplicador;
                break;
            }else if(tentativas == 0){
                break;
            }else if (decisao == 'r') {
                int chance = rand() % 8;
                if (chance == 1) {
                printf("Você crashou! Perdeu a aposta.\n");
                    saldo -= aposta;
                    break;
                }
                multiplicador+= 0.15;
                tentativas++;
            } else {
                printf("Opção inválida! Tente novamente.\n");
            }
        }

        if (saldo <= 0) {
            printf("Você ficou sem saldo. Fim de jogo!\n");
            break;
        }
    } while (1);
}

int  main(){
    crash();
    return 0;
}
