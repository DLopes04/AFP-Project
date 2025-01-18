#ifndef SALVAR_H
#define SALVAR_H

#include "embaixadores.h"
#include "visitas.h"

// Função para carregar dados de embaixadores e visitas de arquivos CSV
void carregarDados(Visita* visitas, int* num_Visitas, Embaixador* embaixadores, int* num_Embaixadores);

// Função para salvar dados de embaixadores e visitas em arquivos CSV
void salvarDados(Visita* visitas, int num_Visitas, Embaixador* embaixadores, int num_Embaixadores);

#endif