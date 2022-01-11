#include <stdio.h>
int initialweek(int year){
    return (year+year/4-year/100+year/400)%7;
}
int leapyear(int year){
    if(year%100){
        if(year%4) return 0;
        else return 1;             
    }
    else{
        if(year%400) return 0;
        else return 1;
    }    
}
void printmonth(int n){
    switch(n+1){
        case  1:printf("\n\n\tJanuary");   break;
        case  2:printf("\n\n\tFebruary");  break;
        case  3:printf("\n\n\tMarch");     break;
        case  4:printf("\n\n\tApril");     break;
        case  5:printf("\n\n\tMay");       break;
        case  6:printf("\n\n\tJune");      break;
        case  7:printf("\n\n\tJuly");      break;
        case  8:printf("\n\n\tAugust");    break;
        case  9:printf("\n\n\tSeptember"); break;
        case 10:printf("\n\n\tOctober");   break;
        case 11:printf("\n\n\tNovember");  break;
        case 12:printf("\n\n\tDecember");  break;   
    };    
}
int main()
{
    int year, day, n, week, k;
    int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    printf("Enter the year:");
    scanf("%d", &year);
    if(year<1900||year>2099) printf("Error");
    week=initialweek(year);
//    printf("week=%d", week);   //测试该年元旦是星期几。 
    if(leapyear(year)) month[1]=29;
    for(n=0; n<12; n++){
        printmonth(n);
        printf("\nSUN MON TUE WED THU FRI SAT\n");
        for(k=0; k<week; k++) {
            printf("    ");}
        for(day=1; day<=month[n]; day++, ++week, week%=7){
            printf("%3d ", day);
            if(week==6) printf("\n");
        }   
    }
    return 0;
}
