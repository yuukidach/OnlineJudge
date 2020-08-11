#include<cstdio>

int main() {
    double val;
    int num;

    scanf("%lf %d", &val, &num);
    printf("%.3f\n", val / num);
    printf("%d\n", num << 1);

    return 0;
}