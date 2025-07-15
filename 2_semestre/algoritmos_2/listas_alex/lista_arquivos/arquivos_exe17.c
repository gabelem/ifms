void consultar_produtos_caros() {
    FILE *file = fopen("PRODUTOS.txt", "r");
    if (!file) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    char linha[256];
    fgets(linha, sizeof(linha), file); // Pular cabeçalho
    
    printf("\nProdutos com preço superior a R$500.00:\n");
    int encontrados = 0;
    
    while (fgets(linha, sizeof(linha), file)) {
        struct Produto p;
        sscanf(linha, "%d;%[^;];%f", &p.codigo, p.descricao, &p.preco);
        
        if (p.preco > 500.0) {
            printf("Código: %d | Descrição: %s | Preço: R$%.2f\n", 
                   p.codigo, p.descricao, p.preco);
            encontrados++;
        }
    }
    
    printf("Total encontrado: %d\n", encontrados);
    fclose(file);
}
