#ifndef HISTORY_H
#define HISTORY_H


#include <stdlib.h>
#include <stdio.h>
#include "tstring.h"


typedef struct history
{
    t_string str;
    struct history *next;
    struct history *prev;

}history;

history *createHistory(t_string str);
void push_back(history *hist,t_string str);
void insert(history *hist,t_string str);
void reset(history **hist);
void printHistory(history *hist);
void clearHistory(history *hist);



#endif
