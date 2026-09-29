#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef Node *List;

static List createNode(int data)
{
    List node = (List)malloc(sizeof(Node));
    if (node == NULL)
    {
        return NULL;
    }

    node->data = data;
    node->next = NULL;
    return node;
}

void freeList(List head);

/* Insert every new node at the front of the list. */
List createListHead(const int values[], size_t count)
{
    List head = NULL;

    for (size_t i = 0; i < count; ++i)
    {
        List node = createNode(values[i]);
        if (node == NULL)
        {
            freeList(head);
            return NULL;
        }

        node->next = head;
        head = node;
    }

    return head;
}

/* Append every new node at the end of the list. */
List createListTail(const int values[], size_t count)
{
    List head = NULL;
    List tail = NULL;

    for (size_t i = 0; i < count; ++i)
    {
        List node = createNode(values[i]);
        if (node == NULL)
        {
            freeList(head);
            return NULL;
        }

        if (head == NULL)
        {
            head = node;
        }
        else
        {
            tail->next = node;
        }
        tail = node;
    }

    return head;
}

void printList(const List head)
{
    List current = head;
    while (current != NULL)
    {
        printf("%d", current->data);
        if (current->next != NULL)
        {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

void freeList(List head)
{
    while (head != NULL)
    {
        List current = head;
        head = head->next;
        free(current);
    }
}

int main(void)
{
    const int values[] = {1, 2, 3, 4, 5};
    const size_t count = sizeof(values) / sizeof(values[0]);

    List headList = createListHead(values, count);
    if (headList == NULL)
    {
        fprintf(stderr, "头插法创建链表失败。\n");
        return EXIT_FAILURE;
    }
    printf("头插法: ");
    printList(headList);
    freeList(headList);

    List tailList = createListTail(values, count);
    if (tailList == NULL)
    {
        fprintf(stderr, "尾插法创建链表失败。\n");
        return EXIT_FAILURE;
    }
    printf("尾插法: ");
    printList(tailList);
    freeList(tailList);

    return EXIT_SUCCESS;
}
