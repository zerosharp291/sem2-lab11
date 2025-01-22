#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n; // кол-во отзывов
    cin >> n;
    long long b; // велчина понижения доверия
    cin >> b;
    long long k; // кол-во подряд читаемых отзыва
    cin >> k;

    vector<char> doverie; 

    for (long long i = 0; i < n; i++) {
        char x;
        cin >> x;
        doverie.push_back(x);
    }

    if (b == 0) {
        cout << 0;
    }
    else {
        long long sum_of_bad_doverie = 0;
        long long bad_count = 0;
        long long good_count = 0;
        long long current_good_doverie = 0;
        long long number_in = 0;
        long long number_out = 0;
        long long total_mnogitel = 0;

        bool flag = true;

        for (long long i = 0; i < k; i++) {
            if (doverie[i] == 'N'){
                bad_count++;
            }
            else {
                good_count++;
            }
        }
        number_out = k - 1;

        if (good_count == 0) {
            cout << -1 << endl;
        }
        else {
            sum_of_bad_doverie = bad_count * b;

            long long mnogitel = 0;

            current_good_doverie = good_count * mnogitel;

            while (sum_of_bad_doverie > current_good_doverie){
                mnogitel++;
                current_good_doverie = good_count * mnogitel;
            }

            total_mnogitel = mnogitel;

            while (number_out < n) {
                //cout << "ALARM 1" << endl;
                if (doverie[number_in] == 'N'){
                    bad_count--;
                }
                else {
                    good_count--;
                }
                number_in++;
                number_out++;
                if (number_out >= n){
                    break;
                }
                if (doverie[number_out] == 'N'){
                    bad_count++;
                }
                else {
                    good_count++;
                }

                sum_of_bad_doverie = bad_count * b;

                long long mnogitel = total_mnogitel;

                current_good_doverie = good_count * mnogitel;

                if (good_count != 0){
                    while (sum_of_bad_doverie > current_good_doverie){
                        mnogitel++;
                        current_good_doverie = good_count * mnogitel;
                        //cout << "Mnogitel = " << mnogitel << endl;
                        //cout << "current_good_doverie = " << current_good_doverie << endl;
                        //cout << "ALARM 2 ___" << endl;
                    }
                }
                else {
                    flag = false;
                    cout << -1 << endl;
                    break;
                }

                if (total_mnogitel < mnogitel) {
                    total_mnogitel = mnogitel;
                }

            }
            if (flag == true){
                cout << total_mnogitel;
            }
        }
    }
}