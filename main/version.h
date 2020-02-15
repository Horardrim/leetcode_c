#ifndef VERSION_H
#define VERSION_H

#include <stdio.h>

#define LEETCODE_EXEC_VERSION "1.0.0"

void show_version()
{
    printf("leetcode_exec version:\n");
    printf("%s:\n", LEETCODE_EXEC_VERSION);
}

#endif
