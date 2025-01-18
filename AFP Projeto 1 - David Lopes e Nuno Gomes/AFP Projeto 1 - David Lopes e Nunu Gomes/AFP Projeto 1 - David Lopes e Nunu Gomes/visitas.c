#include <stdio.h>        
#include <string.h>         
#include "visitas.h"        

// Função para listar todas as visitas cadastradas
void Listar_visitas(Visita* visitas, int num_Visitas) {
    // Verifica se existem visitas registradas
    if (num_Visitas == 0) {
        printf("\nNenhuma visita registrada.\n");
        return; // Sai da função se não houver visitas
    }

    printf("\nLista de Visitas:\n");
    // Percorre a lista de visitas e mostra os detalhes
    for (int i = 0; i < num_Visitas; i++) {
        printf("ID: %d, Estado: %s, Local: %s, Data: %s\n",
               visitas[i].id,         // ID da visita
               visitas[i].estado,     // Estado (planeamento/autorizada)
               visitas[i].local,      // Local da visita
               visitas[i].data);      // Data da visita

        // Mostra os embaixadores associados à visita
        printf("Embaixadores associados: ");
        if (visitas[i].num_EmbaixadoresVisita == 0) {
            printf("Nenhum embaixador associado.\n");
        } else {
            for (int j = 0; j < visitas[i].num_EmbaixadoresVisita; j++) {
                printf("%d, ", visitas[i].embaixadores[j]); // IDs dos embaixadores
            }
            printf("\n");
        }
    }
}

// Função para consultar uma visita específica pelo ID
void Consultar_visita(Visita* visitas, int num_Visitas) {
    int id; // Variável para armazenar o ID da visita buscada
    printf("\nDigite o ID da visita: ");
    scanf("%d", &id);

    // Percorre a lista de visitas à procura do ID fornecido
    for (int i = 0; i < num_Visitas; i++) {
        if (visitas[i].id == id) {
            // Caso a visita seja encontrada, mostra detalhes
            printf("\nVisita encontrada:\n");
            printf("ID: %d, Estado: %s, Local: %s, Data: %s\n",
                   visitas[i].id,
                   visitas[i].estado,
                   visitas[i].local,
                   visitas[i].data);

            // Mostra os embaixadores associados
            printf("Embaixadores associados:\n");
            if (visitas[i].num_EmbaixadoresVisita == 0) {
                printf("Nenhum embaixador associado.\n");
            } else {
                for (int j = 0; j < visitas[i].num_EmbaixadoresVisita; j++) {
                    printf("- ID do Embaixador: %d\n", visitas[i].embaixadores[j]);
                }
            }
            return; // Sai da função após mostrar a visita
        }
    }
    // Mensagem de erro caso o ID não seja encontrado
    printf("\nVisita não encontrada.\n");
}

// Função para adicionar uma nova visita
void Adicionar_visita(Visita* visitas, int* num_Visitas) {
    // Verifica se o limite máximo de visitas foi atingido
    if (*num_Visitas >= MAX_VISITAS) {
        printf("\nErro: Limite máximo de visitas atingido.\n");
        return;
    }

    Visita nova_visita; // Estrutura temporária para armazenar a nova visita
    nova_visita.id = *num_Visitas + 1; // Atribui um ID único à nova visita
    strcpy(nova_visita.estado, "em planeamento"); // Estado inicial padrão
    nova_visita.num_EmbaixadoresVisita = 0; // Inicializa o número de embaixadores associados

    // Solicita o local da visita
    printf("\nDigite o local da visita: ");
    getchar(); 
    fgets(nova_visita.local, sizeof(nova_visita.local), stdin);
    nova_visita.local[strcspn(nova_visita.local, "\n")] = '\0'; 

    // Solicita a data da visita
    printf("Digite a data da visita (dd/mm/yyyy): ");
    scanf("%s", nova_visita.data);

    // Valida o formato da data (deve ser dd/mm/yyyy)
    if (strlen(nova_visita.data) != 10 || nova_visita.data[2] != '/' || nova_visita.data[5] != '/') {
        printf("\nErro: Data inválida. Use o formato dd/mm/yyyy.\n");
        return;
    }

    // Solicita os IDs dos embaixadores associados
    printf("Digite os IDs dos embaixadores associados (máximo %d, digite -1 para parar):\n", MAX_EMB_VISITA);

    int id, count = 0;
    while (count < MAX_EMB_VISITA) {
        printf("ID do Embaixador %d: ", count + 1);
        if (scanf("%d", &id) != 1) {
            printf("Erro: Entrada inválida.\n");
            while (getchar() != '\n'); 
            continue;
        }
        if (id == -1) break; 

        // Verifica se o ID já foi adicionado anteriormente
        int idExiste = 0;
        for (int j = 0; j < count; j++) {
            if (nova_visita.embaixadores[j] == id) {
                printf("Erro: Este ID já foi adicionado.\n");
                idExiste = 1;
                break;
            }
        }
        if (idExiste) continue;

        nova_visita.embaixadores[count] = id; // Adiciona o ID ao array
        count++;
        nova_visita.num_EmbaixadoresVisita++;
    }

    visitas[*num_Visitas] = nova_visita; // Adiciona a nova visita ao array principal
    (*num_Visitas)++; // Aumenta o contador de visitas
    printf("\nVisita adicionada com sucesso!\n");
}

// Função para autorizar uma visita
void Autorizar_visita(Visita* visitas, int num_Visitas) {
    int id; // Variável para armazenar o ID da visita a ser autorizada
    printf("\nDigite o ID da visita: ");
    scanf("%d", &id);

    // Percorre o array de visitas para encontrar o ID correspondente
    for (int i = 0; i < num_Visitas; i++) {
        if (visitas[i].id == id) {

            // Verifica se a visita está "em planeamento" e possui pelo menos dois embaixadores associados para poder ser autorizada

            if (strcmp(visitas[i].estado, "em planeamento") == 0 && visitas[i].num_EmbaixadoresVisita >= 2) {
                strcpy(visitas[i].estado, "autorizada"); // Atualiza o estado da visita para "autorizada"
                printf("\nVisita autorizada com sucesso!\n");
            } else {
                
                printf("\nErro: Não é possível autorizar esta visita.\n");
                printf("Certifique-se de que a visita está 'em planeamento' e possui pelo menos dois embaixadores associados.\n");
            }
            return; // Sai da função após encontrar e processar a visita
        }
    }
    // Mensagem de erro caso o ID não seja encontrado no array de visitas
    printf("\nVisita não encontrada.\n");
}

