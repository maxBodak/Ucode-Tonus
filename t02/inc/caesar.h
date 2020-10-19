#ifndef CAESAR_H
#define CAESAR_H

//#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

int mx_strlen(const char *s);
bool mx_isupper(int c);
bool mx_islower(int c);
bool mx_isalpha(int c);
bool mx_isspace(char c);
bool mx_isdigit(int c);
int mx_atoi(const char *str);

#endif
