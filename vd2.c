#include<stdio.h>

int main()
{
    FILE * f = fopen("SoNguyen.dat", "rb");
    int n, i;
    
    fseek(f, 50*sizeof(int), SEEK_SET);
    while(! feof(f))
    {
        fread(&n, sizeof(int), 1, f);
        printf("%4d", n);
    }
    fclose(f);
    return 0;


}