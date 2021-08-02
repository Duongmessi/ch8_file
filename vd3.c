/*
• Nhập vào từ bàn phím 100 số thực và ghi file nhị phân
SO_DUONG.DAT các số thực dương trong các số đã nhập
• Đọc từ file SO_DUONG.DAT và đưa ra màn hình số thực có
giá trị lớn nhất 
*/

#include <stdio.h>

int main()
{
    FILE *f = fopen("so_duong.dat", "wb");
    int i, soLuong;
    float n, max;
    printf("\nNhap vao so luong phan tu: "); scanf("%d",&soLuong);
    printf("\nNhap vao %d so thuc: \n", soLuong);
    for (i=0; i<soLuong; i++)
    {
        scanf("%f", &n);
        if(n > 0)
        {
            fwrite(&n, sizeof(float), 1, f);
        }
    }
    fclose(f);

    f = fopen("so_duong.dat", "rb");  
    max = 0;
    //fseek(f, sizeof(int), SEEK_SET);
    while(! feof(f))
    {
        fread(&n, 1*sizeof(float), 1, f);
        if (max < n)
        {
            max = n;
        }

    }
    fclose(f);
    printf("\nSo thuc co gia tri lon nhat la: %.3f", max);

}