#include <stdio.h>
#include <string.h>

struct SinhVien {
    char ten[50];
    int maSo;
    float diem;
};

struct SinhVien danhSachSinhVien[100]; // Array to store information of 100 students
int soLuongSinhVien = 0; // Variable to keep track of the number of students

struct SinhVien nhapSinhVien() {
    struct SinhVien sv;
    printf("\nNhap ten sinh vien: ");
    fflush(stdin);
    gets(sv.ten);
    printf("Nhap ma so sinh vien: ");
    scanf("%d", &sv.maSo);
    printf("Nhap diem sinh vien: ");
    scanf("%f", &sv.diem);
    return sv;
}

void hienThiThongTin(struct SinhVien sv) {
    printf("\nThong tin sinh vien:\n");
    printf("Ten: %s\n", sv.ten);
    printf("Ma so: %d\n", sv.maSo);
    printf("Diem: %f\n", sv.diem);
}

void sapXepTheoTen() {
    struct SinhVien temp;
    for (int i = 0; i < soLuongSinhVien - 1; i++) {
        for (int j = i + 1; j < soLuongSinhVien; j++) {
            if (strcmp(danhSachSinhVien[i].ten, danhSachSinhVien[j].ten) > 0) {
                temp = danhSachSinhVien[i];
                danhSachSinhVien[i] = danhSachSinhVien[j];
                danhSachSinhVien[j] = temp;
            }
        }
    }
}

void sapXepTheoDiem() {
    struct SinhVien temp;
    for (int i = 0; i < soLuongSinhVien - 1; i++) {
        for (int j = i + 1; j < soLuongSinhVien; j++) {
            if (danhSachSinhVien[i].diem > danhSachSinhVien[j].diem) {
                temp = danhSachSinhVien[i];
                danhSachSinhVien[i] = danhSachSinhVien[j];
                danhSachSinhVien[j] = temp;
            }
        }
    }
}

void sapXepTheoMaSo() {
    struct SinhVien temp;
    for (int i = 0; i < soLuongSinhVien - 1; i++) {
        for (int j = i + 1; j < soLuongSinhVien; j++) {
            if (danhSachSinhVien[i].maSo > danhSachSinhVien[j].maSo) {
                temp = danhSachSinhVien[i];
                danhSachSinhVien[i] = danhSachSinhVien[j];
                danhSachSinhVien[j] = temp;
            }
        }
    }
}

int main() {
    int luaChon;
    do {
        printf("\nChon yeu cau:\n");
        printf("1. Nhap thong tin sinh vien\n");
        printf("2. Hien thi thong tin sinh vien\n");
        printf("3. Sap xep theo ten\n");
        printf("4. Sap xep theo diem\n");
        printf("5. Sap xep theo ma so\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                if (soLuongSinhVien < 100) { // Check if the array is not full
                    danhSachSinhVien[soLuongSinhVien] = nhapSinhVien();
                    soLuongSinhVien++;
                } else {
                    printf("Danh sach sinh vien da day. Khong the them sinh vien moi.\n");
                }
                break;
            case 2:
                printf("\nDanh sach sinh vien:\n");
                for (int i = 0; i < soLuongSinhVien; i++) {
                    hienThiThongTin(danhSachSinhVien[i]);
                }
                break;
            case 3:
                sapXepTheoTen();
                printf("Da sap xep danh sach theo ten.\n");
                break;
            case 4:
                sapXepTheoDiem();
                printf("Da sap xep danh sach theo diem.\n");
                break;
            case 5:
                sapXepTheoMaSo();
                printf("Da sap xep danh sach theo ma so.\n");
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le, vui long chon lai.\n");
        }
    } while (luaChon != 0);

    return 0;
}

