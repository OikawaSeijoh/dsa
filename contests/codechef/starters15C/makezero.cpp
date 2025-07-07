#include <bits/stdc++.h>
using namespace std;

int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int opone = 0;
        int optwo = 0;
        int last = n;
        int mindex = n;

        while (mindex > 0) {
            int val = INT_MAX;
            for (int i = 0; i < last; i++) {
                if (val >= arr[i]) {
                    val = arr[i];
                    mindex = i;
                }
            }
            for (int i = 0; i < last; i++)
                arr[i] -= val;
            opone += val;
            optwo += last - mindex - 1;
            last = mindex;

            if (last == 0 && val != 0) {
                opone -= val;
                optwo += 1;
            }
        }

        cout << opone + optwo << endl;
    }

    return 0;
}
