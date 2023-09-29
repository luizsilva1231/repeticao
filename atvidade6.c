#include <stdio.h>
#include <ctype.h> // Para usar a função tolower()

int main() {
    int num_homens = 0;
    int num_mulheres = 0;
    float soma_altura_homens = 0.0;
    float soma_altura_mulheres = 0.0;
    float soma_peso_homens = 0.0;
    float soma_peso_mulheres = 0.0;
    float soma_altura_total = 0.0;
    float soma_peso_total = 0.0;

    for (int i = 1; i <= 10; i++) {
        char nome[100];
        char sexo;
        float altura;
        float peso;

        printf("Informe o nome da pessoa %d: ", i);
        scanf("%s", nome);

        printf("Informe o sexo (M/F) da pessoa %d: ", i);
        scanf(" %c", &sexo);
        sexo = tolower(sexo); // Converte para minúsculas para facilitar a comparação

        printf("Informe a altura (em metros) da pessoa %d: ", i);
        scanf("%f", &altura);

        printf("Informe o peso (em quilogramas) da pessoa %d: ", i);
        scanf("%f", &peso);

        if (sexo == 'm') {
            num_homens++;
            soma_altura_homens += altura;
            soma_peso_homens += peso;
        } else if (sexo == 'f') {
            num_mulheres++;
            soma_altura_mulheres += altura;
            soma_peso_mulheres += peso;
        }

        soma_altura_total += altura;
        soma_peso_total += peso;
    }

    float altura_media_homens = num_homens > 0 ? soma_altura_homens / num_homens : 0.0;
    float altura_media_mulheres = num_mulheres > 0 ? soma_altura_mulheres / num_mulheres : 0.0;
    float altura_media_grupo = soma_altura_total / 10;
    float peso_media_homens = num_homens > 0 ? soma_peso_homens / num_homens : 0.0;
    float peso_media_mulheres = num_mulheres > 0 ? soma_peso_mulheres / num_mulheres : 0.0;
    float peso_media_grupo = soma_peso_total / 10;

    printf("\nEstatísticas do grupo:\n");
    printf("Número de homens: %d\n", num_homens);
    printf("Número de mulheres: %d\n", num_mulheres);
    printf("Altura média dos homens: %.2f metros\n", altura_media_homens);
    printf("Altura média das mulheres: %.2f metros\n", altura_media_mulheres);
    printf("Altura média do grupo: %.2f metros\n", altura_media_grupo);
    printf("Peso médio dos homens: %.2f quilogramas\n", peso_media_homens);
    printf("Peso médio das mulheres: %.2f quilogramas\n", peso_media_mulheres);
    printf("Peso médio do grupo: %.2f quilogramas\n", peso_media_grupo);

    return 0;
}