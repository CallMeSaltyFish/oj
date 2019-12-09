#include <iostream>
using namespace std;
void sort(int *list, int start, int end)
{
    if (start >= end)
        return;
    int p = list[start], left = start, right = end;
    while (left < right)
    {
        while (list[right] > p && left < right)
            --right;
        list[left] = list[right];
        while (list[left] <= p && left < right)
            ++left;
        list[right] = list[left];
    }
    list[left] = p;
    sort(list, start, left - 1);
    sort(list, left + 1, end);
}
void sort(int *list, int length)
{
    sort(list, 0, length - 1);
}
int main()
{
    int n;
    cin >> n;
    int *list = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> list[i];
    sort(list, n);
    for (int i = 0; i < n; ++i)
        cout << list[i] << " ";
    return 0;
}