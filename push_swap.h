#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct	S_Unit
{
	int num;
	int	index;
	int mark;
	int rr;
	int rra;
	struct S_Unit *next;
}				Unit;

typedef struct	S_Stack
{
	Unit *A;
	Unit *B;
	int	num_A;
	int num_B;
}				Stack;

int		main(int argc, char **argv);
char	**ft_split(char const *s, char c);
void	ft_swap(Unit **new, int num);
void	rotate(Unit **new, int num);
void	rr(Unit **new, Unit **new_2, int i);
void	reverse(Unit **new, int num);
void 	rrr(Unit **new, Unit **new_2, int i);
void 	push_b(Stack **new, int i);
void	push_a(Stack *new, int i);
int		sort_3(int len, Stack *new);
void	sort_5(int len, Stack *new);
void 	do_operations(Unit *tmp_a, Unit *tmp_b, Stack **stack_a, Stack *stack_b, Stack *new);
int 	find_max_ab(int a, int b);
int 	check_split(char **split, Unit **tmp);
int 	check_dup(Unit *tmp2);
int 	check_if_sorted(Unit *tmp);
int 	check(char *str);
Unit 	*init_Unit(void);
void	find_rr_rra(Unit *new);
Stack   *init_Stack(void);
Unit	*split_argv(int argc, char **argv);
void    error();
int	    check_if_sorted(Unit *tmp);
void    reverse_root(Unit **root);
int     find_max_ab(int a, int b);
Unit    *find_max_struct(Unit *new);
Unit    *find_min_struct(Unit *new);
Unit    *find_min_struct_2(Stack *new);
int     new_size(Unit *new);
void    find_mark_1(Unit *new);
void    free_stack(Unit **new);
int     count_num_argv(char *argv);
void	sort_stack(int len, Stack *new);
void	sort_4_num(Stack *new);
void	sort_5_num(Stack *new);
int     check_content(char *split);
Unit    *find_min(Unit *new);
void    find_two_pairs(Stack **new);
Unit	*find_pair_from_a(Unit *new, int num);
int     min_steps(Unit *stack_a, Unit *stack_b);
#endif