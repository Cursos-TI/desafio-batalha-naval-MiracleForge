#include <stdio.h>
#include <stdlib.h>
#define num_of_rows 10
#define num_of_collums 10
#define ship_size 3
#define pos_vertical 1
//_desafio batalha naval - matecheck
// este código inicial serve como base para o_desenvolvimento do sistema de
// batalha naval. siga os comentários para implementar cada parte_do desafio.
//
void add_ship_vertical(int tabuleiro[num_of_rows][num_of_collums], int coord_x,
                       int coord_y) {
  for (int _v = 0; _v < ship_size; _v++) {
    if (coord_x + ship_size > num_of_rows ||
        tabuleiro[coord_x + _v][coord_y] == 3) {
      printf("coordenada inválida");
      exit(1);
    }
    tabuleiro[coord_x + _v][coord_y] = 3;
  }
}
void add_ship_horizontal(int tabuleiro[num_of_rows][num_of_collums],
                         int coord_x, int coord_y) {
  for (int _h = 0; _h < ship_size; _h++) {
    if (coord_y + ship_size > num_of_collums ||
        tabuleiro[coord_x][coord_y + _h] == 3) {
      printf("coordenada inválida");
      exit(1);
    }
    tabuleiro[coord_x][coord_y + _h] = 3;
  }
}

void add_ship_diag(int tabuleiro[num_of_rows][num_of_collums], int coord_x,
                   int coord_y) {
  for (int _d = 0; _d < ship_size; _d++) {
    if (coord_x - _d < 0 || coord_x - _d >= num_of_rows || coord_y + _d < 0 ||
        coord_y + _d >= num_of_collums) {
      printf(
          "coordenada inválida: o navio ultrapassa os limites_do tabuleiro.\n");
      exit(1);
    }

    if (tabuleiro[coord_x - _d][coord_y + _d] == 3) {
      printf("coordenada inválida: há um navio nesta posição.\n");
      exit(1);
    }
  }

  for (int _d = 0; _d < ship_size; _d++) {
    tabuleiro[coord_x - _d][coord_y + _d] = 3;
  }
}

void draw_table(int tabuleiro[num_of_rows][num_of_collums]) {
  printf("  / | ");
  for (int _c = 0; _c < num_of_collums; _c++) {
    printf("%c | ", 'a' + _c);
  }
  printf("\n");

  for (int _r = 0; _r < num_of_rows; _r++) {
    printf("  %i | ", _r);
    for (int _c = 0; _c < num_of_collums; _c++) {
      printf("%i | ", tabuleiro[_r][_c]);
    }
    printf("\n");
  }
}

void add_power_cone(int tabuleiro[num_of_rows][num_of_collums], int coord_x,
                    int coord_y) {
  // Matriz em formato de cone: 3 linhas por 5 colunas, simulando expansão para
  // baixo

  int _cone[3][5] = {
      {0, 0, 1, 0, 0},
      {0, 1, 1, 1, 0},
      {1, 1, 1, 1, 1},
  };

  for (int _tx = 0; _tx < 3; _tx++) {
    int x = coord_x + _tx;
    for (int _ty = 0; _ty < 5; _ty++) {
      int y = coord_y + _ty;
      // Detecta se as coordenadas estão fora do limite da tabela
      if (x >= 0 && x < num_of_rows && y >= 0 && y < num_of_collums) {
        // caso seja detectada uma celula com navio e o valor na matrix do poder
        // seja um 1, aplica-se o valor 5 a tabela ao inves do valor da matriz
        if (tabuleiro[coord_x + _tx][coord_y + _ty] == 3 &&
            _cone[_tx][_ty] == 1) {
          tabuleiro[coord_x + _tx][coord_y + _ty] = 5;
          // caso não seja um navio aplicar o valor da matri do poder
        } else if (tabuleiro[coord_x + _tx][coord_y + _ty] != 3) {
          tabuleiro[coord_x + _tx][coord_y + _ty] = _cone[_tx][_ty];
        }
      }
    }
  }
}

void add_power_crux(int tabuleiro[num_of_rows][num_of_collums], int coord_x,
                    int coord_y) {
  int _cruz[3][5] = {
      {0, 0, 1, 0, 0},
      {1, 1, 1, 1, 1},
      {0, 0, 1, 0, 0},
  };

  for (int _tx = 0; _tx < 3; _tx++) {
    int x = coord_x + _tx;
    for (int _ty = 0; _ty < 5; _ty++) {
      int y = coord_y + _ty;
      // Detecta se as coordenadas estão fora do limite da tabela
      if (x >= 0 && x < num_of_rows && y >= 0 && y < num_of_collums) {
        // caso seja detectada uma celula com navio e o valor na matrix do poder
        // seja um 1, aplica-se o valor 5 a tabela ao inves do valor da matriz
        if (tabuleiro[coord_x + _tx][coord_y + _ty] == 3 &&
            _cruz[_tx][_ty] == 1) {
          tabuleiro[coord_x + _tx][coord_y + _ty] = 5;
        } else if (tabuleiro[coord_x + _tx][coord_y + _ty] != 3) {
          tabuleiro[coord_x + _tx][coord_y + _ty] = _cruz[_tx][_ty];
        }
      }
    }
  }
}

void add_power_octraetro(int tabuleiro[num_of_rows][num_of_collums],
                         int coord_x, int coord_y) {
  int _octraedro[3][5] = {
      {0, 0, 1, 0, 0},
      {0, 1, 1, 1, 0},
      {0, 0, 1, 0, 0},
  };

  for (int _tx = 0; _tx < 3; _tx++) {
    int x = coord_x + _tx;
    for (int _ty = 0; _ty < 5; _ty++) {
      int y = coord_y + _ty;
      // Detecta se as coordenadas estão fora do limite da tabela
      if (x >= 0 && x < num_of_rows && y >= 0 && y < num_of_collums) {
        // caso seja detectada uma celula com navio e o valor na matrix do poder
        // seja um 1, aplica-se o valor 5 a tabela ao inves do valor da matriz
        if (tabuleiro[coord_x + _tx][coord_y + _ty] == 3 &&
            _octraedro[_tx][_ty] == 1) {
          tabuleiro[coord_x + _tx][coord_y + _ty] = 5;
        } else if (tabuleiro[coord_x + _tx][coord_y + _ty] != 3) {

          if (tabuleiro[coord_x + _tx][coord_y + _ty] == 1) {
            tabuleiro[coord_x + _tx][coord_y + _ty] = 1;
          } else {
            tabuleiro[coord_x + _tx][coord_y + _ty] = _octraedro[_tx][_ty];
          }
        }
      }
    }
  }
}

int main() {
  // nível novato - posicionamento_dos navios
  int tabuleiro[num_of_rows][num_of_collums] = {0};
  // navios
  add_ship_vertical(tabuleiro, 7, 6);
  add_ship_vertical(tabuleiro, 4, 1);

  add_ship_horizontal(tabuleiro, 3, 7);
  add_ship_horizontal(tabuleiro, 6, 7);

  add_ship_diag(tabuleiro, 2, 4);
  add_ship_diag(tabuleiro, 7, 3);

  add_power_cone(tabuleiro, 5, 5);

  add_power_crux(tabuleiro, 1, 3);

  add_power_octraetro(tabuleiro, 6, 1);

  draw_table(tabuleiro);

  return 0;
}
