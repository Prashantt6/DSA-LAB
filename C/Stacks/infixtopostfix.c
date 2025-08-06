#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

struct stacks 
{
    int TOS;
    char data[MAX];
};

void PUSH(struct stacks *s , char result ){
    if(s->TOS == MAX-1){
        printf("\n Stack overflow");
    }
    else {
        s->TOS +=1;
        s->data[s->TOS] = result;
    }
}

char POP(struct stacks *s){
    char element;
    if(s->TOS == -1){
        printf("\n Stack underflow");
        return -1;
    }
    else {
        element = s->data[s->TOS];
        s->TOS -=1;
        return element;
    }
}

int isEmpty(struct stacks *s)
{
    if(s->TOS == -1 ){
        return 1;
    }
    else{
        return 0;
    }
}

int precedence(char c){
    if( c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    if(c == '^') return 3;
    return 0;
}

int isOperator(char exp){
    if(exp =='+'|| exp == '-'|| exp == '*'|| exp == '/' || exp == '^'){
        return 1;
    }
    else return 0 ;
}

void infixtopostfix(struct stacks *s, char exp[]) {
    char post[MAX][MAX]; 
    int k = 0;
    char *token = strtok(exp, " ");

    while (token != NULL) {
        if (strcmp(token, "(") == 0) {
            PUSH(s, '(');
        }
        else if (strcmp(token, ")") == 0) {
            while (s->data[s->TOS] != '(') {
                post[k][0] = POP(s);
                post[k][1] = '\0';
                k++;
            }
            POP(s); // remove '(' too
        }
        else if (isOperator(token[0]) && strlen(token) == 1) {
            while (!isEmpty(s) && precedence(token[0]) <= precedence(s->data[s->TOS])) {
                post[k][0] = POP(s);
                post[k][1] = '\0';
                k++;
            }
            PUSH(s, token[0]);
        }
        else {
            strcpy(post[k++], token);
        }
        token = strtok(NULL, " ");
    }

    while (!isEmpty(s)) {
        post[k][0] = POP(s);
        post[k][1] = '\0';
        k++;
    }

    printf("Postfix expression is: ");
    for (int i = 0; i < k; i++) {
        printf("%s ", post[i]);
    }
    
}

int main(){
    char exp[MAX];
    struct stacks s = {-1};
    printf("Enter the infix expressions\n");
    fgets(exp , MAX, stdin);
    infixtopostfix(&s , exp);
    return 0;
}
