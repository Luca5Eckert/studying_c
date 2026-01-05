
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *itens;
    size_t size;
    size_t capacity;
} Numbers;

int init(Numbers **nums_copy, size_t capacity) {
    Numbers *nums = malloc(sizeof(Numbers));
    if (!nums) {
        return -1;
    }

    nums->itens = malloc(sizeof(int) * capacity);
    if (!nums->itens) {
        free(nums);
        return -1;
    }

    nums->capacity = capacity;
    nums->size = 0;

    *nums_copy = nums;

    return 0;
}

void add(Numbers *nums, const int num) {
    do {
        if (nums->size >= nums->capacity) {
            nums->capacity *= 2;

            int *temp = realloc(nums->itens, nums->capacity * sizeof(int));

            if (!temp) {
                printf("Memory allocation failed\n");
                return;
            }

            nums->itens = temp;
        }

        nums->itens[nums->size] = num;
        nums->size++;

    } while (0);
}

int main() {
    Numbers *nums;

    const int result = init(&nums, 5);
    if (result != 0) {
        return -1;
    }

    add(nums, 1);

    for (int i = 0; i < nums->size; i++) {
        printf("%d\n", nums->itens[i]);
    }

    free(nums);
    free(nums->itens);

    return 0;
}



