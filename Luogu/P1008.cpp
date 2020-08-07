#include <cstdio>

bool check(int a, int b, int c) {
    int res = 0;
    while (a != 0) {
        res |= 1 << (a % 10);
        a /= 10;
    }
    while(b != 0) {
        res |= 1 << (b % 10);
        b /= 10;
    }
    while(c != 0) {
        res |= 1 << (c % 10);
        c /= 10;
    }
    return ((res & 0b1111111110) == 0b1111111110);
}


int main() {
    for (int i = 123; i < 333; ++i) {
        int j = 2 * i;
        int k = 3 * i;
        if (check(i, j, k))
            printf("%d %d %d\n", i, j, k);
    }   
    return 0;
}