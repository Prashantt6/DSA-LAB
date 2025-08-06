#include<stdio.h>
#include<stdlib.h>
struct SLL {
    int data;
    struct SLL *next;
};
struct SLL *first, *last = NULL;
void InsertionfromBeg(){
    struct SLL *NewNode;
    NewNode = (struct SLL*)malloc(sizeof(struct SLL));
    NewNode->next = NULL;
    printf("\nEnter the data:");
    scanf("%d",&NewNode->data);
    if(first==NULL)
        first=last=NewNode;
    else 
    {
        NewNode->next = first;
        first = NewNode;
        
    }
}
void InsertionfromEnd()
{
    struct SLL *NewNode;
    NewNode = (struct SLL*)malloc(sizeof(struct SLL));
    NewNode->next = NULL;
    printf("\nEnter the data:");
    scanf("%d",&NewNode->data);
    if(first==NULL)
        first=last=NewNode;
    else 
    {
        last->next = NewNode;
        last = NewNode;
             
    }
    
}
void DeletionfromBeg()
{
    struct SLL *temp;
    if(first==NULL)
        printf("List is empty\n");
    else 
    {
        temp = first;
        first = first->next;
        printf("%d was deleted from beginning",temp->data);
        free(temp);
    }
}
void DeletionfromEnd()
{
    struct SLL *temp =first;
    
    if(first == NULL)
        printf("List is empty\n");
    else if(first->next == NULL)
    {
        temp= first;
        first = last = NULL;
        printf("%d was deleted ",temp->data);
        free(temp);
    }
    else 
    {
        while(temp->next != last)
        {
            temp = temp->next;
        }
        last = temp;
        temp = temp->next;
        printf("%d was deleted from end",temp->data);
        free(temp);
        last->next = NULL;
      
    }
}
void Deletionfrompos(){
    struct SLL *temp;
    int pos,i;
    
    struct SLL *tempp;
    
    printf("\nEnter the positon data you want to delete :  ");
    scanf("%d",&pos);
    if(first == NULL)
        printf("List is empty\n");
    else if (pos == 1){
        DeletionfromBeg();
    }
    else {
        temp = first;
        for(i=1 ; i<pos-1; i++){
            temp = temp->next;
        }
        if(temp->next == NULL){
            DeletionfromEnd();
        }
        else 
        {
            tempp = temp->next;
            temp->next = tempp->next;
            printf("%d was deleted from end",tempp->data);
            free(tempp);
        }
    }

}
void Search(){
    struct SLL *temp;
    int key,flag =0;
    
    printf("Enter the data you wanted to search");
    scanf("%d",&key);
    if(first == NULL)
        printf("List is empty\n");
    else {
        temp = first;
    while(temp != NULL){
        if(temp->data == key){
            flag =1;
            printf("\nElement found");
        }
        temp = temp->next;
      
    }
    if(flag== 0){
            printf("\nElement not found");
        }
    }
}
void Display(){
    struct SLL *temp;
    
    printf("\n");
    if(first == NULL)
        printf("List is empty");
    else 
    {
        temp =first;
        while(temp!= NULL){
            printf(" %d -> ",temp->data);
            temp = temp->next;
        }
    }

    
}

int main(){
    int ch=0;
    printf("\n");
    while(1){
        printf("1.Insertion from Beginning\n 2.Insertion from End \n 3.Deletion from Beginning \n 4.Deletion from End\n 5.Deletion from desired position\n 6.Searching \n 7.Display \n 8.End\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 :
                InsertionfromBeg();
                break;
            case 2 :
                InsertionfromEnd();
                break;
            case 3 :
                DeletionfromBeg();
                break;
            case 4 :
                DeletionfromEnd();
                break;
            case 5 :
                Deletionfrompos();
                break;
            case 6 :
                Search();
                break;
            case 7 :
                Display();
                break;
            case 8 :
                exit(0);
           
        }
    }
}










