// WAP in C to evaluate postfix expression 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#define True 1;
#define False 0;
#define MAX 10 
struct stack {
    int TOS;
    int data[MAX];
};

// int isOperator(char exp[]){
//     if(exp =='+'|| exp == '-'|| exp == '*'|| exp == '/' || exp == '^'){
//         return True;
//     }
//     else return False ;
// }
void PUSH(struct stack *s , float result ){
        if(s->TOS == MAX-1){
            printf("\n Stack overflow");
        }
        else {
        s->TOS ++;
        s->data[s->TOS] = result;
        }
}
float POP(struct stack *s){
    float element;
    if(s->TOS == -1){
        printf("\n Stack underflow");
        return -1;
    }
    else {
        element = s->data[s->TOS];
        s->TOS --;
        return element; 
       
    }
  
}
void evalaute (struct stack *s , char exp[]){
    int i= 0;
    int op1;
    int op2;
    float result;
    char *token = strtok(exp , " ");
    
  while(token != NULL){
    if(isdigit(token[0]) || (token[0] == '-') && (isdigit(token[1]))){
        PUSH(s , atof(token));
    }
    else {
        op1 = POP(s);
        op2 = POP(s);
        switch (token[0])
        {
        case '+':
            result = op2 + op1;
            PUSH(s , result);
            break;
        case '-':
            result = op2 - op1;
            PUSH(s , result);
            break;
        case '*':
            result = op2 * op1;
            PUSH(s , result);
            break;
       case '/':
            result = op2 / op1;
            PUSH(s , result);
            break;
       case '^':
            result = pow(op2,op1);
            PUSH(s , result);
            break;
        }
        
    }
    token = strtok (NULL , " ");

 }
 printf("%.3f", result);

}
int main(){
    struct stack s = {-1};
    char exp[MAX];
    printf("\nEnter the postfix expression: ");
    fgets(exp ,MAX , stdin);
    evalaute( &s , exp);
    return 0;
    
}