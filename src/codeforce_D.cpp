#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long street_time; // время движения по улице
    cin >> street_time;

    long long under_crown_time; // время движения по парку
    cin >> under_crown_time;

    long long deadline_time; // время, до которого ЕВЛАМПИЙ должен быть дома
    cin >> deadline_time;

    long long rain_reducing_effect; // снижение интенсивности дождя под кроной
    cin >> rain_reducing_effect;

    vector<int> power_of_rain; // интенсивность дождя в каждый момент времени

    for (int i = 0; i < deadline_time; i++)
    {
        cin >> power_of_rain[i];
    }

    long long current_power_sum = 0;
    long long total_power_sum = 0;

    long long total_street_in = 0;

    // участок улицы
    long long street_in = 0;
    long long street_out = 0;

    // участок под кроной дерева
    long long park_in = 0;
    long long park_out = 0;

    for (int i = 0; i < street_time + under_crown_time; i++)
    {
        if (i < street_time)
        {
            current_power_sum += power_of_rain[i];
            street_out = i;
        }
        else
        {
            long long x = power_of_rain[i] - rain_reducing_effect;
            if (x < 0)
            {
                x = 0;
            }
            current_power_sum += x;
            park_out = i;
        }
    }
    park_in = street_out + 1;

    total_power_sum = current_power_sum;

    while (park_out < deadline_time)
    {
        current_power_sum -= power_of_rain[street_in];
        street_in++;

        street_out++;
        current_power_sum += power_of_rain[street_out];

        if (power_of_rain[park_in] - rain_reducing_effect > 0)
        {
            current_power_sum -= power_of_rain[park_in] - rain_reducing_effect;
        }

        park_in++;
        park_out++;

        if (park_out == deadline_time)
        {
            break;
        }

        int x = power_of_rain[park_out] - rain_reducing_effect;

        if (x >= 0)
        {
            current_power_sum += x;
        }

        if (current_power_sum < total_power_sum)
        {
            total_power_sum = current_power_sum;
            total_street_in = street_in;
        }
    }

    cout << total_street_in << endl;
    cout << total_power_sum << endl;
}