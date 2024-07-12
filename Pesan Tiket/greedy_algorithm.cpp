#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
using namespace std;

struct Task
{
    int id;
    string course;
    int deadline;
    int points;
};

void bubbleSortTasks(Task tasks[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (tasks[j].points < tasks[j + 1].points)
            {
                swap(tasks[j], tasks[j + 1]);
            }
        }
    }
}

void scheduleTasks(Task tasks[], int size)
{
    bubbleSortTasks(tasks, size);

    int maxDeadline = 0;
    for (int i = 0; i < size; ++i)
    {
        if (tasks[i].deadline > maxDeadline)
        {
            maxDeadline = tasks[i].deadline;
        }
    }

    int slots[maxDeadline + 1];
    for (int i = 0; i <= maxDeadline; ++i)
    {
        slots[i] = -1;
    }

    Task scheduledTasks[maxDeadline + 1];
    for (int i = 0; i <= maxDeadline; ++i)
    {
        scheduledTasks[i] = {0, "", 0, 0};
    }

    for (int i = 0; i < size; ++i)
    {
        for (int j = min(maxDeadline, tasks[i].deadline); j > 0; --j)
        {
            if (slots[j] == -1)
            {
                slots[j] = i;
                scheduledTasks[j] = tasks[i];
                break;
            }
        }
    }

    int totalPoints = 0;
    cout << "+----+---------------------+-----------------+--------+\n";
    cout << "| ID | Course              | Deadline (Hari) | Points |\n";
    cout << "+----+---------------------+-----------------+--------+\n";
    for (int i = 1; i <= maxDeadline; ++i)
    {
        if (slots[i] != -1)
        {
            Task &task = scheduledTasks[i];
            totalPoints += task.points;
            cout << "| " << setw(2) << task.id << " | "
                 << setw(20) << left << task.course << "| "
                 << setw(15) << right << task.deadline << " | "
                 << setw(6) << task.points << " |\n";
        }
    }
    cout << "+----+---------------------+-----------------+--------+\n";
    cout << "|    | Total Points                          | " << setw(6) << totalPoints << " |\n";
    cout << "+----+---------------------+-----------------+--------+\n";
}

int main()
{
    const int TASK_COUNT = 5;
    Task tasks[TASK_COUNT] = {
        {1, "Kalkulus", 1, 35},
        {2, "Informatika", 1, 15},
        {3, "Rangkaian Listrik", 1, 5},
        {4, "Bahasa Indonesia", 1, 45},
        {5, "Bahasa Inggris", 1, 1},
    };
    scheduleTasks(tasks, TASK_COUNT);
    getch();
    return 0;
}
