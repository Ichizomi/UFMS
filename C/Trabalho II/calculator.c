//Trabalho 2 - Algoritmos e Programação II
//Alunos: Lucas Grijó (2012.1904.038-0), Fabienne do Nascimento Sant'Anna dos Reis(2014.1905.061-3)

//Calculadora de inteiros positivos com precisão infinita.
//Suporta as seguintes operações:
//1 - Adição(+) *funcional*
//2 - Subtração(-) *funcional*
//3 - Multiplicação(*) *funcional*
//4 - Divisão(/) *não implementado*

//Utiliza um sistema de lista encadeada onde cada digito do número corresponde a uma das celulas da lista.
//OBS2: O primeiro digito da entrada é tamanho do numero (quantidade de digitos)
//OBS: Ao entrar 1 valor, separe cada digito por um espaço em branco ex: 5 1 2 3 4 5
//Exemplo de Entrada:
//TAM = 2
//1 0
//TAM = 1
//1
//Operação = 1

//Casos de teste recomendados:
//Adição: [1+1] [50+1] [250+10] [4+200]
//Subtração: [1000-1] [1000-20] [20-10] [220-10] [15-6] [9-10]*
//Multiplicação: [2*2] [10*1][100*10] [1000*1000]
// *detecta automaticamente qual é o maior

#include<stdio.h>
#include<stdlib.h>

/************************************************************************
Estruturas de Dados
*************************************************************************/
struct Node{

	unsigned int digito; //Um numero de 0 à 9
	struct Node *prev; //Aponta para o digito anterior

};

typedef struct Node ListNode;



typedef struct {

	int tam_algarismo; //tamanho da lista
	ListNode* begin; //aponta para o começo da lista
	ListNode* end; //aponta para o final da lista
} Lista;

/**********************************************************************************
Funções Auxiliares - Funções Separadas da Main #A main é a ultima função do arquivo
**********************************************************************************/

/************************************************************************
create() - Criação de uma lista vazia
*************************************************************************/
Lista* create(){
	Lista* li = (Lista*) malloc(sizeof(Lista));
	li->tam_algarismo = 0;
	li->begin = li->end = NULL;
	return li;
}
/************************************************************************
Liberação de toda memória previamente alocada parar armazenar elementos
da lista (destruição da lista toda)
*************************************************************************/
void destroy(Lista* li)
{
	ListNode* tmp = li->end;
	while (tmp)
	{
		tmp=tmp->prev;
		free(li->end);
		li->end = tmp;

	}
	free (li);
}


/************************************************************************
addAtTail() -
Inserção de um novo elemento na lista lo - o elemento em questão tem apenas
o dado digito e é encadeado. A inserção ocorrera no final da lista
e tem complexidade constante - O(1)
*************************************************************************/
void addAtTail(Lista *li, unsigned int digito)
{
	/*aloca e preenche o novo nó*/
	ListNode *novoNode = (ListNode*) malloc (sizeof(ListNode));
	novoNode->digito = digito;

	novoNode->prev = li->end;
	/*se a lista é vazia, o novo nó deve ser o primeiro da lista*/
	if (li->tam_algarismo == 0){
		li->begin = novoNode;
    }

	/*atualiza o ponteiro para o ultimo nó na lista*/
	li->end = novoNode;

	/*atualiza a quantidade de nós na lista*/
	(li->tam_algarismo)++;

}
/************************************************************************
addAtHead()-
Inserção de um novo elemento na lista li - o elemento em questão tem apenas
o dado digito e é encadeado. A inserção ocorrera no inicio da lista
e tem complexidade constante - O(1)
*************************************************************************/
void addAtHead(Lista *li, unsigned int digito)
{
	/*aloca e preenche o novo nó*/
	ListNode *novoNode = (ListNode*) malloc (sizeof(ListNode));
	novoNode->digito = digito;
	novoNode->prev = NULL;

	/*se a lista é vazia, o novo nó deve ser o primeiro da lista*/
	if (li->tam_algarismo == 0){
		li->end = novoNode;
	}
	else{
		(li->begin)->prev = novoNode;
	}
	/*atualiza o ponteiro para o primeiro nó na lista*/
	li->begin = novoNode;

	/*atualiza a quantidade de nós na lista*/
	(li->tam_algarismo)++;

}
/**************************************************************************
print() - Imprime os dados armazenados em uma lista
****************************************************************************/
void print(Lista* li)
{
    int i, j;
	ListNode *tmp;
	printf("##################################\n");
	printf("Numero de Digitos: %d", li->tam_algarismo);
	printf("\nDigitos:\n");

    for(i=0;i < (li->tam_algarismo);i++){
        tmp = li->end;
        j = 0;
        while (j != (li->tam_algarismo)- 1 - i)
        {
            tmp = tmp->prev;
            j++;
        }
        printf("%d ", tmp->digito);
    }
	if ( (li->begin) != NULL) printf("\nDigito mais significativo: %d", (li->begin)->digito);
	if ( (li->end) != NULL) printf("\nDigito menos significativo: %d\n", (li->end)->digito);
	printf("##################################\n");
}

