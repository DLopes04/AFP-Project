#include <stdio.h>               
#include "embaixadores.h"         
#include "visitas.h"              
#include "salvar.h"               

#define File_Embaixadores "Embaixadores.csv"   // Define o nome do arquivo de embaixadores
#define File_Visitas "Visitas.csv"            // Define o nome do arquivo de visitas

// Função para carregar os dados a partir dos arquivos CSV
void carregarDados(Visita* visitas, int* num_Visitas, Embaixador* embaixadores, int* num_Embaixadores) {
    
    *num_Visitas = 0;         // Inicializa o contador de visitas e embaixadores como zero
    *num_Embaixadores = 0;  

    // Abre o arquivo de visitas em modo de leitura
    FILE *ficheiroVisitas = fopen(File_Visitas, "r");

    // Verifica se o arquivo de visitas foi aberto com sucesso
    if (ficheiroVisitas != NULL) {
        // Lê os dados de cada linha do arquivo até o fim do arquivo
        while (fscanf(ficheiroVisitas, "%d,%[^,],%[^,],%[^,],%d",
                      &visitas[*num_Visitas].id, visitas[*num_Visitas].local, 
                      visitas[*num_Visitas].estado, visitas[*num_Visitas].data, 
                      &visitas[*num_Visitas].num_EmbaixadoresVisita) == 5) {

            // Lê o ID de todos os embaixadores associados à visita
            for (int i = 0; i < visitas[*num_Visitas].num_EmbaixadoresVisita; i++) {
                fscanf(ficheiroVisitas, ",%d", &visitas[*num_Visitas].embaixadores[i]);
            }

            (*num_Visitas)++; // Incrementa o número total de visitas
        }
        fclose(ficheiroVisitas);  // Fecha o arquivo de visitas
    }

    // Abre o arquivo de embaixadores em modo de leitura
    FILE *ficheiroEmbaixadores = fopen(File_Embaixadores, "r");

    // Verifica se o arquivo de embaixadores foi aberto com sucesso
    if (ficheiroEmbaixadores != NULL) {
        // Lê os dados de cada linha do arquivo até o fim do arquivo
        while (fscanf(ficheiroEmbaixadores, "%d,%[^,],%[^,],%s",
                      &embaixadores[*num_Embaixadores].id, 
                      embaixadores[*num_Embaixadores].escola,
                      embaixadores[*num_Embaixadores].nome_completo, 
                      embaixadores[*num_Embaixadores].nif) == 4) {

            (*num_Embaixadores)++;  // Aumenta o número total de embaixadores
        }
        fclose(ficheiroEmbaixadores); // Fecha o arquivo de embaixadores
    }
}

// Função para salvar os dados nos arquivos CSV
void salvarDados(Visita* visitas, int num_Visitas, Embaixador* embaixadores, int num_Embaixadores) {
    
    // Abre o arquivo de visitas em modo de escrita
    FILE *ficheiroVisitas = fopen(File_Visitas, "w");

    // Verifica se o arquivo foi aberto corretamente
    if (ficheiroVisitas == NULL) {
        printf("Erro: Não foi possível abrir o arquivo de visitas para escrita.\n");
        return;  // Sai da função caso haja erro
    }

    // Escreve os dados das visitas no arquivo
    for (int i = 0; i < num_Visitas; i++) {
        fprintf(ficheiroVisitas, "%d,%s,%s,%s,%d",
                visitas[i].id, visitas[i].local, visitas[i].estado, 
                visitas[i].data, visitas[i].num_EmbaixadoresVisita);

        // Escreve os IDs dos embaixadores relacionados à visita
        for (int j = 0; j < visitas[i].num_EmbaixadoresVisita; j++) {
            fprintf(ficheiroVisitas, ",%d", visitas[i].embaixadores[j]);
        }

        fprintf(ficheiroVisitas, "\n"); // Skip para a próxima linha
        fflush(ficheiroVisitas);        // Garante que os dados sejam salvos
    }
    fclose(ficheiroVisitas); // Fecha o arquivo de visitas

    // Abre o arquivo de embaixadores em modo de escrita
    FILE *ficheiroEmbaixadores = fopen(File_Embaixadores, "w");

    if (ficheiroEmbaixadores == NULL) {
        printf("Erro: Não foi possível abrir o arquivo de embaixadores para escrita.\n");
        return;  
    }

    // Escreve os dados dos embaixadores no arquivo
    for (int i = 0; i < num_Embaixadores; i++) {
        fprintf(ficheiroEmbaixadores, "%d,%s,%s,%s",
                embaixadores[i].id, embaixadores[i].escola, 
                embaixadores[i].nome_completo, embaixadores[i].nif);
        fprintf(ficheiroEmbaixadores, "\n"); 
        fflush(ficheiroEmbaixadores);     
    }
    fclose(ficheiroEmbaixadores);

    printf("Dados salvos com sucesso.\n"); 
}
