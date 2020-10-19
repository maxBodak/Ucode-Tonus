#ifndef POLYBIUS_H
#define POLYBIUS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

int mx_strlen(const char *s);
char *mx_strnew(const int size);
int mx_strncmp(const char *s1, const char *s2, int n);
bool mx_isupper(int c);
bool mx_islower(int c);
bool mx_isalpha(int c);
bool mx_isspace(char c);
bool mx_isdigit(int c);
int mx_atoi(const char *str);

#endif
