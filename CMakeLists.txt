cmake_minimum_required(VERSION 3.19)
project(push_swap C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(push_swap
        commands.c
        ft_atoi.c
        ft_isdigit.c
        ft_split.c
        ft_strlen.c
        ft_strncmp.c
        mini_sort.c
        new_push_swap.c
        push_swap.h)