/**************************************************************************
soma()-
Soma os digitos de duas listas (dois números) E devolve 1 ponteiro para o começo
do num3
****************************************************************************/
void soma(Lista* num1, Lista* num2, Lista* num3){

	//De acordo com a operação adição: o tamanho máximo de num3 (o resultado) é igual ao tamanho do maior algarismo que será somado
	//(tam_num1 ou tam_num2) + 1.
	//Verificar qual numero possui o maior tamanho
	int maior;
	ListNode *n1, *n2;
	unsigned int carry; //vai-um
	unsigned int result; //resultado de uma soma (n1 + n2 + carry)
	int i;

	//Primeira soma (digito menos significativo)
	n1 = num1->end; //(num1->end)->digito;
	n2 = num2->end;
	carry = 0;

	//Ver qual numero é o maior para decidir o numero de somas
	if(num1->tam_algarismo > num2->tam_algarismo){
		maior = num1->tam_algarismo;
	}
	else{
		maior = num2->tam_algarismo;
	}
	//Realizar várias somas digito-a-digito
	for(i=0;i<maior;i++){
		//Get Result
		if(n1 != NULL && n2 != NULL){
		result = (n1->digito) + (n2->digito) + carry;
		}
		else{
			if(n1 == NULL){
				result = (n2->digito) + carry;
			}
			else{
				result = (n1->digito) + carry;
			}
		}
		//Get Carry
		if(result > 9){
			carry = result / 10;
			result = result % 10;
		}
		else{
			carry = 0;
		}
		addAtHead(num3, result); //Adiciona no começo da lista
		//atualizar n1 e n2
		if(n1!= NULL && n2 != NULL){
		n1 = n1->prev;
		n2 = n2->prev;
		}
		else{
			if(n1 == NULL){
				n2 = n2->prev;
			}
			else{
				n1 = n1->prev;
			}
		}
		//Vai ultimo carry
		if(i == maior-1 && carry == 1){
			addAtHead(num3, carry);
		}
	}
}
/**************************************************************************
getposition()-
Função necessária para remover a necessidade do duplo encadeamento na operação subtração
para fazer borrows e descobrir o maior número.
Recebe um inteiro indice e uma lista a ser vasculhada e retorna um endereço para a posição adequada.
****************************************************************************/
ListNode* getposition(Lista *num, int index){
    ListNode *tmp = num->end;
    int i;
    for(i=0;i<index;i++){
        tmp = tmp->prev;
    }

    return tmp;
}

