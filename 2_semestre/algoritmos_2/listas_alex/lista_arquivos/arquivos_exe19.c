void aumentar_precos_10reais() {
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
    
    int atualizados = 0;
    
    while (fgets(linha, sizeof(linha), file)) {
        struct Produto p;
        sscanf(linha, "%d;%[^;];%f", &p.codigo, p.descricao, &p.preco);
        
        if (p.preco > 100.0) {
            p.preco += 10.0;
            atualizados++;
        }
        
        fprintf(temp, "%d;%s;%.2f\n", p.codigo, p.descricao, p.preco);
    }

    fclose(file);
    fclose(temp);

    remove("PRODUTOS.txt");
    rename("temp.txt", "PRODUTOS.txt");
    printf("%d produtos tiveram aumento de R$10.00!\n", atualizados);
}
