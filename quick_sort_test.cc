
#include <insert_sort.h>
#include <quick_sort.h>
#include <quick_sort_test.h>

int main() {
    #define MAX_N 100000
    int *arr = getRandData(MAX_N);
    TEST(quick_sort_v1, arr, MAX_N);
    TEST(quick_sort_v2, arr, MAX_N);
    TEST(quick_sort_v3, arr, MAX_N);

    TEST(insert_sort, arr, MAX_N);
    TEST(unguarded_insert_sort, arr, MAX_N);

    free(arr);
    #undef MAX_N
    return 0;
}
