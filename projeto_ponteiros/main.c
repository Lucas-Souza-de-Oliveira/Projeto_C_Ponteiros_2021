#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define stringMax 40

typedef struct No {
    char clientName[stringMax];
    int clientCode, consumo, dia, mes, ano;
    float unitPrice, totalPrice;
    struct No *proximo;
} No;

typedef struct {
    No *inicio, *fim;
} Lista;

char clientName2[stringMax], backScanName[stringMax];
int clientCode2, consumo2, dia2, mes2, ano2, c;
float unitPrice2, totalPrice2;

void scanName(){
	printf("Digite o nome do cliente: ");
	fgets(backScanName,40,stdin);
	backScanName[strlen(backScanName)-1]='\0';
}

int scanCode(){
	int codigoClient;
	
	printf("Digite o código do cliente: ");
 	scanf("%d", &codigoClient);
 	while ((c = getchar()) != '\n' && c != EOF) {}
 	
 	return codigoClient;
}

int scanConsumo(){
	int consumo;
	
	printf("Digite consumo de energia: ");
 	scanf("%d", &consumo);
 	while ((c = getchar()) != '\n' && c != EOF) {}
 	
 	return consumo;
}

int scanDia(){
	int dia;
	
	printf("Digite o dia de vencimento: ");
    scanf("%d", &dia);
    while ((c = getchar()) != '\n' && c != EOF) {}
    
    return dia;
}

int scanMes(){
	int mes;
	
	printf("Digite o mes de vencimento: ");
    scanf("%d", &mes);
    while ((c = getchar()) != '\n' && c != EOF) {}
    
    return mes;
}

int scanAno(){
	int ano;
	
	printf("Digite o ano de vencimento: ");
    scanf("%d", &ano);
    while ((c = getchar()) != '\n' && c != EOF) {}
    
    return ano;
}

float scanValUni(){
	float precoUnit;
	
	printf("Digite o preço unitário: ");
    scanf("%f", &precoUnit);
    while ((c = getchar()) != '\n' && c != EOF) {}
    
    return precoUnit;
}

float scanValTotal(){
	float valTotal;
	
	printf("Digite o valor total: ");
 	scanf("%f", &valTotal);
 	while ((c = getchar()) != '\n' && c != EOF) {}
 	
 	return valTotal;
}

void inserirInicio(Lista *lista, float totalPrice2, float unitPrice2, int ano2, int mes2, int dia2, int consumo2, int clientCode2, char clientName2[stringMax]) {
    No *novo = (No*)malloc(sizeof(No)); 
    int i=0;
	
	while(i<stringMax){
    	novo->clientName[i] = clientName2[i];
		i++;

        if(clientName2[i] == '\0'){
		break;
		 }
	}
        novo->clientCode = clientCode2;
    	novo->consumo = consumo2;
    	novo->dia = dia2;
    	novo->mes = mes2;
    	novo->ano = ano2;
    	novo->unitPrice = unitPrice2;
    	novo->totalPrice = totalPrice2;


    if(lista->inicio == NULL) { 
        novo->proximo = NULL;
        lista->inicio = novo;
        lista->fim = novo;
    } else { 
        novo->proximo = lista->inicio;
        lista->inicio = novo;
    }
}

void inserirFim(Lista *lista, float totalPrice2, float unitPrice2, int ano2, int mes2, int dia2, int consumo2, int clientCode2, char clientName2[stringMax]) {
    No *novo = (No*)malloc(sizeof(No)); 
    int i=0;
	
	while(i<stringMax){
    	novo->clientName[i] = clientName2[i];
		i++;

        if(clientName2[i] == '\0'){
		break;
		 }
	}
    novo->clientCode = clientCode2;
   	novo->consumo = consumo2;
   	novo->dia = dia2;
   	novo->mes = mes2;
   	novo->ano = ano2;
   	novo->unitPrice = unitPrice2;
   	novo->totalPrice = totalPrice2;
    novo->proximo = NULL;

    if(lista->inicio == NULL) { 
        lista->inicio = novo;
        lista->fim = novo;
    } else { 
        lista->fim->proximo = novo;
        lista->fim = novo;
    }
}

int Fila_Vazia(Lista *lista){
    if(lista==NULL) return 1;
    if(lista->inicio==NULL) return 1; 
    else return 0;
}

