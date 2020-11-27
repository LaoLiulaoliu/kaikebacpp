
#include <quick_sort.h>
#include <quick_sort_test.h>

int main() {
    #define MAX_N 10000000
    int *arr = getRandData(MAX_N);
    TEST(quick_sort_v1, arr, MAX_N);
    #undef MAX_N
    return 0;
}
