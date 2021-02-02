#include<stdio.h>
#include<stdlib.h>
#define b 20 //teacher
void checkequality_prof(int[],int);
void checkequality_sgap(int[],int);
void checkequality_ssap(int[],int);
void checkequality_asp(int[],int);

static int m=0;                                               //stores the index till when while will be executed
static int s[10];                                                                                        //starting time of exams
static int f[10];
static int remind=0;
int c,del,k=0;
int i,j,prof[20],sgap[20],ssap[20],asp[20];
int profhrs=3, sgaphrs=5, ssaphrs=8, asphrs=12;

int pop=0;
int main()
{
    int p,sg,ss,ap;
    printf("Enter teacher id according to the designations\n");
    printf("Enter the no. of Professors(max 20)\n");
    scanf("%d",&p);
    printf("Enter Ids of Professors\n");
    for(i=0;i<p;i++)
    {
        scanf("%d",&prof[i]);
    }

    checkequality_prof(prof,p);

    printf("Enter the no. of Senior Grade Associate Professor(max 20)\n");
    scanf("%d",&sg);
    printf("Enter IDs Senior Grade Associate Professor\n");
    for(i=0;i<sg;i++)
    {
        scanf("%d",&sgap[i]);
    }

    checkequality_sgap(sgap,sg);


    printf("Enter the no. of Senior Scale Assistant Professor(max 20)\n");
    scanf("%d",&ss);
    printf("Enter IDs Senior Scale Assistant Professor\n");
    for(i=0;i<ss;i++)
    {
        scanf("%d",&ssap[i]);
    }

    checkequality_ssap(ssap,ss);

    printf("Enter the no. of Associate Professor(max 20)\n");
    scanf("%d",&ap);
    printf("Enter IDs Associate Professor\n");
    for(i=0;i<ap;i++)
    {
        scanf("%d",&asp[i]);
    }

    checkequality_asp(asp,ap);

    int x;
     printf("Enter total exams to be conducted\n");
    scanf("%d",&x);
    if(x<=10)
    {
    int k=0;                                                                                                                  //room no's
    for (i=0;i<x;i++)
    {
        printf("Enter starting time of exam:%d\n",(i+1));
        scanf("%d",&s[i]);
        printf("Enter finishing time of exam:%d\n",(i+1));
        scanf("%d",&f[i]);
    }

    printf ("\nFollowing is the schedule\n\n");
    if(b>x)                                      //number of faculty should be greater than number of exams
    {
      int pi=0, qi=0, ri=0, si=0;
      int flag=1;
      int rsi=ap;
      int rpi=p;
      int rqi=sg;
      int rri=ss;
    while(m<x)                                                                                    //till all slots are allocated
    {
      int inde[10];                                                                            //storing indexes to be deleted
      int l=x-1;                                                            //decreasing the size of the array everytime
      int count=0;                                                            //incrementing the location of inde array
      int i=0;						 //for comparison of start time and end time
      printf("\n");
      printf("Room No:%d\n",(k+1));                                               //incrementing room number
      printf("%d-%d\t",s[0],f[0]);
      if(s[0]==f[0])
      {
          printf("Exam Not Possible within given time.");
      }
      else
      {
      for(int ab=0;ab<2;ab++)
              {
      if(si<8)
      {
          si=rand()%rsi;                                                   	 //printing start time and end time
          printf("Faculty ID:%d\t",asp[si]);
          for(int c = si; c < 7; c++)
          asp[c] = asp[c+1];
          rsi--;
      }
      else if(ri<5)
      {
      ri=rand()%rri;
      printf("Faculty ID:%d\t",ssap[ri]);					//printing faculty id
      for(int c = ri; c < 4; c++)
      ssap[c] = ssap[c+1];
      rri--;
      }
      else if(qi<4)
      {
      qi=rand()%rqi;
      printf("Faculty ID:%d\t",sgap[qi]);
      for(int c = qi; c < 3; c++)
          sgap[c] = sgap[c+1];
          rqi--;
      }
      else if(pi<3)
      {
      pi=rand()%rpi;
      printf("Faculty ID:%d\t",prof[pi]);					//printing faculty id
      for(int c = pi; c < 2; c++)
          prof[c] = prof[c+1];
          rpi--;
      }

              }
      }
      m++;                                                   //incrementing till m=x, i.e. till all slots are allocated
      for(j=1;j<x;j++)                                                                     //printing data after comparing
      {
        if(s[j]>=f[i])
        {
            printf("\n");
          printf("%d-%d\t",s[j],f[j]);				     //printing start time and end time
          if(s[j]==f[j])
          {
              printf("Exam Not Possible within given time.");
          }
          else
          {
              for(int ab=0;ab<2;ab++)
              {
              if(flag==1)
              {
                if(ri<5)
                {
           si=rand()%rsi;
            printf("Faculty ID:%d\t",asp[si]);                     

          for(int c = si; c < 7; c++)
          asp[c] = asp[c+1];
          rsi--;
                }
                else if(si<8)
                {                                   
          pi=rand()%rpi;
                  printf("Faculty ID:%d\t",prof[pi]);			//printing faculty id
                  for(int c = pi; c < 2; c++)
          prof[c] = prof[c+1];
          rpi--;
                }
                flag=2;
              }
              else if(flag==2)
              {
                if(qi<4)
               {
               ri=rand()%rri;
               printf("Faculty ID:%d\t",ssap[ri]);				       //printing faculty id
               for(int c = ri; c < 4; c++)
               ssap[c] = ssap[c+1];
               rri--;
                }
               else if(si<8)
               {
               pi=rand()%rpi;
               printf("Faculty ID:%d\t",prof[pi]);		                      //printing faculty id
               for(int c = pi; c < 2; c++)
               prof[c] = prof[c+1];
               rpi--;
               }
                flag=3;
              }
              else if(flag==3)
              {
                if(pi<3)
               {      
             qi=rand()%rqi;
             printf("Faculty ID:%d\t",sgap[qi]);
             for(int c = qi; c < 3; c++)
             sgap[c] = sgap[c+1];
             rqi--;
             }
             else if(si<8)
             {
            int r=2;
            pi=rand()%rpi; //printing faculty id
                    printf("Faculty ID:%d\t",prof[pi++]); 			        //printing faculty id
                    for(int c = pi; c < 2; c++)
          prof[c] = prof[c+1];
          rpi--;
                  }
                flag=4;
              }
              else if(flag==4)
              {
                if(si<8)
                {                                       
                  pi=rand()%rpi;
                  printf("Faculty ID:%d\t",prof[pi]);			//printing faculty id
                  for(int c = pi; c < 2; c++)
          prof[c] = prof[c+1];
          rpi--;
                }
                flag=1;
              }
              }
          }
          i=j;
          ++m;
          inde[count++]=j;                                                               //note the indexes to be deleted
        }									 //end of ab loop
      }
      for(c=0;c<l;c++)                                                                                     //deleting first index
      {
          s[c] = s[c+1];
          f[c] = f[c+1];
      }
      int a=1;
      for(del=0;del<count;del++)                                  //number of middle indexes to be deleted
      {
      for(c=inde[del]-a;c<l-1;c++)                                                                //delete middle indexes
      {
        s[c] = s[c+1];                                                                                       //replacing start time
        f[c] = f[c+1];                                                                                         //replacing end time
      }
      a++;
    }
      k=k+1;                                                                                      //incrementing room number
      l--;                                                                                                      //reducing size of array
    }
  }
    }

}

