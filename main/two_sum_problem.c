#include "two_sum_problem.h"

static char * problem_title = "Two Sum";

static char * description = "Given an array of integers, return indices of the two numbers such that they add up to a specific target.\n\
You may assume that each input would have exactly one solution, and you may not use the same element twice.";

static int * prepare_input(int * target, unsigned int size)
{
    if (size < 1)
    {
        printf("need more than 1 array size for two sum problem\n");
        return NULL;
    }

    int * p = (int *)malloc(sizeof(int) * size);
    if (p == NULL)
    {
        return NULL;
    }

    unsigned int idx;
    srand(time(NULL));
    for(idx = 0; idx < size; ++idx)
    {
        p[idx] = rand() % 60;
    }

    *target = (rand() % 120) + 30;
    return p;
}

static void dump_input_array(int * input_array, int array_size)
{
    char input_array_str_buf[512] = {0};
    int idx;
    input_array_str_buf[0] = '{';
    for (idx = 0; idx < array_size; ++idx)
    {
        sprintf(input_array_str_buf + strlen(input_array_str_buf), "%d,", input_array[idx]);
    }
    input_array_str_buf[strlen(input_array_str_buf) - 1] = '}';
    printf("input: %s\n", input_array_str_buf);
}

static void dump_prepared_data(int * input_array, int array_size, int target)
{
    printf("target: %d\n", target);
    dump_input_array(input_array, array_size);
}

static void swap(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void quick_sort_input(int * input_array, int start_idx, int end_idx)
{
    if (start_idx >= end_idx)
    {
        return;
    }

    int left_idx = start_idx;
    int right_idx = end_idx + 1;
    int flag_num = input_array[start_idx];

    do
    {
        while (input_array[--right_idx] > flag_num)
        {
            if (right_idx == start_idx)
            {
                break;
            }
        }

        while (input_array[++left_idx] < flag_num)
        {
            if (left_idx == end_idx)
            {
                break;
            }
        }

        if (right_idx <= left_idx)
        {
            break;
        }
        else
        {
            swap(&input_array[left_idx], &input_array[right_idx]);
        }
    } while (right_idx > left_idx);
    swap(&input_array[start_idx], &input_array[right_idx]);

    quick_sort_input(input_array, start_idx, right_idx - 1);
    quick_sort_input(input_array, right_idx + 1, end_idx);
}

static void two_sum_resolv_internal(int target, int * array, int length)
{
    if (length <= 0)
    {
        printf("invalid length(%d)\n", length);
        return;
    }

    if (array[length - 1] * 2 < target)
    {
        printf("array do not has such combination, max number(%d) is smaller than half of target(%d)\n", array[length - 1], target);
        return;
    }

    if (array[0] * 2 > target)
    {
        printf("array do not has such combination, min number(%d) is bigger than half of target(%d)\n", array[0], target);
        return;
    }

    int idx;
    int combinations = 0;
    for (idx = length - 1; idx >= 1; --idx)
    {
        int j;
        for (j = idx; j >= 1; --j)
        {
            if (array[idx] + array[j - 1]  == target)
            {
                ++combinations;
                printf("combination(%d, %d) equals target(%d) at index(%d, %d)\n", array[idx], array[j - 1], target, j - 1, idx);
            }
        }
    }

    printf("target %d has %d combinations in following array:\n", target, combinations);
    dump_input_array(array, length);
}

static void resolv_normal_scena()
{
    int target;
    const int array_size = 6;

    int * input_array = prepare_input(&target, array_size);
    if (input_array == NULL)
    {
        printf("prepare data failed.\n");
        return;
    }

    dump_prepared_data(input_array, array_size, target);

    quick_sort_input(input_array, 0, array_size - 1);

    printf("sorted array: \n");
    dump_input_array(input_array, array_size);

    free(input_array);
}

static void debug_resolve()
{
    int a[] = {57, 68, 59, 52, 72, 28, 59, 96, 33, 24, 59};
    int target = 100;
    //int a[] = {24, 68, 59, 52, 72, 28, 96, 33, 57};
    dump_input_array(a, 11);
    quick_sort_input(a, 0, 10);

    printf("sorted array: \n");
    dump_input_array(a, 11);

    two_sum_resolv_internal(target, a, 11);

    target = 118;
    two_sum_resolv_internal(target, a, 11);

    target = 1000;
    two_sum_resolv_internal(target, a, 11);

    target = 40;
    two_sum_resolv_internal(target, a, 11);
}

void two_sum_resolv()
{
    printf("Leet Code Title: %s\n\n", problem_title);
    printf("%s\n", description);

    debug_resolve();
    (void ) resolv_normal_scena;
}
