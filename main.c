#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *board[8][8] = {
    {"WR", "WK", "WB", "WQ", "WG", "WB", "WK", "WR"},
    {"WP", "WP", "WP", "WP", "WP", "WP", "WP", "WP"},
    {"0 ", "0 ", "0 ", "0 ", "0 ", "0 ", "0 ", "0 "},
    {"0 ", "0 ", "0 ", "0 ", "0 ", "0 ", "0 ", "0 "},
    {"0 ", "0 ", "0 ", "0 ", "0 ", "0 ", "0 ", "0 "},
    {"0 ", "0 ", "0 ", "0 ", "0 ", "0 ", "0 ", "0 "},
    {"BP", "BP", "BP", "BP", "BP", "BP", "BP", "BP"},
    {"BR", "BK", "BB", "BQ", "BG", "BB", "BK", "BR"}};

void display();
void change(int, int, int, int);
void pawn(int, int);
void pawnb(int, int);
void bishop(int, int);
void queen(int, int);
void knight(int, int);
void king(int, int);
void rook(int, int);
int check(int, int);
int check2(int, int);
void player1();
void player2();
int isEnemy(int, int, int, int);

int main()
{
  int t = 0;
  do
  {
    t++;
    system("cls");
    display();

    if ((t % 2) == 0)
    {
      player2();
    }
    else
    {
      player1();
    }

  } while (1);
}

void display()
{
  int i, j, k;

  printf(" ");
  for (i = 65; i <= 72; i++)
  {
    printf("  ");

    printf(" %c", i);
  }
  printf("\n");

  for (k = 8; k >= 1; k--)
  {
    printf(" ");

    printf("\n");
    printf("%d ", k);
    for (j = 1; j <= 8; j++)
    {
      printf(" %s ", board[k - 1][j - 1]);
    }
    printf("\n");
  }
}

void player1()
{
  int p1, p2, x2, y2, y1, x1;
  char t, t1;
  int t_int = 0;
  int t1_int = 0;
again1:
  printf("\nEnter Position of piece to change\n");
  scanf("%d%c", &p1, &t);

  t_int = (int)(t)-65; //Casting A,B,C,D,E,F,G,H into interval (0,7)

  y1 = t_int;
  x1 = p1 - 1; //Position - 1 for indexing the array
  char *temp = malloc(sizeof(char) * 2);
  strcpy(temp, board[x1][y1]);

  printf("%s is selected.\n", temp);

  if (strcmp(temp, "WP") == 0)
  {
    printf("Available positions: \n");
    pawn(x1, y1);
  }
  else if (strcmp(temp, "WR") == 0)
  {
    printf("Available positions: \n");
    rook(x1, y1);
  }
  else if (strcmp(temp, "WK") == 0)
  {
    printf("Available positions: \n");
    knight(x1, y1);
  }
  else if (strcmp(temp, "WB") == 0)
  {
    if (x1 == 0)
    {
      if (
          strcmp(board[x1 + 1][y1 - 1], "0 ") != 0 &&
          strcmp(board[x1 + 1][y1 + 1], "0 ") != 0)
      {
        printf("Invalid Position!\n");
        goto again1;
      }
    }
    else if (x1 == 7)
    {
      if (
          strcmp(board[x1 - 1][y1 - 1], "0 ") != 0 &&
          strcmp(board[x1 - 1][y1 + 1], "0 ") != 0)
      {
        printf("Invalid Position!\n");
        goto again1;
      }
    }
    printf("Available positions: \n");
    bishop(x1, y1);
  }
  else if (strcmp(temp, "WG") == 0)
  {
    printf("Available positions: \n");
    king(x1, y1);
  }
  else if (strcmp(temp, "WQ") == 0)
  {
    printf("Available positions: \n");
    queen(x1, y1);
  }
  else
  {
    printf("Invalid Position!\n");
    goto again1;
  }
  printf("\nEnter Position of Place to Send: ");
  scanf("%d%c", &p2, &t1);

  t1_int = (int)(t1)-65;

  y2 = t1_int;
  x2 = p2 - 1;
  change(x1, y1, x2, y2);
}

