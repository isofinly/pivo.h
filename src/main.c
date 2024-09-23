#include "pivo.h"

// Define color codes
#define BUBBLE_COLOR "\033[36m"
#define RESET_COLOR "\033[0m"

int main() {
  srand(time(NULL));

  BeerGlass mug;
  char bubbles[] = {'o', 'O', '*', 'B', 'b', 'o', 'O', 'B', 'b'};
  init_beer_glass(&mug, 15, 30, '~', '#', bubbles,
                  sizeof(bubbles) / sizeof(bubbles[0]));

  printf("\033[2J");
  printf("\033[H");

  printf(ANSI_COLOR_CYAN "Pouring a refreshing beer...\n\n" ANSI_COLOR_RESET);
  display_beer(&mug);

  printf(ANSI_COLOR_CYAN "\nEnjoy your virtual beer!\n" ANSI_COLOR_RESET);

  return 0;
}
