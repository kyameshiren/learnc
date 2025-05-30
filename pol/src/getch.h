#ifndef GETCH_H
#define GETCH_H

#define BUFSIZE 100

int getch(void);
void ungetch(int);
void ungets(char s[]);

#endif
