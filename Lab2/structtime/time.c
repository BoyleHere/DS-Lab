#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Time{
int sec;
int min;
int hour;};

struct Time Add(struct Time t1,struct Time t2) {
    struct Time result;
    result.sec=t1.sec+t2.sec;
    result.min =t1.min+t2.min+result.sec/60;
    result.sec%= 60;
    result.hour=t1.hour+t2.hour+result.min/60;
    result.min%=60;
    return result;
}

struct Time Diff(struct Time t1,struct Time t2) {
    struct Time result;
    int sec1 = t1.sec+t1.min*60+t1.hour*3600;
    int sec2 = t2.sec+t2.min*60+t2.hour*3600;
    int diffSec=sec1-sec2;
    result.sec=diffSec%60;
    diffSec/=60;
    result.min=diffSec%60;
    diffSec/=60;
    result.hour=diffSec;
    return result;
}

void Display(struct Time t) {
    printf("%d hours, %d minutes, %d seconds\n",t.hour,t.min,t.sec);}

struct Time Read() {
    struct Time t1;
    printf("Enter hours: ");
    scanf("%d",&t1.hour);
    printf("Enter minutes: ");
    scanf("%d",&t1.min);
    printf("Enter seconds: ");
    scanf("%d",&t1.sec);
    return t1;
}

int main() {

struct Time time1, time2, result;
printf("Enter details for time 1:\n");
time1=Read();
printf("Enter details for time 2:\n");
time2=Read();
result=Add(time1,time2);
printf("Time 1 + Time 2 = ");
Display(result);
result=Diff(time1,time2);
printf("Time 1 - Time 2 = ");
Display(result);
}