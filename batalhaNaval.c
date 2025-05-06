#include <stdio.h>
#include <stdlib.h>
#define num_of_rows 10
#define num_of_collums 10
#define ship_size 3
#define pos_vertical 1
// desafio batalha naval - matecheck
// este código inicial serve como base para o desenvolvimento do sistema de
// batalha naval. siga os comentários para implementar cada parte do desafio.
//
void add_ship_vertical(int tabuleiro[num_of_rows][num_of_collums], int coord_x,
                       int coord_y) {
  for (int v = 0; v < ship_size; v++) {
    if (coord_x + ship_size > num_of_rows ||
        tabuleiro[coord_x + v][coord_y] == 3) {
      printf("coordenada inválida");
      exit(1);
    }
    tabuleiro[coord_x + v][coord_y] = 3;
  }
}
void add_ship_horizontal(int tabuleiro[num_of_rows][num_of_collums],
                         int coord_x, int coord_y) {
  for (int h = 0; h < ship_size; h++) {
    if (coord_y + ship_size > num_of_collums ||
        tabuleiro[coord_x][coord_y + h] == 3) {
      printf("coordenada inválida");
      exit(1);
    }
    tabuleiro[coord_x][coord_y + h] = 3;
  }
}

void add_ship_diag(int tabuleiro[num_of_rows][num_of_collums], int coord_x,
                   int coord_y) {
  for (int d = 0; d < ship_size; d++) {
    if (coord_x - d < 0 || coord_x - d >= num_of_rows || coord_y + d < 0 ||
        coord_y + d >= num_of_collums) {
      printf(
          "Coordenada inválida: o navio ultrapassa os limites do tabuleiro.\n");
      exit(1);
    }

    if (tabuleiro[coord_x - d][coord_y + d] == 3) {
      printf("Coordenada inválida: há um navio nesta posição.\n");
      exit(1);
    }
  }

  for (int d = 0; d < ship_size; d++) {
    tabuleiro[coord_x - d][coord_y + d] = 3;
  }
}

void draw_table(int tabuleiro[num_of_rows][num_of_collums]) {
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
}

int main() {
  // nível novato - posicionamento dos navios
  int tabuleiro[num_of_rows][num_of_collums] = {0};
  // navios
  add_ship_vertical(tabuleiro, 7, 6);
  add_ship_vertical(tabuleiro, 4, 1);

  add_ship_horizontal(tabuleiro, 3, 7);
  add_ship_horizontal(tabuleiro, 6, 7);

  add_ship_diag(tabuleiro, 2, 4);
  add_ship_diag(tabuleiro, 7, 3);

  draw_table(tabuleiro);
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
