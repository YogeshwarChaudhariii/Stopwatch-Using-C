#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>   // sleep()
#include<conio.h>    // _kbhit(), _getch()

///////////////////////////////////////////////////////////////
//
// Global variables
//
///////////////////////////////////////////////////////////////
int hour = 0, minute = 0, second = 0;
int running = 0;   // 0 = stopped, 1 = running

///////////////////////////////////////////////////////////////
//
// Function : StartStopwatch
// Use : Client can start the stopwatch
//
///////////////////////////////////////////////////////////////
void StartStopwatch()
{
    if (running)
    {
        printf("Stopwatch is already running!\n");
        return;
    }

    running = 1;
    printf("Stopwatch started. It will keep running until you stop it from pressing 2.\n\n");

    while (running)
    {
        printf("\rTime elapsed: %02d : %02d : %02d", hour, minute, second);
        fflush(stdout);
        sleep(1);
        second++;

        if (second == 60)
        {
            second = 0;
            minute++;
        }
        if (minute == 60)
        {
            minute = 0;
            hour++;
        }

        // Non-blocking check for stop request
        if (_kbhit())
        {
            char ch = _getch();
            if (ch == '2')
            {
                printf("\nReturning to menu...\n");
                sleep(2);
                running = 0;
                break;
            }
        }
    }
}

///////////////////////////////////////////////////////////////
//
// Function : StopStopwatch
// Use : Client can stop the stopwatch
//
///////////////////////////////////////////////////////////////
void StopStopwatch()
{
    if (running)
    {
        running = 0;
        printf("\nStopwatch stopped at %02d : %02d : %02d\n", hour, minute, second);
    }
    else
    {
        printf("Stopwatch is not running.\n");
    }
}

///////////////////////////////////////////////////////////////
//
// Function : ResumeStopwatch
// Use : Client can resume the stopwatch
//
///////////////////////////////////////////////////////////////
void ResumeStopwatch()
{
    if (running)
    {
        printf("Stopwatch is already running!\n");
        return;
    }

    running = 1;
    printf("Stopwatch resumed. It will keep running until you stop it from pressing 2.\n\n");

    while (running)
    {
        printf("\rTime elapsed: %02d : %02d : %02d", hour, minute, second);
        fflush(stdout);
        sleep(1);
        second++;

        if (second == 60)
        {
            second = 0;
            minute++;
        }
        if (minute == 60)
        {
            minute = 0;
            hour++;
        }

        if (_kbhit())
        {
            char ch = _getch();
            if (ch == '2')
            {
                printf("\nReturning to menu...\n");
                sleep(2);
                running = 0;
                break;
            }
        }
    }
}

///////////////////////////////////////////////////////////////
//
// Function : ResetStopwatch
// Use : Client can reset the stopwatch
//
///////////////////////////////////////////////////////////////
void ResetStopwatch()
{
    hour = minute = second = 0;
    running = 0;
    printf("Stopwatch reset to 00 : 00 : 00\n");
}

///////////////////////////////////////////////////////////////
//
// Entry Point Function (main)
//
///////////////////////////////////////////////////////////////
int main()
{
    int choice;

    while (1)
    {
        printf("\n\n--- Stopwatch Menu ---\n");
        printf("1. Start Stopwatch\n");
        printf("2. Stop Stopwatch\n");
        printf("3. Resume Stopwatch\n");
        printf("4. Reset Stopwatch\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("cls");
            StartStopwatch();
            break;
        case 2:
            system("cls");
            StopStopwatch();
            break;
        case 3:
            system("cls");
            ResumeStopwatch();
            break;
        case 4:
            system("cls");
            ResetStopwatch();
            break;
        case 0:
            system("cls");
            printf("Exiting program...\n");
            exit(EXIT_SUCCESS);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
