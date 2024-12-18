#include <stdio.h>
#include <stdlib.h>

void inputElement(int* arr, int n);
void printArray(int *arr, int n);
int lengthArray(int *arr, int n);
int sumArray(int *arr, int n);
int maxElement(int *arr, int n);
void Menu();

int main() {
    int choice, n = 0;
    int *arr= NULL;
    do {
        Menu();
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Nhap so phan tu: ");
                scanf("%d", &n);
                arr = (int *)malloc(n * sizeof(int));
                inputElement(arr, n);
                break;
            case 2:
                printArray(arr, n);
                break;
            case 3:
                printf("Do dai mang: %d\n", lengthArray(arr, n));
                break;
            case 4:
                printf("Tong cac phan tu trong mang: %d\n", sumArray(arr, n));
                break;
            case 5:
                printf("Phan tu lon nhat trong mang: %d\n", maxElement(arr, n));
                break;
            case 6:
                if (arr!=NULL) {
                    free(arr);
                }
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le. Thu lai!\n");
        }
    } while (choice!=6);

    return 0;
}

void inputElement(int* arr, int n){
	int i;
    for(i=0; i<n; i++) {
        printf("Nhap arr[%d]: ", i+1);
        scanf("%d", &arr[i]);
    }
}

void printArray(int *arr, int n) {
    printf("Cac phan tu trong mang: ");
    int i;
    for(i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int lengthArray(int *arr, int n) {
    return n;
}

int sumArray(int *arr, int n) {
    int sum=0;
    int i;
    for(i=0; i<n; i++) {
        sum+=arr[i];
    }
    return sum;
}

int maxElement(int *arr, int n) {
    int max=arr[0];
    int i;
    for(i=1; i<n; i++) {
        if(arr[i]>max) {
            max=arr[i];
        }
    }
    return max;
}

void Menu() {
    printf("\nMENU\n");
    printf("1. Nhap vao so phan tu va tung phan tu\n");
    printf("2. Hien thi cac phan tu trong mang\n");
    printf("3. Tinh do dai mang\n");
    printf("4. Tinh tong cac phan tu trong mang\n");
    printf("5. Hien thi phan tu lon nhat\n");
    printf("6. Thoat\n");
}
