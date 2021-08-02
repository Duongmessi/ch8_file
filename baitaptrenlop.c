/*
Bài 1. Thao tác với tệp văn bản
Nhập thông tin điểm thi giữa kỳ và cuối kỳ của môn Tin học đại cương của 2 sinh
viên từ bàn phím, biết điểm thi có giá trị từ 0 đến 10.

Ghi các điểm này vào tệp văn bản có tên “my_score.txt”.

Đọc từ tệp trên, tính điểm theo thang chữ của từng sinh viên 
(biết điểm thi giữa kỳ hệ số 0.3 và điểm thi cuối kỳ hệ số 0.7) 
và in kết quả ra màn hình theo định dạng: GK CK Final Mark. */
#include<stdio.h>
#include <string.h>

int main()
{
    float giuaKy1, cuoiKy1, final1;
    float giuaKy2, cuoiKy2, final2;
    FILE *f;
    
    int i, count;

    printf("\nNhap diem thi cho sinh vien thu 1. ");   
    printf("\nNhap diem giua ky, cuoi ky tu 0 den 10:\n ");
    scanf("%f%f", &giuaKy1, &cuoiKy1);
    while(giuaKy1 > 10 || giuaKy1 < 0 || cuoiKy1 > 10 || cuoiKy1 < 0)
    {
        scanf("%f %f", &giuaKy1, &cuoiKy1);
    }
    printf("\n");
    printf("\nNhap diem thi cho sinh vien thu 2. ");   
    printf("\nNhap diem giua ky, cuoi ky tu 0 den 10:\n ");
    scanf("%f%f", &giuaKy2, &cuoiKy2);
    while(giuaKy2 > 10 || giuaKy2 < 0 || cuoiKy2 > 10 || cuoiKy2 < 0)
    {
        scanf("%f %f", &giuaKy2, &cuoiKy2);
    }
    f = fopen("my_score.txt", "w");
    fprintf(f, "%f %f", giuaKy1, cuoiKy1);
    fprintf(f, "\n%f %f", giuaKy2, cuoiKy2);
    fclose(f);

    giuaKy1 = 0; cuoiKy1 = 0; giuaKy2 = 0; cuoiKy2 = 0;

    f = fopen("my_score.txt", "r");
    //fseek(f, 4, SEEK_CUR);
    fscanf(f, "%f %f %f %f", &giuaKy1, &cuoiKy1, &giuaKy2, &cuoiKy2);
    fclose(f);

    //tinhdiem
    final1 = giuaKy1 * 0.3 + cuoiKy1 * 0.7;
    final2 = giuaKy2 * 0.3 + cuoiKy2 * 0.7;
    printf("\n%s %5s %20s", "GK", "CK", "Final Mark");
    printf("\n%.2f %5.2f %15.2f", giuaKy1, cuoiKy1, final1);
    printf("\n%.2f %5.2f %15.2f", giuaKy2, cuoiKy2, final2);


}