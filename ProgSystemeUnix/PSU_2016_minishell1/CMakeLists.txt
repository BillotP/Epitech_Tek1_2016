cmake_minimum_required(VERSION 3.6)
project(minishell1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        include/base.h
        include/errors.h
        include/get_next_line.h
        include/msg.h
        include/pshell.h
        include/setenv.h
        include/shell1.h
        include/strtowordtab.h
        srcs/built_in/built_in.c
        srcs/built_in/built_inmatch.c
        srcs/gnlrpz/get_next_line.c
        srcs/libfunk/base.c
        srcs/libfunk/check_dir.c
        srcs/libfunk/error.c
        srcs/libfunk/string.c
        srcs/libfunk/strtowordtab.c
        srcs/minishell1/minishell1.c
        srcs/setenv/env.c
        srcs/setenv/env_inlist.c
        srcs/main.c
        Makefile)

add_executable(minishell1 ${SOURCE_FILES})