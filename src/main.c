#include <stdlib.h>
#include <stdio.h>
#include "tstring.h"
#include "history.h"

char *readLine(const char *prompt);
void handleArrow(t_string *buffer, history **hist);

//prints the input
void printstr(const char *str)
{
    int i = 0;
    while (str[i])
    {
        putchar(str[i]);
        i++;
    }
}

//reads input and add it in history
char *readLine(const char *prompt)
{
    char c;
    char *line;
    t_string str;
    init(&str);
    history *hist = createHistory(str);
    while ((c =getchar()) != EOF)
    {
        if (c == '\n')
        {
            line = createLine(prompt, getLine(&str));
            printstr(line);
            putchar('\n');
            free(line);
            reset(&hist);
            if (isValid(&str))
                insert(hist, str);
            reset(&hist);
            clear(&str);
        }
        else
        {
            add(&str, c);
            handleArrow(&str, &hist);
        }

    }
    line = createLine(prompt, getLine(&str));
    reset(&hist);
    clearHistory(hist);
    del(&str);
    return line;
}

int main (int argc, char **argv)
{
	//declare the user input
    char *line = NULL;
    if (argc == 1)
    {
        line = readLine("");
    }
    else if (argc == 2)
    {
        line = readLine(argv[1]);
    }
    else
    {
        printstr("Too many arguments");
        return 0;
    }
    if (line != NULL)
    {
        printstr(line);
        putchar('\n');
        //free memory
        free(line);
        line = NULL;
    }

    return 0;
}

//line creation and memory allocation
char* createLine(const char *prompt, char *input)
{
    int i = 0;
    while (prompt[i])
    {
        i++;
    }
    int j = 0;
    while (input[j])
    {
        j++;
    }
    char *line = (char *)malloc(i + j +1);
    i = 0;
    while (prompt[i])
    {
        line[i] = prompt[i];
        i++;
    }
    j = 0;
    while (input[j])
    {
        line[i + j] = input[j];
        j++;
    }
    line[i + j] = '\0';
    return line;
}

void handleArrow(t_string *str, history **hist)
{

    int c[3] = {0};
    if (str->size < 3)
        return;
    c[0] = (int)get(str, str->size - 3);
    c[1] = (int)get(str, str->size - 2);
    c[2] = (int)get(str, str->size - 1);
    if (c[0] == 27 && c[1] == 91 && c[2] == 65 && (*hist)->next)
    {
        pop(str);
        pop(str);
        pop(str);
        (*hist) = (*hist)->next;
        dupBuffer(&(*hist)->str, str);
    }
    if (c[0] == 27 && c[1] == 91 && c[2] == 66 && (*hist)->prev)
    {
        pop(str);
        pop(str);
        pop(str);
        (*hist) = (*hist)->prev;
        dupBuffer(&(*hist)->str, str);
    }

}
