#include <iostream>
using namespace std;
char s[18];
long long a[18], fac[18],cnt[18];
int main()
{
    fac[0] = fac[1] = 1;
    for (int i = 2; i <= 17; i++)
        fac[i] = fac[i - 1] * i;
    cin >> s + 1;
    for (int i = 1; i <= 17; i++)
        if (s[i] < 'm')
            a[i] = s[i] - 'a' + 1;
        else
            a[i] = s[i] - 'a';
    for (int i = 1; i <= 17; i++)
        cout << a[i] << ' ';
    cout << endl;
    long long ans = 0;
    for (int i = 1; i <= 17; i++){
        cnt[a[i]]++;
        int num=0;
        for(int j=1;j<=a[i];j++)
            num+=cnt[j];
        ans += (a[i] - num) * fac[17 - i];
    }
    cout << ans + 1<< endl;
    return 0;
}