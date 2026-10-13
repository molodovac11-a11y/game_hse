#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#ifdef _WIN32
    #include <windows.h>
#endif

char field[20][20];
int rows, cols;

int winH, winV, winD;

int botRow, botCol;


void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}


void setupConsole() {
#ifdef _WIN32
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
#else
    
#endif
}


void pauseConsole() {
#ifdef _WIN32
    system("pause");
#else
    printf("\nНажмите Enter для выхода...");
    while (getchar() != '\n');
    getchar();
#endif
}

int getNumber(const char* text, int min, int max) {
    int number;
    while (1) {
        printf("%s", text);
        if (scanf("%d", &number) == 1 && number >= min && number <= max) {
            while (getchar() != '\n'); // очистка буфера
            return number;
        }
        while (getchar() != '\n');
        printf("Ошибка! Введите число от %d до %d.\n", min, max);
    }
}

void drawField() {
    printf("\n    ");
    for (int j = 0; j < cols; j++) {
        printf("%2d ", j + 1);
    }
    printf("\n");

    for (int i = 0; i < rows; i++) {
        printf("%2d  ", i + 1);
        for (int j = 0; j < cols; j++) {
            printf(" %c ", field[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int checkWin(char p) {
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <= cols - winH; j++) {
            int count = 0;
            for (int k = 0; k < winH; k++) {
                if (field[i][j + k] == p) count++;
            }
            if (count == winH) return 1;
        }
    }

    
    for (int i = 0; i <= rows - winV; i++) {
        for (int j = 0; j < cols; j++) {
            int count = 0;
            for (int k = 0; k < winV; k++) {
                if (field[i + k][j] == p) count++;
            }
            if (count == winV) return 1;
        }
    }

    
    for (int i = 0; i <= rows - winD; i++) {
        for (int j = 0; j <= cols - winD; j++) {
            int count = 0;
            for (int k = 0; k < winD; k++) {
                if (field[i + k][j + k] == p) count++;
            }
            if (count == winD) return 1;
        }
    }

    
    for (int i = 0; i <= rows - winD; i++) {
        for (int j = winD - 1; j < cols; j++) {
            int count = 0;
            for (int k = 0; k < winD; k++) {
                if (field[i + k][j - k] == p) count++;
            }
            if (count == winD) return 1;
        }
    }

    return 0;
}

int isFull() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (field[i][j] == '.') return 0;
        }
    }
    return 1;
}

void botMove(char p) {
    while (1) {
        int r = rand() % rows;
        int c = rand() % cols;
        if (field[r][c] == '.') {
            field[r][c] = p;
            botRow = r;
            botCol = c;
            break;
        }
    }
}

