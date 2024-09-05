#include <stdio.h>
#include <string.h>

#include "tower_of_hanoi.h"

#define ROD_COUNT (3lu)

#define GET_TEMP_INDEX(temp_indexes, start, end) (*((temp_indexes) + (start) + (end) - 1))

static void print_steps_of_towers_of_hanoi_algorithm_runner(int *rods, int start, int end, int ring_count)
{
    static const int temp_indexes[3] = {2, 1, 0};

    if (!ring_count)
        return;

    print_steps_of_towers_of_hanoi_algorithm_runner(rods, start, GET_TEMP_INDEX(temp_indexes, start, end), ring_count - 1);
    printf("%d %d %d\n", *rods, *(rods + 1), *(rods + 2));
    --*(rods + start);
    ++*(rods + end);
    print_steps_of_towers_of_hanoi_algorithm_runner(rods, GET_TEMP_INDEX(temp_indexes, start, end), end, ring_count - 1);
}

void print_steps_of_towers_of_hanoi_algorithm(int ring_count)
{
    static int rods[ROD_COUNT] = {0};
    memset(rods, 0, ROD_COUNT * sizeof(int));

    *rods = ring_count;

    print_steps_of_towers_of_hanoi_algorithm_runner(rods, 0, 2, ring_count);
    printf("%d %d %d\n", *rods, *(rods + 1), *(rods + 2));
}
