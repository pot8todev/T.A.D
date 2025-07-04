#include "stack.h"
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

bool opening(char c) { return c == '(' || c == '{' || c == '['; }

bool closing(char c) { return c == ')' || c == '}' || c == ']'; }


bool matching_pair(char c1, char c2){
    return
        (c1 == '(' && c2 == ')') ||
        (c1 == '{' && c2 == '}') ||
        (c1 == '[' && c2 == ']');
}

void balanceado(char word[]){
    int len = strlen(word);
    char c;
    Stack* S = init_stack();

    for (int i = 0;word[i]!='\0'; i++) {
        printf("%c",word[i]);
        if(opening(word[i])){
            S->n++;
            S->data[S->n-1]= word[i];

            printf("\n o num el é: %d\n",S->n);
        }
        else if(closing(word[i])){
            if(!matching_pair(top(S), word[i])){
                S->n = 100000;
            }
            //if closing correct then:
            printf("\nfechando: %c\n",top(S));
            S->n--;
        }
    }
    printf("\n\n\t o numero de elementos é: %d\n",S->n);

  if (S->n == 0)
    puts("\n\nbalanceado");
  else
    puts("\n\nerrado");

}



