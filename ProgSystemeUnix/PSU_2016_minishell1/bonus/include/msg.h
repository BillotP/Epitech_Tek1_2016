/*
** msg.h for BOOK in /home/bender/Desktop/Snippets/book/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Thu Dec 22 09:10:38 2016 John Doe
** Last update	Wed Dec 28 11:14:44 2016 John Doe
*/

#ifndef MSG_H_
# define MSG_H_

#include "pshell.h"

#define LICENSE		"\t\t\t\t\t\e[1mMIT License\e[0m\n\t\t\t\tCopyright 2017 John\
Doe TEk1\n\nPermission is hereby granted, free of charge, to any person obtain\
ing a copy of this software and associated documentation files (the \
\"Software\") to deal in the Software without restriction, including without \
limitation the rights to use, copy, modify, merge, publish, distribute, \
sublicense, and/or sell copies of the Software, and to permit persons to whom \
the Software is furnished to do so, subject to the following conditions:\n\n \
The above copyright notice and this permission notice shall be included in all \
copies or substantial portions of the Software. \
THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR \
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, \
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  \
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER \
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, \
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE \
SOFTWARE.\n"

#define LICENSE2 "\t\t\t\e[1mDO WHAT THE FUCK YOU WANT TO PUBLIC \
LICENSE\e[0m\n\t\t\tVersion 2, December 2004 Copyright (C) 2004 \
\n\t\t\tSam Hocevar <sam@hocevar.net>\n\nEveryone is permitted to copy and \
distribute verbatim or modified copies of this license document, and changing \
it is allowed as long as the name is changed.\n\n\e[1mDO WHAT THE FUCK YOU WANT\
 TO PUBLIC LICENSE TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND\
MODIFICATION \e[0m\n\n0. You just \e[1mDO WHAT THE FUCK YOU WANT TO\e[0m.\n"


#define  	PROMPT		"\e[1mMysh >> \e[0m"
#define	 	INTRO		"\t\t>>Mysh<<\n\t'u' for usage, 'h' for help, \n\t'l' for \
license and 'q' to quit\n"
#define 	HELP			"\n\tRTFM\n\nhelp yourself ;)\n"
#define 	NAME			"SHELL=Mysh V0.0.1"
#define		HOME			"HOME=/home/bender"
#define   PWD 			"PWD="
#define   OLDPWD		"OLDPWD="

#define 	ROOT_ERR	"\n\t\e[1mIt's really a bad bad idea to run this shit\n\tas\
 root! u'll be warned..(seriously it's better\n\tfor you to press 'q' now)\e[0m\
\n\n"

void		errors(char *errmsg);
void		help(char *helpmsg, char *buff);
void		license(char *licencemsg, char *buff);
void		shortcuts(char *buff);

#endif
