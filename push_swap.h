#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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
int		ft_atoi(const char *str);
void	ft_swap(Unit *new, int num);
void	rotate(Unit **new, int num);
void 	rr(Unit **new, Unit **new_2);
void	reverse(Unit **new, int num);
void 	rrr(Unit **new, Unit **new_2);
void 	push_b(Stack **new);
void	push_a(Stack *new);
int		sort_3(int len, Stack *new);
void	sort_5(int len, Stack *new);
int		ft_isdigit(int s);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void 	do_operations(Unit *tmp_a, Unit *tmp_b, Stack **stack_a, Stack *stack_b, Stack *new);
int 	find_max_ab(int a, int b);
int 	check_split(char **split, Unit **tmp);
int 	check_dup(Unit *tmp2);
int 	check_if_sorted(Unit *tmp);
int 	check(char *str);
Unit 	*init_Unit(Unit *tmp);
//Unit	*split_argv(int argc, char **argv);

#endif