void player2()
{
  int x1, y1, p1, p2, y2, x2;
  char t, t1;
  int t_int, t1_int;
again2:
  printf("\nEnter Position of piece to change\n");
  scanf("%d%c", &p1, &t);

  t_int = (int)(t)-65; //Casting A,B,C,D,E,F,G,H into interval (0,7)

  y1 = t_int;
  x1 = p1 - 1;
  char *temp = malloc(sizeof(char) * 2);
  temp = strcpy(temp, board[x1][y1]);

  if (strcmp(temp, "BP") == 0)
  {
    printf("Available positions: \n");
    pawnb(x1, y1);
  }
  else if (strcmp(temp, "BR") == 0)
  {
    printf("Available positions: \n");
    rook(x1, y1);
  }
  else if (strcmp(temp, "BK") == 0)
  {
    printf("Available positions: \n");
    knight(x1, y1);
  }
  else if (strcmp(temp, "BB") == 0)
  {
    if (x1 == 0)
    {
      if (
          strcmp(board[x1 + 1][y1 - 1], "0 ") != 0 &&
          strcmp(board[x1 + 1][y1 + 1], "0 ") != 0)
      {
        printf("Invalid Position!\n");
        goto again2;
      }
    }
    else if (x1 == 7)
    {
      if (
          strcmp(board[x1 - 1][y1 - 1], "0 ") != 0 &&
          strcmp(board[x1 - 1][y1 + 1], "0 ") != 0)
      {
        printf("Invalid Position!\n");
        goto again2;
      }
    }
    printf("Available positions: \n");
    bishop(x1, y1);
  }
  else if (strcmp(temp, "BG") == 0)
  {
    printf("Available positions: \n");
    king(x1, y1);
  }
  else if (strcmp(temp, "BQ") == 0)
  {
    printf("Available positions: \n");
    queen(x1, y1);
  }
  else
  {
    printf("Invalid Position!\n");
    goto again2;
  }
  printf("\nEnter Position of Place to Send: ");
  scanf("%d%c", &p2, &t1);

  t1_int = (int)(t1)-65; //Casting A,B,C,D,E,F,G,H into interval (0,7)

  y2 = t1_int;
  x2 = p2 - 1;
  change(x1, y1, x2, y2);
}

void change(int x1, int y1, int x2, int y2)
{
  char *temp = board[x1][y1];
  if (strcmp(board[x2][y2], "0 ") == 0)
  {
    board[x1][y1] = board[x2][y2];
    board[x2][y2] = temp;
  }
  else
  {
    board[x1][y1] = "0 ";
    board[x2][y2] = temp;
  }
}

void pawn(int x1, int y1)
{
  if (x1 == 1)
  {
    if (strcmp(board[x1 + 1][y1], "0 ") == 0)
    {
      printf("%d%c, ", x1 + 2, y1 + 65);
    }

    if (strcmp(board[x1 + 2][y1], "0 ") == 0)
    {
      printf("%d%c", x1 + 3, y1 + 65);
    }
  }
  else
  {
    if (strcmp(board[x1 + 1][y1], "0 ") == 0)
    {
      printf("%d%c, ", x1 + 2, y1 + 65);
    }
    if (strcmp(board[x1 + 1][y1 - 1], "0 ") != 0)
    {
      printf("%d%c", x1 + 2, y1 + 65 - 1);
    }
    if (strcmp(board[x1 + 1][y1 + 1], "0 ") != 0)
    {
      printf("%d%c", x1 + 2, y1 + 65 + 1);
    }
  }
}

