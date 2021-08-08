#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct S_Unit
{
	int				num;
	int				index;
	int				mark;
	int				rr;
	int				rra;
	struct S_Unit	*next;
}				t_Unit;

typedef struct S_Stack
{
	t_Unit	*A;
	t_Unit	*B;
	int		num_A;
	int		num_B;
}				t_Stack;

int		main(int argc, char **argv);
char	**ft_split(char const *s, char c);
void	ft_swap(t_Unit **new, int num);
void	rotate(t_Unit **new, int num);
void	rr(t_Unit **new, t_Unit **new_2, int i);
void	reverse(t_Unit **new, int num);
void	rrr(t_Unit **new, t_Unit **new_2, int i);
void	push_b(t_Stack **new, int i);
void	push_a(t_Stack *new, int i);
int		sort_3(int len, t_Stack *new);
void	sort_5(int len, t_Stack *new);
void	do_operations(t_Unit *tmp_a, t_Unit *tmp_b, t_Stack **stack_a,
			t_Stack *new);
int		find_max_ab(int a, int b);
int		check_split(char **split, t_Unit **tmp);
int		check_dup(t_Unit *tmp2);
int		check_if_sorted(t_Unit *tmp);
int		check(char *str);
t_Unit	*init_Unit(void);
void	find_rr_rra(t_Unit *new);
t_Stack	*init_Stack(void);
t_Unit	*split_argv(int argc, char **argv);
void	error(void);
int		check_if_sorted(t_Unit *tmp);
void	reverse_root(t_Unit **root);
int		find_max_ab(int a, int b);
t_Unit	*find_max_struct(t_Unit *new);
t_Unit	*find_min_struct(t_Unit *new);
t_Unit	*find_min_struct_2(t_Stack *new);
int		new_size(t_Unit *new);
void	find_mark_1(t_Unit *new);
void	free_stack(t_Unit **new);
int		count_num_argv(char *argv);
void	sort_stack(int len, t_Stack *new);
void	sort_4_num(t_Stack *new);
void	sort_5_num(t_Stack *new);
int		check_content(char *split);
t_Unit	*find_min(t_Unit *new);
void	find_two_pairs(t_Stack **new);
t_Unit	*find_pair_from_a(t_Unit *new, int num);
int		min_steps(t_Unit *stack_a, t_Unit *stack_b);

#endif