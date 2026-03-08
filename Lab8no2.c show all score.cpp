#include <stdio.h>

int checkscore(char std[]);  // 2.1

int main() {
    int i;
    char ans[8][10] = {
        {'A','B','A','C','C','D','E','E','A','D'}, // 7
        {'D','B','A','B','C','A','E','E','A','D'}, // 6
        {'E','D','D','A','C','B','E','E','A','D'}, // 5
        {'C','B','A','E','D','C','E','E','A','D'}, // 4
        {'A','B','D','C','C','D','E','E','A','D'}, // 8
        {'B','B','E','C','C','D','E','E','A','D'}, // 7
        {'B','B','A','C','C','D','E','E','A','D'}, // 7
        {'E','B','E','C','C','D','E','E','A','D'}  // 7
    };
    char keys[10] = {'D','B','D','C','C','D','A','E','A','D'};
    
    for(i = 0; i < 8; i++) {
        printf("std %d => %d\n", (i+1), checkscore(ans[i]));
    }
    
    int count_q1_correct = 0;
    for(i = 0; i < 8; i++) {
        if(ans[i][0] == keys[0]) {
            count_q1_correct++;
        }
    }
    printf("Number of students who answered question 1 correctly: %d\n", count_q1_correct);
    
    int correct_count[10] = {0};
    
    for(int q = 0; q < 10; q++) {
        for(i = 0; i < 8; i++) {
            if(ans[i][q] == keys[q]) {
                correct_count[q]++;
            }
        }
    }
    
    int min_correct = 9;
    int hardest_question = 0;
    
    for(int q = 0; q < 10; q++) {
        if(correct_count[q] < min_correct) {
            min_correct = correct_count[q];
            hardest_question = q;
        }
    }
    printf("\nHardest question is Question %d (%d students correct)\n", 
           hardest_question+1, min_correct);
    
    return 0;
}

int checkscore(char std[]) {
    char keys[10] = {'D','B','D','C','C','D','A','E','A','D'};
    int score = 0;
    
    for(int i = 0; i < 10; i++) {
        if(std[i] == keys[i]) {
            score++;
        }
    }
    return score;

}
