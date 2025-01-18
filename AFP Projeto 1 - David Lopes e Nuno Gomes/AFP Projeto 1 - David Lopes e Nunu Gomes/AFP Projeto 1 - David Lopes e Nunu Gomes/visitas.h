#ifndef VISITAS_H
#define VISITAS_H

// Definição de constantes para limites máximos
#define MAX_VISITAS 1000     
#define MAX_LOCAL 100        
#define MAX_EMB_VISITA 9     

// Estrutura para representar uma visita
typedef struct VISITA {
    int id;                              // Identificador único da visita
    int embaixadores[MAX_EMB_VISITA];    // Array de IDs dos embaixadores associados
    int num_EmbaixadoresVisita;          // Número de embaixadores na visita
    char estado[20];                     // Estado da visita (em planeamento, autorizada, cancelada, realizada)
    char local[MAX_LOCAL];               // Local da visita
    char data[11];                       // Data da visita no formato "dd/mm/yyyy"
} Visita;

// Funções para manipulação de visitas

// Listar todas as visitas registradas
void Listar_visitas(Visita* visitas, int num_Visitas);

// Consultar detalhes de uma visita específica
void Consultar_visita(Visita* visitas, int num_Visitas);

// Adicionar uma nova visita
void Adicionar_visita(Visita* visitas, int* num_Visitas);

// Autorizar uma visita
void Autorizar_visita(Visita* visitas, int num_Visitas);

#endif // VISITAS_H