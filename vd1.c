#include<stdio.h>
#include<string.h>
// Tạo file Songuyen.dat ghi 100 số lẻ đầu tiên.
int main()
{
    FILE * f = fopen("SoNguyen.dat", "wb");

    int i,n;
    for(i=0; i<100; i++)
    {
        n = 2*i + 1;
        fwrite(&n, sizeof(int), 1, f);
    }
    fclose(f);
    return 0;


}