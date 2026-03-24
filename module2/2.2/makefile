CC = gcc
CFLAGS = -Wall -Wextra -Werror -O2
OBJS = main.o ui.o calculator.o
TARGET = calculator.exe

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

main.o: main.c calculator.h ui.h
	$(CC) $(CFLAGS) -c main.c -o main.o

ui.o: ui.c ui.h calculator.h
	$(CC) $(CFLAGS) -c ui.c -o ui.o

calculator.o: calculator.c calculator.h ui.h
	$(CC) $(CFLAGS) -c calculator.c -o calculator.o

clean:
	del /Q $(OBJS) $(TARGET) 2>nul || exit 0

.PHONY: all clean