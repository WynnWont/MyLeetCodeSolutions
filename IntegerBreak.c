#include <stdio.h>
#include <stdlib.h>

int imax(int i, int j){
    return i>j?i:j;
}

int integerBreak(int n) {
    int k,i,j,m,left,right;
    int* p =(int*)malloc(sizeof(int)*(n+1));
    p[2]=1;
    p[3]=2;
    for(i=4;i<=n;++i){
        k=i/2;
        p[i]=-1;
        for(j=2;j<=k;++j){
            left=j>p[j]?j:p[j];
            right=(i-j)>p[i-j]?(i-j):p[i-j];
            m=left*right;
            if(m>p[i]) p[i]=m;
        }
    }
    m=p[n];
    free(p);
    return m;
}

int main(int argc, char** argv){
    printf("%d.\n", integerBreak(atoi(argv[1])));
    return 0;
}