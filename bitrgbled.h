#ifndef BITRGBLED_H
#define BITRGBLED_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// Константы
enum
{
    RED = 0,
    GREEN = 8,
    BLUE = 16,
    RED_MASK = 0xFF,
    GREEN_MASK = 0xFF00,
    BLUE_MASK = 0xFF0000,
    BRIGHTNESS = 24,
    BRIGHTNESS_MASK = 0x7F000000,
    COLORTEMP = 31,
    COLORTEMP_MASK = 0x1FFF80000000,
    CONTROL_TYPE = 45,
    CONTROL_TYPE_MASK = 0xE00000000000,
    MODE = 48,
    MODE_MASK = 0x3000000000000
};

// Объявления
typedef unsigned char uch;
typedef unsigned long ulg;
typedef unsigned short ushort;

// Структура
typedef struct
{
    uch red : 8;
    uch green : 8;
    uch blue : 7;
    uch : 1;
    uch brightness : 8;
    ushort colortemp : 14;
    ushort : 2;
    uch controltype : 3;
    uch mode : 2;
    uch : 3;
    ulg : 0;
} BITrgbled;

// Процедуры для работы с переменной
void bitrgbled_constructor(ulg *s, uch red, uch green, uch blue, uch brightness, ushort colortemp, uch controltype, uch mode);
void bitrgbled_setred(ulg *s, uch n);
void bitrgbled_setgreen(ulg *s, uch n);
void bitrgbled_setblue(ulg *s, uch n);
void bitrgbled_setbrightness(ulg *s, uch n);
void bitrgbled_setcolortemp(ulg *s, ushort n);
void bitrgbled_setcontroltype(ulg *s, uch n);
void bitrgbled_setmode(ulg *s, uch n);

void show_bitrgbled(ulg *s);
void show_bitrgbled_bits(ulg s);

// Процедуры для работы со структурой
void bitrgbled_struct_constructor(BITrgbled *b, uch red, uch green, uch blue, uch brightness, ushort colortemp, uch controltype, uch mode);
void bitrgbled_struct_setred(BITrgbled *b, uch n);
void bitrgbled_struct_setgreen(BITrgbled *b, uch n);
void bitrgbled_struct_setblue(BITrgbled *b, uch n);
void bitrgbled_struct_setbrightness(BITrgbled *b, uch n);
void bitrgbled_struct_setcolortemp(BITrgbled *b, ushort n);
void bitrgbled_struct_setcontroltype(BITrgbled *b, uch n);
void bitrgbled_struct_setmode(BITrgbled *b, uch n);

void show_struct_bitrgbled(BITrgbled *b);
void show_struct_bitrgbled_bits(BITrgbled *b);

void destroy_struct_bitrgbled(BITrgbled *b);
#endif
