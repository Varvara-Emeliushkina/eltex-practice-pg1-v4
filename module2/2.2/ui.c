#include <stdio.h>
#include "ui.h"
#include "calculator.h"

void print_error(int msg){
    switch (msg)
    {
    case 0:
        printf("На ноль делить нельзя!!!\n");
        break;
    case 1:
        printf("Неверный выбор *в жизни :(\n");
        break;
    case 2:
        printf("Оба значения должны быть числами!!!\n");
    }
}

void menu(){
    printf("____________________________\n");
    printf("|                          |\n");
    printf("|    ГАДКИЙ КАЛЬКУЛЯТОР    |\n");
    printf("|__________________________|\n");
    printf("|      Зачем пришёл?       |\n");
    printf("|__________________________|\n");
    printf("|    1. Сложить (+)        |\n");
    printf("|    2. Вычесть (-)        |\n");
    printf("|    3. Умножить (*)       |\n");
    printf("|    4. Разделить (/)      |\n");
    printf("|    0. Всё. Ухожу!        |\n");
    printf("|__________________________|\n");
    printf("Ваш выбор: ");
}

void run_c(){
    int choice;
    double a, b, result;
    
    while (1){
        menu();
         if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            print_error (1);
            continue;
         }

        if (choice == 0) {
            printf("До связи!\n");
            break;
        }

        if (choice <1 || choice >4) {
            print_error (1); 
            continue;
        }

        printf("Введите первое число: ");
        if (scanf ("%lf", &a) != 1) {
            print_error (2);
            while (getchar() != '\n');
            continue;
        }

        printf("Введите второе число: ");
        if (scanf ("%lf", &b) != 1) {
            print_error (2);
            while (getchar() != '\n');
            continue;
        }

        switch (choice)
        {
        case 1:
            result = add(a,b);
            printf("Результат %.2lf + %.2lf = %.2lf\n", a, b, result);
            break;
        case 2:
            result = substract(a,b);
            printf("Результат %.2lf - %.2lf = %.2lf\n", a, b, result);
            break;
        case 3:
            result = multiply(a,b);
            printf("Результат %.2lf * %.2lf = %.2lf\n", a, b, result);
            break;
        case 4:
            if (b != 0) { 
                result = devide(a,b);
                printf("Результат %.2lf / %.2lf = %.2lf\n", a, b, result);
            } else print_error (0);
            break;
        }
        printf("\n");
    }
}