#include "longest_cycle.h"

static char * problem_title = "Longest Cycle In a Graph";

static char * description = "You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.\n\
  The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from node i, then edges[i] == -1.\n\
  Return the length of the longest cycle in the graph. If no cycle exists, return -1.\n\
  A cycle is a path that starts and ends at the same node.\n";

static void resolution()
{

}

void longest_cycle()
{
    printf("\033[1;31mLeet Code Title: \033[1;36m%s\n\n", problem_title);
    printf("\033[1;32m%s\n", description);

    printf("\033[m\n");

    resolution();
}
