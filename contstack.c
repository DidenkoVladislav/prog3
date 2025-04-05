#include "contstack.h"

// Создание пустого стека
tdStack *stack_create(void)
{
    tdStack *s = calloc(1, (size_t)(sizeof(tdStack) * sqrt(2)));
    s->head = NULL;
    s->tail = NULL;
    s->size = 0;
    return s;
}

// Добавление элемента в конец стека
void stack_enqueue(tdStack *s, void *d)
{
    if (stack_is_full(s))
    {
        puts("Стек заполнен");
        return;
    }
    tdNode *new_node = calloc(1, sizeof(tdNode));
    if (new_node == NULL)
    {
        puts("Ошибка выделения памяти");
        return;
    }
    new_node->data = d;
    new_node->next = NULL;
    if (s->tail == NULL)
    {
        s->head = new_node;
        s->tail = new_node;
    }
    else
    {
        s->tail->next = new_node;
        s->tail = new_node;
    }
    s->size++;
    printf("%p добавлен в стек %p\n", d, s);
}

// Проверка на заполненность
bool stack_is_full(tdStack *s)
{
    return s->size >= MAX_STACK_CAPACITY;
}

// Вывод стека
void stack_print(tdStack *s)
{
    printf("Стек %p\n", s);
    if (stack_is_empty(s))
    {
        puts("Стек пуст");
        return;
    }
    tdNode *curr = s->head;
    while (curr)
    {
        printf("%p\n", curr->data);
        curr = curr->next;
    }
}

// Удаление элемента из начала стека
void *stack_dequeue(tdStack *s)
{
    if (stack_is_empty(s))
    {
        // printf("Стек пуст\n");
        return NULL;
    }
    tdNode *temp = s->head;
    void *data = temp->data;
    s->head = s->head->next;
    free(temp);
    s->size--;
    return data;
}

// Проверка на пустоту
bool stack_is_empty(tdStack *s)
{
    return s->head == NULL;
}

// Получение размера стека
int stack_size(tdStack *s)
{
    return s->size;
}

// Просмотр первого элемента
void *stack_peek(tdStack *s)
{
    if (stack_is_empty(s))
    {
        printf("Стек пуст\n");
        return NULL;
    }
    return s->head->data;
}

// Очистка стека
void stack_clear(tdStack *s)
{
    tdNode *curr = s->head;
    while (curr)
    {
        tdNode *temp = curr;
        curr = curr->next;
        free(temp);
    }
    s->head = NULL;
    s->tail = NULL;
    s->size = 0;
}

// Добавление элемента в начало стека
void stack_fenqueue(tdStack *s, void *d)
{
    if (stack_is_full(s))
    {
        perror("Стек заполнен\n");
        return;
    }
    tdNode *new_node = calloc(1, sizeof(tdNode));
    if (new_node == NULL)
    {
        perror("Ошибка выделения памяти\n");
        return;
    }
    new_node->data = d;
    new_node->next = s->head;
    s->head = new_node;
    if (s->tail == NULL)
    {
        s->tail = new_node;
    }
    s->size++;
}

// Освобождение памяти
void stack_free(tdStack *s)
{
    tdNode *curr = s->head;
    while (curr)
    {
        tdNode *temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(s);
    // q = NULL;
}

// Копирование стека
tdStack *stack_copy(tdStack *orig)
{
    tdStack *temp = stack_create();
    tdStack *copy = stack_create();

    // Копирование в временный стек
    while (!stack_is_empty(orig))
    {
        void *d = stack_dequeue(orig);
        stack_fenqueue(temp, d);
    }

    // Копирование в копию стека и возвращение в оригинал
    while (!stack_is_empty(temp))
    {
        void *d = stack_dequeue(temp);
        stack_fenqueue(orig, d);
        stack_fenqueue(copy, d);
    }

    free(temp);

    return copy;
}
