#include <stdio.h>
#include <time.h>

int leap_year(int year)
{
    if (year % 400 == 0)
    {
        return 1;
    }
    else if (year % 100 == 0)
    {
        return 0;
    }
    else if (year % 4 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main_day_date()
{
    int day, month, year;

    printf("Enter day (1-31): ");
    scanf("%d", &day);
    printf("Enter month (1-12): ");
    scanf("%d", &month);
    printf("Enter year: ");
    scanf("%d", &year);

    struct tm date = {0};
    date.tm_mday = day;
    date.tm_mon = month - 1;
    date.tm_year = year - 1900;

    if (day>31)
    {
        printf("This Date Doen't even Exist \n");
        return 0;
    }
    else if(month>12){
        printf("What the hell bro there are only 12 month in a year\n");
        return 0;
    }
    else if (month == 2 && day==29)
    {
        if (!leap_year(year))
        {
            printf("this is not a leap year \n");
            return 0;
        }
    }
    else if (month == 2 && day==30)
    {
        printf("Are You Serious bro! \n");
        return 0;
    }
    else if (month == 2 || month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30)
        {
            printf("this date doesn't exist in this month \n");
            return 0;
        }
    }
    else if(day>31 || day<1){
        printf("there is no such a date in calander \n");
        return 0;
    }
    else if(day<1 ||month<1||year<1){
        printf("Nice try but i checked that you are dumb \n");
        printf("In which universe this date exist\n");
        return 0;
    }

    mktime(&date);
    const char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    printf("The day on %02d-%02d-%04d : %s\n", day, month, year, days[date.tm_wday]);

    return 0;
}