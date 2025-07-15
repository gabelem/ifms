void criar_arquivo_produtos() {
    FILE *file = fopen("PRODUTOS.txt", "w");
    if (!file) {
        printf("Erro ao criar arquivo!\n");
        return;
    }
    fprintf(file, "codigo;descricao;preco\n");
    fclose(file);
    printf("Arquivo PRODUTOS.txt criado com sucesso!\n");
}
