#include <stdlib.h>
#include <stdio.h>

typedef struct Item
{
  int node_id;
  int inc;
} Item;

static Item list[20] = {};

int compare(const void *a, const void *b) {
  return (((Item*)b)->inc - ((Item*)a)->inc);
}

int main() {
  list[0] = {0, 15};
  list[1] = {1, 35};
  list[2] = {2, 55};
  list[3] = {3, 12};
  list[4] = {4, 1};

  qsort(list, 5, sizeof(Item), compare);
  for(int i = 0; i < 5; i++) {
    printf("%d %d\n", list[i].node_id, list[i].inc);
  }

  return 0;
}
