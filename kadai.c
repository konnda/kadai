#include<stdio.h>

#define STACK_SIZE  100   /* スタックに積むことのできるデータの最大個数 */
#define SUCCESS     1     /* 成功 */
#define FAILURE     0     /* 失敗 */
#define PUSH 0
#define POP  1
#define PEEK 2
#define SIZE 3
#define END  -1

typedef struct {
    int stack_data[STACK_SIZE];
}data_t;


int stack_num;
data_t data;

int push(push_data)//push関数
{
    if (stack_num < STACK_SIZE) {
        data.stack_data[stack_num] = push_data;
        stack_num ++;
        return SUCCESS;
    } else {
        return FAILURE;
    }
}

int pop(data_t *pop_data)//pop関数
{
    if(stack_num > 0){
        int PopNo;
        int *Pop_Data;
        PopNo = stack_num;
        printf("pop %d\n",data.stack_data[PopNo - 1]);
        stack_num--;
        pop_data = data.stack_data[stack_num];
        return SUCCESS;
    }else{
        return FAILURE;
    }
}

void stackPrint()//stackしているデータを表示する関数
{
    int i;

    printf("stack[");
    for(i = 0;i < stack_num; i++){
        printf("%3d", data.stack_data[i]);
    }
    printf("]\n");
}

int peek(data_t *peek_data)//peek関数
{
    if(stack_num > 0){
        printf("peek %d\n", data.stack_data[stack_num - 1]);
        return SUCCESS;
    }else{
        return FAILURE;
    }
}

int size(data_t *size_data) //size関数
{
    printf("element count:%d\n", stack_num);
}

int main()
{
    int kannsuu_yobidasi,hantei;/*iは数字入力用、bは呼び出す関数選ぶ用*/

    stack_num = 0;
    while(1)
    {
        data_t data;

        printf("push = 0, pop = 1, peek = 2, size = 3\n");
        scanf("%d",&hantei);

        switch(hantei){
        case PUSH:/*push*/
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
            pop(&kannsuu_yobidasi);
            stackPrint();
            break;

        case PEEK://peek
            peek(kannsuu_yobidasi);
            break;

        case SIZE://size
            size(&kannsuu_yobidasi);
            break;

        case END://end
            return 0;
            break;
        }
    }
}