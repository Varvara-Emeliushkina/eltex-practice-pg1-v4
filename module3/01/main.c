#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // для процессов
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>

// целое или вещественное ?
int is_number(const char *str) {
    char *endptr;
    strtod(str, &endptr);
    return *endptr == '\0';
}

// обработкa аргументов
void process_args(int start, int end, char *argv[]) {
    for (int i = start; i < end; i++) {
        if (is_number(argv[i])) {
            double num = atof(argv[i]);
            printf("    PID %d:     %s %.2f\n", getpid(), argv[i], num * 2);
        } else {
            printf("    PID %d:     %s\n", getpid(), argv[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Использование: %s <arg1> <arg2> ... <argN>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int total_args = argc - 1;
    int mid = total_args / 2;

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
 
    // сложно предсказать вывод тк гонка 
    if (pid == 0) {
        // дочерний процесс обрабатывает первую половину аргументов
        printf("\n Child process (PID %d):\n", getpid());
        process_args(1, 1 + mid, argv); 
        _exit(EXIT_SUCCESS);
    } else {
        // родительский процесс вторую 
        wait(NULL); //можно ждать ребенка до своей работы (тогда всегда будет сначала выводиться ребенок)
        printf("\n Parent process (PID %d):\n", getpid());
        process_args(1 + mid, argc, argv);
        exit(EXIT_SUCCESS);
        // wait(NULL); // ждем завершения дочернего - здесь при разных запусках увидим разное
    } 
    return 0;
}