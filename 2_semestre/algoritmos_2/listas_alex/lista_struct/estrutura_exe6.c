#include <stdio.h>

struct Aluno {
    int matricula;
    char nome[100];
    float notas[3];
};

int main() {
    struct Aluno alunos[5];
    int i, j, melhor = 0;
    float media, maior_media = 0;

    for (i = 0; i < 5; i++) {
        printf("Aluno %d:\n", i + 1);
        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);
        getchar(); // limpar buffer
        printf("Nome: ");
        fgets(alunos[i].nome, 100, stdin);
        for (j = 0; j < 3; j++) {
            printf("Nota %d: ", j + 1);
            scanf("%f", &alunos[i].notas[j]);
        }
        getchar(); // limpar buffer
        media = (alunos[i].notas[0] + alunos[i].notas[1] + alunos[i].notas[2]) / 3;
        if (media > maior_media) {
            maior_media = media;
            melhor = i;
        }
    }

    printf("\nAluno com maior media: %s", alunos[melhor].nome);
    for (i = 0; i < 3; i++)
        printf("Nota %d: %.2f\n", i + 1, alunos[melhor].notas[i]);

    return 0;
}

