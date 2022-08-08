#include<stdio.h>

#define QUEUE_SIZE  200   /* キューに積むことのできるデータの最大個数 */
#define SUCCESS     1     /* 成功 */
#define FAILURE     0     /* 失敗 */
#define ENQ  0
#define DEQ  1
#define PEEK 2
#define SIZE 3
#define END  -1


typedef struct{
    int queue_data[QUEUE_SIZE];
}data_t;

int queue_num, queue_head;
data_t data;

int enqueue(enq_data)
{
    if(queue_head + queue_num < QUEUE_SIZE){
    data.queue_data[queue_head + queue_num] = enq_data;
    queue_num ++;
    return SUCCESS;
    }else{
        return FAILURE;
    }
}

int dequeue(data_t *deq_data)
{
    if(queue_num > 0){
        printf("dequeue %d\n",data.queue_data[queue_head]);
        deq_data = data.queue_data[queue_head];
        queue_head++;
        queue_num--;
        return SUCCESS;
    }else{
        return FAILURE;
    }
}

void queuePrint()
{
    int i;
    printf("queue[");
    for(i = queue_head; i < (queue_head + queue_num); i++){
            printf("%3d",data.queue_data[i]);   
    }
    printf("]\n");
}

int peek(data_t *peek_data)//peek関数
{
     if(queue_num > 0){
        printf("peek %d\n",data.queue_data[queue_head]);
        return SUCCESS;
    }else{
        return FAILURE;
    }
}

int size(data_t *size_data)//size関数
{
    int queue_data_size = queue_num - queue_head;
    printf("element count:%d\n", queue_data_size);
}

int main(){
    int no,hikisuu,hantei;

    queue_num = 0;
    for(;;)
    {
        printf("enqueue = 0, dequeue = 1, peek = 2, size = 3, end = -1\n");
        scanf("%d",&hantei);

        switch(hantei){
        case ENQ:
            for(;;)
            {
                printf("enqueue number:");
                scanf("%d", &no);

                if(no == -1)
                {
                    break;
                }else{
                    enqueue(no);
                    printf("enqueue %d\n", no);
                    queuePrint();
                }
            }
        break;
        

        case DEQ:
            dequeue(&hikisuu);
            queuePrint();
            break;

        case PEEK:
            peek(&hikisuu);
            break;
        
        case SIZE:
            size(&hikisuu);
            break;

        case END:
            return 0;
            break;
        }
    }
}