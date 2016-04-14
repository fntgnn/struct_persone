#include <stdio.h>
#include <stdlib.h>
#define LEN 30

struct s_persona{
	char nome[LEN];
	int eta;
	float peso;
	int altezza;
};
typedef struct s_persona persona;

void inserisci(persona *);
void stampa(persona *);
int confronta(const void *, const void *);

int dim;

int main(){
	freopen("input.txt","r",stdin);
	scanf("%d\n",&dim);
	persona *elenco=(persona*)malloc(dim*sizeof(persona));
	
	inserisci(elenco);
	stampa(elenco);
	
	qsort(elenco,dim,sizeof(persona),confronta);
	printf("------Ordinato:----------\n");
	stampa(elenco);
	
	return 0;
}

void inserisci(persona* elenco){
	int i=0;
	for(i=0; i<dim; i++)
		scanf("%s %d %f %d\n",elenco[i].nome, &(elenco[i].eta), &(elenco[i].peso), &(elenco[i].altezza));
}

void stampa(persona* elenco){
	int i=0;
	printf("Nome\tEta\tPeso\tAltezza\n");
	for(i=0; i<dim; i++)
		printf("%s\t%d\t%.1f\t%d\n",elenco[i].nome, elenco[i].eta, elenco[i].peso, elenco[i].altezza);
}

int confronta(const void *a, const void *b){
	persona *p1 = (persona *)a;
	persona *p2 = (persona *)b;
	return p1->eta - p2->eta;
}

