#include<stdio.h>
#define MAX 10

struct queue{
    int front,rear;
    int data[MAX];
};
struct queue q={-1,-1};

void isFull(struct queue *q){
    if(q->rear==MAX-1){
        printf("\nQueue is full");
    }
    else{
        printf("\nQueue is not full");
    }
}

void isEmpty(struct queue *q){
    if(q->front==-1 || q->front>q->rear){
        printf("\nQueue is empty");
    }
    else{
        printf("\nQueue is not empty");
    }
}

void enqueue(struct queue *q,int element){
    if(q->rear==MAX-1){
        printf("\nQueue overflow");
    }
    else{
        if(q->front==-1) q->front=0;
        q->rear++;
        q->data[q->rear]=element;
    }
}

int dequeue(struct queue *q){
    int element;
    if(q->front==-1 || q->front>q->rear){
        printf("\nQueue underflow");
        return -1;
    }
    else{
        element=q->data[q->front];
        q->front++;
        return element;
    }
}

void display(struct queue *q){
    int i;
    if(q->front==-1 || q->front>q->rear){
        printf("\nQueue is empty");
        return;
    }
    for(i=q->front;i<=q->rear;i++){
        printf("%d\t",q->data[i]);
    }
}

int main(){
    int ch,element;
    do{
        printf("\nENTER THE CHOICE");
        printf("\n1.CHECK IS FULL\n2.CHECK IS EMPTY\n3.ENQUEUE\n4.DEQUEUE\n5.DISPLAY\n6.EXIT\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                isFull(&q);
                break;
            case 2:
                isEmpty(&q);
                break;
            case 3:
                printf("\nEnter the element: ");
                scanf("%d",&element);
                enqueue(&q,element);
                break;
            case 4:
                element=dequeue(&q);
                if(element!=-1)
                    printf("\nYou dequeued %d",element);
                break;
            case 5:
                printf("Elements in queue are:\n");
                display(&q);
                break;
            case 6:
                break;
            default:
                printf("\nInvalid choice");
        }
    }while(ch!=6);
    return 0;
}
