#include "tbitfield.h"
#include <iomanip>
int main()
{
    int n, m, k, count;

    cout << "Input a number:  ";
    cin >> n;
    TBitField s(n + 1);
    // ���������� ���������
    for (m = 2; m <= n; m++)
        s.SetBit(m);
    // �������� �� sqrt(n) � �������� �������
    for (m = 2; m * m <= n; m++)
        // ���� m � s, �������� �������
        if (s.GetBit(m))
            for (k = 2 * m; k <= n; k += m)
                if (s.GetBit(k))
                    s.ClrBit(k);
    // ���������� � s �������� - ������� �����
    cout << endl << "Set all digits: " << endl << s << endl;
    cout << endl << "Set prime digits: " << endl;
    count = 0;
    k = 1;
    for (m = 2; m <= n; m++)
        if (s.GetBit(m))
        {
            count++;
            cout << setw(3) << m << " ";
            if (k++ % 10 == 0)
                cout << endl;
        }
    cout << endl;
    cout << "Count of prime digits: " << count << endl;
}