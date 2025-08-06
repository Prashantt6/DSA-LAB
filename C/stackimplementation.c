#include<stdio.h>
#define MAX 10
struct stacks{
    int TOS;
   int  data[MAX];
};
struct stacks s = {-1};
void isfull(struct stacks *s){
    if(s-> TOS == MAX-1){
        printf("\nStack is full");
    }
    else {
        printf("\nStack is not full");
    }

}
void isEmpty(struct  stacks *s)
{
  if(s->TOS == -1 ){
    printf("\nStack is empty");
  }
  else{
    printf("\nStack is not empty");
  }
}
void PUSH(struct stacks *s , int element){
        if(s->TOS == MAX-1){
            printf("\n Stack overflow");
        }
        else {
        s->TOS ++;
        s->data[s->TOS] = element;
        }
}
int POP(struct stacks *s){
    int element;
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
void display(struct stacks *s){
    int i ;
    for(i=0;i<=s->TOS;i++){
        printf("%d \t",s->data[i]);
    }

}
int main() {
    int ch;
    int element;
    
    do {
        printf("\nENTER THE CHOICE");
        printf("\n1.CHECK IS FULL \n 2.CHECK IS EMPTY \n 3.PUSH ELEMENT \n 4.POP ELEMENT \n 5.DISPLAY\n6.EXIT\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            isfull(&s);
            break;
        case 2:
            isEmpty(&s);
            break;
        case 3:
            printf("\nEnter the element:");
            scanf("%d",&element);
            PUSH(&s,element);
            break;
        case 4:
            element= POP(&s);
            if(element!=-1){
            printf("\nYou popped %d",element);
            }
            
            break;
    
        case 5:
            printf("Elements in stack are: \n");
            display(&s);
            break;
        case 6:
            break;
                    
        default:
            printf("\nInvalid choice");
            break;
        }
        
    }while(ch!=6);
return 0;
}