void pawnb(int x1, int y1)
{
  if (x1 == 6)
  {
    if (strcmp(board[x1 - 1][y1], "0 ") == 0)
    {
      printf("%d%c, ", x1, y1 + 65);
    }

    if (strcmp(board[x1 - 2][y1], "0 ") == 0)
    {
      printf("%d%c", x1 - 1, y1 + 65);
    }
  }
  else
  {
    if (strcmp(board[x1 - 1][y1], "0 ") == 0)
    {
      printf("%d%c, ", x1, y1 + 65);
    }
    if (strcmp(board[x1 - 1][y1 - 1], "0 ") != 0)
    {
      printf("%d%c", x1, y1 + 65 - 1);
    }
    if (strcmp(board[x1 - 1][y1 + 1], "0 ") != 0)
    {
      printf("%d%c", x1, y1 + 65 + 1);
    }
  }
}

void rook(int x1, int y1)
{
  int a, b;

  a = 1;
  b = 1;

  if ((x1 - a) != -1)
  {
    while (strcmp(board[x1 - a][y1], "0 ") == 0)
    {

      printf("%d%c , ", x1 - a + 1, y1 + 65);
      a++;
      if ((x1 - a) != -1)
      {
        if (isEnemy(x1, y1, x1 - a, y1))
        {
          printf("%d%c , ", x1 - a + 1, y1 + 65);
          break;
        }
      }
      else
      {
        break;
      }
    }
  }

  a = 1;
  b = 1;

  if ((x1 + a) != 8)
  {
    while (strcmp(board[x1 + a][y1], "0 ") == 0)
    {

      printf("%d%c , ", x1 + a + 1, y1 + 65);
      a++;
      if ((x1 + a) != 8)
      {
        if (isEnemy(x1, y1, x1 + a, y1))
        {
          printf("%d%c , ", x1 + a + 1, y1 + 65);
          break;
        }
      }
      else
      {
        break;
      }
    }
  }

  a = 1;
  b = 1;

  if ((y1 - b) != -1)
  {
    while (strcmp(board[x1][y1 - b], "0 ") == 0)
    {

      printf("%d%c , ", x1 + 1, y1 + 65 - b);
      b++;
      if ((y1 - b) != -1)
      {
        if (isEnemy(x1, y1, x1, y1 - b))
        {
          printf("%d%c , ", x1 + 1, y1 + 65 - b);
          break;
        }
      }
      else
      {
        break;
      }
    }
  }

  a = 1;
  b = 1;
  if ((y1 + b) != 8)
  {
    while (strcmp(board[x1][y1 + b], "0 ") == 0)
    {

      printf("%d%c , ", x1 + 1, y1 + 65 + b);
      b++;
      if ((y1 + b) != 8)
      {
        if (isEnemy(x1, y1, x1, y1 + b))
        {
          printf("%d%c , ", x1 + 1, y1 + 65 + b);
          break;
        }
      }
      else
      {
        break;
      }
    }
  }
}

