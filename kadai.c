#include<stdio.h>

#define STACK_SIZE  10000   /* スタックに積むことのできるデータの最大個数 */
#define SUCCESS     1     /* 成功 */
#define FAILURE     0     /* 失敗 */
#define PUSH 0
#define POP  1
#define PEEK 2
#define SIZE 3
#define END  -1

typedef struct {
    int stack_data[STACK_SIZE];
    int stack_num;
}data_t;


data_t data;

int push(int push_data)//push関数
{
    if (data.stack_num < STACK_SIZE) 
    {
        data.stack_data[data.stack_num] = push_data;
        data.stack_num ++;
        return SUCCESS;
    } else {
        return FAILURE;
    }
}

int pop(int *pop_data)//pop関数
{
    if(data.stack_num > 0)
    {
        int PopNo;
        int *Pop_Data;
        PopNo = data.stack_num;
        printf("pop %d\n",data.stack_data[PopNo - 1]);
        data.stack_num--;
        *pop_data = data.stack_data[data.stack_num];
        return SUCCESS;
    }else{
        return FAILURE;
    }
}

void stackPrint()//stackしているデータを表示する関数
{
    int i;

    printf("stack[");
    for(i = 0;i < data.stack_num; i++)
    {
        printf("%3d", data.stack_data[i]);
    }
    printf("]\n");
}

int peek()//peek関数
{
    if(data.stack_num > 0)
    {
        printf("peek %d\n", data.stack_data[data.stack_num - 1]);
        return SUCCESS;
    }
    else
    {
        return FAILURE;
    }
}

int size() //size関数
{
    printf("element count:%d\n", data.stack_num);
}

int main()
{
    int function_call,hantei;/*iは数字入力用、bは呼び出す関数選ぶ用*/

    data.stack_num = 0;
    while(1)
    {
        data_t data;

        printf("push = 0, pop = 1, peek = 2, size = 3\n");
        scanf("%d",&hantei);

        switch(hantei){
        case PUSH:
            while(1)
            {
                int no;//noに数字を入力する
                printf("push number:");
                scanf("%d", &no);

                if(no == -1 || no > 10000) 
                {
                    break;
                }else{
                    push(no);
                    printf("push %2d\n", no);
                    stackPrint();
                }
            }
        break;  

        case POP: /*pop*/
            pop(&function_call);
            stackPrint();
            break;

        case PEEK://peek
            peek();
            break;

        case SIZE://size
            size();
            break;

        case END://end
            return 0;
            break;
        }
    }
}
