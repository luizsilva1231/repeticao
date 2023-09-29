#include <stdio.h>

int main() {
    int elevadorA = 0, elevadorB = 0, elevadorC = 0;
    int matutino = 0, vespertino = 0, noturno = 0;
    int total_usos = 0;

    for (int i = 0; i < 50; i++) {
        char elevador, periodo;

        printf("Resposta do morador %d:\n", i + 1);

        printf("Elevador mais utilizado (A/B/C): ");
        scanf(" %c", &elevador);

        printf("Período mais utilizado (M/V/N): ");
        scanf(" %c", &periodo);

        // Contabilizar o uso dos elevadores e períodos
        switch (elevador) {
            case 'A':
                elevadorA++;
                break;
            case 'B':
                elevadorB++;
                break;
            case 'C':
                elevadorC++;
                break;
            default:
                printf("Elevador inválido. Use A, B ou C.\n");
                i--;  // Repetir a entrada para este morador
                continue;
        }

        switch (periodo) {
            case 'M':
                matutino++;
                break;
            case 'V':
                vespertino++;
                break;
            case 'N':
                noturno++;
                break;
            default:
                printf("Período inválido. Use M, V ou N.\n");
                i--;  // Repetir a entrada para este morador
                continue;
        }

        total_usos++;
    }

    // Encontrar o período mais usado
    char periodo_mais_usado;
    int max_periodo_usado = matutino;

    if (vespertino > max_periodo_usado) {
        max_periodo_usado = vespertino;
        periodo_mais_usado = 'V';
    }

    if (noturno > max_periodo_usado) {
        max_periodo_usado = noturno;
        periodo_mais_usado = 'N';
    }

    printf("O período mais usado de todos é o período %c e pertence ao elevador: ", periodo_mais_usado);
    if (periodo_mais_usado == 'M') {
        printf("A\n");
    } else if (periodo_mais_usado == 'V') {
        printf("B\n");
    } else {
        printf("C\n");
    }

    // Encontrar o elevador mais frequentado
    char elevador_mais_frequentado;
    int max_uso_elevador = elevadorA;

    if (elevadorB > max_uso_elevador) {
        max_uso_elevador = elevadorB;
        elevador_mais_frequentado = 'B';
    }

    if (elevadorC > max_uso_elevador) {
        max_uso_elevador = elevadorC;
        elevador_mais_frequentado = 'C';
    }

    printf("O elevador mais frequentado é o elevador %c e no período: ", elevador_mais_frequentado);
    if (elevador_mais_frequentado == 'A') {
        printf("A\n");
    } else if (elevador_mais_frequentado == 'B') {
        printf("B\n");
    } else {
        printf("C\n");
    }

    // Calcular a diferença percentual entre o mais usado dos horários e o menos usado
    int min_periodo_usado = matutino;

    if (vespertino < min_periodo_usado) {
        min_periodo_usado = vespertino;
    }

    if (noturno < min_periodo_usado) {
        min_periodo_usado = noturno;
    }

    float diferenca_percentual = ((float)(max_periodo_usado - min_periodo_usado) / max_periodo_usado) * 100;
    printf("Diferença percentual entre o mais usado dos horários e o menos usado: %.2f%%\n", diferenca_percentual);

    // Calcular a percentagem sobre o total de serviços prestados do elevador de média utilização
    int elevador_media_utilizacao = (elevadorA + elevadorB + elevadorC) / 3;
    float percentagem_media_utilizacao = ((float)elevador_media_utilizacao / total_usos) * 100;
    printf("Percentagem sobre o total de serviços prestados do elevador de média utilização: %.2f%%\n", percentagem_media_utilizacao);

    return 0;
}