void checkequality_prof(int prof[3], int nop)   //nop is no. of professors
{
    for(int i=0;i<nop;i++)
    {
        for(int j=i+1;j<nop;j++)
        {
            if(prof[i]==prof[j])
            {
                printf("Ids should be unique\n");
                printf("Enter Ids again\n");
                for(int k=0;k<nop;k++)
                scanf("%d",&prof[k]);
                checkequality_prof(prof,nop);
            }
        }
    }

}


void checkequality_sgap(int sgap[4],int nosg)
{
    for(int i=0;i<nosg;i++)
    {
        for(int j=i+1;j<nosg;j++)
        {
            if(sgap[i]==sgap[j])
            {
                printf("Ids should be unique\n");
                printf("Enter Ids again\n");
                for(int k=0;k<nosg;k++)
                scanf("%d",&sgap[k]);
                checkequality_sgap(sgap,nosg);
            }
        }
    }

}

void checkequality_ssap(int ssap[5],int noss)
{
    for(int i=0;i<noss;i++)
    {
        for(int j=i+1;j<noss;j++)
        {
            if(ssap[i]==ssap[j])
            {
                printf("Ids should be unique\n");
                printf("Enter Ids again\n");
                for(int k=0;k<noss;k++)
                scanf("%d",&ssap[k]);
                checkequality_ssap(ssap,noss);
            }
        }
    }

}


void checkequality_asp(int asp[8],int noap)
{
    for(int i=0;i<noap;i++)
    {
        for(int j=i+1;j<noap;j++)
        {
            if(asp[i]==asp[j])
            {
                printf("Ids should be unique\n");
                printf("Enter Ids again\n");
                for(int k=0;k<noap;k++)
                scanf("%d",&asp[k]);
                checkequality_asp(asp,noap);
            }
        }
    }

}
