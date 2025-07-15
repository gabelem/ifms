void consultar_produtos_M() {
    FILE *file = fopen("PRODUTOS.txt", "r");
    if (!file) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    char linha[256];
    fgets(linha, sizeof(linha), file);
    
    printf("\nProdutos que começam com 'M':\n");
    int encontrados = 0;
    
    while (fgets(linha, sizeof(linha), file)) {
        struct Produto p;
        sscanf(linha, "%d;%[^;];%f", &p.codigo, p.descricao, &p.preco);
        
        if (p.descricao[0] == 'M' || p.descricao[0] == 'm') {
            printf("Código: %d | Descrição: %s | Preço: R$%.2f\n", 
                   p.codigo, p.descricao, p.preco);
            encontrados++;
        }
    }
    
    printf("Total encontrado: %d\n", encontrados);
    fclose(file);
}
