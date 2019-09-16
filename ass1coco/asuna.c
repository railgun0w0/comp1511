// Assignment 1 19T1 COMP1511 Coco
//
// This program was written by Yanghaoyu (z5223796)
// on 25/3/2019
//

#include <stdio.h>
#include <assert.h>
#include <math.h>


#define ACTION_PLAYER_NAME    0
#define ACTION_DISCARD        1
#define ACTION_PLAY_CARD      2

#define N_CARDS              40
#define N_CARDS_INITIAL_HAND 10
#define N_PLAYERS             4
#define N_CARDS_DISCARDED     3

#define CARD_MIN             10
#define CARD_MAX             49
#define factor_max           6

// IF YOU NEED MORE #defines ADD THEM HERE


void print_player_name(void);
void choose_discards(void);
void choose_card_to_play(void);


// ADD PROTOTYPES FOR YOUR FUNCTIONS HERE
void bubble_sort(int a[], int n);
int primecheck(int n);
void NFplaycard(int a,int n,int b[],int pri[],int y,int l);
void chooseprime(int a[],int b[]);
void primesort(int a[],int b[],int c[],int n);
int countarray(int a[]);
int maximum(int a[],int b);
// You should not need to change this main function

int main(void) {

    int which_action = 0;
    scanf("%d", &which_action);
    if (which_action == ACTION_PLAYER_NAME) {
        print_player_name();
    } else if (which_action == ACTION_DISCARD) {
        choose_discards();
    } else if (which_action == ACTION_PLAY_CARD) {
        choose_card_to_play();
    }

    return 0;
}

void print_player_name(void) {

    // CHANGE THIS PRINTF TO YOUR DESIRED PLAYER NAME

    printf("Asuna\n");

}

void choose_discards() {

    // ADD CODE TO READ THE CARDS OF YOUR HAND INTO AN ARRAY USING SCANF
    //save array1  as orgin 10 card 
    int a=0; 
    int array1[N_CARDS_INITIAL_HAND];
    while (a<N_CARDS_INITIAL_HAND) {
        scanf("%d",&array1[a]);
        a=a+1;
    }
    bubble_sort(array1, N_CARDS_INITIAL_HAND);
    int pri[CARD_MIN]={0};
    int notpri[CARD_MIN]={0};
    int i=0;
    int j=0;
    primesort(array1,notpri,pri,N_CARDS_INITIAL_HAND);
    //whether we have 42 card
    while(i<N_CARDS_INITIAL_HAND){
        if(array1[i]==42){
            j=1;
            i=i+10;
        }
        i++;
    }
    i=0;
    // we have 42
    if(j==1){
        if(countarray(notpri)>countarray(pri)){
            while(i<N_CARDS_DISCARDED){
                if(pri[0]!=0){
                    printf("%d",pri[countarray(pri)-1]);
                    pri[countarray(pri)-1]=0;
                    i++;
                }else if(pri[0]==0&&notpri[countarray(notpri)-1]!=42){
                    printf("%d",notpri[countarray(notpri)-1]);
                    notpri[countarray(notpri)-1]=0;
                    i++;
                }else if(notpri[countarray(notpri)-1]==42){
                    notpri[countarray(notpri)-1]=0;
                }
            }
        }else if(countarray(pri)>=countarray(notpri)){
            while(i<N_CARDS_DISCARDED){
                if(notpri[0]!=0&&notpri[countarray(notpri)-1]!=42){
                    printf("%d",notpri[countarray(notpri)-1]);
                    notpri[countarray(notpri)-1]=0;
                    i++;
                }else if(notpri[0]==0){
                    printf("%d",pri[countarray(pri)-1]);
                    pri[countarray(pri)-1]=0;
                    i++;
                }
            }
        }
    }
    //if we do not get 42
    int k=0;
    int n=0;
    int m=0;
    if(j==0){
        while(k<N_CARDS_INITIAL_HAND){
            if(array1[k]>42){
                n=n+1;
            }
            k++;
        }
    }
    int v=9;
    while(m<N_CARDS_DISCARDED){
        if(array1[v]>42){
            printf("%d",array1[v]);
            array1[v]=0;
            v=v-1;
            m=m+1;
        }else{
            primesort(array1,notpri,pri,N_CARDS_INITIAL_HAND-m);
            if(countarray(notpri)>countarray(pri)){
                if(pri[0]!=0){
                    printf("%d",pri[countarray(pri)-1]);
                    pri[countarray(pri)-1]=0;
                    m++;
                }else if(pri[0]==0){
                    printf("%d",notpri[countarray(notpri)-1]);
                    notpri[countarray(notpri)-1]=0;
                    m++;
                }
            }else if(countarray(pri)>=countarray(notpri)){
                if(notpri[0]!=0){
                    printf("%d",notpri[countarray(notpri)-1]);
                    notpri[countarray(notpri)-1]=0;
                    m++;
                }else if(notpri[0]==0){
                    printf("%d",pri[countarray(pri)-1]);
                    pri[countarray(pri)-1]=0;
                    m++;
                }
            }
        }
    }              
    // numpc compare the number of prime and composite number. 1. more or equal prime. 2.more composite number

    // THEN ADD YOUR CODE HERE TO CHOOSE AND PRINT THE CARDS YOU WISH TO DISCARD
    
    // NOTE: THE PROVIDED CODE PROBABLY DISCARDS CARDS NOT IN YOUR HAND
    // WHICH IS NOT LEGAL AND WILL RECEIVE PENALTY POINTS
    // YOU MUST CHANGE IT TO DISCARD CARDS FROM YOUR HAND.

}


