#include "contqueue.h"
#include "matrix2d.h"

int main(void)
{
    Matrix2d *mat1, *mat2, *mat3, *mat4, *mat5, *mat6;

    // Создание Matrix2d
    mat1 = matrix2d_default_constructor();
    mat2 = matrix2d_default_constructor();
    mat3 = matrix2d_default_constructor();
    mat4 = matrix2d_default_constructor();
    mat5 = matrix2d_default_constructor();
    mat6 = matrix2d_default_constructor();

    // Создание очереди
    printf("Создадим очередь q1 - ");
    tdQueue *q1 = queue_create();
    printf("%p\n", q1);
    printf("Очередь пуста: %d\n", queue_is_empty(q1));

    puts("Попробуем взять элемент из пустой очереди q1");
    queue_dequeue(q1);
    puts("Попробуем вывести элемент из пустой очереди q1");
    queue_peek(q1);

    puts("");

    puts("Добавим 2 элемента в очередь q1");
    queue_enqueue(q1, mat1);
    queue_enqueue(q1, mat2);
    printf("Размер очереди q1: %d\n", queue_size(q1));
    puts("Выведем очередь q1");
    queue_print(q1);

    puts("");

    puts("Добавим элемент в начало очереди q1");
    queue_fenqueue(q1, mat3);
    puts("Очередь q1");
    queue_print(q1);

    puts("");

    puts("Выведем первый элемент очереди q1");
    printf("%p\n", queue_peek(q1));

    puts("");

    puts("Возьмём первый элемент очереди q1");
    printf("%p\n", queue_dequeue(q1));
    puts("Очередь q1");
    queue_print(q1);

    puts("");

    puts("Добавим элемент в очередь q1");
    queue_enqueue(q1, mat4);
    puts("Очередь q1");
    queue_print(q1);

    puts("");

    puts("Выведем последний элемент очереди q1");
    printf("%p\n", queue_peek_last(q1));

    puts("");

    puts("Возьмём элемент очереди q1");
    printf("%p\n", queue_dequeue(q1));
    puts("Очередь q1");
    queue_print(q1);

    puts("");

    puts("Создадим копию очереди q1 - q2");
    tdQueue *q2 = queue_copy(q1);
    puts("Выведем очередь q1");
    queue_print(q1);
    puts("Выведем очередь q2");
    queue_print(q2);

    puts("");

    puts("Удалим элемент из очереди q1");
    queue_dequeue(q1);
    puts("Очередь q1");
    queue_print(q1);
    puts("Очередь q2");
    queue_print(q2);

    puts("");

    puts("Очистим очередь q2");
    queue_clear(q2);
    queue_print(q2);
    puts("Выведем очередь q1");
    queue_print(q1);

    puts("");

    puts("Добавим элемент в очередь q2");
    queue_enqueue(q2, mat5);
    puts("Выведем очередь q2");
    queue_print(q2);
    puts("Выведем очередь q1");
    queue_print(q1);

    puts("");

    puts("Произведём слияние очередей q1 и q2 в q3");
    tdQueue *q3 = queue_merge(q1, q2);
    puts("Выведем очередь q3");
    queue_print(q3);

    puts("");

    puts("Создадим очереди q4 и q5");
    tdQueue *q4 = queue_create();
    tdQueue *q5 = queue_create();
    queue_print(q4);
    queue_print(q5);

    puts("");

    puts("Сольём их в q6");
    tdQueue *q6 = queue_merge(q4, q5);
    queue_print(q6);

    puts("");

    puts("Добавим элемент в q6");
    queue_enqueue(q6, mat6);
    queue_print(q6);

    puts("");

    puts("Сольём q6 и q5 в q7");
    tdQueue *q7 = queue_merge(q6, q5);
    queue_print(q7);

    puts("");

    puts("Создадим итераторы для q3 - it1 и it2 указывающие на начало");
    QueueIterator *it1 = queue_iterator_create(q3, 0);
    QueueIterator *it2 = queue_iterator_create(q3, 0);
    printf("Итератор it1 указывает на q2: %d\n", queue_iterator_check_queue(it1, q2));
    printf("Итератор it1 указывает на q3: %d\n", queue_iterator_check_queue(it1, q3));
    printf("Итератор it1 равен итератору it2: %d\n", queue_iterator_is_equal(it1, it2));
    puts("Используем итератор it1 и выведем элемент");
    printf("%p\n", queue_iterator_next(it1));
    printf("Итератор it1 равен итератору it2: %d\n", queue_iterator_is_equal(it1, it2));
    puts("Используем ещё 2 раза");
    printf("%p\n", queue_iterator_next(it1));
    printf("%p\n", queue_iterator_next(it1));

    puts("");

    puts("Создадим итератор для q1 - it3 указывающий на начало");
    QueueIterator *it3 = queue_iterator_create(q1, 0);
    puts("Сравним it2 и it3");
    printf("it2 == it3: %d\n", queue_iterator_is_equal(it2, it3));

    puts("");

    puts("Получим структуру Matrix2d из итератора it3 и выведем её");
    Matrix2d *mattest = queue_iterator_next(it3);
    printf("%p\n", mattest);
    show_matrix2d(mattest);

    // Освобождение памяти
    queue_free(q1);
    queue_free(q2);
    queue_free(q3);
    queue_free(q4);
    queue_free(q5);
    queue_free(q6);
    queue_free(q7);
    free(it1);
    free(it2);
    free(it3);
    destroy_matrix2d(mat1, 1);
    destroy_matrix2d(mat2, 1);
    destroy_matrix2d(mat3, 1);
    destroy_matrix2d(mat4, 1);
    destroy_matrix2d(mat5, 1);
    destroy_matrix2d(mat6, 1);

    return EXIT_SUCCESS;
}
