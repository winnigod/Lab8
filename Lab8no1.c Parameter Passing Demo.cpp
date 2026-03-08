#include <stdio.h>

void addone(int number[], int add[], int sizeNum);
void addtwo(int number[], int pos[], int x, int sizeNum, int sizePos);
void addthree(int number[], int pos[][2], int sizePos);
void printAr(int myAr[], int size);

int main() {
    int number[5] = {10, 20, 30, 40, 50};
    int sizeNum = 5;
    
    printf("1.1\n");
    printAr(number, sizeNum);
    
    int add[5] = {2, 4, 6, 8, 10};
    addone(number, add, sizeNum);
    printAr(number, sizeNum);
    
    printf("1.2\n");
    int number2[5] = {10, 20, 30, 40, 50};
    printAr(number2, sizeNum);
    
    int pos[] = {0, 2, 4};
    int sizePos = 3;
    int x = 5;
    
    addtwo(number2, pos, x, sizeNum, sizePos);
    printAr(number2, sizeNum);
    
    printf("1.3\n");
    int number3[5] = {10, 20, 30, 40, 50};
    printAr(number3, sizeNum);
    
    int pos2[3][2] = {
        {0, 3},
        {2, 7},
        {4, 5}
    };
    int sizePos2 = 3;
    
    addthree(number3, pos2, sizePos2);
    printAr(number3, sizeNum);
    
    return 0;
}

void addone(int number[], int add[], int sizeNum) {
    for(int i = 0; i < sizeNum; i++) {
        number[i] += add[i];
    }
}

void addtwo(int number[], int pos[], int x, int sizeNum, int sizePos) {
    for(int i = 0; i < sizePos; i++) {
        int index = pos[i];
        if(index >= 0 && index < sizeNum) {
            number[index] += x;
        }
    }
}

void addthree(int number[], int pos[][2], int sizePos) {
    for(int i = 0; i < sizePos; i++) {
        int index = pos[i][0];
        int value = pos[i][1];
        number[index] += value;
    }
}

void printAr(int myAr[], int size) {
    printf("[");
    for(int i = 0; i < size; i++) {
        printf("%d", myAr[i]);
        if(i < size - 1) printf(", ");
    }
    printf("]\n");
}