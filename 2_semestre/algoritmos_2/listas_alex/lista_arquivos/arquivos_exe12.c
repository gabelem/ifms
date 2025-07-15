void criar_arquivos_moda() {
    // Arquivo de estilistas
    FILE *estilistas = fopen("estilistas.txt", "w");
    if (estilistas) {
        fprintf(estilistas, "codigo;nome;salario\n");
        fclose(estilistas);
    }
    
    // Arquivo de roupas
    FILE *roupas = fopen("roupas.txt", "w");
    if (roupas) {
        fprintf(roupas, "codigo;descricao;cod_estilista;cod_estacao;ano\n");
        fclose(roupas);
    }
    
    // Arquivo de estações
    FILE *estacoes = fopen("estacoes.txt", "w");
    if (estacoes) {
        fprintf(estacoes, "codigo;nome\n");
        fclose(estacoes);
    }
    
    printf("Arquivos do sistema de moda criados com sucesso!\n");
}