/**************************************************************************
sub()-
Subtrai os digitos de duas listas (dois números) E armazena no num3(resultado)
****************************************************************************/
void sub(Lista* num1, Lista* num2, Lista* num3){


	//De acordo com a operação subtração: o tamanho máximo de num3 é igual ou menor o tamanho do menor numero
	int maior, maiorflag; //Maior recebe o tamanho_algarismo do maior numero, maior flag recebe 1 se num1 é o maior ou 2 se num2 é o maior.
	ListNode *n1, *n2;
	ListNode *tmp1, *tmp2;
	ListNode *borrowaux; //Empresta-um
	//ListNode *borrowsave; //Armazena o endereço de quem precisa do empréstimo
	unsigned int result; //resultado de uma subtração (n1 - n2) (n1 = n1 + borrow * 10)
	int i, x, b;

	//Descobrir qual é o maior numero entre os dois e colocar o maior em N1
	//Critério 1: Tamanho do Numero (quantidade de digitos)
	if(num1->tam_algarismo > num2->tam_algarismo){
		n1 = num1->end;
		n2 = num2->end;
        maiorflag = 1;//O maior decide o numero de operações!
	}
	else{
		if(num2->tam_algarismo > num1->tam_algarismo){
		n1 = num2->end;
		n2 = num1->end;
		maiorflag = 2;//O maior decide o numero de operações!
		}
		else{
			//IF(num1->tam_algarismo == num2->tam_algarismo)
			//Critério 2: Valor do primeiro digito
			if((num1->begin)->digito > (num2->begin)->digito){
				//Num1 é o maior
				n1 = num1->end;
				n2 = num2->end;
				maiorflag = 1;//O maior decide o numero de operações!
			}
			else{
				if((num2->begin)->digito > (num1->begin)->digito){
					//Num2 é o maior
					n1 = num2->end;
					n2 = num1->end;
					maiorflag = 2;//O maior decide o numero de operações!
				}
				else{
					//Critério 3: Valor dos digitos seguintes
					//Remover o duplo encadeamento, usar func getposition to return adress
					//Os comentários são como o código funcianava em uma lista duplamente encadeada
					x = 2;
					tmp1 = getposition(num1, (num1->tam_algarismo-x));//tmp1 = (num1->begin)->next;
					tmp2 = getposition(num2, (num2->tam_algarismo-x));//tmp2 = (num2->begin)->next;
					while(tmp1 != NULL && tmp2 != NULL){ //tmp1->next) != NULL && (tmp2->next) != NULL
						if(tmp1->digito > tmp2->digito){
							n1 = num1->end;
							n2 = num2->end;
							maiorflag = 1;//O maior decide o numero de operações!
							//Achou, sair do while
							tmp1 = NULL;
							tmp2 = NULL;
						}
						else{
							if(tmp2->digito > tmp1->digito){
								n1 = num2->end;
								n2 = num1->end;
								maiorflag = 2;//O maior decide o numero de operações!
								//Achou, sair do while
								tmp1 = NULL;
								tmp2 = NULL;
							}
							else{
							    x--;//Decrementa X para que tmp1 aponte para o proximo, mesmo usando uma lista unicamente encadeada
								tmp1 = getposition(num1,(num1->tam_algarismo-x));//tmp1 = tmp1->next;
								tmp2 = getposition(num2,(num1->tam_algarismo-x));//tmp2 = tmp2->next;
								//printf("tmp1: %d tmp2: %d\n", tmp1->digito, tmp2->digito); print de teste
							}
						}

					}
				}

			}
		}
	}
	//Print de teste N1 = Maior numero, N2 = Menor numero
	//printf("N1: %d N2: %d\n", n1->digito, n2->digito);

	//O maior numero (n1) decide o numero de subtrações
	if(maiorflag == 1){
        maior = num1->tam_algarismo;
    }
    else{//maiorflag = 2
        maior = num2->tam_algarismo;
    }

	//Realizar várias subtrações digito-a-digito
	for(i=0;i<maior;i++){

		//Get Result
		if(n1 != NULL && n2 != NULL){
			if(n1->digito >= n2->digito){
				result = (n1->digito) - (n2->digito);
			}
			else{
				//Get Borrow
				//Procura borrow
				borrowaux = n1->prev; //Recebe primeiramente o anterior ao digito que precisa do empréstimo
				b = i + 1;
				while(borrowaux->digito == 0){
					borrowaux = borrowaux->prev;
					b++; //Conta quantas casas avançou procurando o empréstimo
				}
				//Take borrow - if(borrowaux->digito > 0)
				while(borrowaux != n1){

				    //printf("borrowaux=%d n1=%d getpos=%d", borrowaux, n1, getposition(num1, (num1->tam_algarismo) - b - 1));
					//Take borrow
					(borrowaux->digito)--;
					//Passa empréstimo adiante
                        if(maiorflag == 1){
                            borrowaux = getposition(num1, b - 1);//borrowaux = borrowaux->next;
                        }
                        else{
                            borrowaux = getposition(num2, b - 1);//borrowaux = borrowaux->next;
                        }
                        (borrowaux->digito) = (borrowaux->digito) + 10;
                     b--;//Decrementa b, para ir voltando até o número que pediu o empréstimo
				}
				//Get Result
				result = (n1->digito) - (n2->digito);

			}
		}
		else{
			//Quando n2 == NULL
			if(n1->digito >= 0){
				result = (n1->digito) - 0;
			}
		}

		//Add Result
		addAtHead(num3, result); //Adiciona no começo da lista

		//atualizar n1 e n2
		if(n2 != NULL){
			if((n1->prev) != NULL && (n2->prev) != NULL){
			n1 = n1->prev;
			n2 = n2->prev;
			}
			else{
				if((n1->prev) == NULL){
					n2 = n2->prev;
					n1 = NULL;
				}
				else{
					n1 = n1->prev;
					n2 = NULL;
				}
			}
		}
		else{
			if((n1->prev) != NULL){
			n1 = n1->prev;
			}
			else{
				//if((n1->prev) == NULL){
				n1 = NULL;
			}
		}

		//print(num1);
	}//Fimfor

}
/**************************************************************************
mult()-
Multiplica os digitos de duas listas (dois números) E armazena no num3(resultado)
****************************************************************************/
void mult(Lista* num1, Lista* num2, Lista* num3){

//Estrátegia: Ter 2 tmps para realizar as somas assim que for necessário (como um contador)
//A quantidade de somas posteriores depende do tamanho do num2
//O crescimento de 1 numero da soma é o tamanho do num1 + 1
//Na multiplicacão existe o mul_carry (de 0 a 9)
//As somas subsequentes devem ter 1 casa decimal a mais que a anterior (um 0 no final delas)
//EX: 10
//   x10
//    00
//   10+
//   100

	int key = 0; //Chave para dizer se é a primeira soma ou é uma soma posterior (que adiciona há já existente, como um contador). 0=primeira soma, 1=soma posterior
	int i, j, k, l;
	unsigned int carry, result, scarry, sresult; //Carry é o carry nas multiplicações, Scarry é o carry das somas subsequentes
	int qnt_somas_post = (num2->tam_algarismo);
	ListNode *aux1, *aux2, *aux3, *auxx; //Aux1 e Aux2 apontam para os digitos de num1 e num2 respectivamente que estão sendo multiplicados no momento!
                                         //Auxx e Aux3 aponta para os digitos de numaux e num3 respectivamente, na hora de transferir a soma atual para o resultado(contador)!
	//ListNode *s1 *s2;

	//Lista* soma2 = create();

	//Prepara a multiplicação
	aux1 = num1->end;
	aux2 = num2->end;
	carry = 0;

	//Start Quantidade de Somas (depende do tamanho de num2)
	for(i=0;i<qnt_somas_post;i++){
	    aux1 = num1->end; //Reseta aux1
	    Lista* numaux = create(); //Numaux recebera a soma atual para que seja guardada no resultado num3 (o contador)
	    //Clear num aux?
		//Start Multiplicações para obter a soma atual. (Que será somada com todas as outras)
		//Mult aux->digito * num1 e armazena em num3 (resultado)(Na primeira mult, equivalente a num2->end * num1)
		//Tomar cuidado com a casa decimal adicional (usar i * 10)
		for(j=0; j < (num1->tam_algarismo);j++){
			result = (aux1->digito * aux2->digito) + carry;
			if(result > 9){
				carry = result / 10;
				result = result % 10;
			}
			else{
				carry = 0;
			}
			addAtHead(numaux, result);
			aux1 = aux1->prev;//Atualiza aux1
		}

		//Vai ultimo carry se ele ficou sobrando
		if (carry != 0){
            addAtHead(numaux, carry);
		}
		carry = 0;

		//Somar a soma atual(numaux) com o num3(resultado). De acordo com a casa decimal (i*10)
		//Ajuste na potencia da soma (i*10)
		for(k=0;k<i;k++){
			addAtTail(numaux, 0);
		}

        //Prepara a transferência de numaux para num3 (soma)
		auxx = numaux->end; //Prepara auxx (aponta para numaux)
        aux3 = num3->end; //Reseta aux3
		scarry = 0; //carry da soma;
        //printf("Key: %d Tam: %d", key, numaux->tam_algarismo);
		//Somar cada digito da numaux na num3
		//-key, pois soma posteriores usam 1 operação a menos que a primeira
		for(l=0;l < (numaux->tam_algarismo) - key;l++){
            //printf("numaux->tam_algarismo: %d", numaux->tam_algarismo);

			if(key == 0){ //Se é a primeira soma atual (apenas armazenar)
				//aux3->digito = numaux->digito;
				addAtHead(num3, auxx->digito);
			}
			else{
			    //Se é uma soma posterior, adicionar ao valor já existente em num3
                //printf("aux3->prev: %d", (aux3->prev)->digito);
			    //
				if(aux3->prev != NULL){

                    sresult = (aux3->digito) + (auxx->digito) + scarry;
                    if(sresult > 9){
                        scarry = sresult / 10;
                        sresult = sresult % 10;
                    }
                    else{
                        scarry = 0;
                    }
                    aux3->digito = (aux3->digito) + sresult;
                    aux3 = aux3->prev;
				}
				else{

					//Quando aux3(num3) está acabando
					//aux3->digito = (aux3->digito) + (auxx->digito) + scarry;
					sresult = (aux3->digito) + (auxx->digito) + scarry;
					if(sresult > 9){
						scarry = sresult / 10;
						sresult = sresult % 10;
					}
					else{
                        scarry = 0;
					}

					aux3->digito = (aux3->digito) + sresult;
					//vai carry + ultimo digito
					sresult = scarry + (auxx->prev)->digito;
					addAtHead(num3, sresult);
				}
			}
			auxx = auxx->prev;

		}//fim soma cada digito
		scarry = 0;
		aux2 = aux2->prev; //Atualiza aux2

		destroy(numaux);
		key = 1; //primeira soma ja foi
	}//fim quantidade de somas



}

