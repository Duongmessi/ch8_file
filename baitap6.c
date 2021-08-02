#include<stdio.h>
#include<string.h>
#include<ctype.h>

typedef struct {
    char tenhang[30];
    int soluong;
    double donGia;
}HANGHOA;

int main()
{
    int i=1, count=0;
    HANGHOA hanghoa;
    FILE * f1;
    f1 = fopen("hanghoa6.dat", "wb");

    while(1){
        printf("\nNhap vao ten hang: ");
        fflush(stdin);
        gets(hanghoa.tenhang);
        if( strcmp(hanghoa.tenhang, "***") == 0 ) break;

        printf("\nNhap vao so luong: ");
        scanf("%d", &hanghoa.soluong);

        printf("\nNhap vao don gia: ");
        scanf("%lf", &hanghoa.donGia);

        fwrite(&hanghoa, sizeof(HANGHOA), 1, f1);
        count ++;
    }
    fclose(f1);

    printf("\n%s %-4s %-10s %-20s %-40s","STT", "Ten Hang","So Luong", "Don Gia", "Thanh Tien");

    f1 = fopen("hanghoa6.dat", "rb");
    while(fread(&hanghoa, sizeof(HANGHOA), 1, f1) >0){
        
        printf("\n%d %-4s %-10d %-20.2f %-40.2f", i++, hanghoa.tenhang, hanghoa.soluong, hanghoa.donGia, hanghoa.donGia*hanghoa.soluong );
    }



}