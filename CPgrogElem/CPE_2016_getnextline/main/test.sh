gcc -g -Wall -Werror *.c main/main.c -o tt; man gcc > main/ttestcat; man gcc | ./tt > main/ttest ; diff \
main/ttest main/ttestcat
