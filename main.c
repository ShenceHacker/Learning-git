#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 30
void Recorddata(int ID[],int score[],int n);
void Desecending(int score[],int ID[],int n);
void Ascending1(int score[],int ID[],int n);
void Ascending2(int ID[],int score[],int n);
void Search(int ID[],int score[],int n);
void Classify(int score[],int n);
double Ave(int score[],int n);
int Tot(int score[],int n);

int main()
{
    printf("Number:200210404\nName:唐超翔\nProgram5-Experiment1\n");
    int score[N],ID[N],choice,i,n;
    double averagescore,totalscore;

    do
    {
        printf("1.Input record\n2.Calculate total and average score of course\n3.Sort in desecending order by score\n4.Sort in ascending order by score\n");
        printf("5.Sort in ascending order by students'ID\n6.Search by students'ID\n7.Statistic analysis\n8.List record\n9.exit\n\n");
        printf("Please enter your choice:\n");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("How many are the students?\n");
            scanf("%d",&n);
            printf("Please input the students'ID and score,format as (2020111 89)\n");
            Recorddata(ID,score,n);
            printf("Have stored the data successfully,thanks!\n\n\n");


        }
        else if(choice==2)
        {
            averagescore=Ave(score,n);
            totalscore=Tot(score,n);
            printf("The total number is %lf,the averagenumber is %lf\n",totalscore,averagescore);
        }
        else if(choice==3)
        {
            Desecending(score,ID,n);
            for (i=0; i<=n-1; i++)
            {
                printf("%d %d\n",ID[i],score[i]);

            }
        }
        else if(choice==4)
        {
            Ascending1(score,ID,n);
            for (i=0; i<=n-1; i++)
            {
                printf("%d %d\n",ID[i],score[i]);

            }
        }

    else if(choice==5)
    {
        Ascending2(ID,score,n);
        for (i=0; i<=n-1; i++)
        {
            printf("%d %d\n",ID[i],score[i]);

        }
    }

else if(choice==6)
{
    Search(ID,score,n);

}
else if(choice==7)
{
    Classify(score,n);
}
else if(choice==8)
{
    for (i=0; i<=n-1; i++)
    {
        printf("%d %d\n",ID[i],score[i]);

    }
}

} while(choice!=9);

printf("quit the program");





}



void Recorddata(int ID[],int score[],int n)
{
    int i;
    for(i=0; i<=n-1; i++)
    {
        scanf("%d %d",&ID[i],&score[i]);
    }


}



double Ave(int score[],int n)
{
    int i,y=0;
    double m;
    for(i=0; i<=n-1; i++)
    {
        y+=score[i];
    }
    m=y/n;
    return m;

}



int Tot(int score[],int n)
{
    int y=0;
    int i;
    for(i=0; i<=n-1; i++)
    {
        y+=score[i];
    }
    return y;
}



void Desecending(int score[],int ID[],int n)
{
    int i,j,t;
    for(i=0; i<=n-2; i++)
        for(j=i+1; j<=n-1; j++)
            if (score[i]<score[j])
                t=score[i],score[i]=score[j],score[j]=t,
                                                      t=ID[i],ID[i]=ID[j],ID[j]=t;
}



void Ascending1(int score[],int ID[],int n)
{
    int i,j,t;
    for(i=0; i<=n-2; i++)
        for(j=i+1; j<=n-1; j++)
            if (score[i]>=score[j])
                t=score[i],score[i]=score[j],score[j]=t,
                                                      t=ID[i],ID[i]=ID[j],ID[j]=t;
}



void Ascending2(int ID[],int score[],int n)
{
    int i,j,t;
    for(i=0; i<=n-2; i++)
        for(j=i+1; j<=n-1; j++)
            if (ID[i]>=ID[j])
                t=ID[i],ID[i]=ID[j],ID[j]=t,
                                          t=score[i],score[i]=score[j],score[j]=t;


}



void Search(int ID[],int score[],int n)
{
    int i,c;
    printf("Please input the number of the student whoes grade you want to search:\n");
    scanf("%d",&i);
    for(c=0; c<=n-1; c++)
    {
        if(i==ID[c])
        {
            printf("the grade of the student is:%d\n\n\n",score[c]);
        }
    }
}



void Classify(int score[],int n)
{
    int i;
    double y1=0,y2=0,y3=0,y4=0,y5=0;
    for(i=0; i<=n-1; i++)
    {
        if(score[i]>=90)
        {
            y1++;
        }
        else if(score[i]>=80)
        {
            y2++;
        }
        else if(score[i]>=70)
        {
            y3++;
        }
        else if(score[i]>=60)
        {
            y4++;
        }
        else
        {
            y5++;
        }
    }
    y1=y1/n;
    y2=y2/n;
    y3=y3/n;
    y4=y4/n;
    y5=y5/n;
    printf("Excellent rate is %lf\nGood rate is %lf\nMid rate is %lf\nPassed rate is %lf\nUnpassed rate is %lf\n\n",y1,y2,y3,y4,y5);
}

