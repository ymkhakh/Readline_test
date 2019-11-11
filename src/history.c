#include "history.h"


history *createHistory(t_string str)
{
    history *new = (history *)malloc(sizeof(history));
    new->str = cpy(str);
    new->next = NULL;
    new->prev = NULL;
    return new;
}

void push_back(history *hist,t_string str)
{
    history *new = createHistory(str);
    while (hist->next)
    {
        hist = hist->next;
    }
    hist->next = new;
    new->prev = hist;
}

void insert(history *hist, t_string str)
{
    history *second = hist->next;
    history *new = createHistory(str);
    hist->next = new;
    new->prev = hist;
    if (second)
        second->prev = new;
    new->next = second;
}

void reset(history **hist)
{
    while ((*hist)->prev)
    {
        (*hist) = (*hist)->prev;
    }
}

void clearHistory(history *hist)
{

    while (hist)
    {
        history *tmp = hist->next;
        del(&hist->str);
        free(hist);
        hist = tmp;
    }
}

void printHistory(history *hist)
{

    while (hist)
    {
        print(&hist->str);
        hist = hist->next;
    }
}
