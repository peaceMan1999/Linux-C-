#include "Queue.h"


// 初始化
void Init(Queue* que)
{
    que->head = que->tail = NULL;
}

// 插入
void Push(Queue* que, T x)
{
    QueueNode* newNode = (QueueNode*) malloc (sizeof(QueueNode));
    if (newNode == NULL){
        perror("Found");
        exit(-1);
    }
    newNode->data = x;
    newNode->next = NULL;

    // 空和非空两种情况
    if (que->head == NULL){
        que->head = que->tail = newNode;
    }else{
        que->tail->next = newNode;
        que->tail = newNode;
    }
}

// 删除
void Pop(Queue* que)
{
    assert(que);
    assert(que->head);

    if (que->head == que->tail){
        free(que->head);
        que->head = que->tail = NULL;
    }else{
        QueueNode* cur = que->head->next;
        free(que->head);
        que->head = cur;
    }
}

// 队前、队后
void QueueFront(Queue* que)
{    
    assert(que);
    assert(que->head);

    printf("队前:%d\n", que->head->data);
}
void QueueBack(Queue* que)
{
    assert(que);
    assert(que->head);

    printf("队尾:%d\n", que->tail->data);
}

// 大小
void Size(Queue* que)
{
    assert(que);

    QueueNode* cur = que->head;
    int count = 0;
    while (cur)
    {
        count++;
        cur = cur->next;
    }
    printf("大小:%d\n", count);

}

// 判空
void Emply(Queue* que)
{
    assert(que);

    if (que->head == NULL){
        printf("空\n");
    }else{
        printf("非空\n");
    }
}

// 清空
void Delete(Queue* que)
{
    assert(que);

    QueueNode* cur = que->head;
    while (cur)
    {
        QueueNode* p = cur->next;
        free(cur);
        cur = p;
    }

    que->head = que->tail = NULL;
}

// 打印
void Print(Queue* que)
{
    assert(que);

    QueueNode* cur = que->head;
    printf("队列 : ");
    while (cur)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n"); 

}



