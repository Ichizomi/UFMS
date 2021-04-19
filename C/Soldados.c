#include<stdio.h>
#include<stdlib.h>

struct soldados{
    int numero;
    struct soldados *prox;
};

int main(void){

    int i, sorteio, soldadosrestantes; // i é uma var auxiliar para laços, sorteio é o numero sorteado entre 1 a 20 na hora de remover um soldado, soldadosrestantes é um contador de quantos soldados ainda existem no circulo
    struct soldados *p, *circulo, *ant, *prox; //circulo aponta para o primeiro da fila, p apontar para o atual(manipulado), ant aponta para o anterior de p, prox aponta para o prox de p

    //Aloca o primeiro soldado (circulo sempre aponta para o primeiro soldado da fila)
    circulo = (struct soldados*) malloc(sizeof(struct soldados));
    //p é um ponteiro auxiliar para alocar todos os soldados (vai de prox em prox)
    p = circulo;
    for(i=1;i<10;i++){
        p->numero = i;
        p->prox = (struct soldados*) malloc(sizeof(struct soldados));
        p = p->prox;
    }
    //Coloca o numero do ultimo soldado e faz o ultimo soldado apontar para o primeiro
    p->numero = i;
    p->prox = circulo;

    //imprime o numero e a posicição de cada soldado
    p = circulo;
    for(i=0;i<10;i++){
        printf("Posição na fila %d Soldado Numero %d\n", i, p->numero);
        p = p->prox;
    }

    prox = circulo; // Inicialisa-se prox em circulo para p sempre apontar para uma posição valida caso o primeiro do circulo seja o numero removido
    soldadosrestantes = 10; //Conta quantos soldados restam para remove-los até sobrar apenas 1
    while(soldadosrestantes > 1){

        //Sorteia um numero entre 1 a 20
        scanf("%d", &sorteio);

        //Conta os soldados utilizando o ponteiro auxiliar *p(aponta para o que deve ser removido) e o *ant (aponta aoo anterior do p) e *prox(aponta para o proximo do p)

        p = prox;   // Inicialisa-se prox em circulo para p sempre apontar para uma posição valida caso o primeiro do circulo seja o numero removido
        for(i=0;i<sorteio;i++){
            ant = p;
            p = p->prox;
        }

        //O ponteiro sorteado é imprimido
        printf("O soldado escolhido é o numero %d!\n", p->numero);
        printf("Ele ficara nas defesas!\n");
        //Liberar o soldado do circulo!
        //O soldado anterior deve apontar para o proximo do removido
        prox = p->prox;    //*prox aponta para o proximo do *p(o seguinte do removido)
        ant->prox = prox;    //o proximo do soldado anterior é o proximo do que foi removido do circulo
        free(p);            //remove p do circulo
        soldadosrestantes--; //1 soldado foi removido
    }

    //Imprime o soldado restante
    printf("O soldado restante é o numero %d!\n", prox->numero);
    printf("Ele sobrevivera e entregara a mensagem pedindo reforços!\n");
}
