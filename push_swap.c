#include <stdio.h>
#include "../libft/libft.h"

int check_argv(char **argv)
{
    int     i;
    char    *str;

    i = 1;
    while (argv[i])
    {
        // if (!ft_atoi(argv[i]))
        //     printf("ERROR\n");
        if (!ft_isdigit(argv[i][0]))
        {
            printf("ERROR\n");
            return (1);
        }
            
        i++;
    }
    int j;

    i = 1;
    while (argv[i])
    {
        j = i + 1;
        while (argv[j])
        {
            if (!ft_strncmp(argv[i], argv[j], ft_strlen(argv[1])))
            {
                printf("ERROR\n");
                return (2);
            }
                
            j++;
        }
        i++;
    }
    return (0);
}

void    ft_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}

void    rra(int *array)
{
    int c;

    c = array[0];
    array[0] = array[2];
    array[2] = array[1];
    array[1] = c;
}

void    ra(int *array)
{
    int c;

    c = array[2];
    array[2] = array[0];
    array[0] = array[1];
    array[1] = c;
}

void    algorithm_3(int argc, int *stackA)
{
    if (stackA[0] > stackA[1] && stackA[0] < stackA[2])
        ft_swap(&stackA[0], &stackA[1]);
    else if (stackA[0] > stackA[1] && stackA[1] > stackA[2])
    {
        ft_swap(&stackA[0], &stackA[1]);
        rra(stackA);
    }
    else if (stackA[0] > stackA[1] && stackA[1] < stackA[2])
        ra(stackA);
    else if (stackA[0] < stackA[1] && stackA[0] < stackA[2])
    {
        ft_swap(&stackA[0], &stackA[1]);
        ra(stackA);
    }
    else if (stackA[0] < stackA[1] && stackA[0] < stackA[1])
        rra(stackA);
  //  return (0);
}

void    remove_elements(int *array, int argc, int num)
{
    int i;

    i = 0;
    while (i < argc - 1)
    {
        array[i] = array[i + num];
        i++;
    }
    
}

void pa(int *stackA, int *stackB, int argc)
{
    int i;
    int size;

    i = 0;
    size = sizeof(&stackA) / sizeof(int);
    size++;
    while (size)
    {
        stackA[size] = stackA[size - 1];
        size--;
    }
    stackA[0] = stackB[0];
    size = sizeof(&stackA) / sizeof(int);
    size++;
    i = 0;
    while (i > size)
    {
        stackB[i] = stackB[i + 1];
        i++;
    }
}

void pb(int *stackA, int *stackB)
{
    int size;

    size = sizeof(&stackB) / sizeof(int);
    if (!stackB)
      stackB[0] = stackA[0];
    else
    {
         size++;
        while (size)
        {
            stackB[size] = stackB[size - 1];
            size--;
        }
        stackB[0] = stackA[0]; 
    }
}

int algorithm_5(int argc, int *stackA, int *stackB)
{
    int i;

    i = 0;
    pb(stackA, stackB);
    remove_elements(stackA, argc, 2);
    algorithm_3(argc, stackA);
    pa(stackA, stackB, argc);
    while (stackA[i] > stackA[i + 1])
        ft_swap(&stackA[i], &stackA[i + 1]);
    pa(stackA, stackB, argc);
    // while (stackA[i] > stackA[i + 1])
    //     ft_swap(&stackA[i], &stackA[i + 1]);
      for (int i = 0; i < 5; i++)
        printf("%d\n", stackA[i]);
    return (0);
}

void check_num(int argc, int *stackA, int *stackB)
{
    if (argc == 4)
        algorithm_3(argc, stackA);
    else if (argc == 6)
        algorithm_5(argc, stackA, stackB);

}

int check_if_sorted(int argc, int *stackA)
{
    int i;

    i = 0;
    while (i + 1 < argc - 1)
    {
        if (stackA[i] > stackA[i + 1])
            return (0);
        i++;
    }
    write(1, "Sorted!\n", 8);
    return (1);
}

int main(int argc, char **argv)
{
    int i;
    int *stackA;
    int *stackB;

    i = 1;
    stackA = (int *)malloc(sizeof(int) * argc - 1);
    stackB = (int *)malloc(sizeof(int) * argc - 1);
    while (i < argc)
    {
        stackA[i - 1] = ft_atoi(argv[i]);
        i++;
    }
    if (check_if_sorted(argc, stackA))
        return (0);
    if (check_argv(argv))
        return (0);
    check_num(argc, stackA, stackB);
}