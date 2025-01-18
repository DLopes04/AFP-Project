#include <stdio.h>        
#include <string.h>       
#include <stdbool.h>       
#include <ctype.h>         
#include "embaixadores.h"   

// Função para listar todos os embaixadores cadastrados
void Listar_embaixadores(Embaixador *embaixadores, int num_Embaixadores) {
    // Verifica se há embaixadores cadastrados
    if (num_Embaixadores == 0) {
        printf("\nNenhum embaixador cadastrado.\n");
        return; // Sai da função caso não haja registros
    }

    // Lista todos os embaixadores
    printf("\nEmbaixadores cadastrados:\n");
    for (int i = 0; i < num_Embaixadores; i++) {
        // Exibe os dados de cada embaixador no formato especificado
        printf("Nome: %s, Número: %d, Escola: %s, NIF: %s\n", 
               embaixadores[i].nome_completo, 
               embaixadores[i].id, 
               embaixadores[i].escola, 
               embaixadores[i].nif);
    }
}

// Função para consultar um embaixador específico pelo número de estudante
void Consultar_embaixador(Embaixador *embaixadores, int num_Embaixadores) {
    // Verifica se há embaixadores cadastrados
    if (num_Embaixadores == 0) {
        printf("\nNenhum embaixador cadastrado.\n");
        return; // Sai da função caso não haja registros
    }

    int id; // Variável para armazenar o número de estudante a ser procurado
    printf("\nDigite o número do estudante: ");
    
    // Lê o número do estudante do usuário
    if (scanf("%d", &id) != 1) {
        printf("Erro: Entrada inválida.\n");
        while (getchar() != '\n'); 
        return;
    }

    // Procura pelo número do estudante no array de embaixadores
    for (int i = 0; i < num_Embaixadores; i++) {
        if (embaixadores[i].id == id) {
            // Caso o embaixador seja encontrado, mostra dados
            printf("\nEmbaixador encontrado:\n");
            printf("Nome: %s, Número: %d, Escola: %s, NIF: %s\n", 
                   embaixadores[i].nome_completo, 
                   embaixadores[i].id, 
                   embaixadores[i].escola, 
                   embaixadores[i].nif);
            return; // Sai da função após encontrar o registro
        }
    }

    // Mensagem de erro caso o embaixador não seja encontrado
    printf("\nEmbaixador não encontrado.\n");
}

// Função para adicionar um novo embaixador
void Adicionar_embaixador(Embaixador *embaixadores, int *num_Embaixadores) {
    // Verifica se o limite de embaixadores foi atingido
    if (*num_Embaixadores >= MAX_EMBAIXADORES) {
        printf("\nErro: Limite de embaixadores atingido (%d).\n", MAX_EMBAIXADORES);
        return; // Sai da função caso não seja possível adicionar mais registros
    }

    Embaixador novo_embaixador; // Estrutura para armazenar o novo embaixador

    // Lê o número do estudante
    printf("\nDigite o número do estudante: ");
    if (scanf("%d", &novo_embaixador.id) != 1) {
        printf("Erro: Número de estudante inválido.\n");
        while (getchar() != '\n'); 
        return;
    }

    // Verifica se o número do estudante já está registrado
    for (int i = 0; i < *num_Embaixadores; i++) {
        if (embaixadores[i].id == novo_embaixador.id) {
            printf("\nErro: Este número de estudante já está registrado.\n");
            return; // Sai da função caso o ID já exista
        }
    }

    // Lê a escola do embaixador
    printf("Digite a escola (ESTS, ESTB, ESE, ESCE ou ESS): ");
    scanf("%s", novo_embaixador.escola);

    // Valida se a escola inserida é válida
    if (strcmp(novo_embaixador.escola, "ESTS") != 0 &&
        strcmp(novo_embaixador.escola, "ESTB") != 0 &&
        strcmp(novo_embaixador.escola, "ESE") != 0 &&
        strcmp(novo_embaixador.escola, "ESCE") != 0 &&
        strcmp(novo_embaixador.escola, "ESS") != 0) {
        printf("\nErro: Escola inválida.\n");
        return;
    }

    // Lê o nome completo do embaixador
    printf("Digite o nome completo: ");
    getchar(); 
    fgets(novo_embaixador.nome_completo, MAX_NOME, stdin);
    novo_embaixador.nome_completo[strcspn(novo_embaixador.nome_completo, "\n")] = '\0';

    printf("Digite o NIF (9 dígitos): ");
    scanf("%s", novo_embaixador.nif);

    // Valida o NIF
    if (strlen(novo_embaixador.nif) != 9 || strspn(novo_embaixador.nif, "0123456789") != 9) {
        printf("\nErro: NIF inválido. Deve conter exatamente 9 dígitos numéricos.\n");
        return;
    }

    // Adiciona o novo embaixador ao array
    embaixadores[*num_Embaixadores] = novo_embaixador;
    (*num_Embaixadores)++; 

    printf("\nEmbaixador adicionado com sucesso!\n"); 
}