void imprimir(Lista *lista){
	if(Fila_Vazia(lista)){
		printf("\n!--------------------------Pilha vazia-------------------------!\n");
		printf ("\n  Fila End. Inicio %p: ", lista->inicio);
        printf ("\n  Fila End. Fim    %p: ", lista->fim);
        return;
	}

	No *aux = lista->inicio;
	printf ("\n  Fila Atual: ");
    printf ("\n  Fila End. Inicio %p: ", lista->inicio);
    printf ("\n  Fila End. Fim    %p: ", lista->fim);
    printf ("\n");

    while(aux!=NULL){
    	printf("\n=---------------------------------------------------------------=\n");
        printf ("\nNome: %s\t\tEndereco: %p ==> %p", aux->clientName, aux, aux->proximo);
        printf ("\nCódigo: %d\t\t\tEndereco: %p ==> %p", aux->clientCode, aux, aux->proximo);
        printf ("\nConsumo: %d\t\t\tEndereco: %p ==> %p", aux->consumo, aux, aux->proximo);
        printf ("\nVencimento: %d/%d/%d\t\tEndereco: %p ==> %p", aux->dia, aux->mes, aux->ano, aux, aux->proximo);
		printf ("\nPreço unitario: %.2f\t\tEndereco: %p ==> %p", aux->unitPrice, aux, aux->proximo);
		printf ("\nValor total: %.2f\t\tEndereco: %p ==> %p", aux->totalPrice, aux, aux->proximo);
		aux = aux->proximo;
    }
    printf ("\n");
}

void remover(Lista *lista, int clientCode2) {
    No *inicio = lista->inicio; 
    No * noARemover = NULL; 

    if(inicio != NULL && lista->inicio->clientCode == clientCode2) { 
        noARemover = lista->inicio;
        lista->inicio = noARemover->proximo;
        if(lista->inicio == NULL)
            lista->fim = NULL;
    } else { 
        while(inicio != NULL && inicio->proximo != NULL && inicio->proximo->clientCode != clientCode2) {
            inicio = inicio->proximo;
        }
        if(inicio != NULL && inicio->proximo != NULL) {
            noARemover = inicio->proximo;
            inicio->proximo = noARemover->proximo;
            if(inicio->proximo == NULL)
                lista->fim = inicio;
        }
    }
    if(noARemover) {
        free(noARemover); 
    }
}

void inserir_no_meio(No **lista, float totalPrice2, float unitPrice2, int ano2, int mes2, int dia2, int consumo2, int clientCode2, char clientName2[stringMax], int ant){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
    int i=0;
	
	while(i<stringMax){
    	novo->clientName[i] = clientName2[i];
		i++;

        if(clientName2[i] == '\0'){
		break;
		 }
	}
    novo->clientCode = clientCode2;
   	novo->consumo = consumo2;
   	novo->dia = dia2;
   	novo->mes = mes2;
   	novo->ano = ano2;
   	novo->unitPrice = unitPrice2;
   	novo->totalPrice = totalPrice2;

        if(*lista == NULL){
            novo->proximo = NULL;
            *lista = novo;
        }
        else{
            aux = *lista;
            while(aux->clientCode != ant && aux->proximo)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}

int main() {
    Lista lista;
    int opcao, procura;
    
    setlocale(LC_ALL, "");

    lista.inicio = NULL;
    lista.fim = NULL;

    do { 
        printf("\n\n=---------------------------------------------------------------=\n");
        printf("1 - Inserir no inicio\n2 - Imprimir\n3 - Inserir no fim\n4 - Remover\n5 - Inserir em local especifico\n6 - Sair\n");
        printf("\nDigite o número da opção desejada: ");
		scanf("%d", &opcao);
        while ((c = getchar()) != '\n' && c != EOF) {}

        switch(opcao) {
        case 1:
			printf("\n=---------------------------------------------------------------=\n");
            scanName();
            inserirInicio(&lista, scanValTotal(), scanValUni(), scanAno(), scanMes(), scanDia(), scanConsumo(), scanCode(), backScanName);
            break;
        case 2:
        	printf("\n=---------------------------------------------------------------=\n");
            imprimir(&lista);
            break;
        case 3:
        	printf("\n=---------------------------------------------------------------=\n");
            scanName();
            inserirFim(&lista, scanValTotal(), scanValUni(), scanAno(), scanMes(), scanDia(), scanConsumo(), scanCode(), backScanName);
            break;
        case 4:
        	printf("\n=---------------------------------------------------------------=\n");
            printf("Digite o código de uma conta a ser removida: ");
            scanf("%d", &procura);
            remover(&lista, procura);
            break;
		case 5:
			printf("\n=---------------------------------------------------------------=\n");
        	printf("Digite o código a procurar: ");
        	scanf("%d", &procura);
        	while ((c = getchar()) != '\n' && c != EOF) {}
        	printf("\n=---------------------------------------------------------------=\n");
        	scanName();
        	inserir_no_meio(&lista, scanValTotal(), scanValUni(), scanAno(), scanMes(), scanDia(), scanConsumo(), scanCode(), backScanName, procura);
        	break;
        case 6:
            printf("Finalizando...\n");
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while(opcao != 6);

    return 0;
}
