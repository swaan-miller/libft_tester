#!/bin/bash

cd ../ && make bonus && cd libft_tester
gcc -Wall -Wextra -Werror -c libft_p1.c libft_p2.c libft_bonus.c
gcc -Wall -Wextra -Werror ../libft.a -o libft_p1 libft_p1.o
gcc -Wall -Wextra -Werror ../libft.a -o libft_p2 libft_p2.o
gcc -Wall -Wextra -Werror ../libft.a -o libft_bonus libft_bonus.o
./libft_p1
./libft_p2
./libft_bonus
rm ft_libft_tester_putchar.txt ft_putendl_tester.txt
rm ft_putnbr_tester.txt ft_putstr_tester.txt
rm libft_bonus.o libft_bonus libft_p1.o libft_p1 libft_p2.o libft_p2