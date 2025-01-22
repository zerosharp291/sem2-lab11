#include <iostream>
#include <vector>

// 11 4 2 5 6 7 6 0 2 8 7 5 3

using namespace std;

int main() {
    long long n;
    cin >> n;
    long long k;
    cin >> k;

    vector<long long> cloudy_days;
    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        cloudy_days.push_back(x);
    }

    long long b = 0;

    long long count_of_cloudy_days = 0;
    long long min_of_power = 0;
    long long number_of_day = 0;
    long long number_of_min = 0;

    while (number_of_day < n){
        //cout << " ALARM 1 " << endl;
        if (cloudy_days[number_of_day] <= b){
            count_of_cloudy_days = 0;
            //cout << " ALARM 2 " << endl;
        }
        else {
            //cout << " ALARM 3 __" << endl;
            count_of_cloudy_days++;
            if (count_of_cloudy_days >= k) {
                //cout << "ALARM 4 " << endl;
                long long x = number_of_day - k + 1;
                number_of_min = x;
                min_of_power = cloudy_days[x];
                //cout << "x = " << x << endl;
                //cout << "cloudy = " << cloudy_days[x] << endl;
                while (x <= number_of_day) {
                    if (cloudy_days[x] <= min_of_power){
                        number_of_min = x;
                        min_of_power = cloudy_days[x];
                    }
                    x++;
                }
                b = min_of_power;
                number_of_day = number_of_min;
                count_of_cloudy_days = 0;
            }
        }
        number_of_day++;
        //cout << "number_of_day = " << number_of_day << endl;
        //cout << "b = " << b << endl;
        //cout << "+++++++" << endl;
    }

    cout << b;
}