# include <stdio.h>
# include <malloc/malloc.h>  //包含了malloc函数
# include <stdlib.h>  //包含了exit函数

//定义了一个数据类型，该数据类型的名字叫做struct Arr, 该数据类型含有三个成员，分别是pBase, len, cnt
struct Arr
{
    int * pBase; //存储的是数组第一个元素的地址
    int len; //数组所能容纳的最大元素的个数
    int cnt; //当前数组有效元素的个数
};

void init_arr(struct Arr * pArr, int length);  //分号不能省
bool append_arr(struct Arr * pArr, int val); //追加
bool insert_arr(struct Arr * pArr, int pos, int val); // pos的值从1开始
bool delete_arr(struct Arr * pArr, int pos, int * pVal);
int get();
bool is_empty(struct Arr * pArr);
bool is_full(struct Arr * pArr);
void sort_arr(struct Arr * pArr);
void show_arr(struct Arr * pArr);
void inversion_arr(struct Arr * pArr);

int main(void)
{
    struct Arr arr;
    int val;

    init_arr(&arr, 8);
    append_arr(&arr, 1);
    append_arr(&arr, 2);
    append_arr(&arr, 3);
    append_arr(&arr, 4);
    append_arr(&arr, 5);
    append_arr(&arr, 6);
//    if ( delete_arr(&arr, 4, &val) )
//    {
//        printf("删除成功!\n");
//        printf("您删除的元素是: %d\n", val);
//    }
//    else
//    {
//        printf("删除失败!\n");
//    }
///*	append_arr(&arr, 2);
//	append_arr(&arr, 3);
//	append_arr(&arr, 4);
//	append_arr(&arr, 5);
//    insert_arr(&arr, 5, 99);
//	append_arr(&arr, 6);
//	append_arr(&arr, 7);
//	if ( append_arr(&arr, 8) )
//	{
//		printf("追加成功\n");
//	}
//	else
//	{
//		printf("追加失败!\n");
//	}
//*/
    show_arr(&arr);
    inversion_arr(&arr);
    printf("倒置之后的数组内容是:\n");
    show_arr(&arr);
//	sort_arr(&arr);
//	show_arr(&arr);

//	//printf("%d\n", arr.len);

    return 0;
}
void init_arr(struct Arr * pArr, int length)
{
    pArr->pBase = (int *)malloc(length * sizeof(int));
    if(pArr->pBase == NULL)
    {
        exit(1);
    }else
    {
        pArr->cnt = 0;
        pArr->len = length;
    }
}

bool append_arr(struct Arr * pArr, int val)
{
    if(pArr->cnt < pArr->len)
    {
        pArr->pBase[pArr->cnt++] = val;
        return true;
    }
    return false;
}

void show_arr(struct Arr * pArr)
{
    for(int i = 0;i < pArr->cnt;i++)
    {
        printf("%d ",pArr->pBase[i]);
    }
}

bool is_empty(struct Arr * pArr)
{
    if(pArr->cnt == 0)
    {
        return true;
    }
    return false;
}

bool is_full(struct Arr * pArr)
{
    if(pArr->cnt == pArr->len)
    {
        return true;
    }
    return false;
}

// pos的值从1开始
bool insert_arr(struct Arr * pArr, int pos, int val)
{
    if(pos <= 0 || pos > pArr->cnt || is_full(pArr))
    {
        return false;
    }

    //移动
    for(int i = pArr->cnt-1;i >= pos - 1;i-- )
    {
        pArr->pBase[i+1] = pArr->pBase[i];
    }
    pArr->pBase[pos-1] = val;
    pArr->cnt++;
    return true;
}

bool delete_arr(struct Arr * pArr, int pos, int * pVal)
{
    if(pos <= 0 || pos > pArr->cnt || is_empty(pArr))
    {
        return false;
    }

    //移动
    *pVal = pArr->pBase[pos - 1];
    for(int i = pos - 1;i < pArr->cnt -1;i++)
    {
        pArr->pBase[i] = pArr->pBase[i+1];
    }
    pArr->cnt--;
    return true;
}

void inversion_arr(struct Arr * pArr)
{
    if(pArr->cnt <= 1)
    {
        return;
    }
    int t,i = 0;
    while(i < pArr->cnt/2)
    {
        t = pArr->pBase[i];
        pArr->pBase[i] = pArr->pBase[pArr->cnt-i-1];
        pArr->pBase[pArr->cnt-i-1] = t;
        i++;
    }
}
