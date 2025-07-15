void recebimentos_por_cliente() {
    int cod_cliente;
    printf("Código do cliente: ");
    scanf("%d", &cod_cliente);

    FILE *clientes_file = fopen("clientes.txt", "r");
    FILE *receb_file = fopen("recebimentos.txt", "r");
    
    if (!clientes_file || !receb_file) {
        printf("Erro ao abrir arquivos!\n");
        return;
    }

    // Pular cabeçalhos
    char linha[256];
    fgets(linha, sizeof(linha), clientes_file);
    fgets(linha, sizeof(linha), receb_file);

    // Buscar nome do cliente
    char nome_cliente[50] = "";
    int cliente_encontrado = 0;
    
    while (fgets(linha, sizeof(linha), clientes_file)) {
        struct Cliente cli;
        sscanf(linha, "%d;%[^;];%[^;];%s", 
               &cli.cod_cli, cli.nome, cli.endereco, cli.fone);
        
        if (cli.cod_cli == cod_cliente) {
            strcpy(nome_cliente, cli.nome);
            cliente_encontrado = 1;
            break;
        }
    }

    if (!cliente_encontrado) {
        printf("Cliente não encontrado!\n");
        fclose(clientes_file);
        fclose(reb_file);
        return;
    }

    printf("\nRecebimentos do cliente %s:\n", nome_cliente);
    int total = 0;
    float valor_total = 0.0;

    while (fgets(linha, sizeof(linha), receb_file)) {
        struct Recebimento rec;
        sscanf(linha, "%d;%f;%[^;];%[^;];%d", 
               &rec.num_doc, &rec.valor_doc, 
               rec.data_emissao, rec.data_vencimento, 
               &rec.cod_cli);

        if (rec.cod_cli == cod_cliente) {
            printf("Documento: %d | Valor: R$%.2f\n", rec.num_doc, rec.valor_doc);
            printf("Emissão: %s | Vencimento: %s\n\n", rec.data_emissao, rec.data_vencimento);
            total++;
            valor_total += rec.valor_doc;
        }
    }

    printf("Total de recebimentos: %d\n", total);
    printf("Valor total: R$%.2f\n", valor_total);
    fclose(clientes_file);
    fclose(receb_file);
}
