#include <stdio.h>

int main() {
    int n;
    long long int termo_atual = 0; // Para evitar estouro de inteiros
    long long int termo_anterior = 1;
    long long int termo_anterior_anterior = 0;

    printf("Digite um número inteiro não negativo n: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Por favor, insira um número não negativo.\n");
    } else if (n == 0) {
        printf("O termo de ordem 0 na sequência de Fibonacci é: 0\n");
    } else if (n == 1) {
        printf("O termo de ordem 1 na sequência de Fibonacci é: 1\n");
    } else {
        for (int i = 2; i <= n; i++) {
            termo_atual = termo_anterior + termo_anterior_anterior;
            termo_anterior_anterior = termo_anterior;
            termo_anterior = termo_atual;
        }
        printf("O termo de ordem %d na sequência de Fibonacci é: %lld\n", n, termo_atual);
    }

    return 0;
}