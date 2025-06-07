#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char estado;
    char codigo[5];
    char nome[50];
    char cidade[25];
    unsigned long int populacao;
    float area;
    float PIB;
    int pontos_Turisticos;
    float densidade_Populacional;
    float PIB_Percapita;
    float super_Poder;

} Cidade;

void calcularAtributosDerivados(Cidade* c){
    
    if (c->area > 0){
        c->densidade_Populacional = (float) c->populacao / c->densidade_Populacional ;
    } else {
        c->densidade_Populacional = 0.0f;
    }

    if (c->populacao> 0){
        c->PIB_Percapita = c->PIB / (float) c->populacao;
    } else {
        c->PIB_Percapita = 0.0f;
    }

    c->super_Poder = (float) c->populacao+ c->area + c->PIB + (float) c->pontos_Turisticos + c->pontos_Turisticos + c->PIB_Percapita;

    if (c->densidade_Populacional > 0.0f){
        c->super_Poder += (1.0f / c->densidade_Populacional);
    }
}

void cadastrarCidade(Cidade* c, int numero_Carta){
    printf("\n--- cadastro da carta %d ---\n", numero_Carta);

    printf("digite o estado (uma letra de A a H):");
    scanf("%c", &c->estado);

    c->estado = toupper (c->estado);

    printf("digite o codigo da carta (ex: B02):");
    scanf("%s", c->codigo);

    while (getchar() != '\n');
    printf("digite o nome da cidade:");
    fgets(c->nome, sizeof(c->nome), stdin);
    
    c->nome [strcspn(c->nome, "\n")] = '\0';

    printf("digite a populacao:");
    scanf("%lu", &c->populacao);

    printf("digite a area(em km):");
    scanf("%f", &c->area);

    printf("digite o PIB:");
    scanf("%f", &c->PIB);

    printf("digite o numero de pontos turisticos:");
    scanf("%d", &c->pontos_Turisticos);

    calcularAtributosDerivados(c);
}

void exibirCidade(const Cidade* c, int numero_Carta){
    printf("\n--- carta %d ---\n", numero_Carta);

    printf("estado: %c \n", c->estado);
    printf("codigo: %s \n", c->codigo);
    printf("nome da cidade: %s \n", c->nome);
    printf("populacao: %lu \n", c->populacao);
    printf("area: %.2f km \n", c->area);
    printf("PIB: %.2f 1 bilhao de reais \n", c->PIB);
    printf("numero de pontos turisticos: %d \n", c->pontos_Turisticos);
    printf("densidade populacional: %.2f hab/km \n", c->densidade_Populacional);
    printf("PIB Percapita: %.2f reais \n", c->PIB_Percapita);
    printf("super poder: %.2f \n", c->super_Poder);
}

int compararAtributo(const char* nome_Atributo, float valor1, float valor2, int maior_vence){
    printf("%s:", nome_Atributo);
    if (maior_vence){
        if (valor1 > valor2){
            printf("carta 1 venceu (1) \n");
            return 1;
        } else {
            printf("carta 2 venceu (0) \n");
            return 0;
        }  
    } else {
        if (valor1 < valor2){
            printf("carta 1 venceu (1) \n");
            return 1;
            } else{
                printf("carta 2 venceu (0) \n");
                return 0;
            }
        
       }

    }


    int compararAtributoint(const char* nome_Atributo, int valor1, int valor2, int maior_vence){
        printf("%sd:", nome_Atributo);
        if (maior_vence){
            if (valor1 >valor2){
                printf("carta 1 venceu (1) \n");
                return 1;
            } else {
                printf("carta 2 venceu (0) \n");
                return 0;
            }
        } else {
            if (valor1 < valor2){
                printf("carta 1 venceu (1) \n");
                return 1;
            } else {
                printf("carta 2 venceu (0) \n");
                return 0;
            }
        }
    }

    int compararAtributosUlong(const char* nome_Atributo, unsigned long int valor1, unsigned long int valor2, int maior_vence){
        printf("%s:", nome_Atributo);

        if (maior_vence){
            if(valor1 > valor2){
                printf("carta 1 venceu (1) \n");
                return 1;

            } else {
                printf("carta 2 venceu (0) \n");
                return 0;
            }
        } else {
            if (valor1 < valor2){
                printf("carta 1 venceu (1) \n");
                return 1;

            } else {
                printf("carta 2 venceu (0) \n");
                return 0;
            }
        }
    }

    int main(){
        Cidade carta1;
        Cidade carta2;

        cadastrarCidade(&carta1, 1);
        cadastrarCidade(&carta2, 2);

        exibirCidade(&carta2, 2);

        printf("\n--- comparaçao de cartas ---\n");

        compararAtributosUlong("populacao", carta1.populacao, carta2.populacao, 1);
        compararAtributo("area", carta1.area, carta2.area, 1);
        compararAtributo("PIB", carta1.PIB, carta2.PIB, 1);
        compararAtributoint("pontos turisticos", carta1.pontos_Turisticos, carta2.pontos_Turisticos, 1);
        compararAtributo("densidade populacional", carta1.densidade_Populacional, carta2.densidade_Populacional, 0);
        compararAtributo("PIB Percapita", carta1.PIB_Percapita, carta2.PIB_Percapita, 1);
        compararAtributo("super poder", carta1.super_Poder, carta2.super_Poder, 1);

        printf("\n fim da comparacao.\n");

        return 0;
    }

        
    
        
    
    


