#ifndef EMBAIXADORES_H
#define EMBAIXADORES_H

// Constantes para limites máximos
#define MAX_EMBAIXADORES 100  /
#define MAX_NOME 100          

// Estrutura para representar um embaixador
typedef struct {
    int id;                         // Número do estudante (identificador único)
    char escola[10];                // Escola do embaixador
    char nome_completo[MAX_NOME];   // Nome completo do embaixador
    char nif[10];                   // NIF (Número de Identificação Fiscal) do embaixador
} Embaixador;

// Protótipos de funções para manipulação de embaixadores
// Listar todos os embaixadores cadastrados
void Listar_embaixadores(Embaixador *embaixadores, int num_Embaixadores);

// Consultar detalhes de um embaixador específico
void Consultar_embaixador(Embaixador *embaixadores, int num_Embaixadores);

// Adicionar um novo embaixador
void Adicionar_embaixador(Embaixador *embaixadores, int *num_Embaixadores);

#endif // EMBAIXADORES_H