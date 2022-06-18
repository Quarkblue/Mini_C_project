#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define true 1

char board[100][100];
int i,j,h=6,w=7,turns=0;
char pce,p1='X',p2='O';
int k[100];
void Start()
{
    for(i=0;i<w;i++)
    {
        k[i]=5;
    }
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            board[i][j]='_';
        }
    }
}
void Board()
{
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
    for(int i=1;i<=w;i++)
    {
        printf("%d ",i);
    }
    printf("\n");
}
int wcheck(int x,int y,char tok)
{
    int count=0,t1,t2;
    //horizontal
    t1=y+1;count=0;
    while(t1<w && board[x][t1]==tok)
    {
        count++;
        t1++;
    }
    t1=y-1;
    while(t1>=0 && board[x][t1]==tok)
    {
        count++;
        t1--;
    }
    if(count>=3)
        return 1;
    //vertical
    t1=x+1;count=0;
    while(t1<h && board[t1][y]==tok)
    {
        count++;
        t1++;
    }
    t1=x-1;
    while(t1>=0 && board[t1][y]==tok)
    {
        count++;
        t1--;
    }
    if(count>=3)
        return 1;
    //first diagonal
    t1=x+1;t2=y+1;count=0;
    while(t1<h && t2<w && board[t1][t2]==tok)
    {
        count++;
        t1++;t2++;
    }
    t1=x-1;t2=y-1;
    while(t1>=0 && t2>=0 && board[t1][t2]==tok)
    {
        count++;
        t1--;t2--;
    }
    if(count>=3)
        return 1;
    //second diagonal
    t1=x-1;t2=y+1;count=0;
    while(t1>=0 && t2<w  && board[t1][t2]==tok)
    {
        count++;
        t1--;t2++;
    }
    t1=x+1;t2=y-1;
    while(t1<h && t2>=0 && board[t1][t2]==tok)
    {
        count++;
        t1++;t2--;
    }
    if(count>=3)
        return 1;
    else
        return 0;
}
void Input()
{
    int g_o=0,one,two,row,r,c;
    while(g_o==0)
    {
        if(turns%2==0)
        {
            printf("Player 1's Turn.\n");
            Board();
            scanf("%d",&one);
            if(one>0 && one<=w && k[one-1]>=0)
            {
                row=k[one-1];
                board[row][one-1]=p1;
                k[one-1]--;
                r=row;c=one-1;
                turns++;
                pce=p1;
            }
            else
            {
                printf("Invalid input try again.\n");
                continue;
            }
        }
        else
        {
            printf("Player 2's Turn.\n");
            Board();
            scanf("%d",&two);
            if(two>0 && two<=w && k[two-1]>=0)
            {
                row=k[two-1];
                board[row][two-1]=p2;
                k[two-1]--;
                r=row;c=two-1;
                turns++;
                pce=p2;
            }
            else
            {
                printf("Invlaid input try again.\n");
                continue;
            }
        }
        if(wcheck(r,c,pce)==1)
        {
            g_o=1;
            Board();
        }
    }
}
int main()
{
    while(true)
    {
        int y_n=0;
        printf("Welcome to Connect 4!\n");
        Start();
        Input();
        if(turns==h*w)
        {
            printf("It's a Draw you both suck!\n");
        }
        else if(pce=='O')
        {
            printf("Player 2 Wins!\n");
        }
        else if(pce=='X')
        {
            printf("Player 1 Wins!\n");
        }
        printf("Would you like to play again? 1 or 0\n");
        scanf("%d",&y_n);
        if(y_n!=1)
        {
            printf("Goodbye!\n");
            break;
        }
        else{
            printf("\nPlaying again!\n");
        }
    }
    getch();
    return 0;
}