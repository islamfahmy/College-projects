#include <stdio.h>
#include <stdlib.h>

/*
 * Process: Each process has a name and has an execution time.
 *          We keep track of how long the process still needs
 *          to run on the processor. "remaining_time" is the
 *          remaining execution time of the process.
 * Item: An item that is being enqueued to or dequeued from the queue
 *       It is a pointer to the process
 */
typedef struct
{
    int id;
    int remaining_time;
} Process, Item;
/*
 *
 */
typedef struct Node
{
    Item data;
    struct Node* next;
} Node;
/*
 *
 */
typedef struct
{
    Node *head;
    Node *tail;

} Queue;
/*
 *
 */
void init(Queue *q)
{
    q->head=NULL;
    q->tail=NULL;
}
/*
 *
 */
int isEmpty(Queue *q)
{

    return q->head==NULL ? 1:0;
}
/*
 *
 */
Item dequeue(Queue *q)
{
    if(!isEmpty(&q))
    {
        Item temp=q->head->data;
        Node * tmp =q->head;
        q->head=q->head->next;
        free(tmp);
        return temp;
    }
}
Node * construct(Item val)
{
    Node * temp=(Node *)malloc(sizeof(Node));
    temp->data=val;
    return temp;
}
void enqueue(Queue *q, Item val)
{     //printf("enque item =");print(val);
    if(q->head==NULL)
    {
        q->tail=construct(val);
        q->head=q->tail;
        q->tail->next=NULL;

    }
    else
    {
        q->tail->next=construct(val);
        q->tail=q->tail->next;
        q->tail->next=NULL;
    }

}
/*
 *
 */
void destroy(Queue *q)
{
    /* TODO: ADD YOUR CODE HERE */
}
/*
 * RoundRobin Scheduling
 */
void makeprocess(Queue*q,int time)
{  //   printf("process ");
    if(!isEmpty(q))
    {
        Item temp;
        temp=dequeue(q);
        // print(temp);
            temp.remaining_time--;
            printf("P%d (%d-->%d)\n",temp.id,time,time+1);
            if(temp.remaining_time!=0)
                enqueue(q,temp);
    }
        else
         printf("IDLE (%d-->%d)\n",time,time+1);
    }
    void print(Item p)
    {
        printf("id= %d time =%d\n",p.id,p.remaining_time);
    }
    void RoundRobin()
    {    Queue q;
        int n=4;
        int time =0A;
        init(&q);
        while (n--)
        {  //printf("while 1\n");
             Item temp;
            int start;
            char c[100];
            scanf("%s %d %d",&c,&start,&temp.remaining_time);
            c[0]='0';
            temp.id=atoi(&c);
           // print(temp);
            while((start>time&&isEmpty(&q))||(start-1>time&&!isEmpty(&q)))
                {makeprocess(&q,time);time++;}
            enqueue(&q,temp);
         // printf("enqueued");
        }
        while(!isEmpty(&q))
           {
               makeprocess(&q,time);time++;}

    }
    /*
     *
     */
    int main(int argc, char**argv)
    {
        RoundRobin();
        return 0;
       
    }
