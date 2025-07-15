void consultar_produtos_filtrados() {
    char letra;
    float preco_min, preco_max;
    
    printf("Letra inicial: ");
    scanf(" %c", &letra);
    printf("Preço mínimo: ");
    scanf("%f", &preco_min);
    printf("Preço máximo: ");
    scanf("%f", &preco_max);

    FILE *file = fopen("PRODUTOS.txt", "r");
    if (!file) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    char linha[256];
    fgets(linha, sizeof(linha), file);
    
    printf("\nProdutos encontrados:\n");
    int encontrados = 0;
    
    while (fgets(linha, sizeof(linha), file)) {
        struct Produto p;
        sscanf(linha, "%d;%[^;];%f", &p.codigo, p.descricao, &p.preco);
        
        if ((p.descricao[0] == letra || p.descricao[0] == letra + 32 || 
             p.descricao[0] == letra - 32) && 
            p.preco >= preco_min && p.preco <= preco_max) {
            
            printf("Código: %d | Descrição: %s | Preço: R$%.2f\n", 
                   p.codigo, p.descricao, p.preco);
            encontrados++;
        }
    }
    
    printf("Total encontrado: %d\n", encontrados);
    fclose(file);
}
