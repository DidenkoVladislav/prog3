#include "bitrgbled.h"

const char *mode_work_types[3] = {"свечение", "мерцание", "затухание"};

// bitrgbled как переменная
// Конструктор
void bitrgbled_constructor(ulg *s, uch red, uch green, uch blue, uch brightness, ushort colortemp, uch controltype, uch mode)
{
    *s = 0;
    bitrgbled_setred(s, red);
    bitrgbled_setgreen(s, green);
    bitrgbled_setblue(s, blue);
    bitrgbled_setbrightness(s, brightness);
    bitrgbled_setcolortemp(s, colortemp);
    bitrgbled_setcontroltype(s, controltype);
    bitrgbled_setmode(s, mode);
}

// Установка канала красного цвета
void bitrgbled_setred(ulg *s, uch n)
{
    *s &= ~(ulg)RED_MASK;
    *s |= ((ulg)n << RED) & RED_MASK;
}

// Установка канала синего цвета
void bitrgbled_setgreen(ulg *s, uch n)
{
    *s &= ~(ulg)GREEN_MASK;
    *s |= ((ulg)n << GREEN) & GREEN_MASK;
}

// Установка канала зелёного цвета
void bitrgbled_setblue(ulg *s, uch n)
{
    *s &= ~(ulg)BLUE_MASK;
    *s |= ((ulg)n << BLUE) & BLUE_MASK;
}

// Установка яркости
void bitrgbled_setbrightness(ulg *s, uch n)
{
    if (n > 100)
    {
        exit(EXIT_FAILURE);
    }
    *s &= ~(ulg)BRIGHTNESS_MASK;
    *s |= ((ulg)n << BRIGHTNESS) & BRIGHTNESS_MASK;
}

// Установка температуры цвета
void bitrgbled_setcolortemp(ulg *s, ushort n)
{
    if (n < 800)
    {
        exit(EXIT_FAILURE);
    }
    if (n > 15000)
    {
        exit(EXIT_FAILURE);
    }
    *s &= ~(ulg)COLORTEMP_MASK;
    *s |= ((ulg)n << COLORTEMP) & COLORTEMP_MASK;
}

// Установка типа управления
void bitrgbled_setcontroltype(ulg *s, uch n)
{
    if (n > 8)
    {
        exit(EXIT_FAILURE);
    }
    *s &= ~(ulg)CONTROL_TYPE_MASK;
    *s |= ((ulg)n << CONTROL_TYPE) & CONTROL_TYPE_MASK;
}

// Установка режима работы
void bitrgbled_setmode(ulg *s, uch n)
{
    if (n > 2)
    {
        exit(EXIT_FAILURE);
    }
    *s &= ~(ulg)MODE_MASK;
    *s |= ((ulg)n << MODE) & MODE_MASK;
}

// Вывод параметров
void show_bitrgbled(ulg *s)
{
    printf("Канал красного цвета: %lu\n", (*s & RED_MASK) >> RED);
    printf("Канал зелёного цвета: %lu\n", (*s & GREEN_MASK) >> GREEN);
    printf("Канал синего цвета: %lu\n", (*s & BLUE_MASK) >> BLUE);
    printf("Уровень яркости: %lu%%\n", (*s & BRIGHTNESS_MASK) >> BRIGHTNESS);
    printf("Температура цвета: %luK\n", (*s & COLORTEMP_MASK) >> COLORTEMP);
    printf("Тип модуля управления: %lu\n", (*s & CONTROL_TYPE_MASK) >> CONTROL_TYPE);
    printf("Режим работы: %s\n", mode_work_types[(*s & MODE_MASK) >> MODE]);
}

void show_bitrgbled_bits(ulg s)
{
    static const int size = CHAR_BIT * sizeof(ulg);

    for (int i = size - 1; i >= 0; i--)
        putchar((s >> i) & 1 ? '1' : '0');
    putchar('\n');
}

// bitrgbled как структура
static void mem_check(void *p)
{
    if (p == NULL)
    {
        free(p);
        puts("Ошибка выделения памяти.\n");
        exit(EXIT_FAILURE);
    }
}

// Конструктор
void bitrgbled_struct_constructor(BITrgbled *b, uch red, uch green, uch blue, uch brightness, ushort colortemp, uch controltype, uch mode)
{
    mem_check(b);
    bitrgbled_struct_setred(b, red);
    bitrgbled_struct_setgreen(b, green);
    bitrgbled_struct_setblue(b, blue);
    bitrgbled_struct_setbrightness(b, brightness);
    bitrgbled_struct_setcolortemp(b, colortemp);
    bitrgbled_struct_setcontroltype(b, controltype);
    bitrgbled_struct_setmode(b, mode);
}

// Установка канала красного цвета
void bitrgbled_struct_setred(BITrgbled *b, uch n)
{
    mem_check(b);
    b->red = n;
}

// Установка канала синего цвета
void bitrgbled_struct_setgreen(BITrgbled *b, uch n)
{
    mem_check(b);
    b->green = n;
}

// Установка канала зелёного цвета
void bitrgbled_struct_setblue(BITrgbled *b, uch n)
{
    mem_check(b);
    b->blue = n;
}

// Установка яркости
void bitrgbled_struct_setbrightness(BITrgbled *b, uch n)
{
    mem_check(b);
    if (n > 100)
    {
        exit(EXIT_FAILURE);
    }
    b->brightness = n;
}

// Установка температуры цвета
void bitrgbled_struct_setcolortemp(BITrgbled *b, ushort n)
{
    mem_check(b);
    if (n < 800)
    {
        exit(EXIT_FAILURE);
    }
    if (n > 15000)
    {
        exit(EXIT_FAILURE);
    }
    b->colortemp = n;
}

// Установка типа управления
void bitrgbled_struct_setcontroltype(BITrgbled *b, uch n)
{
    mem_check(b);
    if (n > 8)
    {
        exit(EXIT_FAILURE);
    }
    b->controltype = n;
}

// Установка режима работы
void bitrgbled_struct_setmode(BITrgbled *b, uch n)
{
    mem_check(b);
    if (n > 2)
    {
        exit(EXIT_FAILURE);
    }
    b->mode = n;
}

// Вывод параметров
void show_struct_bitrgbled(BITrgbled *b)
{
    mem_check(b);
    printf("Канал красного цвета: %hu\n", b->red);
    printf("Канал зелёного цвета: %hu\n", b->green);
    printf("Канал синего цвета: %hu\n", b->blue);
    printf("Уровень яркости: %hu%%\n", b->brightness);
    printf("Температура цвета: %uK\n", b->colortemp);
    printf("Тип модуля управления: %hu\n", b->controltype);
    printf("Режим работы: %s\n", mode_work_types[b->mode]);
}

static void printbits(unsigned int num, int bits)
{
    for (int i = bits - 1; i >= 0; i--)
        putchar((num & (1 << i)) ? '1' : '0');
}

void show_struct_bitrgbled_bits(BITrgbled *b)
{
    int size = CHAR_BIT * sizeof(ulg) - (8 + 8 + 8 + 8 + 14 + 3 + 2);

    for (int i = size - 1; i >= 0; i--)
        putchar('0');

    printbits(b->mode, 2);
    printbits(b->controltype, 3);
    printbits(b->colortemp, 14);
    printbits(b->brightness, 8);
    printbits(b->blue, 8);
    printbits(b->green, 8);
    printbits(b->red, 8);

    putchar('\n');
}

// Очистка структуры bitrgbled
void destroy_struct_bitrgbled(BITrgbled *b)
{
    free(b);
    b = NULL;
}
