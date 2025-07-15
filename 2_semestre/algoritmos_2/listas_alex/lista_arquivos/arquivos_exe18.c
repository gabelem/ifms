void aumentar_precos_15porcento() {
    FILE *file = fopen("PRODUTOS.txt", "r");
    if (!file) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    // Criar arquivo temporário
    FILE *temp = fopen("temp.txt", "w");
    if (!temp) {
        printf("Erro ao criar arquivo temporário!\n");
        fclose(file);
        return;
    }

    char linha[256];
    fgets(linha, sizeof(linha), file); // Ler cabeçalho
    fprintf(temp, "%s", linha); // Escrever cabeçalho
    
    while (fgets(linha, sizeof(linha), file)) {
        struct Produto p;
        sscanf(linha, "%d;%[^;];%f", &p.codigo, p.descricao, &p.preco);
        p.preco *= 1.15; // Aumento de 15%
        fprintf(temp, "%d;%s;%.2f\n", p.codigo, p.descricao, p.preco);
    }

    fclose(file);
    fclose(temp);

    // Substituir arquivo original
    remove("PRODUTOS.txt");
    rename("temp.txt", "PRODUTOS.txt");
    printf("Preços atualizados com aumento de 15%%!\n");
}
