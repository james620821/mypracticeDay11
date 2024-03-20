#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

void find_different__num(void);
void check_sheet_num(void);
void exchange_num(void);
void Linear_Cong_Gen(void);
int my_rand(void);
//影片19-8 自定義亂數函式
void my_srand(unsigned int);
static unsigned int _next=1; //加上static表示只有這個檔案內可以用
//靜態的(static)區域變數<--只會初始化一次
int count(void)
{
    static int k=0;
    k++;
    return k;
}
int main()
{
    srand(time(0));
    my_srand(time(0));
    //teacher's code
    //產生不重複亂數
    //影片19 搜索法
    //find_different__num();
    //影片19-1 建表法
    //check_sheet_num();
    //影片19-2 交換法
    //exchange_num();
    /*
    for (int i =1; i<=5; i++)
    {
        printf("%d\n", count()); //1 2 3 4 5
    }
    */
    //影片19-5 整數的溢位
    /*
    unsigned int a=1000;
    unsigned int c=a*a*a*a;
    //無號整數的溢位<<不是>>未定義行為
    printf("%u\n", c);// 1000000000000 % (UINT_MAX+1)
    printf("%u\n", UINT_MAX);
    */
    //影片19-6 自行生僞亂數
    //線性同餘法(Linear congruential generator)
    //Xn+1 = (Xn*a+c)%m <--實際應用上 a,c,m需要設計，不是隨便亂挑的
    //Linear_Cong_Gen();
    for(int i=0; i<5; i++)
    {
       printf("%d\n", my_rand());
    }
    return 0;
}
void my_srand(unsigned int seed)
{
    _next = seed;
}

int my_rand(void)
{
    _next=_next *1103515245 + 12345;
    return (_next/65536)%32768;
}
void Linear_Cong_Gen()
{
    unsigned int x=1;
    int i;
    for (i=0; i<5; i++)
    {
        x=x*1103515245+12345; //Xn+1 = (Xn*1103515245+12345)%(UINT_MAX+1)
        int rand =(unsigned int) (x/65536)%32768; //xooooooo oooooooo xxxxxxxx xxxxxxxx
        printf("%u\n",x);
        printf("%d\n",rand); //rand為取x bit30~bit16的數字
    }
}
void exchange_num()
{
    int i, j, n[10]={0};
    for (i=1; i<=10; i++)
    {
        n[i-1]=i;
    }
    for (i=0; i<10; i++)
    {
        j=rand()%(10-i)+i;
        int t=n[i];
        n[i]=n[j];
        n[j]=t;
        printf("%d ",n[i]);
    }

}
void check_sheet_num()
{
    int i,n,count[10]={0};
    for (i=0; i<10; i++)
    {
        do
        {
            n = rand()%10+1;
        }while(count[n-1] != 0);
        printf("%d ",n);
        count[n-1]++;
    }
}
void find_different__num()
{
    int i,j,n[10]={0};
    for (i=0; i<10; i++)
    {
        do
        {
            n[i] = rand()%10+1;
            for (j=0; j<i; j++)
            {
                if(n[j] == n[i])
                {
                    break;
                }
            }
        }while(j < i);
        printf("%d ",n[i]);
    }
}
