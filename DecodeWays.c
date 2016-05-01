int isValidDecodings(char* s, int n){//Actually, i think the validation of string is one responsibiity of the encode function.
    int i;
    for(i=0;i<n;++i){
        if('0'==s[i]){
            if(0==i ||
                (i+1<n && s[i+1]=='0') ||
                (s[i-1]!='1' && s[i-1]!='2'))
                return 0;
        }
    }
    return 1;
}

int numDecodings(char* s) {
    const int N = strlen(s);
    int i,tmp;
    if(N==0) return 0;
    if(!isValidDecodings(s,N))
        return 0;
    int* ways = (int*)malloc(sizeof(int)*(N+1));
    ways[0]=ways[1]=1;
    for(i=2;i<N+1;++i){
        if('0'==s[i-1]){
            if(i>=N)//end with '0'
                ways[i]=ways[i-2];
            else
                ways[i+1]=ways[i]=ways[i-2];
            ++i;
            continue;
        }
        tmp=(s[i-2]-'0')*10+(s[i-1]-'0');
        if(tmp>=1 && tmp<=26)
            ways[i]=ways[i-2]+ways[i-1];
        else
            ways[i]=ways[i-1];
    }
    tmp=ways[N];
    free(ways);
    return tmp;
}