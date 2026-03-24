// 2.3 (2 балла). Усовершенствовать программу-калькулятор: состав возможных
// команд определяется динамически, с использованием указателей на функции.

 #include <stdio.h>
 #include <math.h>
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

double power(double a, double b) {
    return pow(a, b);
}