/**************************************************************************
div()-
****************************************************************************/
//void div(Lista* num1, Lista* num2, Lista* num3)
/************************************************************************

Função Principal
*************************************************************************/
int main(void){

	int i, j, k;
	int num1_tam, num2_tam;
	unsigned int armazena_digito;
	int opera; // 1 = soma, 2 = subtação, 3 = multiplicação, 4 = divisão.

	//Criar listas vazias
	Lista *num1 = create();
	Lista *num2 = create();
	Lista *num3 = create(); //resultado

	/*****************************************************************************************************************************
		Sistema para armazenar o Numero 1 e o Numero 2.
		O usuário deve informar o tamanho do numero e digitar de 50 em 50 digitos até atingir aquele tamanho.
		O usuário deve digitar os digitos do começo para o fim (Digito mais significativo para o digito menos significativo).
	******************************************************************************************************************************/

	//-------------------------------------------Armazenar o Primeiro Número-----------------------------------------------
	printf("\n\nInsira o primeiro número seguindo os seguintes critérios:\n");
	printf("1- Primeiramente digite o tamanho do seu numero (quantos digitos ele contém).\n");
	printf("2- Depois digite todos os digitos, separados por espaço. (naturalmente cada digito deve ser um numero entre 0 e 9)\n");
	printf("3- Lembre-se de digitar os digitos do MAIS significativo para o MENOS significativo\n");


	//Ler o tamanho do primeiro número
	printf("TAM = ");
	scanf("%d", &num1_tam);

	//Adiciona digitos(em tamanho multiplo de 50)
	for(i=0;i<num1_tam/50;i++){

		for(j=0;j<50;j++){
			//Cada digito deve ser entre 0 a 9 e devem ser armazenados no final da lista
			scanf("%u", &armazena_digito);
			addAtTail(num1, armazena_digito);
		}
	}
	//Adiciona digitos restantes
	for(k=0;k<num1_tam%50;k++){
		//Cada digito deve ser entre 0 a 9 e devem ser armazenados no final da lista
		scanf("%u", &armazena_digito);
		addAtTail(num1, armazena_digito);
	}

	//Teste de Impressão
	print(num1);

	//-------------------------------------------Armazenar o Segundo Número-----------------------------------------------
	printf("\n\nAgora siga os mesmos critérios para inserir o segundo número:\n");

	//Ler o tamanho do segundo numero
	printf("TAM = ");
	scanf("%d", &num2_tam);

	//Adiciona digitos(em tamanho multiplo de 50)
	for(i=0;i<num2_tam/50;i++){

		for(j=0;j<50;j++){
			//Cada digito deve ser entre 0 a 9 e devem ser armazenados no final da lista
			scanf("%u", &armazena_digito);
			addAtTail(num2, armazena_digito);
		}
	}
	//Adiciona digitos restantes
	for(k=0;k<num2_tam%50;k++){
		//Cada digito deve ser entre 0 a 9 e devem ser armazenados no final da lista
		scanf("%u", &armazena_digito);
		addAtTail(num2, armazena_digito);
	}

	//Teste de Impressão
	print(num2);

	//-------------------------------------------Escolha a operação aritmética--------------------------------------------
	printf("\n\nEscolha a operação aritmética:\n");
	printf("Num: 1 -> Operação: Adição\n");
	printf("Num: 2 -> Operação: Subtração\n");
	printf("Num: 3 -> Operação: Multiplicação\n");
	printf("Num: 4 -> Operação: Divisão\n");
	scanf("%d", &opera);
	switch(opera){

		case 1:
			soma(num1, num2, num3);
			break;

		case 2:
			sub(num1, num2, num3);
			break;

		case 3:
			mult(num1, num2, num3);
			break;

		case 4:
			//div();
			break;

		default:
			printf("\nOcorreu um erro na especificação da operação!\n");
			break;
	}

	//Imprimir Resultado
	printf("\nResultado da Operação!\n");
	print(num3);
}

