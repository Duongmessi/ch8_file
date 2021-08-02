/*Nhập từ bàn phím danh sách hàng hóa, mỗi hàng hóa gồm tên hàng, số lượng,
 đơn giá.
Dữ liệu nhập được ghi vào file HangHoa.dat.  
Kết thúc nhập khi gặp một hàng hóa có tên là « *** »
Đọc từ file HangHoa.Dat, đưa ra màn hình danh sách các hàng hóa 
theo quy cách */

#include<stdio.h>
#include<string.h>

typedef struct{
    char name[30];
    int soLuong;
    float donGia;
}HANGHOA;

int main()
{
    HANGHOA hang;
    FILE *f;
    int i = 0, count = 0;
    float tien, k;
    f = fopen("HangHoa.dat", "wt");
    while(1)
    {
        printf("\nNhap vao hang hoa thu %d.", i+1);
        printf("\nNhap ten: ");
        fflush(stdin);
        gets(hang.name);
        if(strcmp(hang.name, "***") == 0) break;
        hang.name[strlen(hang.name)-1 ] = '\0';

        printf("\nNhap so luong: ");
        scanf("%d", &hang.soLuong);

        printf("\nNhap don gia: ");
        scanf("%f", &hang.donGia );

        fwrite(&hang, sizeof(HANGHOA), 1, f);

        i++;
        count++;
    }
    fclose(f);

    printf("%s %5s %10s %15s %20s", "STT", "Ten Hang","So Luong","Don Gia","Thanh Tien");
    f = fopen("HangHoa.dat", "rb");
    i=0;
    while (fread(&hang, sizeof(HANGHOA), 1, f) > 0)
    {
        printf("\n%-1d  %-10s %-20d %-12.2f %15.2f", i++, hang.name, hang.soLuong, hang.donGia, hang.soLuong*hang.donGia);
        tien = tien + hang.soLuong*hang.donGia;
        k += hang.soLuong;
        
    }
    printf("\n%-s %-15s %-20s ", "Tong ket", "Tong So Hang", "Tong So Tien");
    printf("\n%-1s %-15.2f %-25.2f","Tong Ket: ", k, tien);

    fclose(f);

}