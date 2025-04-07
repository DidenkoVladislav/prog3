#include "contstack.h"
#include "matrix2d.h"

int main(void)
{
    Matrix2d *mat1, *mat2, *mat3, *mat4, *mat5;

    // Создание Matrix2d
    mat1 = matrix2d_default_constructor();
    mat2 = matrix2d_default_constructor();
    mat3 = matrix2d_default_constructor();
    mat4 = matrix2d_default_constructor();
    mat5 = matrix2d_default_constructor();

    // Создание стека
    printf("Создадим стек s1 - ");
    tdStack *s1 = stack_create();
    printf("%p\n", s1);

    puts("Попробуем взять элемент из пустого стека s1");
    stack_peek(s1);

    puts("");

    puts("Добавим 2 элемента в стек s1");
    stack_enqueue(s1, mat1);
    stack_enqueue(s1, mat2);
    puts("Выведем стек s1");
    stack_print(s1);

    puts("");

    puts("Добавим элемент в начало стека s1");
    stack_fenqueue(s1, mat3);
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

    puts("Добавим элемент в стек s1");
    stack_enqueue(s1, mat4);
    puts("Cтек s1");
    stack_print(s1);

    puts("");

    puts("Возьмём последний элемент стека s1");
    printf("%p\n", stack_pop(s1));
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
    stack_enqueue(s2, mat5);
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

    puts("");

    puts("Получим структуру Matrix2d из итератора it2 и выведем её");
    Matrix2d *mattest = stack_iterator_next(it2);
    printf("%p\n", mattest);
    show_matrix2d(mattest);

    // Освобождение памяти
    stack_free(s1);
    stack_free(s2);
    stack_free(s3);
    free(it1);
    free(it2);
    destroy_matrix2d(mat1, 1);
    destroy_matrix2d(mat2, 1);
    destroy_matrix2d(mat3, 1);
    destroy_matrix2d(mat4, 1);
    destroy_matrix2d(mat5, 1);

    return EXIT_SUCCESS;
}
