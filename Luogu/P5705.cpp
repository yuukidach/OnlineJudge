#include<cstdio>

int main() {
    double a, res = 0.0;
    scanf("%lf", &a);
    int b = a * 10;
    while (b > 0) {
        res = res * 10 + b % 10;
        b = b / 10; 
    }

    res /= 1000;
    printf("%.3f", res);

    return 0;
}