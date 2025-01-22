#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long sunny_days_count; // количество солнечных дней
    cin >> sunny_days_count;
    long long requests_count; // количество просьб горожан
    cin >> requests_count;

    vector<int> sunny_days;
    sunny_days.resize(sunny_days_count);

    for (int i = 0; i < sunny_days_count; i++)
    {
        cin >> sunny_days[i];
    }

    vector<int> requests;
    requests.resize(requests_count);

    for (int i = 0; i < requests_count; i++)
    {
        cin >> requests[i];
    }

    long long number_of_sunny_day = 0; // номер солнечного дня
    long long number_of_request = 0;   // номер просьбы

    while (requests[number_of_request] >= sunny_days[number_of_sunny_day])
    {
        number_of_sunny_day++;
    }

    long long max_wait = sunny_days[number_of_sunny_day] - requests[number_of_request];
    long long min_wait = sunny_days[number_of_sunny_day] - requests[number_of_request];

    number_of_sunny_day = 0;

    while (number_of_sunny_day < sunny_days_count)
    {
        long long x = 0; // разность, время ожидания
        if (requests[number_of_request] < sunny_days[number_of_sunny_day])
        {
            x = sunny_days[number_of_sunny_day] - requests[number_of_request];
            if (x > max_wait)
            {
                max_wait = x;
            }
            else if (x < min_wait)
            {
                min_wait = x;
            }
            number_of_request++;
            if (number_of_request >= requests_count)
            {
                break;
            }
        }
        else
        {
            number_of_sunny_day++;
            if (number_of_sunny_day >= sunny_days_count)
            {
                break;
            }
        }
    }

    cout << min_wait << endl;
    cout << max_wait << endl;
}