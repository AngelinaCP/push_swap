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
void	push_b(Stack *new);
void	push_a(Stack *new);
int		sort_3(int len, Stack *new);
void	sort_5(int len, Stack *new);
int		ft_isdigit(int s);
//Unit	*split_argv(int argc, char **argv);

#endif