void choose_card_to_play(void) {
    
    // READ THE FIRST THREE NUMBERS WHICH ARE:
    // NUMBER OF CARDS IN YOUR HAND  
    int Ncard;
    //NUMBER OF CARDS PLAYED THIS ROUND
    int Ncardround;
    //TABLE POSITION
    int tableposition;
    scanf("%d %d %d",&Ncard,&Ncardround,&tableposition);
    // READ THE CARDS OF YOUR HAND INTO AN ARRAY
    int a=0;
    int array1[Ncard];
    // array1 we got card here
    // YOU WILL NEED TO USE A WHILE LOOP AND SCANF
    while (a<Ncard) {
        scanf("%d",&array1[a]);
        a=a+1;
    }

    // ADD CODE TO READ THE CARDS PREVIOUSLY PLAYED THIS ROUND INTO AN ARRAY
    // YOU WILL NEED TO USE A WHILE LOOP AND SCANF
    int array2[N_PLAYERS];
    //this round played card
    int b=0;
    while (b<Ncardround) {
        scanf("%d",&array2[b]);
        b=b+1;
    }

    // ADD CODE TO READ THE CARDS PLAYED IN THE HISTORY OF THE GAME INTO AN ARRAY
    // YOU WILL NEED TO USE A WHILE LOOP AND SCANF
    int playedcard=(N_CARDS_INITIAL_HAND-Ncard)*4;
    int c=0;
    int array3[CARD_MAX];
    while (c<playedcard) {
        scanf("%d",&array3[c]);
        c=c+1;
    }
    

    
    
    // THEN REPLACE THIS PRINTF WITH CODE TO CHOOSE AND PRINT THE CARD YOU WISH TO PLAY
    int primecard[CARD_MIN]={0};
    int notprimecard[CARD_MIN]={0};
    int w=0;
    int x=0;
    int y=0;
    bubble_sort(array1, Ncard);
    // whether first play card
    primesort(array1,notprimecard,primecard,Ncard);
    if(Ncardround==0){
        //first playcard
        //has prime played before  if x=1 prime card have been played
        while(w<playedcard){
            if(primecheck(array3[w])==1){
                x=1;  //does prime be played before?
            }
            if(array3[w]==42){
                y=1;  //does 42 be played before?
            }
            w++;
        }
        
        // sort primecard and no prime card
        //has prime card played before
        if(x==1){  //play any card
            printf("%d\n",array1[0]);
             
        }else if(notprimecard[0]!=0){  // only play no prime card  i dont not noprime card
            printf("%d\n",notprimecard[0]);                                       
        }else{
            printf("%d\n",array1[0]);   // i can play anycard(all prime card in my hand)
        }
    }else{
        //not first play card
        int max=maximum(array2,Ncardround);
        while(w<playedcard){
            if(array3[w]==42){
                y=1;  //does 42 be played before?
            }
            w++;
        }
        
        //the first card is a prime ?
        if(primecheck(array2[0])==0){
            // not prime 
            NFplaycard (array2[0],Ncard,notprimecard,primecard,y,max);
        }else{
            // is prime
            chooseprime(primecard,notprimecard);
        }
    }

}