void knight(int x1, int y1)
{
  if (x1 + 2 < 8 && y1 + 1 < 8)
  {
    if (!strcmp(board[x1 + 2][y1 + 1], "0 ") || isEnemy(x1, y1, x1 + 2, y1 + 1))
    {
      printf("%d%c, ", x1 + 1 + 2, y1 + 65 + 1);
    }
  }

  if (x1 + 2 < 8 && y1 - 1 > -1)
  {
    if (!strcmp(board[x1 + 2][y1 - 1], "0 ") || isEnemy(x1, y1, x1 + 2, y1 - 1))
    {
      printf("%d%c, ", x1 + 1 + 2, y1 + 65 - 1);
    }
  }

  if (x1 + 1 < 8 && y1 + 2 < 8)
  {
    if (!strcmp(board[x1 + 1][y1 + 2], "0 ") || isEnemy(x1, y1, x1 + 1, y1 + 2))
    {
      printf("%d%c, ", x1 + 1 + 1, y1 + 65 + 2);
    }
  }

  if (x1 - 1 > -1 && y1 + 2 < 8)
  {
    if (!strcmp(board[x1 - 1][y1 + 2], "0 ") || isEnemy(x1, y1, x1 - 1, y1 + 2))
    {
      printf("%d%c, ", x1 + 1 - 1, y1 + 65 + 2);
    }
  }

  if (x1 - 2 > -1 && y1 - 1 > -1)
  {
    if (!strcmp(board[x1 - 2][y1 - 1], "0 ") || isEnemy(x1, y1, x1 - 2, y1 - 1))
    {
      printf("%d%c, ", x1 + 1 - 2, y1 + 65 - 1);
    }
  }

  if (x1 - 2 > -1 && y1 + 1 < 8)
  {
    if (!strcmp(board[x1 - 2][y1 + 1], "0 ") || isEnemy(x1, y1, x1 - 2, y1 + 1))
    {
      printf("%d%c, ", x1 + 1 - 2, y1 + 65 + 1);
    }
  }

  if (x1 + 1 < 8 && y1 - 2 > -1)
  {
    if (!strcmp(board[x1 + 1][y1 - 2], "0 ") || isEnemy(x1, y1, x1 + 1, y1 - 2))
    {
      printf("%d%c, ", x1 + 1 + 1, y1 + 65 - 2);
    }
  }

  if (x1 - 1 > -1 && y1 - 2 > -1)
  {
    if (!strcmp(board[x1 - 1][y1 - 2], "0 ") || isEnemy(x1, y1, x1 - 1, y1 - 2))
    {
      printf("%d%c, ", x1 + 1 - 1, y1 + 65 - 2);
    }
  }
}

