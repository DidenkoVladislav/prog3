#include "contstack.h"

int main(void)
{
    int d1 = 5, d2 = 3, d3 = 7, d4 = 3;
    // Создание стека
    printf("Создадим стек s1 - ");
    tdStack *s1 = stack_create();
    printf("%p\n", s1);

    puts("Попробуем взять элемент из пустого стека s1");
    stack_peek(s1);

    puts("");

    puts("Добавим 2 элемента в стек s1");
    stack_enqueue(s1, &d1);
    stack_enqueue(s1, &d2);
    puts("Выведем стек s1");
    stack_print(s1);

    puts("");

    puts("Добавим элемент в начало стека s1");
    stack_fenqueue(s1, &d3);
    puts("Cтек s1");
    stack_print(s1);

    puts("");

    puts("Выведем первый элемент стека s1");
    printf("%p\n", stack_peek(s1));

    puts("");

    puts("Возьмём первый элемент стека s1");
    printf("%p\n", stack_dequeue(s1));
    puts("Cтек s1");
    stack_print(s1);

    puts("");

    printf("Создадим копию стека s1 s2");
    tdStack *s2 = stack_copy(s1);
    puts("Выведем оригинальный стек s1");
    stack_print(s1);
    puts("Выведем скопированный стек s2");
    stack_print(s2);

    puts("");

    puts("Удалим элемент из стека s1");
    stack_dequeue(s1);
    puts("Стек s1");
    stack_print(s1);
    puts("Стек s2");
    stack_print(s2);

    puts("");

    puts("Очистим стек s2");
    stack_clear(s2);
    stack_print(s2);

    puts("");

    puts("Добавим элемент в стек s2");
    stack_enqueue(s2, &d4);
    puts("Выведем стек s2");
    stack_print(s2);

    puts("");

    puts("Произведём слияние очереди s1 и s2 в s3");
    tdStack *s3 = stack_merge(s1, s2);
    puts("Выведем стек s3");
    stack_print(s3);

    puts("");

    puts("Создадим итератор для s3 it1 указывающий на начало");
    StackIterator *it1 = stack_iterator_create(s3, 0);
    puts("Используем его");
    printf("%p\n", stack_iterator_next(it1));
    puts("Используем ещё 2 раза");
    printf("%p\n", stack_iterator_next(it1));
    printf("%p\n", stack_iterator_next(it1));

    puts("");

    puts("Создадим итератор для s1 it2 указывающий на начало");
    StackIterator *it2 = stack_iterator_create(s1, 0);
    puts("Сравним it1 и it2");
    printf("it1 == it2: %d\n", stack_iterator_is_equal(it1, it2));

    // Освобождение памяти
    stack_free(s1);
    stack_free(s2);
    stack_free(s3);
    free(it1);
    free(it2);

    return EXIT_SUCCESS;
}
