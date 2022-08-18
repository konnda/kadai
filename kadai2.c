#include<stdio.h>

#define QUEUESIZE   10000   /* キューに積むことのできるデータの最大個数 */
#define SUCCESS     1     /* 成功 */
#define FAILURE     0     /* 失敗 */
#define ENQ  0
#define DEQ  1
#define PEEK 2
#define SIZE 3
#define END  -1


typedef struct
{
    int queue_data[QUEUESIZE];
    int queue_num;
    int queue_head;
}data_t;

data_t data;

int enqueue(int enq_data)
{
    int InputNum = (data.queue_head + data.queue_num) % QUEUESIZE;//リングバッファ
    if(data.queue_num < QUEUESIZE){  
    data.queue_data[InputNum] = enq_data;
    data.queue_num ++;
    return SUCCESS;
    }else{
        printf("queue data is full\n");
        return FAILURE;
    }
}

int dequeue(int *deq_data)
{
    if(data.queue_num > 0)
    {
        int true_queue_head = data.queue_head % QUEUESIZE;//リングバッファ対応用
        printf("dequeue %d\n",data.queue_data[true_queue_head]);
        *deq_data = data.queue_data[true_queue_head];
        data.queue_head++;
        data.queue_num--;
        return SUCCESS;
    }
    else
    {
        return FAILURE;
    }
}

void queuePrint()
{
    int i;
    int true_queue_head = data.queue_head % QUEUESIZE;//リングバッファ対応用
    printf("queue[");
    for(i = 0; i < data.queue_num; i++){
            printf("%3d",data.queue_data[(i + true_queue_head) % QUEUESIZE]);   
    }
    printf("]\n");
}

int peek()//peek関数
{
     if(data.queue_num > 0)
    {
        int true_queue_head = data.queue_head % QUEUESIZE;//リングバッファ対応用
        printf("peek %d\n",data.queue_data[true_queue_head]);
        return SUCCESS;
    }
    else
    {
        return FAILURE;
    }
}

int size()//size関数
{
    printf("element count:%d\n", data.queue_num);
}

int main()
{
    int input_num,function_call,function_select;
    data.queue_num = 0;
    for(;;)
    {
        printf("enqueue = 0, dequeue = 1, peek = 2, size = 3, end = -1\n");
        scanf("%d",&function_select);

        switch(function_select)
        {
        case ENQ:
            for(;;)
            {
                printf("enqueue number:");
                scanf("%d", &input_num);

                if(input_num == -1)
                {
                    break;
                }else{
                    enqueue(input_num);
                    printf("enqueue %d\n", input_num);
                    queuePrint();
                }
            }
        break;

        case DEQ:
            dequeue(&function_call);
            queuePrint();
            break;

        case PEEK:
            peek();
            break;
        
        case SIZE:
            size();
            break;

        case END:
            return 0;
            break;
        }
    }
}
