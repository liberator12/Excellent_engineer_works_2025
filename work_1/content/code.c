#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

int main() {
    srand((unsigned int)time(NULL));
    const int count = 5; // 固定数量，避免除以零
    unsigned int nums[count];

    // 写入 input.txt 并终端打印
    FILE *input = fopen("input.txt", "w");
    if (!input) { perror("Write file error"); return 1; }
    for (int i = 0; i < count; i++) {
        nums[i] = rand() % (UINT32_MAX + 1);
        fprintf(input, "%u ", nums[i]);
        printf("%u ", nums[i]);
    }
    printf("\n");
    fclose(input);

    // 读取计算均值
    input = fopen("input.txt", "r");
    if (!input) { perror("Read file error"); return 1; }
    unsigned long long sum = 0;
    for (int i = 0; i < count; i++) {
        unsigned int num;
        fscanf(input, "%u", &num);
        sum += num;
    }
    fclose(input);
    float avg = (float)sum / count; // count 固定为5，无除零风险

    // 写入 output.txt 并终端打印
    FILE *output = fopen("output.txt", "w");
    if (!output) { perror("Write output error"); return 1; }
    fprintf(output, "%.2f\n", avg);
    printf("Average: %.2f\n", avg);
    fclose(output);

    return 0;
}