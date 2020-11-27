#include <string>
#include <stdlib.h>
#include <time.h>

#define TEST(func, arr, n) __TEST(func, arr, n, #func);

int check(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i-1]) return 0;
    }
    return 1;
}

void __TEST(
        void (*func)(int *, int, int),
        int *arr, int n,
        const char *func_name) {

    int *temp = (int *)malloc(sizeof(int) * n);
    memcpy(temp, arr, sizeof(int) * n);
    long long b = clock();
    func(temp, 0, n - 1);
    long long e = clock();

    if (check(temp, n)) {
        printf("[  OK    ] %s\t", func_name);
    } else {
        printf("[FAILED  ] %s\t", func_name);
    }
    printf("%lld ms\n", 1000 * (e-b) / CLOCKS_PER_SEC);
    free(temp);
    return;
}


int *getRandData(int n) {
    srand(time(0));
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n;
    }
    return arr;
}