int main() {
    // ----------------------------
    // 1. DECLARAÇÃO DE VARIÁVEIS
    // ----------------------------

    // Matriz 10x10 representando o tabuleiro
    // 0 = água / 3 = parte do navio
    int tabuleiro[10][10];

    // Vetores representando os navios (3 posições cada)
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};

    // Coordenadas iniciais dos navios
    // (definidas diretamente no código conforme o desafio)
    int linhaHorizontal = 2; // Linha onde o navio horizontal começa
    int colunaHorizontal = 4; // Coluna inicial do navio horizontal
    int linhaVertical = 5; // Linha inicial do navio vertical
    int colunaVertical = 7; // Coluna onde o navio vertical começa

    // Tamanho fixo dos navios
    int tamanhoNavio = 3;

    // ----------------------------
    // 2. INICIALIZAR O TABULEIRO
    // ----------------------------
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0; // todas as posições começam como água
        }
    }

    // ----------------------------
    // 3. POSICIONAR NAVIO HORIZONTAL
    // ----------------------------
    // Verifica se o navio horizontal cabe no tabuleiro
    if (colunaHorizontal + tamanhoNavio <= 10) {
        for (int i = 0; i < tamanhoNavio; i++) {
            tabuleiro[linhaHorizontal][colunaHorizontal + i] = navioHorizontal[i];
        }
    } else {
        printf("Erro: o navio horizontal nao cabe no tabuleiro!\n");
        return 1;
    }

    // ----------------------------
    // 4. POSICIONAR NAVIO VERTICAL
    // ----------------------------
    // Verifica se o navio vertical cabe no tabuleiro e não sobrepõe o horizontal
    if (linhaVertical + tamanhoNavio <= 10) {
        int sobreposicao = 0;
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linhaVertical + i][colunaVertical] == 3) {
                sobreposicao = 1;
            }
        }

        if (sobreposicao) {
            printf("Erro: os navios se sobrepoem!\n");
            return 1;
        } else {
            for (int i = 0; i < tamanhoNavio; i++) {
                tabuleiro[linhaVertical + i][colunaVertical] = navioVertical[i];
            }
        }
    } else {
        printf("Erro: o navio vertical nao cabe no tabuleiro!\n");
        return 1;
    }

    // ----------------------------
    // 5. EXIBIR O TABULEIRO
    // ----------------------------
    printf("\n===== TABULEIRO BATALHA NAVAL =====\n\n");

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\nLegenda: 0 = Agua | 3 = Navio\n");

    return 0;
}