#ifndef PIVO_H
#define PIVO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_WHITE "\x1b[37m"
#define ANSI_COLOR_CYAN "\x1b[36m"

typedef struct {
  int height;
  int width;
  char foam;
  char liquid;
  char *bubbles;
  int num_bubbles;
} BeerGlass;

static inline void init_beer_glass(BeerGlass *glass, int height, int width,
                                   char foam, char liquid, char *bubbles,
                                   int num_bubbles);
static inline void pour_beer(BeerGlass *glass);
static inline void add_bubbles(BeerGlass *glass);
static inline void display_beer(BeerGlass *glass);
static inline void init_beer_glass(BeerGlass *glass, int height, int width,
                                   char foam, char liquid, char *bubbles,
                                   int num_bubbles) {
  glass->height = height;
  glass->width = width;
  glass->foam = foam;
  glass->liquid = liquid;
  glass->bubbles = bubbles;
  glass->num_bubbles = num_bubbles;
}

static inline void pour_beer(BeerGlass *glass) {
  for (int i = glass->height - 1; i >= 0; i--) {
    for (int j = 0; j < glass->width; j++) {
      if (i == 0 || i == glass->height - 1 || j == 0 || j == glass->width - 1) {
        printf(ANSI_COLOR_YELLOW "|" ANSI_COLOR_RESET);
      } else if (i > glass->height - 4) {
        printf(ANSI_COLOR_WHITE "%c" ANSI_COLOR_RESET, glass->foam);
      } else {
        printf(ANSI_COLOR_YELLOW "%c" ANSI_COLOR_RESET, glass->liquid);
      }
    }
    printf("\n");
    fflush(stdout);
    usleep(150000);
  }

  printf(ANSI_COLOR_WHITE "  ");
  for (int j = 2; j < glass->width - 2; j++) {
    printf("%c", glass->foam);
  }
  printf("  " ANSI_COLOR_RESET "\n");
}

static inline void add_bubbles(BeerGlass *glass) {
  for (int frame = 0; frame < 100; frame++) {
    printf("\033[1;1H" ANSI_COLOR_YELLOW "|" ANSI_COLOR_WHITE);
    for (int j = 1; j < glass->width - 1; j++) {
      printf("%c", glass->foam);
    }
    printf(ANSI_COLOR_YELLOW "|" ANSI_COLOR_RESET);

    for (int i = glass->height - 4; i > 1; i--) {
      for (int j = 1; j < glass->width - 1; j++) {
        if (rand() % 20 == 0) {
          char bubble = glass->bubbles[rand() % glass->num_bubbles];
          printf("\033[%d;%dH" ANSI_COLOR_CYAN "%c" ANSI_COLOR_RESET, i, j,
                 bubble);
          fflush(stdout);
        }
      }
    }

    for (int i = 1; i < glass->height; i++) {
      printf("\033[%d;1H" ANSI_COLOR_YELLOW "|" ANSI_COLOR_RESET, i);
      printf("\033[%d;%dH" ANSI_COLOR_YELLOW "|" ANSI_COLOR_RESET, i,
             glass->width);
    }

    printf("\033[%d;1H" ANSI_COLOR_YELLOW, glass->height);
    for (int j = 0; j < glass->width; j++) {
      printf("|");
    }
    printf(ANSI_COLOR_RESET);

    printf("\033[%d;1H" ANSI_COLOR_WHITE "  ", glass->height + 1);
    for (int j = 2; j < glass->width - 2; j++) {
      printf("%c", glass->foam);
    }
    printf("  " ANSI_COLOR_RESET);

    fflush(stdout);
    usleep(100000);
  }
}

static inline void display_beer(BeerGlass *glass) {
  pour_beer(glass);
  add_bubbles(glass);

  printf("\033[1;1H");
  for (int i = 0; i < glass->height; i++) {
    for (int j = 0; j < glass->width; j++) {
      if (i == 0 || i == glass->height - 1 || j == 0 || j == glass->width - 1) {
        printf(ANSI_COLOR_YELLOW "|" ANSI_COLOR_RESET);
      } else if (i > glass->height - 4) { // Foam at the top
        printf(ANSI_COLOR_WHITE "%c" ANSI_COLOR_RESET, glass->foam);
      } else {
        printf(ANSI_COLOR_YELLOW "%c" ANSI_COLOR_RESET, glass->liquid);
      }
    }
    printf("\n");
  }

  for (int layer = 0; layer < 2; layer++) {
    printf(ANSI_COLOR_WHITE "  ");
    for (int j = 2; j < glass->width - 2; j++) {
      printf("%c", glass->foam);
    }
    printf("  " ANSI_COLOR_RESET "\n");
  }
}

#endif // PIVO_H
