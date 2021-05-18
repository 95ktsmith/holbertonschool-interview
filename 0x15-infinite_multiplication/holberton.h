#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/* It's not infinite but it's better than a ton of reallocating */
#define BUFFER_SIZE 4096

char *mul_strings(char *str1, char *str2);
void add_to_string(char buf[], int n, int place);
int _strlen(char *str);
int _putchar(char c);
char *_strdup(char *str);
unsigned int is_numerical(char *str);

#endif /* HOLBERTON_H */
