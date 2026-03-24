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
    printf("|    5. Степень (^)        |\n");
    printf("|    0. Всё. Ухожу!        |\n");
    printf("|__________________________|\n");
    printf("Ваш выбор: ");
}

void run_c(){
    int choice;
    double a, b, result;
    
    double (*operations[])(double, double) = {add, substract, multiply, devide, power};
    char* symbols[] = {"+", "-", "*", "/", "^"};
    int operations_count = sizeof(operations)/sizeof(operations[0]);

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

        if (choice <1 || choice > operations_count) {
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

        if (choice == 4 && b == 0) {
            print_error (0);
            continue;
        } 

        int index = choice - 1; 

        result = operations[index](a, b);
        printf ("Результат: %.2lf %s %.2lf = %.2lf\n", a, symbols[index], b, result);
    }
}