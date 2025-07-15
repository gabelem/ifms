void excluir_produto() {
    int codigo;
    printf("Código do produto a excluir: ");
    scanf("%d", &codigo);

    FILE *file = fopen("PRODUTOS.txt", "r");
    if (!file) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    if (!temp) {
        printf("Erro ao criar arquivo temporário!\n");
        fclose(file);
        return;
    }

    char linha[256];
    fgets(linha, sizeof(linha), file);
    fprintf(temp, "%s", linha);
    
    int encontrado = 0;
    
    while (fgets(linha, sizeof(linha), file)) {
        struct Produto p;
        sscanf(linha, "%d;%[^;];%f", &p.codigo, p.descricao, &p.preco);
        
        if (p.codigo == codigo) {
            encontrado = 1;
            continue; // Não escreve no arquivo temporário
        }
        
        fprintf(temp, "%d;%s;%.2f\n", p.codigo, p.descricao, p.preco);
    }

    fclose(file);
    fclose(temp);

    remove("PRODUTOS.txt");
    rename("temp.txt", "PRODUTOS.txt");
    
    if (encontrado) {
        printf("Produto excluído com sucesso!\n");
    } else {
        printf("Produto não encontrado!\n");
        remove("temp.txt");
    }
}
