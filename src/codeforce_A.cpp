#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Значит так, нам нужно считать время подготовки и время работы отдельно. Делать это методом скользащего окна.
// Потребуется всего один массив. Время подготовки в дни с маленьким кол-вом времени найти по условию.
// Минимально потраченное время считать по времени подготовки.

int main()
{
    long long days_count; // общее кол-во дней
    cin >> days_count;
    long long writing_time; // время, которое требуется для написания работы
    cin >> writing_time;
    long long preparation_time; // время, которое требуется на подготовку к работе
    cin >> preparation_time;

    long long sum = 0; // сумма времени работы

    long long quantity_of_working_days = 0; // кол-во рабочих дней

    vector<int> calendar;                             // время работы в каждый день
    long long current_first_day = 0;                  // индекс первого дня работы
    long long first_day = 0;                          // индеекс первого подходящего дня работы
    long long sum_of_preparating = 0;                 // время подготовки
    long long min_sum_of_preparating = LONG_LONG_MAX; // минимальное время подготовки

    long long current_day;
    for (int i = 0; i < days_count; i++)
    {
        cin >> current_day;
        calendar.push_back(current_day - preparation_time);
        quantity_of_working_days++;
        if (current_day - preparation_time > 0)
        {
            sum += current_day - preparation_time;
            sum_of_preparating += preparation_time;
        }
        else
        {
            sum_of_preparating += current_day;
        }
        while ((sum - calendar[current_first_day] >= writing_time || calendar[current_first_day] < 0) && quantity_of_working_days > 1)
        {
            if (calendar[current_first_day] >= 0)
            {
                sum -= calendar[current_first_day];
                sum_of_preparating -= preparation_time;
            }
            else
            {
                sum_of_preparating -= preparation_time + calendar[current_first_day];
            }
            current_first_day++;
            quantity_of_working_days--;
        }
        if (min_sum_of_preparating >= sum_of_preparating && sum >= writing_time)
        {
            min_sum_of_preparating = sum_of_preparating;
            first_day = current_first_day;
        }
    }
    if (sum < writing_time)
    {
        cout << -1 << endl
             << -1;
    }
    else
    {
        long long result = min_sum_of_preparating += writing_time;
        cout << first_day + 1 << endl
             << result;
    }
}