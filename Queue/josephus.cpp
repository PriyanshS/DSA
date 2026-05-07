#include <iostream>
#include <list>
#include <numeric>

using namespace std;

int josephus_solve(int n, int k)
{
    list<int> circle;
    for (int i = 1; i <= n; ++i)
    {
        circle.push_back(i);
    }

    auto it = circle.begin();

    while (circle.size() > 1)
    {
        for (int i = 0; i < k - 1; ++i)
        {
            ++it;
            if (it == circle.end())
            {
                it = circle.begin();
            }
        }
        it = circle.erase(it);
        if (it == circle.end())
        {
            it = circle.begin();
        }
    }
    return circle.front();
}

int main()
{
    int n1 = 10, k1 = 3;
    cout << "The position of the last remaining person for N=" << n1 << " and K=" << k1 << " is: " << josephus_solve(n1, k1) << endl;

    int n2 = 10, k2 = 2;
    cout << "The position of the last remaining person for N=" << n2 << " and K=" << k2 << " is: " << josephus_solve(n2, k2) << endl;

    int n3 = 15, k3 = 4;
    cout << "The position of the last remaining person for N=" << n3 << " and K=" << k3 << " is: " << josephus_solve(n3, k3) << endl;

    return 0;
}
