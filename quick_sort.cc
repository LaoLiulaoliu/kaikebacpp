#define swap(a, b) { \
    __typeof(a) __c = a; \
    a = b; \
    b = __c; \
}


void quick_sort_v1(int *arr, int l, int r) {
    if (l >= r) return;
    int x = l, y = r, z = arr[l];
    while (x < y) {
        while (x < y && arr[y] >= z) --y;
        if (x < y) arr[x++] = arr[y];
        while (x < y && arr[x] <= z) ++x;
        if (x < y) arr[y--] = arr[x];
    }
    arr[x] = z;
    quick_sort_v1(arr, l, x-1);
    quick_sort_v1(arr, x+1, r);
    return;
}

// 单边递归
void quick_sort_v2(int *arr, int l, int r) {
    while (l < r) {
        int x = l, y = r, z = arr[l];
        while (x < y) {
            while (x < y && arr[y] >= z) --y;
            if (x < y) arr[x++] = arr[y];
            while (x < y && arr[x] <= z) ++x;
            if (x < y) arr[y--] = arr[x];
        }
        arr[x] = z;
        quick_sort_v2(arr, l, x-1);
        l = x + 1;
    }
    return ;
}


//无监督快速排序优化
void quick_sort_v3(int *arr, int l, int r) {
    while (l < r) {
        int x = l, y = r, z = arr[l];
        do {
            while (arr[x] < z) ++x;
            while (arr[y] > z) --y;
            if (x <= y) {
                swap(arr[x], arr[y]);
                ++x; --y;
            }
        } while (x <= y);

        quick_sort_v3(arr, l, y);
        l = x;
    }
    return ;
}
