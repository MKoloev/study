﻿// ВТ.Лаб4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//Задание из двух частей.В первом задании необходимо подсчитать
//количество чисел, соответствующих определенному условию на некотором
//числовом промежутке.Во втором задании требуется модифицировать свою
//программу так, чтобы найти и вывести на экран двухсотое число или пару
//чисел соответствующих заданному условию.Если таких чисел меньше
//двухсот, то вывести об этом сообщение на экран.Для выполнения задания
//выделяется 8 часов аудиторного времени.
//7) На промежутке от - 128 до 127.Подсчитать количество таких пар чисел
//X и Y, что 50 < (Х - У) <= 80. Ответ вывести на экран.


#include <iostream>
#include <stdio.h> // необходим для работы printf
using namespace std;

int main()
{
    int F = -128;
    _asm
    {

        mov ecx, 0;//В ecx будет записываться количество подходяших пар
        mov eax, F;//eax это (X)
    M1://если eax меньше 128
        mov ebx, F;//ebx это (Н)
        M2:
            mov edx, eax;//в edx записывается (X)
            SUB edx, ebx;//в edx записывается (Х - У)

            cmp edx, 50;
            JLE M3;//если edx <= 50 то переходим k M3
                cmp edx, 80;
                JG M4;//если edx > 80 то переходим k M4
                    inc ecx;
                M4:
            M3:

            inc ebx;
            cmp ebx, 128;
            JL M2;//цикл ктый проверят ebx(Y) меньше 128

        inc eax;
        cmp eax, 128;
        JL M1;//если eax меньше 128

        mov F, ecx;
    }

    std::cout << F;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
