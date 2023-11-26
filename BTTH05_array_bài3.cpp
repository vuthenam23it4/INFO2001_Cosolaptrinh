#include <stdio.h>
#include <string.h>

struct SinhVien {
    char ten[50];
    int maSo;
    float diem;
};

struct SinhVien danhSachSinhVien[100];
int soLuongSinhVien = 0;

struct SinhVien nhapSinhVien() {
    struct SinhVien sv;
    printf("\nNhap ten sinh vien: ");
    fflush(stdin);
    fgets(sv.ten, sizeof(sv.ten), stdin);
    printf("Nhap ma so sinh vien: ");
    scanf("%d", &sv.maSo);
    printf("Nhap diem sinh vien: ");
    scanf("%f", &sv.diem);
    return sv;
}

void hienThiThongTin(struct SinhVien sv) {
    printf("\nThong tin sinh vien:\n");
    printf("Ten: %s", sv.ten);
    printf("Ma so: %d\n", sv.maSo);
    printf("Diem: %f\n", sv.diem);
}

int main() {
    int i, total = 0;
    int size = soLuongSinhVien; // Sửa thành số lượng sinh viên hiện tại

    printf("Nhap so luong sinh vien: ");
    scanf("%d", &soLuongSinhVien);

    // Nhập thông tin sinh viên
    for (i = 0; i < soLuongSinhVien; i++) {
        danhSachSinhVien[i] = nhapSinhVien();
    }

    // Hiển thị thông tin sinh viên
    for (i = 0; i < soLuongSinhVien; i++) {
        hienThiThongTin(danhSachSinhVien[i]);
    }

    // Tính điểm trung bình của lớp
    for (i = 0; i < soLuongSinhVien; i++) {
        total += danhSachSinhVien[i].diem;
    }

    printf("\nDiem trung binh cua lop la: %f", (float)total / soLuongSinhVien);

    return 0;
}
