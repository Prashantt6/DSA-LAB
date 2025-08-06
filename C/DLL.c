#include<stdio.h>
#include<stdlib.h>
struct DLL {
    int data;
    struct DLL *next;
    struct DLL *prev;
};
struct DLL *first, *last = NULL;

void InsertfromBegining(){
    struct DLL *NewNode;
    NewNode = (struct DLL*)malloc(sizeof(struct DLL));
    NewNode->next = NULL;
    NewNode->prev = NULL;
    printf("Enter the data");
    scanf("%d",&NewNode->data);
    if(first==NULL)
        first=last=NewNode;
    else 
    {
        NewNode->next = first;
        first = NewNode;
        
    }
}
void InsertfromEnd(){
    struct DLL *NewNode;
    NewNode = (struct DLL *)malloc(sizeof(struct DLL));
    NewNode->next = NULL;
    NewNode->prev = NULL;
    printf("Enter the data");
    scanf("%d",&NewNode->data);
    if(first==NULL && last == NULL){
        first=last=NewNode;
    }
    else {
        NewNode->prev = last;
        NewNode->next = NULL;
        last = NewNode;
    }
}
void DeletionfromBeg()
{
    struct  DLL*temp;
    
    if(first==NULL)
        printf("List is empty\n");
    else 
    {
        temp = first;
        first = first->next;
        printf("%d was deleted from beginning\n",temp->data);
        free(temp);
    }
}
void DeletionfromEnd()
{
    struct DLL *temp =last;

    
    if(first == NULL)
        printf("List is empty\n");
    else if(first->next == NULL)
    {
        temp= first;
        first = last = NULL;
        printf("%d was deleted\n",temp->data);
        free(temp);
    }
    else 
    {   printf("%d was deleted\n", temp->data);
        last = last->prev;
        last->next = NULL;
        free(temp);
    }
}
void DeletefromPos(){
    struct DLL *temp ;
    struct DLL *tempp;
    int pos, i;
    
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
void Search(int key)
{
    int flag = 0;
    struct DLL *temp;
    if(first == NULL)
        printf("Empty List!!\n");
    else
    {
        temp = first;
        while(temp!=NULL)
        {
            if(temp->data == key)
            {
                printf("%d found in list!\n", key);
                flag = 1;
            }
            temp = temp->next;
        }
        if(flag == 0)
        {
            printf("%d not found in list!\n", key);
        }
    }
}
void Display()
{
    struct DLL *temp;
    temp = first;
    if (first == NULL)
        printf("Empty List !!\n");
    else
    {
        while(temp!=NULL)
        {
            printf("%d <-> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main(){
    int ch = 0, key;
  
    
    while (ch !=8)
    {
        printf("1.Insertion from Beginning\n 2.Insertion from End \n 3.Deletion from Beginning \n 4.Deletion from End\n 5.Deletion from desired position\n 6.Searching \n 7.Display \n 8.End\n");
        printf("\nEnter the choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1 :
            InsertfromBegining();
            break;
        case 2 : 
            InsertfromEnd();
            break;
        case 3 :
            DeletionfromBeg();
            break;
        case 4 :
            DeletionfromEnd();
            break;
        case 5 : 
            DeletefromPos();
            break;
        case 6 :
            printf("Enter the data you wanted to search");
            scanf("%d",&key);
            Search(key);
            break;
        case 7 :
            Display();
            break;
        case 8 : 
            break;
        
        default:
            printf("Invalid choice");
            break;
        }
    }
    

}