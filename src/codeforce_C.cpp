#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n; // кол-во товаров на кассе
    cin >> n;
    long long s;
    cin >> s; // кол-во наличных деняг

    vector<long long> price; // цена каждого товара
    vector<long long> value; // важность каждого товара

    // ввод цены и важности каждого товара 
    for (long long i = 0;  i < n; i++) {
        long long x;
        cin >> x;
        price.push_back(x);
        long long y;
        cin >> y;
        value.push_back(y);
    }

    long long current_price = 0; // текущая цена
    long long current_value = 0; // текущая важность
    //long long total_price = 0; // итоговая цена
    long long total_value = 0; // итоговая важность

    long long first_item = 0; // первый товар
    long long last_item = 0; // последний товар
    long long current_first_item = 0;
    long long current_last_item = 0;

    current_price += price[0];
    current_value += value[0];

    bool flag = false;

    for(long long i = 0; i < n; i++){
        //cout << "ALARM";
        if (price[i] <= s){
            flag = true;
            break;
        }
    }
    if (flag == true){
          while (last_item < n) {
            current_last_item++;
            if (current_last_item >= n){
                break;
            }
            current_price += price[current_last_item];
            current_value += value[current_last_item];
            while (current_price > s && current_first_item < current_last_item){
                current_price -= price[current_first_item];
                current_value -= value[current_first_item];
                current_first_item++;
            }
            if (total_value < current_value){
                total_value = current_value;
                first_item = current_first_item;
                last_item = current_last_item;
            }
        }

        cout << first_item + 1 << " ";
        cout << last_item + 1;
    }
    else {
        cout << 0 << " " << 0;
    }

    

    //cout << "total_value = " << total_value << endl;
    //cout << "current_price = " << current_price << endl;

    
}