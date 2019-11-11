#include "tstring.h"

void init(t_string *str)
{
    str->buffer = (char *)malloc(10);
    str->capacity = 10;
    str->size = 0;
}

void clear(t_string *str)
{
    str->size = 0;
}

void print(t_string *str)
{
    int i = 0;
    while (str->buffer && i < str->size)
    {
        putchar(str->buffer[i]);
        i++;
    }
    putchar('\n');
}

void add(t_string *str, char c)
{
    if (!str->buffer)
        return;
    str->buffer[str->size++] = c;
    if (str->size == str->capacity)
    {
        str->buffer = (char*)realloc(str->buffer, str->capacity*2);
        str->capacity *=2;
    }
}

void pop(t_string *str)
{
    if (str->size > 0)
        str->size--;
}

void del(t_string *str)
{
    if (str->buffer)
        free(str->buffer);
    str->buffer = NULL;
}

char* getLine(t_string *str)
{
    add(str,'\0');
    return str->buffer;
}

t_string cpy(t_string str)
{
    t_string cp;
    cp.buffer = (char *)malloc(str.size);
    int i = 0;
    while (i < str.size)
    {
        cp.buffer[i] = str.buffer[i];
        i++;
    }
    cp.capacity = str.capacity;
    cp.size = str.size;
    return cp;
}

char get(t_string *str, int position)
{
    return str->buffer[position];
}

void dupBuffer(t_string *src, t_string *dest)
{
   clear(dest);
   int i = 0;
   while (src->buffer[i])
   {
       add(dest, src->buffer[i]);
       i++;
   }
}

int isValid(t_string *str)
{
   int i = 0;
   while (str->buffer[i])
   {
       if (str->buffer[i] != '\t' && str->buffer[i] != ' ')
            return 1;
       i++;
   }
   return 0;
}
