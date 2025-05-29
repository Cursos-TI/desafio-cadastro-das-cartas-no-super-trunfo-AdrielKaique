// TEMA 2 - Super Trunfo em C: desenvolvendo a lógica do jogo
// Desafio: nível Aventureiro - Implementando menu interativo e comparação por atributo

#include <stdio.h>
#include <string.h> // Necessário para usar strcmp, se precisar comparar strings no futuro (embora os requisitos atuais não exijam)

int main() {
    // Declaração de variáveis 1
@@ -12,7 +13,6 @@ int main() {
    float area1;
    float pib1;
    int pontostur1;
    

    // Declaração de variáveis 2
    char estado2;
@@ -23,15 +23,15 @@ int main() {
    float pib2;
    int pontostur2;

    // Declaração de variáveis para contagem de vitórias
    int vitorias1 = 0; // Contador de vitórias da carta 1
    int vitorias2 = 0; // Contador de vitórias da carta 2
    // Variável para a escolha do atributo no menu
    int escolha_atributo;

    // --- Cadastro das Cartas (Mantido do código anterior) ---

    // Dados 1
    printf("Cadastro da 1ª carta\n");

    printf("Digite o estado (letra de A a H): ");
    scanf(" %c", &estado1);  // espaço antes do %c limpa o buffer
    scanf(" %c", &estado1);

    printf("Digite o código da carta (ex: B02): ");
    scanf("%s", codigo1);
@@ -51,8 +51,10 @@ int main() {
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontostur1);

    // Dados 2
    printf("Cadastro da 2ª carta\n");
    // Limpar o buffer do teclado após o último scanf antes de ler a próxima string
    while (getchar() != '\n');

    printf("\nCadastro da 2ª carta\n");

    printf("Digite o estado (letra de A a H): ");
    scanf(" %c", &estado2);
@@ -75,159 +77,106 @@ int main() {
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontostur2);

    // Cálculos
    // --- Cálculos Derivados (Mantido do código anterior) ---

    // Calcular densidade populacional
    float densidade1 = populacao1 / area1;  // Densidade populacional da carta 1
    float densidade2 = populacao2 / area2;  // Densidade populacional da carta 2
    float densidade1 = (area1 > 0) ? (float)populacao1 / area1 : 0; // Evita divisão por zero
    float densidade2 = (area2 > 0) ? (float)populacao2 / area2 : 0; // Evita divisão por zero

    // Calcular PIB per capita
    // o PIB está em bilhões de reais. A notação 1e9 significa 1 × 10⁹ (ou seja, 1 bilhão)

    float pibPerCapita1 = pib1 * 1e9 / populacao1;  // PIB per capita da carta 1
    float pibPerCapita2 = pib2 * 1e9 / populacao2;  // PIB per capita da carta 2

    // Normalizar os valores para evitar overflow
    // O PIB per capita é calculado em reais, enquanto o PIB é em bilhões de reais. Para evitar overflow, convertemos o PIB para reais.
    float popNorm1 = populacao1 / 1000000.0;         // normaliza por milhão
    float areaNorm1 = area1 / 1000.0;                // normaliza por mil km²
    float pibNorm1 = pib1;                           // já está em bilhões
    float pontosTurNorm1 = pontostur1 / 10.0;        // normaliza por 10
    float pibPerCapitaNorm1 = pibPerCapita1 / 50000.0; // normaliza por 50 mil
    float densidadeInvNorm1 = 1.0f / densidade1 * 100; // dá peso ao inverso

    float popNorm2 = populacao2 / 1000000.0;         // normaliza por milhão
    float areaNorm2 = area2 / 1000.0;                // normaliza por mil km²
    float pibNorm2 = pib2;                           // já está em bilhões
    float pontosTurNorm2 = pontostur2 / 10.0;        // normaliza por 10
    float pibPerCapitaNorm2 = pibPerCapita2 / 50000.0; // normaliza por 50 mil
    float densidadeInvNorm2 = 1.0f / densidade2 * 100; // dá peso ao inverso

    // Calcular super poder
    // O super poder é calculado com todos os valores números da carta, e o inverso da densidade populacional(Quanto menor a densidade, maior o poder.).
    // Armazenando o maior valor em uma variável chamada superPoder1 e o menor em superPoder2.
    float superPoder1 = popNorm1 + areaNorm1 + pibNorm1 + pontosTurNorm1 + pibPerCapitaNorm1 + densidadeInvNorm1;
    float superPoder2 = popNorm2 + areaNorm2 + pibNorm2 + pontosTurNorm2 + pibPerCapitaNorm2 + densidadeInvNorm2;

    // Mostrando as cartas

    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontostur1);
    printf("Densidade Populacional: %.2f habitantes/km²\n", densidade1);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita1);
    printf("Super Poder: %.2f\n", superPoder1);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontostur2);
    printf("Densidade Populacional: %.2f habitantes/km²\n", densidade2);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita2);
    printf("Super Poder: %.2f\n", superPoder2);

    // Comparações
    printf("\nComparações:\n");

    // Comparando População
    if (populacao1 > populacao2) {
        printf("A carta 1 vence!\n");
        vitorias1++;
    } else if (populacao1 < populacao2) {
        printf("A carta 2 vence!\n");
        vitorias2++;
    } else {
        printf("Empate na população!\n");
    }

    // Comparando Área
    if (area1 > area2) {
        printf("A carta 1 vence!\n");
        vitorias1++;
    } else if (area1 < area2) {
        printf("A carta 2 vence!\n");
        vitorias2++;
    } else {
        printf("Empate na área!\n");
    }
    
    // Comparando PIB
    if (pib1 > pib2) {
        printf("A carta 1 vence!\n");
        vitorias1++;
    } else if (pib1 < pib2) {
        printf("A carta 2 vence!\n");
        vitorias2++;
    } else {
        printf("Empate no PIB!\n");
    }
    
    // Comparando Número de Pontos Turísticos
    if (pontostur1 > pontostur2) {
        printf("A carta 1 vence!\n");
        vitorias1++;
    } else if (pontostur1 < pontostur2) {
        printf("A carta 2 vence!\n");
        vitorias2++;
    } else {
        printf("Empate nos pontos turísticos!\n");
    }

    // Comparando  pib per capita
    if (pibPerCapita1 > pibPerCapita2) {
        printf("A carta 1 vence!\n");
        vitorias1++;
    } else if (pibPerCapita1 < pibPerCapita2) {
        printf("A carta 2 vence!\n");
        vitorias2++;
    } else {
        printf("Empate no PIB per capita!\n");
    float pibPerCapita1 = (populacao1 > 0) ? (pib1 * 1e9) / populacao1 : 0; // Evita divisão por zero
    float pibPerCapita2 = (populacao2 > 0) ? (pib2 * 1e9) / populacao2 : 0; // Evita divisão por zero

    // --- Menu Interativo ---

    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite o número do atributo desejado: ");
    scanf("%d", &escolha_atributo);

    // --- Comparação e Exibição do Resultado (Usando switch) ---

    printf("\n--- Resultado da Comparação ---\n");
    printf("Cidades: %s vs %s\n", nomeCidade1, nomeCidade2);

    switch (escolha_atributo) {
        case 1: // População
            printf("Atributo escolhido: População\n");
            printf("Valor %s: %d\n", nomeCidade1, populacao1);
            printf("Valor %s: %d\n", nomeCidade2, populacao2);
            if (populacao1 > populacao2) {
                printf("Vencedor: %s\n", nomeCidade1);
            } else if (populacao1 < populacao2) {
                printf("Vencedor: %s\n", nomeCidade2);
            } else {
                printf("Empate!\n");
            }
            break;

        case 2: // Área
            printf("Atributo escolhido: Área\n");
            printf("Valor %s: %.2f km²\n", nomeCidade1, area1);
            printf("Valor %s: %.2f km²\n", nomeCidade2, area2);
            if (area1 > area2) {
                printf("Vencedor: %s\n", nomeCidade1);
            } else if (area1 < area2) {
                printf("Vencedor: %s\n", nomeCidade2);
            } else {
                printf("Empate!\n");
            }
            break;

        case 3: // PIB
            printf("Atributo escolhido: PIB\n");
            printf("Valor %s: %.2f bilhões de R$\n", nomeCidade1, pib1);
            printf("Valor %s: %.2f bilhões de R$\n", nomeCidade2, pib2);
            if (pib1 > pib2) {
                printf("Vencedor: %s\n", nomeCidade1);
            } else if (pib1 < pib2) {
                printf("Vencedor: %s\n", nomeCidade2);
            } else {
                printf("Empate!\n");
            }
            break;

        case 4: // Número de Pontos Turísticos
            printf("Atributo escolhido: Número de Pontos Turísticos\n");
            printf("Valor %s: %d\n", nomeCidade1, pontostur1);
            printf("Valor %s: %d\n", nomeCidade2, pontostur2);
            if (pontostur1 > pontostur2) {
                printf("Vencedor: %s\n", nomeCidade1);
            } else if (pontostur1 < pontostur2) {
                printf("Vencedor: %s\n", nomeCidade2);
            } else {
                printf("Empate!\n");
            }
            break;

        case 5: // Densidade Demográfica (regra invertida)
            printf("Atributo escolhido: Densidade Demográfica\n");
            printf("Valor %s: %.2f habitantes/km²\n", nomeCidade1, densidade1);
            printf("Valor %s: %.2f habitantes/km²\n", nomeCidade2, densidade2);
            if (densidade1 < densidade2) { // Menor valor ganha para Densidade
                printf("Vencedor: %s\n", nomeCidade1);
            } else if (densidade1 > densidade2) {
                printf("Vencedor: %s\n", nomeCidade2);
            } else {
                printf("Empate!\n");
            }
            break;

        default:
            printf("Opção inválida!\n");
            break;
    }

    // Comparando Densidade Populacional
    if (densidade1 < densidade2) {
        printf("A carta 1 vence!\n");
        vitorias1++;
    } else if (densidade1 > densidade2) {
        printf("A carta 2 vence!\n");
        vitorias2++;
    } else {
        printf("Empate na densidade populacional!\n");
    }

    // Comparando Super Poder
    if (superPoder1 > superPoder2) {
        printf("A carta 1 vence!\n");
        vitorias1++;
    } else if (superPoder1 < superPoder2) {
        printf("A carta 2 vence!\n");
        vitorias2++;
    } else {
        printf("Empate no super poder!\n");
    }


    // Exibindo o placar final
    printf("\nPLACAR FINAL:\n");
    printf("Carta 1: %d vitórias\n", vitorias1);
    printf("Carta 2: %d vitórias\n", vitorias2);

    if (vitorias1 > vitorias2) {
        printf(">>> A Carta 1 é a vencedora!\n");
    } else if (vitorias2 > vitorias1) {
        printf(">>> A Carta 2 é a vencedora!\n");
    } else {
        printf(">>> EMPATE!\n");
    }
    // O código original calculava o Super Poder e fazia todas as comparações.
    // Removemos essa parte para seguir os requisitos de comparar apenas o atributo escolhido.
    // O placar final também foi removido, pois a comparação é de apenas um atributo por vez.

    return 0;
}
