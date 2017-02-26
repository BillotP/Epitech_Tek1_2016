#!/bin/bash
#
# test.sh for Minishell1 in /home/bender/Repo/PSU_2016_minishell1/Stress_Test/
#
# Made by John Doe
# Login   <login_x@epitech.eu>
#
# Started on  Sun Jan 15 20:36:41 2017 John Doe
# Last update Sun Jan 15 20:37:27 2017 John Doe
#
make re; make clean;
(echo "./mysh"; echo "mysh"; echo "cd .."; echo "/ls"; echo "bin/ls"; echo "/bin/ls"; echo "cd .."; echo "ls -a /usr"; echo "pwd"; echo "cd /bin"; echo "pwd"; echo "cd -"; echo "pwd") | tcsh 2>&1 > result.tcsh;
(echo "./mysh"; echo "mysh"; echo "cd .."; echo "/ls"; echo "bin/ls"; echo "/bin/ls"; echo "cd .."; echo "ls -a /usr" ; echo "pwd" ; echo "cd /bin" ; echo "pwd" ; echo "cd -" ; echo "pwd") | ./mysh 2>&1 > result.mysh;
 diff result.mysh result.tcsh;
