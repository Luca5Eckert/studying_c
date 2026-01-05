
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *itens;
    size_t size;
    size_t capacity;
} Numbers;

void add(Numbers *nums, int num) {
    do {
        if (nums->size >= nums->capacity) {
            nums->capacity *= 2;

            int *temp = realloc(nums->itens, nums->capacity * sizeof(int));

            if (!temp) {
                printf("Erro ao alocar mémoria: Não foi possível alocar mémoria para a lista");
                return;
            }

            nums->itens = temp;
        }

        nums->itens[nums->size] = num;
        nums->size++;

    } while (0);
}


