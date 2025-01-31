#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdio.h>
#include <stdlib.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void print_the_grid(int grid[3][3]);
int is_stable(int grid[3][3]);
void toppling(int grid[3][3]);

#endif /* SANDPILES_H */
