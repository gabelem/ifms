void aplicar_desconto() {
    float min, max, desconto;
    
    printf("Preço mínimo: ");
    scanf("%f", &min);
    printf("Preço máximo: ");
    scanf("%f", &max);
    printf("Percentual de desconto: ");
    scanf("%f", &desconto);

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
        
        if (p.preco >= min && p.preco <= max) {
            p.preco *= (1 - desconto/100);
            atualizados++;
        }
        
        fprintf(temp, "%d;%s;%.2f\n", p.codigo, p.descricao, p.preco);
    }

    fclose(file);
    fclose(temp);

    remove("PRODUTOS.txt");
    rename("temp.txt", "PRODUTOS.txt");
    printf("%d produtos tiveram desconto de %.1f%% aplicado!\n", atualizados, desconto);
}
