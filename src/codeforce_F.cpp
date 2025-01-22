#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long days_count;
    cin >> days_count;
    long long minimal_cloudy_streak;
    cin >> minimal_cloudy_streak;

    vector<long long> cloudy_days(days_count);
    for (long long i = 0; i < days_count; i++)
    {
        cin >> cloudy_days[i];
    }

    long long b_criterio = 0; // критерий излишней облачности Бургоминистра

    long long cloudy_streak = 0;
    long long minimal_cloudness = 0;
    long long cur_day = 0;
    long long minimal_cloudness_index = 0;

    while (cur_day < days_count)
    {
        if (cloudy_days[cur_day] <= b_criterio)
        {
            cloudy_streak = 0;
        }
        else
        {
            cloudy_streak++;
            if (cloudy_streak >= minimal_cloudy_streak)
            {
                long long x = cur_day - minimal_cloudy_streak + 1;
                minimal_cloudness = cloudy_days[x];
                while (x <= cur_day)
                {
                    if (cloudy_days[x] <= minimal_cloudness)
                    {
                        minimal_cloudness_index = x;
                        minimal_cloudness = cloudy_days[x];
                    }
                    x++;
                }
                b_criterio = minimal_cloudness;
                cur_day = minimal_cloudness_index;
                cloudy_streak = 0;
            }
        }
        cur_day++;
    }

    cout << b_criterio;
}