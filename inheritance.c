// Simulate genetic inheritance of blood type //
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct person {
  struct person *parents[2];
  char alleles[2];
}
person;

// Function prototypes
person *create_family(int generations);
char random_allele();
void print_family(person *p, int generation);
void free_family(person *p);

int main(void) {
  int generation_count = 0;
  printf("Number of generations? ");
  if (!scanf("%d", &generation_count)) {
    printf("ERROR: Input must be an integer.");
    return 1;
  }

  srand(time(0));
  person *p = create_family(generation_count);
  print_family(p, 0);
  free_family(p);
}


person *create_family(int generations) {
  person *p = malloc(sizeof(person));
  if (p == NULL) {
    printf("ERROR: Not enough memory to run module.\n");
    return false;
  }

  if (generations > 1) {
    for (int n = 0; n < 2; n++) {
      p->parents[n] = create_family(generations - 1);
      
      int r = rand() % 2;
      if (r == 0) {
        p->alleles[n] = p->parents[n]->alleles[0];
      }
      else {
        p->alleles[n] = p->parents[n]->alleles[1];
      }
    }
  }
  else {
    for (int n = 0; n < 2; n++) {
      p->parents[n] = NULL;
      p->alleles[n] = random_allele();
    }
  }
  return p;
}

char random_allele() {
  int r = rand() % 3;
  if (r == 0) {
    return 'A';
  }
  else if (r == 1) {
    return 'B';
  }
  else {
    return 'O';
  }
}

void print_family(person *p, int generation) {
  if (p == NULL) {
    return;
  }
  for (int i = 0; i < generation*2; i++) {
    printf(" ");
  }

  printf("Generation %i, blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
  print_family(p->parents[0], generation + 1);
  print_family(p->parents[1], generation + 1);
}

void free_family(person *p) {
  if (p == NULL) {
    return;
  }
  else {
    free_family(p->parents[0]);
    free_family(p->parents[1]);
  }
  free(p);
}
