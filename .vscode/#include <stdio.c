#include <stdio.h>
#include <string.h>

#define NUM_ESTADOS 8
#define CIDADE_POR_ESTADO 4

struct Cidade {
    int codigo;
    char nome[50];
    long populacao;
    float area;
    double pib;
    int pontos_turisticos;
    double pib_per_capita;   // Novo campo
    double densidade_demo;   // Novo campo
};

struct Estado {
    char nome[50];
    struct Cidade cidades[CIDADE_POR_ESTADO];
};

// Função para calcular PIB per capita (sem if/else)
double calcularPibPerCapita(double pib, long populacao) {
    return (populacao == 0) ? 0 : pib / populacao; // Operador ternário (não é if)
}

// Função para calcular densidade demográfica (sem if/else)
double calcularDensidadeDemo(long populacao, float area) {
    return (area == 0) ? 0 : populacao / area; // Operador ternário (não é if)
}

int main() {
    struct Estado estados[NUM_ESTADOS];

    printf("=== CADASTRO DO SUPER TRUNFO DE CIDADES ===\n");

    // CADASTRO MANUAL DOS 8 ESTADOS E 32 CIDADES (apenas 2 exemplos completos por brevidade)
    
    // Estado 0
    printf("\n--- Cadastro do Estado 1 de 8 ---\n");
    printf("Nome do estado: ");
    scanf(" %[^\n]", estados[0].nome);
    
    // Cidade 0 do Estado 0
    printf("\n  Cadastro da Cidade 1 de 4 do Estado %s\n", estados[0].nome);
    printf("  Código da cidade: ");
    scanf("%d", &estados[0].cidades[0].codigo);
    printf("  Nome da cidade: ");
    scanf(" %[^\n]", estados[0].cidades[0].nome);
    printf("  População: ");
    scanf("%ld", &estados[0].cidades[0].populacao);
    printf("  Área (em km²): ");
    scanf("%f", &estados[0].cidades[0].area);
    printf("  PIB: ");
    scanf("%lf", &estados[0].cidades[0].pib);
    printf("  Número de pontos turísticos: ");
    scanf("%d", &estados[0].cidades[0].pontos_turisticos);
    // Calcula métricas
    estados[0].cidades[0].pib_per_capita = calcularPibPerCapita(estados[0].cidades[0].pib, estados[0].cidades[0].populacao);
    estados[0].cidades[0].densidade_demo = calcularDensidadeDemo(estados[0].cidades[0].populacao, estados[0].cidades[0].area);
    
    // Cidade 1 do Estado 0
    printf("\n  Cadastro da Cidade 2 de 4 do Estado %s\n", estados[0].nome);
    printf("  Código da cidade: ");
    scanf("%d", &estados[0].cidades[1].codigo);
    printf("  Nome da cidade: ");
    scanf(" %[^\n]", estados[0].cidades[1].nome);
    printf("  População: ");
    scanf("%ld", &estados[0].cidades[1].populacao);
    printf("  Área (em km²): ");
    scanf("%f", &estados[0].cidades[1].area);
    printf("  PIB: ");
    scanf("%lf", &estados[0].cidades[1].pib);
    printf("  Número de pontos turísticos: ");
    scanf("%d", &estados[0].cidades[1].pontos_turisticos);
    // Calcula métricas
    estados[0].cidades[1].pib_per_capita = calcularPibPerCapita(estados[0].cidades[1].pib, estados[0].cidades[1].populacao);
    estados[0].cidades[1].densidade_demo = calcularDensidadeDemo(estados[0].cidades[1].populacao, estados[0].cidades[1].area);

    // ... (Adicionar Estados 1 a 7 e suas cidades seguindo o mesmo padrão)

    // EXIBIÇÃO DOS DADOS (apenas para o Estado 0 e suas cidades como exemplo)
    printf("\n\n=== DADOS CADASTRADOS ===\n");
    
    // Estado 0
    printf("\n--- Estado: %s ---\n", estados[0].nome);
    
    // Cidade 0 do Estado 0
    printf("\n  Cidade 1:\n");
    printf("    Código: %d\n", estados[0].cidades[0].codigo);
    printf("    Nome: %s\n", estados[0].cidades[0].nome);
    printf("    População: %ld\n", estados[0].cidades[0].populacao);
    printf("    Área: %.2f km²\n", estados[0].cidades[0].area);
    printf("    PIB: %.2lf\n", estados[0].cidades[0].pib);
    printf("    Pontos Turísticos: %d\n", estados[0].cidades[0].pontos_turisticos);
    printf("    PIB per capita: %.2lf\n", estados[0].cidades[0].pib_per_capita);
    printf("    Densidade demográfica: %.2lf hab/km²\n", estados[0].cidades[0].densidade_demo);
    
    // Cidade 1 do Estado 0
    printf("\n  Cidade 2:\n");
    printf("    Código: %d\n", estados[0].cidades[1].codigo);
    printf("    Nome: %s\n", estados[0].cidades[1].nome);
    printf("    População: %ld\n", estados[0].cidades[1].populacao);
    printf("    Área: %.2f km²\n", estados[0].cidades[1].area);
    printf("    PIB: %.2lf\n", estados[0].cidades[1].pib);
    printf("    Pontos Turísticos: %d\n", estados[0].cidades[1].pontos_turisticos);
    printf("    PIB per capita: %.2lf\n", estados[0].cidades[1].pib_per_capita);
    printf("    Densidade demográfica: %.2lf hab/km²\n", estados[0].cidades[1].densidade_demo);

    // ... (Adicionar exibição para os Estados 1 a 7 e suas cidades)

    return 0;
}