// 2.2 Написать программу-калькулятор: в основном меню программа
// запрашивает у пользователя необходимое действие и аргументы. Затем
// вызывает указанную функцию и выводит результат. После этого снова
//запрашивает действие.

 #include <stdio.h>
 #include "calculator.h"
 #include "ui.h"

double multiply(double a, double b){
    return  a * b;
 }

double devide(double a, double b){
    return a / b;
 }

double substract(double a, double b){
    return a - b;
}

double add(double a, double b){
    return a + b;
}