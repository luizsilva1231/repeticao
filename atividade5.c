#include <stdio.h>
#include <string.h>

#define MAX_JOGADORAS 5  // Defina o número de jogadoras na tabela
#define MAX_PESSOAS 300
#define MIN_PESSOAS 50

// Estrutura para representar uma pessoa
struct Pessoa {
    char nome[50];
    int idade;
    char sexo;
    char voto;
};

// Estrutura para representar uma jogadora
struct Jogadora {
    char nome[50];
    char voto;
    int votos;
};

int main() {
    struct Jogadora jogadoras[MAX_JOGADORAS];
    struct Pessoa pessoas[MAX_PESSOAS];
    int num_pessoas = 0;
    int num_mulheres = 0;
    int num_maior_idade = 0;
    int num_menor_idade = 0;
    int num_votos_marta = 0;

    // Inicialize a lista de jogadoras
    strcpy(jogadoras[0].nome, "Marta Vieira");
    jogadoras[0].voto = 'A';
    jogadoras[0].votos = 0;

    // Adicione outras jogadoras conforme necessário

    // Solicita que o usuário insira os dados das pessoas entrevistadas
    printf("Pesquisa sobre a Melhor Jogadora da Copa do Mundo de Futebol Feminino:\n");

    do {
        printf("Informe o nome da pessoa entrevistada (ou 'FIM' para encerrar): ");
        scanf(" %[^\n]s", pessoas[num_pessoas].nome);

        if (strcmp(pessoas[num_pessoas].nome, "FIM") == 0) {
            break;
        }

        printf("Informe a idade da pessoa entrevistada (maior que 12 anos): ");
        scanf("%d", &pessoas[num_pessoas].idade);

        printf("Informe o sexo da pessoa entrevistada (M/F): ");
        scanf(" %c", &pessoas[num_pessoas].sexo);

        printf("Informe o voto da pessoa entrevistada (A/B/C/D/E): ");
        scanf(" %c", &pessoas[num_pessoas].voto);

        if (pessoas[num_pessoas].idade >= 12 && (pessoas[num_pessoas].voto == 'A' || pessoas[num_pessoas].voto == 'B' || pessoas[num_pessoas].voto == 'C' || pessoas[num_pessoas].voto == 'D' || pessoas[num_pessoas].voto == 'E')) {
            num_pessoas++;

            // Contabilize o sexo, maior/menor de idade e os votos na Marta Vieira
            if (pessoas[num_pessoas - 1].sexo == 'F') {
                num_mulheres++;
            }

            if (pessoas[num_pessoas - 1].idade >= 18) {
                num_maior_idade++;
            } else {
                num_menor_idade++;
            }

            if (pessoas[num_pessoas - 1].voto == 'A') {
                num_votos_marta++;
            }

            // Contabilize os votos para as jogadoras
            for (int i = 0; i < MAX_JOGADORAS; i++) {
                if (pessoas[num_pessoas - 1].voto == jogadoras[i].voto) {
                    jogadoras[i].votos++;
                }
            }
        } else {
            printf("Dados inválidos! Certifique-se de que a idade seja maior que 12 e o voto esteja na lista (A/B/C/D/E).\n");
        }
    } while (num_pessoas < MAX_PESSOAS);

    // Exibir a quantidade de votos que cada jogadora recebeu
    printf("\nQuantidade de votos para cada jogadora:\n");
    for (int i = 0; i < MAX_JOGADORAS; i++) {
        printf("%s: %d votos\n", jogadoras[i].nome, jogadoras[i].votos);
    }

    // Encontrar a jogadora mais votada
    int max_votos = 0;
    printf("\nJogadora(s) mais votada(s):\n");
    for (int i = 0; i < MAX_JOGADORAS; i++) {
        if (jogadoras[i].votos > max_votos) {
            max_votos = jogadoras[i].votos;
        }
    }
    for (int i = 0; i < MAX_JOGADORAS; i++) {
        if (jogadoras[i].votos == max_votos) {
            printf("%s\n", jogadoras[i].nome);
        }
    }

    // Exibir o nome, idade e sexo de todas as pessoas que participaram da pesquisa
    printf("\nPessoas que participaram da pesquisa:\n");
    for (int i = 0; i < num_pessoas; i++) {
        printf("Nome: %s, Idade: %d, Sexo: %c\n", pessoas[i].nome, pessoas[i].idade, pessoas[i].sexo);
    }

    // Exibir o nome das pessoas maior de idade que votaram na Marta Vieira
    printf("\nPessoas maior de idade que votaram na Marta Vieira:\n");
    for (int i = 0; i < num_pessoas; i++) {
        if (pessoas[i].idade >= 18 && pessoas[i].voto == 'A') {
            printf("%s\n", pessoas[i].nome);
        }
    }

    // Exibir a quantidade de mulheres que participaram da pesquisa
    printf("\nQuantidade de mulheres que participaram da pesquisa: %d\n", num_mulheres);

    return 0;
}