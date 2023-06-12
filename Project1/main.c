#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Menu() {
    printf("\n1. Keo");
    printf("\n2. Bua");
    printf("\n3. Bao");
}

void LuaChon(int x) {
    if (x == 1) {
        printf("Keo");
    }
    else if (x == 2) {
        printf("Bua");
    }
    else {
        printf("Bao");
    }
}

int main() {
    int LuotChoi = 0; // 0: Nguoi choi, 1: May tinh
    int NguoiChoi, MayTinh;
    int TiepTucChoi = 1;
    srand(time(0));
    while (TiepTucChoi != 0) {
        if (LuotChoi == 0) {
            Menu();
            do {
                printf("\nMoi ban nhap lua chon: ");
                scanf_s("%d", &NguoiChoi);
                if (NguoiChoi < 1 || NguoiChoi > 3) {
                    printf("\nLua chon chi trong doan 1 --> 3. Xin nhap lai!");
                }
            } while (NguoiChoi < 1 || NguoiChoi > 3);
            printf("\nNguoi choi chon: ");
            LuaChon(NguoiChoi);
            LuotChoi = 1;
        }
        else {
            MayTinh = 1 + rand() % 3;
            printf("\nMay tinh ra: ");
            LuaChon(MayTinh);
            printf("\nKet qua: ");
            if (MayTinh == 1) {
                if (NguoiChoi == 1) {
                    printf("Hoa nhau");
                }
                else if (NguoiChoi == 2) {
                    printf("Nguoi choi thang");
                }
                else {
                    printf("May tinh thang");
                }
            }
            else if (MayTinh == 2) {
                if (NguoiChoi == 1) {
                    printf("May tinh thang");
                }
                else if (NguoiChoi == 2) {
                    printf("Hoa nhau");
                }
                else {
                    printf("Nguoi choi thang");
                }
            }
            else {
                if (NguoiChoi == 1) {
                    printf("Nguoi choi thang");
                }
                else if (NguoiChoi == 2) {
                    printf("May tinh thang");
                }
                else {
                    printf("Hoa nhau");
                }
            }

            if (NguoiChoi == MayTinh) {
                LuotChoi = 0;
            }
            else {
                TiepTucChoi = 0;
            }
        }
    }
    return 0;
}
