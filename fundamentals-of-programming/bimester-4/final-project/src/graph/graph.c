#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "graph.h"
#include "../utils/utils.h"
#define GRAPH_WIDTH 30
#define GRAPH_HEIGHT 18

void Print_graph(Graph graph, char line_prefix[], char bar_caption[])
{
  int i, j, prefix_length = strlen(line_prefix);
  double min, max, interval;

  min = Get_min_value(graph.values, GRAPH_WIDTH);
  max = Get_max_value(graph.values, GRAPH_WIDTH);
  interval = (max - min) / (GRAPH_HEIGHT - 1);

  printf("\n\n");

  for (i = 0; i < (GRAPH_WIDTH * 2 + 8 + prefix_length) / 2 - 3; i++)
    printf(" ");

  printf("%s\n\n", graph.title);

  for (i = 0; i < GRAPH_HEIGHT; i++)
  {
    // Row value
    printf("%s%6.2f", line_prefix, round((max - i * interval) * 100) / 100.0);

    // Bar
    printf(" |");

    // Lines
    for (j = 0; j < GRAPH_WIDTH; j++)
      if (graph.values[j] >= max + (-i * interval) - (interval / 2))
        printf("█ ");
      else
        printf("  ");

    printf("\n");
  }

  // Values space
  for (i = 0; i < 8 + prefix_length; i++)
    printf(" ");

  // Bar
  for (i = 0; i < GRAPH_WIDTH; i++)
    printf("￣");

  printf("\n%s\n\n", bar_caption);
}