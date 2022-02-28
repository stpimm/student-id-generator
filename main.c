#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

struct Data
{
    long long int id;
    char nama[101];
    int age;
};

struct Data mhs[101];
void CreateStruct();
int Power();
int getFirst3Digits();
void CreateId();
void ShowData();
void InputData();

int main()
{
menu:
    system("cls");
    puts("Student ID Generator");
    puts("1. Generate ID");
    puts("2. Show Data");
    puts("3. End Program");
    puts("\nInput any number to continue");
	printf(">> ");

    int choice = 0;
    scanf("%d", &choice);
    
    switch (choice)
    {
    case(1):
        system("cls");
        InputData();
        system("cls");
        ShowData();
        puts("\nPress Enter To Continue");
        getchar();
        goto menu;
        break;

    case(2):
        system("cls");
        ShowData();
        char back[1];
        puts("\nPress Enter To Continue");getchar();
        getchar();
        goto menu;
        break;
        
    case(3):
    	system("cls");
    	break;
    }

    puts("Thankyou, see you next time");
    
    return 0;
}

void CreateStruct(int N, char nama[], int age)
{
    strcpy(mhs[N].nama, nama);
    mhs[N].age = age;
}

int Power(long long int base, long long int a)
{
    if (a != 0)
        return (base * Power(base, a - 1));
    else
        return 1;
}

int getFirst4Digits(long long input)
{
    long long local = input;

    while (local >= 10000)
    {
        local /= 10;
    }

    return local;
}

void CreateId(int N)
{
    for (int i = 0; i < N; i++)
    {
        long long int id = 0, firstCh = 0, secondCh = 0, thirdCh = 0;
        char nama[101];
        strcpy(nama, mhs[i].nama);
        firstCh = nama[0] - 96;
        secondCh = nama[1] - 96;
        thirdCh = nama[2] - 96;

        if (firstCh >= 10)
        {
            firstCh = firstCh % 10 + 2;
        }

        if (secondCh >= 10)
        {
            secondCh = secondCh % 10 + 2;
        }

        if (secondCh < 4)
        {
            secondCh = secondCh + 4;
        }

        id = 5 * Power(firstCh, secondCh);
        id = getFirst4Digits(abs(id));
        mhs[i].id = id;
    }
}

void ShowData()
{
    system("cls");
    FILE *fp = fopen("data.txt", "r");
    struct Data dummy;
    int N = 0;
    while (fscanf(fp, "%[^|]|%d\n", dummy.nama, &dummy.age) != EOF)
    {
        CreateStruct(N, dummy.nama, dummy.age);
        N++;
    }
    CreateId(N);
    printf("Nama                    Umur\t   ID\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d: %-22s%d\t2022%lld\n", i + 1, mhs[i].nama, mhs[i].age, mhs[i].id);
    }

    fclose(fp);
}

void InputData()
{
    FILE *fp = fopen("data.txt", "a");
    char inputData[BUFFER_SIZE];
    fflush(stdin);
    puts("Masukkan Nama dan umur, dengan format NAMA|UMUR");
    printf(">> ");
    fgets(inputData, BUFFER_SIZE, stdin);
    fputs(inputData, fp);

    fclose(fp);
}
