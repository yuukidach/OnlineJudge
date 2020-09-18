/*
ID: dachen1
LANG: C++
TASK: transform
*/
#include <cstdio>
int n;
typedef struct board{
    char v[11][11];
} Board;
Board a,b;
Board rdboard(int n){
    Board c;
    for (int i(1);i<=n;i++){
        for (int j(1);j<=n;j++){
            scanf("%c",&c.v[i][j]);
        }
        scanf("\n");
    }
    return c;
}

Board change(Board a,int k,int n){
    Board c;
    for (int i(1);i<=n;i++){
        for (int j(1);j<=n;j++){
            switch(k){
                case 1: c.v[i][j]=a.v[n-j+1][i];break;
                case 2: c.v[i][j]=a.v[n+1-i][n+1-j];break;
                case 3: c.v[i][j]=a.v[j][n+1-i];break;
                case 4: c.v[i][j]=a.v[i][n+1-j];break;
            }
        }
    }
    return c;
}

int isequel(Board a,Board b,int n){
    for (int i(1);i<=n;i++){
        for (int j(1);j<=n;j++){
            if (a.v[i][j]!=b.v[i][j]) return 0;
        }
    }
    return 1;
}
int main(){
    freopen("transform.in","r",stdin);
    freopen("transform.out","w",stdout);
    scanf("%d\n",&n);
    a=rdboard(n);
    b=rdboard(n);
    for (int i(1);i<=4;i++){
        Board t=change(a,i,n);
        if (isequel(t,b,n)){
            printf("%d\n",i);
            return 0;
        }
        if (i==4){
            for (int j(1);j<=3;j++){
                if (isequel(change(t,j,n),b,n)){
                    printf("5\n");
                    return 0;
                }
            }
        }
    }
    if (isequel(a,b,n)){
        printf("6\n");
        return 0;
    }
    printf("7\n");
    return 0;
}