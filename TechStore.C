#include <stdio.h>

#define TAMANHO_ESTOQUE 100

typedef struct {
    char nome [50];
    int codigo;
    float preco;
    int quantidade;
} Produto;

Produto estoque [TAMANHO_ESTOQUE];
int totalProdutos= 0;

void registrarEntrada() {
    printf ("Informe o nome do produto: ");
    scanf ("%s", estoque [totalProdutos].nome);

    printf ("Informe o codigo dos produtos: ");
    scanf ("%d", &estoque [totalProdutos].codigo);

    printf ("Informe o preço do produto: ");
    scanf ("%f", &estoque [totalProdutos].preco);

    printf ("Informe a quantidade do produto: ");
    scanf ("%d", &estoque [totalProdutos].quantidade);

    totalProdutos++;
}

void registrarVenda () {
    int codigoProduto;

    printf ("Informe o codigo do produto: ");
    scanf ("%d", &codigoProduto);

    int indiceProduto = -1;
    for (int i = 0; i < totalProdutos; i++) {
        if (estoque[i].codigo == codigoProduto) {
            indiceProduto = i;
            break;
        }
    }
    if (indiceProduto != -1) {
        if (estoque [indiceProduto].quantidade > 0) {
            printf ("Produto disponivel! Realize o registro da venda.\n");
            estoque[indiceProduto].quantidade--;
        } else {
            printf ("Produto esgotado!\n");
        } 
       } else {
            printf ("Produto nao encontrado!\n");
        }
    }

    void gerarRelatorio () {
        for (int i = 0; i < totalProdutos; i++) {

            printf ("Nome: %s\n", estoque[i].nome);
            printf ("Codigo: %d\n", estoque[i].codigo);
            printf ("Quantidade: %d\n", estoque[i].quantidade);
            printf ("------------------\n");
        }
    }

    int main () {
        int opcao;

        do {
            printf ("===== MENU ====\n");
            printf ("1. Registrar entrada de produto\n");
            printf ("2. Registrar venda de produto\n");
            printf ("3. Gerar relatorio de estoque\n");
            printf ("4. Sair\n");
            scanf ("%d", &opcao);

            if (opcao == 1) {
                registrarEntrada ();
            } else if (opcao == 2) {
                registrarVenda ();
            } else if (opcao == 3) {
                gerarRelatorio ();
            }
        } while (opcao != 4);

    return 0;
    }

