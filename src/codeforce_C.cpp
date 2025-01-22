#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long products_count; // кол-во товаров на кассе
    cin >> products_count;
    long long cash_count;
    cin >> cash_count; // кол-во наличных

    vector<long long> price; // цена каждого товара
    vector<long long> value; // важность каждого товара

    long long cur_price;
    long long cur_value;
    // ввод цены и важности каждого товара
    for (long long i = 0; i < products_count; i++)
    {
        cin >> cur_price;
        price.push_back(cur_price);
        cin >> cur_value;
        value.push_back(cur_value);
    }

    // long long total_price = 0; // итоговая цена
    long long total_value = 0; // итоговая важность

    long long first_item = 0; // первый товар
    long long last_item = 0;  // последний товар
    long long cur_first_item = 0;
    long long cur_last_item = 0;

    cur_price = price[0]; // текущая цена
    cur_value = value[0]; // текущая важность

    bool flag = false;

    // Проверка, если ли хотя бы один товар который возможно купить
    for (long long i = 0; i < products_count; i++)
    {
        if (price[i] <= cash_count)
        {
            flag = true;
            break;
        }
    }

    if (flag == true)
    {
        while (last_item < products_count)
        {
            cur_last_item++;
            if (cur_last_item >= products_count)
            {
                break; // перебрали всю ленту
            }

            cur_price += price[cur_last_item];
            cur_value += value[cur_last_item];

            while (cur_price > cash_count && cur_first_item < cur_last_item)
            {
                cur_price -= price[cur_first_item];
                cur_value -= value[cur_first_item];
                cur_first_item++;
            }
            if (total_value < cur_value)
            {
                total_value = cur_value;
                first_item = cur_first_item;
                last_item = cur_last_item;
            }
        }

        cout << first_item + 1 << " ";
        cout << last_item + 1;
    }
    else
    {
        cout << 0 << " " << 0;
    }
}