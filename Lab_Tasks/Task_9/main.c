#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int num_of_laps;
int lap_time;

void my_own_signal_handler(int sig_num);
void print_laps(int laps, int seconds);
void print_total_time(int laps, int seconds);

int main()
{
    printf("Enter Number of Laps: ");
    scanf("%d", &num_of_laps);
    printf("Enter Lap Time: ");
    scanf("%d", &lap_time);

    if (fork() == 0)
    {
        print_laps(num_of_laps, lap_time);
    }
    else
    {
        if (signal(SIGCHLD, my_own_signal_handler) == SIG_ERR)
        {
            printf("Couldn't handle signal\n");
        }
        while (1)
        {
            sleep(1);
        }
    }
    return 0;
}

void my_own_signal_handler(int sig_num)
{
    printf("Received SIGCHLD\n");
    print_total_time(num_of_laps, lap_time);
    exit(0);
}

void print_laps(int laps, int seconds)
{
    int current_lap = 0;
    while (1)
    {
        sleep(seconds);
        printf("Lap: %d Completed\n", current_lap + 1);
        current_lap++;
        if (current_lap == laps)
        {
            break;
        }
    }
    exit(0);
}

void print_total_time(int laps, int seconds)
{
    printf("Total Time in Seconds: %d\n", laps * seconds);
}