#include<stdio.h>

struct Date
{
    int day;
    int month;
    int year;
};

// Initialize Date
void initDate(struct Date* ptrDate)
{
    ptrDate->day = 1;
    ptrDate->month = 1;
    ptrDate->year = 2000;
}

// Accept Date from user
void acceptDateFromConsole(struct Date* ptrDate)
{
    printf("Enter Day: ");
    scanf("%d",&ptrDate->day);

    printf("Enter Month: ");
    scanf("%d",&ptrDate->month);

    printf("Enter Year: ");
    scanf("%d",&ptrDate->year);
}

// Print Date
void printDateOnConsole(struct Date* ptrDate)
{
    printf("Date: %d/%d/%d\n", ptrDate->day, ptrDate->month, ptrDate->year);
}

int main()
{
    struct Date d1;
    int choice;

    do
    {
        printf("\n----- Date Menu -----\n");
        printf("1. Initialize Date\n");
        printf("2. Accept Date\n");
        printf("3. Print Date\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                initDate(&d1);
                printf("Date initialized.\n");
                break;

            case 2:
                acceptDateFromConsole(&d1);
                break;

            case 3:
                printDateOnConsole(&d1);
                break;

            case 0:
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    }while(choice != 0);

    return 0;
}