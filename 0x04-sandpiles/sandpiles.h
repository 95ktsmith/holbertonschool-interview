#ifndef SANDPILES_H
#define SANDPILES_H

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void topple(int grid1[3][3], int grid2[3][3]);
void add_grids(int grid1[3][3], int grid2[3][3]);
int is_stable(int grid[3][3]);
void copy(int grid1[3][3], int grid2[3][3]);

#endif /* SANDPILES_H */
