struct Estilista {
    int codigo;
    char nome[50];
    float salario;
};

struct Roupa {
    int codigo;
    char descricao[100];
    int cod_estilista;
    int cod_estacao;
    int ano;
};

struct Estacao {
    int codigo;
    char nome[50];
};

void cadastrar_estacao() {
    struct Estacao nova;
    printf("Código da estação: ");
    scanf("%d", &nova.codigo);
    printf("Nome da estação: ");
    scanf(" %[^\n]", nova.nome);

    FILE *file = fopen("estacoes.txt", "a");
    if (!file) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }
    
    fprintf(file, "%d;%s\n", nova.codigo, nova.nome);
    fclose(file);
    printf("Estação cadastrada com sucesso!\n");
}

void cadastrar_estilista() {
    struct Estilista novo;
    printf("Código do estilista: ");
    scanf("%d", &novo.codigo);
    printf("Nome do estilista: ");
    scanf(" %[^\n]", novo.nome);
    printf("Salário: ");
    scanf("%f", &novo.salario);

    FILE *file = fopen("estilistas.txt", "a");
    if (!file) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }
    
    fprintf(file, "%d;%s;%.2f\n", novo.codigo, novo.nome, novo.salario);
    fclose(file);
    printf("Estilista cadastrado com sucesso!\n");
}

void cadastrar_roupa() {
    struct Roupa nova;
    printf("Código da roupa: ");
    scanf("%d", &nova.codigo);
    printf("Descrição: ");
    scanf(" %[^\n]", nova.descricao);
    printf("Código do estilista: ");
    scanf("%d", &nova.cod_estilista);
    printf("Código da estação: ");
    scanf("%d", &nova.cod_estacao);
    printf("Ano: ");
    scanf("%d", &nova.ano);

    // Verificar se estilista e estação existem
    FILE *estilistas = fopen("estilistas.txt", "r");
    FILE *estacoes = fopen("estacoes.txt", "r");
    
    if (!estilistas || !estacoes) {
        printf("Erro ao verificar arquivos!\n");
        if (estilistas) fclose(estilistas);
        if (estacoes) fclose(estacoes);
        return;
    }

    int estilista_existe = 0, estacao_existe = 0;
    char linha[256];
    
    // Pular cabeçalhos
    fgets(linha, sizeof(linha), estilistas);
    fgets(linha, sizeof(linha), estacoes);

    // Verificar estilista
    while (fgets(linha, sizeof(linha), estilistas)) {
        int cod;
        sscanf(linha, "%d;", &cod);
        if (cod == nova.cod_estilista) {
            estilista_existe = 1;
            break;
        }
    }

    // Verificar estação
    while (fgets(linha, sizeof(linha), estacoes)) {
        int cod;
        sscanf(linha, "%d;", &cod);
        if (cod == nova.cod_estacao) {
            estacao_existe = 1;
            break;
        }
    }

    fclose(estilistas);
    fclose(estacoes);

    if (!estilista_existe || !estacao_existe) {
        printf("Erro: %s não encontrado!\n", 
               !estilista_existe ? "Estilista" : "Estação");
        return;
    }

    // Cadastrar roupa
    FILE *roupas = fopen("roupas.txt", "a");
    if (!roupas) {
        printf("Erro ao abrir arquivo de roupas!\n");
        return;
    }
    
    fprintf(roupas, "%d;%s;%d;%d;%d\n", 
            nova.codigo, nova.descricao, 
            nova.cod_estilista, nova.cod_estacao, nova.ano);
    fclose(roupas);
    printf("Roupa cadastrada com sucesso!\n");
}

void relatorio_roupas_estacao() {
    int cod_estacao;
    printf("Código da estação: ");
    scanf("%d", &cod_estacao);

    FILE *estacoes = fopen("estacoes.txt", "r");
    FILE *roupas = fopen("roupas.txt", "r");
    FILE *estilistas = fopen("estilistas.txt", "r");
    
    if (!estacoes || !roupas || !estilistas) {
        printf("Erro ao abrir arquivos!\n");
        if (estacoes) fclose(estacoes);
        if (roupas) fclose(roupas);
        if (estilistas) fclose(estilistas);
        return;
    }

    // Buscar nome da estação
    char nome_estacao[50] = "Desconhecida";
    char linha[256];
    fgets(linha, sizeof(linha), estacoes); // Pular cabeçalho
    
    while (fgets(linha, sizeof(linha), estacoes)) {
        int cod;
        char nome[50];
        sscanf(linha, "%d;%[^\n]", &cod, nome);
        
        if (cod == cod_estacao) {
            strcpy(nome_estacao, nome);
            break;
        }
    }
    fclose(estacoes);

    printf("\nRelatório de roupas da estação: %s\n", nome_estacao);

    // Ler estilistas para memória
    struct Estilista {
        int codigo;
        char nome[50];
    } estilistas_arr[100];
    
    int num_estilistas = 0;
    fgets(linha, sizeof(linha), estilistas); // Pular cabeçalho
    
    while (fgets(linha, sizeof(linha), estilistas)) {
        sscanf(linha, "%d;%[^;]", &estilistas_arr[num_estilistas].codigo, 
               estilistas_arr[num_estilistas].nome);
        num_estilistas++;
    }
    fclose(estilistas);

    // Processar roupas
    fgets(linha, sizeof(linha), roupas); // Pular cabeçalho
    int encontradas = 0;
    
    while (fgets(linha, sizeof(linha), roupas)) {
        struct Roupa r;
        sscanf(linha, "%d;%[^;];%d;%d;%d", 
               &r.codigo, r.descricao, 
               &r.cod_estilista, &r.cod_estacao, &r.ano);

        if (r.cod_estacao == cod_estacao) {
            // Encontrar nome do estilista
            char nome_estilista[50] = "Desconhecido";
            for (int i = 0; i < num_estilistas; i++) {
                if (estilistas_arr[i].codigo == r.cod_estilista) {
                    strcpy(nome_estilista, estilistas_arr[i].nome);
                    break;
                }
            }

            printf("\nCódigo: %d | Descrição: %s\n", r.codigo, r.descricao);
            printf("Estilista: %s | Ano: %d\n", nome_estilista, r.ano);
            encontradas++;
        }
    }

    fclose(roupas);
    printf("\nTotal de roupas encontradas: %d\n", encontradas);
}
