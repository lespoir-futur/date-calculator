#include <stdio.h>
#include <stdlib.h>

int main()
{
    //读取年月日
    char start_date[] = "1966/6/6";
    char end_date[] = "1999/9/9";
    int start_year, start_month, start_day, end_year, end_month, end_day;
    sscanf(start_date, "%d/%d/%d", &start_year, &start_month,&start_day);
    sscanf(end_date, "%d/%d/%d", &end_year, &end_month, &end_day);

    int sum_days = 0;

    //计算起始日至结束日经过的日期
    if (start_year > end_year)
        goto fail;
    else if (start_year == end_year)
    {
        if (start_month > end_month)
            goto fail;
        else if (start_month == end_month){
            if (start_day > end_day)
                goto fail;
            else sum_days += (end_day - start_day);
        }

        else sum_days += (n_day_of_the_year(end_year,end_month,end_day)
         - n_day_of_the_year(start_year,start_month,start_day));
        
    }

    else {
        for(int y = start_year; y < end_year; y++){
            if (is_runnian(y)) sum_days += 366;
            else sum_days += 365;
        }
        sum_days -= n_day_of_the_year(start_year,start_month,start_day);
        sum_days += n_day_of_the_year(end_year,end_month,end_day);
    }

    printf("从%d年%d月%d日到%d年%d月%d日经过了%d天\n", start_year,start_month,start_day,end_year,end_month,end_day,sum_days);

    printf("%d\n",sum_days);
    system ("pause");
    return 0;

fail: {
    printf("输入错误：起始日在结束日之后\n");
    return -1;
    }

}

int is_runnian(int year){
    //判断该年是否为闰年
    if (year % 4 !=0)
        return 0;
    else if (year % 100 ==0){
        if (year % 400 != 0)
            return 0;
        else return 1;
    }
}

int n_day_of_the_year(int year, int month, int day){
    int n = 0;
    for (int m = 1; m < month; m++){
        switch(m){
            case 1:
                break;
            case 2:
                n += 31;
                break;
            case 3:
                if(is_runnian(year))    n += 29;
                else n += 28;
                break;
            case 4:
                n += 31;
                break;
            case 5:
                n += 30;
                break;
            case 6:
                n += 31;
                break;
            case 7:
                n += 30;
                break;
            case 8:
                n += 31;
                break;
            case 9:
                n += 31;
                break;
            case 10:
                n += 30;
                break;
            case 11:
                n += 31;
                break;
            case 12:
                n += 30;
                break;
            default:
                break; 
        }
    }
    n += day; 
    return n;
}