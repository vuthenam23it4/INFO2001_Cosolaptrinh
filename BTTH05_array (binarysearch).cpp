#include <stdio.h>

int binarySearch(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

       
        if (arr[mid] == x)
            return mid;

        
        if (arr[mid] < x)
            left = mid + 1;

       
        else
            right = mid - 1;
    }

    
    return -1;
}

int main() {
    int arr[] = {26, 12, 20, 45, 79};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;

    printf("Nhap so can tim: ");
    scanf("%d", &x);

    int result = binarySearch(arr, 0, n - 1, x);

    if (result == -1)
        printf("Khong tim thay %d trong mang.\n", x);
    else
        printf("Tim thay %d tai vi tri %d trong mang.\n", x, result);

    return 0;
}
