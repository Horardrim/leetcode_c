#ifndef LEETCODE_DEF_H
#define LEETCODE_DEF_H

#include <stdio.h>

typedef void (*solve_func)(void);

typedef struct leetcode_solve_t
{
    int id;
    char problem[64];
    char description[512];
    char solve_desc[512];
    void * input_data;
    void * expected_data;
    solve_func solve;
} leetcode_solve_t;

#endif
