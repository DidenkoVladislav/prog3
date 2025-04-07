#ifndef CONTSTACK_H
#define CONTSTACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Структура узел
typedef struct tdNode
{
    void *data;          // Данные
    struct tdNode *next; // Следующий узел
} tdNode;

// Структура стека
typedef struct
{
    tdNode *head; // Первый элемент
    tdNode *tail; // Последний элемент
    int size;     // Размер стека
} tdStack;

// Структура итератора
typedef struct
{
    tdStack *stack;
    tdNode *current;
} StackIterator;

// Прототипы

tdStack *stack_create(void);
void stack_enqueue(tdStack *s, void *d);
void stack_print(tdStack *s);
void *stack_dequeue(tdStack *s);
void *stack_pop(tdStack *s);
bool stack_is_empty(tdStack *s);
int stack_size(tdStack *s);
void *stack_peek(tdStack *s);
void *stack_peek_last(tdStack *s);
void stack_clear(tdStack *s);
void stack_fenqueue(tdStack *s, void *d);
tdStack *stack_copy(tdStack *orig);
tdStack *stack_merge(tdStack *s1, tdStack *s2);

void stack_free(tdStack *s);

StackIterator *stack_iterator_create(tdStack *s, int index);
void *stack_iterator_next(StackIterator *it);
bool stack_iterator_check_stack(StackIterator *it, tdStack *s);
bool stack_iterator_is_equal(StackIterator *it1, StackIterator *it2);

#endif
