#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MENU();
void inputString(char str[], int length);
void printString(char *str);
void countCharacters(char *str, int *letters, int *digits, int *specials);

int main() {
    char str[100];
    str[0] = '\0';
    int choice;
    do {
        MENU();
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                inputString(str, sizeof(str));
                break;
            case 2:
                printString(str);
                break;
            case 3: {
                int letters = 0, digits = 0, specials = 0;
                countCharacters(str, &letters, &digits, &specials);
                printf("So luong chu cai: %d\n", letters);
                break;
            }
            case 4: {
                int letters = 0, digits = 0, specials = 0;
                countCharacters(str, &letters, &digits, &specials);
                printf("So luong chu so: %d\n", digits);
                break;
            }
            case 5: {
                int letters = 0, digits = 0, specials = 0;
                countCharacters(str, &letters, &digits, &specials);
                printf("So luong ky tu dac biet: %d\n", specials);
                break;
            }
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Thu lai!\n");
        }

    } while (choice != 6);

    return 0;
}

void MENU() {
		printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai trong chuoi\n");
        printf("4. Dem so luong chu so trong chuoi\n");
        printf("5. Dem so luong ky tu dac biet trong chuoi\n");
        printf("6. Thoat\n");
}

void inputString(char str[], int length) {
    printf("Nhap mot chuoi ky tu bat ky: ");
    fgets(str, length, stdin);
    str[strcspn(str, "\n")] = 0;
}

void printString(char *str) {
    if (str[0] == '\0') {
        printf("Chuoi chua duoc nhap!\n");
    } else {
        printf("Chuoi vua nhap: %s\n", str);
    }
}

void countCharacters(char *str, int *letters, int *digits, int *specials) {
    *letters = 0;
    *digits = 0;
    *specials = 0;

    if (str[0] == '\0') {
        printf("Chuoi chua duoc nhap!\n");
        return;
    }

    while (*str) {
        if ((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z')) {
            (*letters)++;
        } else if (*str >= '0' && *str <= '9') {
            (*digits)++;
        } else if (*str != ' ' && *str != '\t' && *str != '\n') {
            (*specials)++;
        }
        str++;
    }
}

