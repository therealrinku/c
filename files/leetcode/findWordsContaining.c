#include <stdio.h>
#include <string.h>

int* findWordsContaining(char** words, int wordsSize, char x, int* returnSize) {
    int* indices = malloc(wordsSize * sizeof(int));
    int count = 0;

    for(int i=0;i<wordsSize;i++){
        char *word = words[i];

        int curr = 0;
        while(word[curr] != '\0'){
            if(word[curr] == x){
                indices[count++] = i;
                break;
            }
            curr++;
        }
    }

    *returnSize = count;
    return indices;
}
