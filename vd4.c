#include<stdio.h>
#include<string.h>

typedef struct {
    char name[30];
    int sbd;
    char khoaDuThi[50];
    int diemThi;
} THISINH;

int main()
{
    THISINH thisinh;
    int i=0, n=0, count=0;
    FILE * f1, *f2; 
    f1 = fopen("Thi_Sinh.dat", "wb");  //. Dữ liệu nhập được ghi vào file ThiSinh.dat
    while(1)
    {
        printf("\nThi sinh thu %d: ", i+1);
        printf("\nNhap vao ho ten: ");
        fflush(stdin);
        gets(thisinh.name);
        thisinh.name[strlen(thisinh.name)-1 ] = '\0'; // bo ky tu xuong dong

        if(strcmp(thisinh.name, "***") == 0) break;
        

        printf("\nNhap vao so bao danh: ");
        scanf("%d", &thisinh.sbd);

        printf("\nKhoa du thi: ");
        fflush(stdin);
        gets(thisinh.khoaDuThi);
        thisinh.khoaDuThi[strlen(thisinh.khoaDuThi)-1 ] = '\0'; // bo ky tu xuong dong

        printf("\nDiem Thi: ");
        scanf("%d", &thisinh.diemThi);
        fwrite(&thisinh, sizeof(THISINH), 1, f1);

        i++;
        count++;
    }
    fclose(f1);

    printf("\n%s. %5s  %12s  %30s ", "STT", "So Bao Danh", "Ho Ten", "Diem Thi");
    f1 = fopen("Thi_Sinh.dat", "rb");  // Mo tep nhi phan chi de read.
    while(! feof(f1))
    {
        for ( i = 0; i < count; i++)
        {
            fread(&thisnh.khoaDuThi, sizeof(THISINH), 1, f1);
            if(strcmp(thisnh.khoaDuThi, "CNTT") == 0)
            {
                fread(&thisinh.diemThi, sizeof(THISINH), 1, f1);
                if(thisinh.diemThi > 21 )
                {
                    printf("\n%d. %5d  %12s  %30d ", n+1, thisinh.sbd, thisinh.name, thisinh.diemThi);
                }
            }
        }
        
    }
    fclose(f1);







}