// ADD YOUR FUNCTIONS HERE
void bubble_sort(int a[], int n){
    int i, j, temp;
    for (j = 0; j < n - 1; j++)
    for (i = 0; i < n - 1 - j; i++){
        if(a[i] > a[i + 1]){
            temp = a[i];
            a[i] = a[i + 1];
            a[i + 1] = temp;
        }
    }
}

int countarray(int a[]){
    int b=0;
    int n=0;
    while(b<CARD_MIN){
        if(a[b]!=0){
            n=n+1;
        }
        b++;
    }
    return n;
}

//IS THIS PRIME?
int primecheck(int n){
    int a=2;
    int x=n;
    if(n!=0){
        while(a<n){
            if(n%a==0){
                n=n/a;
            }else{
                a++;
            }
        }
        if(n==x){
            return 1; //1 is a prime
        }else{
            return 0; // 0 is a not prime
        }
    }else{
        return 2; //2 is 0
    }   
}

//sort prime and not prime card
void primesort(int a[],int b[],int c[],int n){
    int z=0;
    int x=0;
    int y=0;
    while(z<n){
        if(primecheck(a[z])==0){   //b[] is not prime card
            b[x]=a[z];
            x++;
            z++;
        }else{
            c[y]=a[z];          //c[] is prime card
            y++;
            z++;
        }
    }
}

//choose not prime 
void NFplaycard (int a,int n,int b[],int pri[],int y,int l){
    int c[factor_max]={2,3,5,7,11,13};
    int i=0;
    // the factor of first card
    int d[factor_max]={0};
    while(i<factor_max){
        //confirm first card factor
        if(a%c[i]==0){
            a=a/c[i];
            d[i]=c[i];
        }else{
            i=i+1;
        }
    }
    //choose same common factor card which i can play
    int q=0;
    int p=0;
    int k=0;
    //the array play which i can play 
    int play[CARD_MIN]={0};
    while(p<n){
        q=0;
        while(q<factor_max){
            if(d[q]!=0){
                if(b[p]%d[q]==0){
                    play[p]=b[p];
                }
            }
            q=q+1;
        }
        p=p+1;
    }
    bubble_sort(play,CARD_MIN);
    int w=0;
    //we do not have same factor card
    if(countarray(play)==0){
        if(pri[0]==0){
            printf("%d\n",b[countarray(b)-1]);
        }else{
            printf("%d\n",pri[countarray(pri)-1]);
        }
    }else{
        if(y==1){
            printf("%d\n",play[CARD_MIN-1]);
        }else{
            while(w<CARD_MIN){
                if(play[w]!=0&&play[w]<l){
                    printf("%d\n",play[w]);
                    w=w+100;
                }else if(play[w]!=0&&play[w]<42){
                    printf("%d\n",play[w]);
                    w=w+100;
                }
                w++;
            }
            if(w<100){
                printf("%d\n",play[CARD_MIN-countarray(play)]);
            }
        }
        
    }
}

//choose prime card to play
void chooseprime(int a[],int b[]){
    //if we do not have prime card
    if(a[0]==0){
        printf("%d\n",b[countarray(b)-1]);
    }else{
        printf("%d\n",a[0]);
    }

}

int maximum(int a[],int b){
    int i=0;
    int max=0;
    while(i<b){
        if(max<a[i]){
            max=a[i];
        }
        i++;
    }
    return max;
}