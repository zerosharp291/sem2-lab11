#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n; // количество солнечных дней
    cin >> n;
    long long m; // количество просьб горожан
    cin >> m;

    vector<int> sun_days;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        sun_days.push_back(x);
    }

    vector<int> request;
    for (int i = 0; i < m; i++) {
        long long y;
        cin >> y;
        request.push_back(y);  
    }
    long long number_of_sun = 0;
    long long number_of_request = 0;

    while (request[number_of_request] >= sun_days[number_of_sun]){
        number_of_sun++;
    }
    long long max_wait = sun_days[number_of_sun] - request[number_of_request];
    long long min_wait = sun_days[number_of_sun] - request[number_of_request];

    number_of_sun = 0;

    while (number_of_sun < n) {
        //cout << "ALARM1" << endl;
        long long x = 0; // разность, время ожидания
        if (request[number_of_request] < sun_days[number_of_sun]) {
            //cout << "ALARM2" << endl;
            x = sun_days[number_of_sun] - request[number_of_request];
            if (x > max_wait) {
                max_wait = x;
            }
            else if (x < min_wait){
                min_wait = x;
            }
            number_of_request++;
            if (number_of_request >= m) {
                break;
            }
        }
        else {
            //cout << "ALARM3" << endl;
            number_of_sun++;
            if (number_of_sun >= n) {
                break;
            }
        }
    }

    cout << min_wait << endl;
    cout << max_wait << endl;
}