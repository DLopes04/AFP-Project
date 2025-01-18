#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "embaixadores.h"
#include "visitas.h"
#include "salvar.h"

int main() {
    
    setlocale(LC_ALL, "pt_PT");
 

    Visita visitas[MAX_VISITAS];                    // Array que armazena todas as visitas
    int totalVisitas = 0;                           // Contador de visitas
    Embaixador embaixadores[MAX_EMBAIXADORES];      // Array que armazena todos os embaixadores
    int totalEmbaixadores = 0;                      // Contador de embaixadores

    // Carrega os dados salvos anteriormente dos arquivos CSV

    carregarDados(visitas, &totalVisitas, embaixadores, &totalEmbaixadores);
    int opcao;  // variavel para a escolha do utilizador

    do {
        printf("\nMenu:\n");
        printf("1. Listar visitas\n");
        printf("2. Listar embaixadores\n");
        printf("3. Consultar visita\n");
        printf("4. Consultar embaixador\n");
        printf("5. Adicionar visita\n");
        printf("6. Adicionar embaixador\n");
        printf("7. Autorizar visita\n");
        printf("8. Salvar dados\n");
        printf("15. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                Listar_visitas(visitas, totalVisitas); break;
            case 2:
                Listar_embaixadores(embaixadores, totalEmbaixadores); break;
            case 3:
                Consultar_visita(visitas, totalVisitas); break;
            case 4:
                Consultar_embaixador(embaixadores, totalEmbaixadores); break;
            case 5:
                Adicionar_visita(visitas, &totalVisitas); break;
            case 6:
                Adicionar_embaixador(embaixadores, &totalEmbaixadores); break;
            case 7:
                Autorizar_visita(visitas, totalVisitas); break;
            case 8:
                salvarDados(visitas, totalVisitas, embaixadores, totalEmbaixadores); printf("\nDados salvos com sucesso.\n"); break;
            case 15: salvarDados(visitas, totalVisitas, embaixadores, totalEmbaixadores); printf("\nSaindo do programa.\n"); break;
            default:
                printf("\nOpção inválida!\n");
        }
    } while (opcao != 15); // sai do loop caso utilizador escolher opção 15

    return 0;
}