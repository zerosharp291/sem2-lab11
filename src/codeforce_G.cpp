#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long review_count; // кол-во отзывов
    cin >> review_count;
    long long reputation_decrease; // велчина понижения доверия
    cin >> reputation_decrease;
    long long streak; // кол-во подряд читаемых отзыва
    cin >> streak;

    vector<char> reputation;

    for (long long i = 0; i < review_count; i++)
    {
        char x;
        cin >> x;
        reputation.push_back(x);
    }

    if (reputation_decrease == 0)
    {
        cout << 0;
    }
    else
    {
        long long sum_of_bad_reputation = 0;
        long long bad_count = 0;
        long long good_count = 0;
        long long current_good_reputation = 0;
        long long left = 0;
        long long right = 0;
        long long reputation_increase = 0;

        bool flag = true;

        for (long long i = 0; i < streak; i++)
        {
            if (reputation[i] == 'N')
            {
                bad_count++;
            }
            else
            {
                good_count++;
            }
        }
        right = streak - 1;

        if (good_count == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            sum_of_bad_reputation = bad_count * reputation_decrease;

            long long mnogitel = 0;

            current_good_reputation = good_count * mnogitel;

            while (sum_of_bad_reputation > current_good_reputation)
            {
                mnogitel++;
                current_good_reputation = good_count * mnogitel;
            }

            reputation_increase = mnogitel;

            while (right < review_count)
            {
                if (reputation[left] == 'N')
                {
                    bad_count--;
                }
                else
                {
                    good_count--;
                }
                left++;
                right++;
                if (right >= review_count)
                {
                    break;
                }
                if (reputation[right] == 'N')
                {
                    bad_count++;
                }
                else
                {
                    good_count++;
                }

                sum_of_bad_reputation = bad_count * reputation_decrease;

                long long mnogitel = reputation_increase;

                current_good_reputation = good_count * mnogitel;

                if (good_count != 0)
                {
                    while (sum_of_bad_reputation > current_good_reputation)
                    {
                        mnogitel++;
                        current_good_reputation = good_count * mnogitel;
                    }
                }
                else
                {
                    flag = false;
                    cout << -1 << endl;
                    break;
                }

                if (reputation_increase < mnogitel)
                {
                    reputation_increase = mnogitel;
                }
            }
            if (flag == true)
            {
                cout << reputation_increase;
            }
        }
    }
}