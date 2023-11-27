#include<stdio.h>

int linearSearch(int a[], int n);

int main() {
    int a[10];
    int n;

    for (int i = 0; i < 10; i++) {
        printf("nhap phan tu thu %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    printf("nhap phan tu can tim: ");
    scanf("%d", &n);

    if (linearSearch(a, n)) {
        printf("Phan tu co trong mang\n");
    } else {
        printf("Phan tu khong co trong mang\n");
    }

    return 0;
}

int linearSearch(int a[], int n) {
    for (int i = 0; i < 10; i++) {
        if (a[i] == n) {
            return 1; // Phan tu co trong mang
        }
    }
    return 0; // Phan tu khong co trong mang
}
