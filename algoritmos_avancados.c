#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Sala {
    char nome[30];
    struct Sala *esq;
    struct Sala *dir;
};

struct Sala* criarSala(char nome[]) {
    struct Sala* nova = (struct Sala*) malloc(sizeof(struct Sala));
    strcpy(nova->nome, nome);
    nova->esq = NULL;
    nova->dir = NULL;
    return nova;
}

int main() {
    // --- CRIAÇÃO DO MAPA ---
    struct Sala *entrada = criarSala("Entrada");
    struct Sala *floresta = criarSala("Floresta");
    struct Sala *caverna = criarSala("Caverna");
    struct Sala *rio = criarSala("Rio");
    struct Sala *montanha = criarSala("Montanha");
    struct Sala *tesouro = criarSala("Tesouro");

    // --- CONEXÕES (ARESTAS) ---

    entrada->esq = floresta;
    entrada->dir = caverna;

    floresta->esq = rio;
    floresta->dir = montanha;

    caverna->dir = tesouro; // Tesouro está à direita da caverna

    // --- LOOP DO JOGO ---
    struct Sala *atual = entrada;
    char escolha;

    printf("--- BEM-VINDO À AVENTURA ---\n");

    while (1) {
        printf("\nVocê está em: ** %s **\n", atual->nome);
        
        if (strcmp(atual->nome, "Tesouro") == 0) {
            printf("PARABÉNS! Você encontrou o tesouro!\n");
            break;
        }

        printf("Deseja ir para (e) esquerda, (d) direita ou (s) sair? ");
        scanf(" %c", &escolha);

        if (escolha == 's') {
            printf("Saindo da aventura...\n");
            break;
        }
        
        // Lógica para Esquerda
        else if (escolha == 'e') {
            if (atual->esq != NULL) {
                atual = atual->esq;
            } else {
                printf(">> Não há caminho para a esquerda aqui!\n");
            }
        }
        
        // Lógica para Direita
        else if (escolha == 'd') {
            if (atual->dir != NULL) {
                atual = atual->dir;
            } else {
                printf(">> Não há caminho para a direita aqui!\n");
            }
        } 
        
        else {
            printf(">> Comando inválido. Tente 'e', 'd' ou 's'.\n");
        }
    }

    return 0;
}