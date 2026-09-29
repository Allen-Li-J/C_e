#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
struct Node
{
    int data;
    PtrToNode next;
};
typedef PtrToNode List;

List createListHead(int N);
List CreateListTail(int Z);
List ListInsert(List S, int n);
void FreeMalloc(List M);
int FactorialSum(List W, int x);

int main()
{
    List T;
    int num = 0, result = 0, pos = 0;
    printf("创建头插入链表\n");
    printf("请输入整数num:\n");
    scanf("%d", &num);
    printf("请输入num个整数,中间以回车符隔开\n");
    T = createListHead(num);
    result = FactorialSum(T, num);
    printf("result = %d\n", result);
    FreeMalloc(T);
    printf("创建尾插入链表\n");
    printf("请输入整数num:\n");
    scanf("%d", &num);
    printf("请输入num个整数,中间以回车符隔开\n");
    T = CreateListTail(num);
    printf("请输入要插入链表的位置:");
    scanf("%d", &pos);
    if (pos > num)
        printf("插入位置超过链表长度,默认插入尾部\n");
    // if (pos > num)
    //{
    //     printf("非法输入,请输入小于num的整数:\n");
    //     scanf("%d", &pos);
    // }
    if (pos == 1 || pos > num)
        T = ListInsert(T, pos);
    else
        ListInsert(T, pos);
    result = FactorialSum(T, num);
    printf("result = %d\n", result);
    FreeMalloc(T);
    return 0;
}

List createListHead(int N)
{
    List L = NULL;
    for (int i = 0; i < N; i++)
    {
        List p = (List)malloc(sizeof(struct Node));
        scanf("%d", &p->data);
        p->next = L;
        L = p;
    }
    return L;
}

List CreateListTail(int Z)
{
    List head = (List)malloc(sizeof(struct Node));
    // head->data = scanf("%d", &head->data); 经典错误，scanf获取成功时返回的是正确按指定格式输入变量的个数，也即正确接收到值的变量个数此处接受一个变量所以返回1
    // 如果scanf("%d,%d,%d",&a1,&a2,&a3)，且用户输入为：1,2,a时，scanf会返回2，因为正确接收了2个字符
    scanf("%d", &head->data);
    head->next = NULL;
    List tail = head;
    for (int j = 2; j <= Z; j++)
    {
        List q = (List)malloc(sizeof(struct Node));
        scanf("%d", &q->data);
        q->next = NULL;
        tail->next = q;
        tail = q;
    }
    return head;
}

// 单个节点插入
List ListInsert(List S, int n)
{
    List M = S;
    if (n == 1)
    {
        List L = (List)malloc(sizeof(struct Node));
        printf("请输入要插入的节点数据:\n");
        scanf("%d", &L->data);
        L->next = M;
        S = L;
        return S;
    }
    for (int i = 1; i < n - 1; i++)
    {
        M = M->next;
        if (M->next == NULL)
        {
            List L = (List)malloc(sizeof(struct Node));
            printf("请输入要插入的节点数据:\n");
            scanf("%d", &L->data);
            L->next = NULL;
            M->next = L;
            return S;
        }
    }
    List L = (List)malloc(sizeof(struct Node));
    printf("请输入要插入的节点数据:\n");
    scanf("%d", &L->data);
    L->next = M->next;
    M->next = L;
}

// 整个链表插入

void FreeMalloc(List M)
{
    while (M != NULL)
    {
        List current = M;
        M = M->next;
        free(current);
    }
    printf("内存已释放\n");
}

int FactorialSum(List W, int x)
{
    int mul = 1, sum = 0;
    int a[x];
    List V = W;
    while (W != NULL)
    {
        for (int i = 1; i <= W->data; i++)
        {
            mul *= i;
        }
        sum += mul;
        mul = 1;
        W = W->next;
    }
    printf("节点的阶乘和为:");
    while (V != NULL)
    {
        printf("%d! + ", V->data);
        V = V->next;
        if (V->next == NULL)
        {
            break;
        }
    }
    printf("%d! = %d\n", V->data, sum);
    // printf("节点的阶乘和为:%d! + %d! +%d!\n", a[0], a[1], a[2]);
    return sum;
}
