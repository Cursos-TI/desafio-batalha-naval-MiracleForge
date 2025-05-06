#include <stdio.h>
#define num_of_rows 10
#define num_of_collums 10
#define ship_size 3
// desafio batalha naval - matecheck
// este código inicial serve como base para o desenvolvimento do sistema de
// batalha naval. siga os comentários para implementar cada parte do desafio.

int main() {
  // nível novato - posicionamento dos navios
  int tabuleiro[num_of_rows][num_of_collums] = {0};
  // navios
  for (int x = 0; x < num_of_rows; x++) {
    for (int y = 0; y < num_of_collums; y++) {
      if (x == 3 && y == 2) {
        for (int s = 0; s < ship_size; s++) {
          tabuleiro[x + s][y] = 3;
        }
      } else if (x == 6 && y == 7) {
        for (int s = 0; s < ship_size; s++) {
          tabuleiro[x][y + s] = 3;
        }
      }
    }
  }

  printf("  / | ");
  for (int c = 0; c < num_of_collums; c++) {
    printf("%c | ", 'a' + c);
  }
  printf("\n");

  for (int r = 0; r < num_of_rows; r++) {
    printf("  %i | ", r);
    for (int c = 0; c < num_of_collums; c++) {
      printf("%i | ", tabuleiro[r][c]);
    }
    printf("\n");
  }

  // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro
  //
  // (Ex: int tabuleiro[5][5];). Sugestão: Posicione dois navios no tabuleiro,
  // um verticalmente e outro horizontalmente. Sugestão: Utilize `printf` para
  // exibir as coordenadas de cada parte dos navios.

  // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
  // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
  // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
  // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições
  // vazias e 3 para posições ocupadas.

  // Nível Mestre - Habilidades Especiais com Matrizes
  // Sugestão: Crie matrizes para representar habilidades especiais como cone,
  // cruz, e octaedro. Sugestão: Utilize estruturas de repetição aninhadas para
  // preencher as áreas afetadas por essas habilidades no tabuleiro. Sugestão:
  // Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não
  // afetadas e 1 para áreas atingidas.

  // Exemplos de exibição das habilidades:
  // Exemplo para habilidade em cone:
  // 0 0 1 0 0
  // 0 1 1 1 0
  // 1 1 1 1 1

  // Exemplo para habilidade em octaedro:
  // 0 0 1 0 0
  // 0 1 1 1 0
  // 0 0 1 0 0

  // Exemplo para habilidade em cruz:
  // 0 0 1 0 0
  // 1 1 1 1 1
  // 0 0 1 0 0

  return 0;
}
