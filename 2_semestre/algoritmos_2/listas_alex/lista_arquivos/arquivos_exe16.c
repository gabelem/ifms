struct Produto {
    int codigo;
    char descricao[100];
    float preco;
};

void incluir_produto() {
    struct Produto novo;
    printf("Código: ");
    scanf("%d", &novo.codigo);
    printf("Descrição: ");
    scanf(" %[^\n]", novo.descricao);
    printf("Preço: ");
    scanf("%f", &novo.preco);

    // Verificar se código já existe
    FILE *file = fopen("PRODUTOS.txt", "r");
    if (file) {
        char linha[256];
        fgets(linha, sizeof(linha), file); // Pular cabeçalho
        
        while (fgets(linha, sizeof(linha), file)) {
            int cod;
            sscanf(linha, "%d;", &cod);
            if (cod == novo.codigo) {
                printf("Erro: Código já existe!\n");
                fclose(file);
                return;
            }
        }
        fclose(file);
    }

    // Adicionar novo produto
    file = fopen("PRODUTOS.txt", "a");
    if (!file) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }
    
    fprintf(file, "%d;%s;%.2f\n", novo.codigo, novo.descricao, novo.preco);
    fclose(file);
    printf("Produto adicionado com sucesso!\n");
}
