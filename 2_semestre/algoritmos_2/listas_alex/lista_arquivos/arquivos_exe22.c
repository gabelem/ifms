void consultar_produtos_baratos() {
    FILE *file = fopen("PRODUTOS.txt", "r");
    if (!file) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    char linha[256];
    fgets(linha, sizeof(linha), file);
    
    printf("\nProdutos com preço inferior a R$15.00:\n");
    int encontrados = 0;
    
    while (fgets(linha, sizeof(linha), file)) {
        struct Produto p;
        sscanf(linha, "%d;%[^;];%f", &p.codigo, p.descricao, &p.preco);
        
        if (p.preco < 15.0) {
            printf("Código: %d | Descrição: %s | Preço: R$%.2f\n", 
                   p.codigo, p.descricao, p.preco);
            encontrados++;
        }
    }
    
    printf("Total encontrado: %d\n", encontrados);
    fclose(file);
}
