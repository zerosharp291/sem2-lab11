#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long t1; // время движения по улице
    cin >> t1;
    long long t2; // время движения по парку
    cin >> t2;
    long long d; // время, до которого ЕВЛАМПИЙ должен быть дома
    cin >> d;
    long long s; // снижение интенсивности дождя
    cin >> s;

    vector<int> power_of_rain; // интенсивность дождя в каждый момент времени
    for (int i = 0; i < d; i++) {
        long long x;
        cin >> x;
        power_of_rain.push_back(x);
    }

    long long current_power_sum = 0;
    long long total_power_sum = 0;

    long long total_street_in = 0;


    
    long long street_in = 0;
    long long street_out = 0;
    long long park_in = 0;
    long long park_out = 0;

    for (int i = 0; i < t1+t2; i++) {
        //cout << " ALARM 1 " << endl;
        if (i < t1){
            current_power_sum += power_of_rain[i];
            street_out = i;
        }
        else {
            long long x = power_of_rain[i] - s;
            if (x < 0){
                x = 0;
            }
            current_power_sum += x;
            park_out = i;
        }
        
    }
    park_in = street_out + 1;
    //cout << current_power_sum << endl;
    total_power_sum = current_power_sum;

    while (park_out < d) {
        //cout << " ALARM 2 " << endl;
        current_power_sum -= power_of_rain[street_in];
        //cout << current_power_sum << endl;
        street_in++;
        //cout << "power_of_rain[street_in] = " << power_of_rain[street_in] << endl;
        street_out++;
        current_power_sum += power_of_rain[street_out];
        //cout << current_power_sum << endl;

        if (power_of_rain[park_in] - s > 0) {
            current_power_sum -= power_of_rain[park_in];
            current_power_sum += s;
        }
        park_in++;
        //cout << current_power_sum << endl;

        park_out++;
        if(park_out == d) {
            break;
        }
        int x = power_of_rain[park_out] - s;
        if (x < 0){
            x = 0;
        }
        current_power_sum += x;
        //cout << current_power_sum << endl;

        if (current_power_sum < total_power_sum) {
            total_power_sum = current_power_sum;
            total_street_in = street_in;
            //cout << "total_street_in = " << total_street_in << endl;
            //cout << "total_power_sum = " << total_power_sum << endl;
        }
        //cout << current_power_sum << endl;
        //cout << "--------------" << endl;
    }

    cout << total_street_in << endl;
    cout << total_power_sum << endl;
}