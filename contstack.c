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
    printf("%p добавлен в стек %p\n", d, s);
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
    tdStack *copy = stack_create();

    tdNode *curr = orig->head;
    while (curr)
    {
        void *d = curr->data;
        stack_enqueue(copy, d);
        curr = curr->next;
    }

    return copy;
}

// Слияние двух стеков
tdStack *stack_merge(tdStack *s1, tdStack *s2)
{
    tdStack *merge = stack_create();

    tdNode *curr = s1->head;
    while (curr)
    {
        void *d = curr->data;
        stack_enqueue(merge, d);
        curr = curr->next;
    }

    curr = s2->head;
    while (curr)
    {
        void *d = curr->data;
        stack_enqueue(merge, d);
        curr = curr->next;
    }

    return merge;
}

// Создание итератора стека
StackIterator *stack_iterator_create(tdStack *s, int index)
{
    if ((index < 0) || (index > s->size))
    {
        puts("Ошибка: недопустимый индекс");
        return NULL;
    }
    StackIterator *it = calloc(1, sizeof(StackIterator));
    if (it == NULL)
    {
        puts("Ошибка выделения памяти");
        return NULL;
    }

    it->stack = s;
    it->current = s->head;
    while (index > 0)
    {
        it->current = it->current->next;
        index--;
    }

    return it;
}

// Получение данных итератором
void *stack_iterator_next(StackIterator *it)
{
    if (it->current == NULL)
    {
        printf("Итератор %p дошёл до конца\n", it);
        return NULL;
    }

    void *temp = it->current->data;
    it->current = it->current->next;

    return temp;
}

// Проверка стека итератора
bool stack_iterator_check_stack(StackIterator *it, tdStack *s)
{
    return it->stack == s;
}

// Проверка на равенство итераторов
bool stack_iterator_is_equal(StackIterator *it1, StackIterator *it2)
{
    return (it1->stack == it2->stack) && (it1->current == it2->current);
}
