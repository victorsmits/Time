#include <stdio.h>
#include <hdf5.h>
#include <unistd.h>

struct time {
    unsigned char hours ;
    unsigned char minutes ;
    unsigned char seconds ;
};
void increment_hour(struct time *time);


int main( )
{
    struct time now={0,59,55};
    while (1){
        increment_hour(&now);
        printf("%02d:%02d:%02d\n",now.hours,now.minutes,now.seconds);
        sleep(1);
    }
}

void increment_hour(struct time *time){
    time->seconds +=1;
    if (time->seconds==60){
        time->minutes +=1;
        time->seconds=0;
    }
    if (time->minutes==60){
        time->hours+=1;
        time->minutes =0;
    }
}