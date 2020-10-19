#ifndef MORSE_H
#define MORSE_H

//#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *mx_strnew(const int size);

int mx_strncmp(const char *s1, const char *s2, int n);
char *mx_strchr(const char *str, int c);
int mx_strlen(const char *s);
char *mx_strcpy(char *dst, const char *src);
char *mx_strdup(const char *str);
char *mx_strstr(const char *s1, const char *s2);
#endif