void bishop(int x1, int y1)
{
  int a, b;

  a = 1, b = 1;

  if ((x1 - a) != -1 && (y1 + b) != 8)
  {
    while (strcmp(board[x1 - a][y1 + b], "0 ") == 0)
    {
      printf("%d%c , ", x1 - a + 1, y1 + 65 + b);
      a++;
      b++;

      if ((x1 - a) != -1 && (y1 + b) != 8)
      {
        if (isEnemy(x1, y1, x1 - a, y1 + b))
        {
          printf("%d%c , ", x1 - a + 1, y1 + 65 + b);
          break;
        }
      }
      else
      {
        break;
      }
    }
  }

  a = 1, b = 1;

  if ((x1 + a) != 8 && (y1 - b) != -1)
  {
    while (strcmp(board[x1 + a][y1 - b], "0 ") == 0)
    {
      printf("%d%c , ", x1 + a + 1, y1 + 65 - b); //8 1
      a++;
      b++;

      if ((x1 + a) != 8 && (y1 - b) != -1)
      {
        if (isEnemy(x1, y1, x1 + a, y1 - b))
        {
          printf("%d%c , ", x1 + a + 1, y1 + 65 - b);
          break;
        }
      }
      else
      {
        break;
      }
    }
  }

  a = 1;
  b = 1;

  if ((x1 + a) != 8 && (y1 + b) != 8)
  {
    while (strcmp(board[x1 + a][y1 + b], "0 ") == 0)
    {

      printf("%d%c , ", x1 + a + 1, y1 + 65 + b);
      a++;
      b++;
      if ((x1 + a) != 8 && (y1 + b) != 8)
      {
        if (isEnemy(x1, y1, x1 + a, y1 + b))
        {
          printf("%d%c , ", x1 + a + 1, y1 + 65 + b);
          break;
        }
      }
      else
      {
        break;
      }
    }
  }

  a = 1;
  b = 1;

  if ((x1 - a) != -1 && (y1 - b) != -1)
  {
    while (strcmp(board[x1 - a][y1 - b], "0 ") == 0)
    {

      printf("%d%c , ", x1 - a + 1, y1 + 65 - b);
      a++;
      b++;
      if ((x1 - a) != -1 && (y1 - b) != -1)
      {
        if (isEnemy(x1, y1, x1 - a, y1 - b))
        {
          printf("%d%c , ", x1 - a + 1, y1 + 65 - b);
          break;
        }
      }
      else
      {
        break;
      }
    }
  }
}
void queen(int x1, int y1)
{
  if (y1 + 1 < 8)
  {
    if (!strcmp(board[x1][y1 + 1], "0 ") || isEnemy(x1, y1, x1, y1 + 1))
    {
      printf("%d%c, ", x1 + 1, y1 + 65 + 1);
    }
  }

  if (y1 - 1 > -1)
  {
    if (!strcmp(board[x1][y1 - 1], "0 ") || isEnemy(x1, y1, x1, y1 - 1))
    {
      printf("%d%c, ", x1 + 1, y1 + 65 - 1);
    }
  }

  if (x1 + 1 < 8)
  {
    if (!strcmp(board[x1 + 1][y1], "0 ") || isEnemy(x1, y1, x1 + 1, y1))
    {
      printf("%d%c, ", x1 + 1 + 1, y1 + 65);
    }
  }

  if (x1 - 1 > -1)
  {
    if (!strcmp(board[x1 - 1][y1], "0 ") || isEnemy(x1, y1, x1 - 1, y1))
    {
      printf("%d%c, ", x1 + 1 - 1, y1 + 65);
    }
  }

  if (x1 + 1 < 8 && y1 + 1 < 8)
  {
    if (!strcmp(board[x1 + 1][y1 + 1], "0 ") || isEnemy(x1, y1, x1 + 1, y1 + 1))
    {
      printf("%d%c, ", x1 + 1 + 1, y1 + 65 + 1);
    }
  }

  if (x1 - 1 > -1 && y1 - 1 > -1)
  {
    if (!strcmp(board[x1 - 1][y1 - 1], "0 ") || isEnemy(x1, y1, x1 - 1, y1 - 1))
    {
      printf("%d%c, ", x1 + 1 - 1, y1 + 65 - 1);
    }
  }

  if (x1 - 1 > -1 && y1 + 1 < 8)
  {
    if (!strcmp(board[x1 - 1][y1 + 1], "0 ") || isEnemy(x1, y1, x1 - 1, y1 + 1))
    {
      printf("%d%c, ", x1 + 1 - 1, y1 + 65 + 1);
    }
  }

  if (x1 + 1 < 8 && y1 - 1 > -1)
  {
    if (!strcmp(board[x1 + 1][y1 - 1], "0 ") || isEnemy(x1, y1, x1 + 1, y1 - 1))
    {
      printf("%d%c, ", x1 + 1 + 1, y1 + 65 - 1);
    }
  }
}
void king(int x1, int y1)
{
  int a, b;

  a = 1, b = 1;

  if ((x1 - a) != -1 && (y1 + b) != 8)
  {
    while (strcmp(board[x1 - a][y1 + b], "0 ") == 0)
    {
      printf("%d%c , ", x1 - a + 1, y1 + 65 + b);
      a++;
      b++;

      if ((x1 - a) != -1 && (y1 + b) != 8)
      {
        if (isEnemy(x1, y1, x1 - a, y1 + b))
        {
          printf("%d%c , ", x1 - a + 1, y1 + 65 + b);
          break;
        }
      }
      else
      {
        break;
      }
    }
  }

  a = 1, b = 1;

  if ((x1 + a) != 8 && (y1 - b) != -1)
  {
    while (strcmp(board[x1 + a][y1 - b], "0 ") == 0)
    {
      printf("%d%c , ", x1 + a + 1, y1 + 65 - b);
      a++;
      b++;

      if ((x1 + a) != 8 && (y1 - b) != -1)
      {
        if (isEnemy(x1, y1, x1 + a, y1 - b))
        {
          printf("%d%c , ", x1 + a + 1, y1 + 65 - b);
          break;
        }
      }
      else
      {
        break;
      }
    }
  }

  a = 1;
  b = 1;

  if ((x1 + a) != 8 && (y1 + b) != 8)
  {
    while (strcmp(board[x1 + a][y1 + b], "0 ") == 0)
    {

      printf("%d%c , ", x1 + a + 1, y1 + 65 + b);
      a++;
      b++;
      if ((x1 + a) != 8 && (y1 + b) != 8)
      {
        if (isEnemy(x1, y1, x1 + a, y1 + b))
        {
          printf("%d%c , ", x1 + a + 1, y1 + 65 + b);
          break;
        }
      }
      else
      {
        break;
      }
    }
  }

  a = 1;
  b = 1;

  if ((x1 - a) != -1 && (y1 - b) != -1)
  {
    while (strcmp(board[x1 - a][y1 - b], "0 ") == 0)
    {

      printf("%d%c , ", x1 - a + 1, y1 + 65 - b);
      a++;
      b++;
      if ((x1 - a) != -1 && (y1 - b) != -1)
      {
        if (isEnemy(x1, y1, x1 - a, y1 - b))
        {
          printf("%d%c , ", x1 - a + 1, y1 + 65 - b);
          break;
        }
      }
      else
      {
        break;
      }
    }
  }

  a = 1;
  b = 1;

  if ((x1 - a) != -1)
  {
    while (strcmp(board[x1 - a][y1], "0 ") == 0)
    {

      printf("%d%c , ", x1 - a + 1, y1 + 65);
      a++;
      if ((x1 - a) != -1)
      {
        if (isEnemy(x1, y1, x1 - a, y1))
        {
          printf("%d%c , ", x1 - a + 1, y1 + 65);
          break;
        }
      }
      else
      {
        break;
      }
    }
  }

  a = 1;
  b = 1;

  if ((x1 + a) != 8)
  {
    while (strcmp(board[x1 + a][y1], "0 ") == 0)
    {

      printf("%d%c , ", x1 + a + 1, y1 + 65);
      a++;
      if ((x1 + a) != 8)
      {
        if (isEnemy(x1, y1, x1 + a, y1))
        {
          printf("%d%c , ", x1 + a + 1, y1 + 65);
          break;
        }
      }
      else
      {
        break;
      }
    }
  }

  a = 1;
  b = 1;

  if ((y1 - b) != -1)
  {
    while (strcmp(board[x1][y1 - b], "0 ") == 0)
    {

      printf("%d%c , ", x1 + 1, y1 + 65 - b);
      b++;
      if ((y1 - b) != -1)
      {
        if (isEnemy(x1, y1, x1, y1 - b))
        {
          printf("%d%c , ", x1 + 1, y1 + 65 - b);
          break;
        }
      }
      else
      {
        break;
      }
    }
  }

  a = 1;
  b = 1;
  if ((y1 + b) != 8)
  {
    while (strcmp(board[x1][y1 + b], "0 ") == 0)
    {

      printf("%d%c , ", x1 + 1, y1 + 65 + b);
      b++;
      if ((y1 + b) != 8)
      {
        if (isEnemy(x1, y1, x1, y1 + b))
        {
          printf("%d%c , ", x1 + 1, y1 + 65 + b);
          break;
        }
      }
      else
      {
        break;
      }
    }
  }
}

int check(int k, int l)
{
  char *temp = malloc(sizeof(char) * 2);
  temp = strcpy(temp, board[k][l]);
  if (
      strcmp(temp, "WP") == 0 ||
      strcmp(temp, "WR") == 0 ||
      strcmp(temp, "WK") == 0 ||
      strcmp(temp, "WB") == 0 ||
      strcmp(temp, "WG") == 0 ||
      strcmp(temp, "WQ") == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int check2(int k, int l)
{
  char *temp = malloc(sizeof(char) * 2);
  temp = strcpy(temp, board[k][l]);
  if (
      strcmp(temp, "BP") == 0 ||
      strcmp(temp, "BR") == 0 ||
      strcmp(temp, "BK") == 0 ||
      strcmp(temp, "BB") == 0 ||
      strcmp(temp, "BG") == 0 ||
      strcmp(temp, "BQ") == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int isEnemy(int x0, int y0, int x1, int y1)
{
  if (strcmp(board[x1][y1], "0 ") != 0)
    return board[x0][y0][0] != board[x1][y1][0];
  else
    return 0;
}
