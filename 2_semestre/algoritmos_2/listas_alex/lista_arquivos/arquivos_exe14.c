struct Aluno {
    int numero;
    char nome[50];
    float nota1;
    float nota2;
};

void menu_alunos() {
    int opcao;
    
    do {
        printf("\nMENU DE OPÇÕES\n");
        printf("1. Criar arquivo\n");
        printf("2. Incluir aluno\n");
        printf("3. Sair\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                criar_arquivo_alunos();
                break;
            case 2:
                incluir_aluno();
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 3);
}

void criar_arquivo_alunos() {
    FILE *file = fopen("alunos.txt", "w");
    if (!file) {
        printf("Erro ao criar arquivo!\n");
        return;
    }
    
    fprintf(file, "numero;nome;nota1;nota2\n");
    fclose(file);
    printf("Arquivo de alunos criado com sucesso!\n");
}

void incluir_aluno() {
    struct Aluno novo;
    printf("Número: ");
    scanf("%d", &novo.numero);
    printf("Nome: ");
    scanf(" %[^\n]", novo.nome);
    printf("Nota 1: ");
    scanf("%f", &novo.nota1);
    printf("Nota 2: ");
    scanf("%f", &novo.nota2);

    FILE *file = fopen("alunos.txt", "a");
    if (!file) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }
    
    fprintf(file, "%d;%s;%.1f;%.1f\n", 
            novo.numero, novo.nome, novo.nota1, novo.nota2);
    fclose(file);
    printf("Aluno cadastrado com sucesso!\n");

    // Mostrar todos os registros e médias
    mostrar_alunos();
}

void mostrar_alunos() {
    FILE *file = fopen("alunos.txt", "r");
    if (!file) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    printf("\nLista de alunos e médias:\n");
    char linha[256];
    fgets(linha, sizeof(linha), file); // Pular cabeçalho
    
    while (fgets(linha, sizeof(linha), file)) {
        struct Aluno a;
        sscanf(linha, "%d;%[^;];%f;%f", 
               &a.numero, a.nome, &a.nota1, &a.nota2);
        
        float media = (a.nota1 + a.nota2) / 2;
        printf("%d - %s: Notas: %.1f, %.1f | Média: %.1f\n", 
               a.numero, a.nome, a.nota1, a.nota2, media);
    }

    fclose(file);
}
