int checkprime(int c[]){
   int a=2;
    int i=0;
    int b;
    int np=0,nc=0;
    int Nprime[]={0};
    int Ncompositenumber[]={0};
    int prime[N_CARDS_INITIAL_HAND];
    int compositenumber[N_CARDS_INITIAL_HAND];
    int d=0;
    int x=0,y=0;
    int j=1,k=2;
    while(i<N_CARDS_INITIAL_HAND){
        while(a<c[i]){
            b=c[i];
            if(c[i]%a==0){
            b=b/a;
            }else{
            a++;
            }
        }
        if ( b==c[i] ){
            Nprime[i]=1;
            b=prime[x];
            x++;
            }else{
            Ncompositenumber[i]=1;
            b=compositenumber[y];
            y++;
            }
        i++;
    }
    // the number of prime and compositenumber
    while(d<N_CARDS_INITIAL_HAND){
        np=np+Nprime[d];
        nc=nc+Ncompositenumber[d];
        d++;
    }
    // j=1: we have more prime we need to discard compositenumber
    // k=2: we have more compositenumber we need to discard compositenumber
    if(np>=nc){
        return j;
    }else{
        return k;
    }
}