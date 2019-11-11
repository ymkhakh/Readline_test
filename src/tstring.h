#ifndef TSTRING_H
#define TSTRING_H


#include <stdlib.h>
#include <stdio.h>

typedef struct t_string
{
    char *buffer;
    int size;
    int capacity;
} t_string;

void init(t_string *str);

void clear(t_string *str);

void print(t_string *str);

void add(t_string *str, char c);

void pop(t_string *str);

void del(t_string *str);

char* getLine(t_string *str);

t_string cpy(t_string str);

char get(t_string *str, int position);

void dupBuffer(t_string *src, t_string *dest);

int isValid(t_string *str);

#endif
