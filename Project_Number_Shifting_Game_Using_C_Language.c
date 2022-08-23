#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<windows.h>
// main function
int main()
{
    int arr[5][5];// 5*5 matrix
    int attemptmax=5;// maximum move
    char name[20];
    system(" cls "); //it clear screen
    printf("Beautiful soul, please Enter Your Name: ");
    scanf("%s",name);
    while(24)
    {             Matrixcreate(arr);// calling function to create  matrix
                  gameRule(arr);// game rule function calling

          while(!winner(arr))// checking for winning situation
        {
               system("cls");
               if(!attemptmax)// for remaing zero move
               break;
               printf("\n\n welcome  %s  ,  Move remaining : %d\n\n",name,attemptmax);
               Matrixshow(arr);// show matrix
               int key=readEnteredKey();   // this will return ascii code of user entered key

        switch(key)//maping
        {
            case 69:// ascii of E

            case 101:// ascii of e
                        printf("\a\a\a\a\a\a\n     Thanks for Playing ! \n\a");
                        printf("\nHit 'Enter' to exit the game \n");
                        key=readEnteredKey();
                        exit(0);
            case 72:// arrow up
                        if(shiftUp(arr))
                        attemptmax--;
                        break;
            case 80:// arrow down
                        if(shiftDown(arr))
                        attemptmax--;
                        break;
            case 77:// arrow  right
                        if(shiftRight(arr))
                        attemptmax--;
                        break;
            case 75:// arrow left
                        if(shiftLeft(arr))
                        attemptmax--;
                        break;
            default://  delay(200);
                       printf("\n\n      \a\a Not Allowed \a");

        }
        }
        if(!attemptmax)
         printf("\n\a          YOU LOSE !          \a\a\n");
         else
         { printf("\n\a!!!!!!!!!!!!! Congratualization !!!!!!!!!!!!!\n\a");
           printf("\a               You have Won      \a\a\a ");
         }
         char check;
        printf("\n want to play again ? \n");
        printf("enter 'y' to play again:  ");
        scanf("%c",&check);
        if(check!='y' && check!='Y')
            break;
        attemptmax=500;
    }
    return 0;
}
// create matrix 5*5
void Matrixcreate(int arr[][5])
{
    int n=24;
    int num[n],i,j;
    for(i=0;i<24;i++)// These 1-24 number will be in th matrix
    num[i]=i+1;
    srand(time(NULL));// for random number generation
    int lastIndex=n-1,index;
    for(i=0;i<5;i++)
    for(j=0;j<5;j++)
  {
    if(lastIndex>=0)
    {  index=rand()%(lastIndex+1); // idea : performing % operation by (lastIndex+1)
       arr[i][j]=num[index];       // will give index , so put that num[index] number in matrix
       num[index]=num[lastIndex--]; // and replace last number with this indexed positioned number
    }                               // and finally lastIndex--
  }
       arr[i-1][j-1]=0;// last number is zero

}
// showing matrix
void Matrixshow(int arr[][5])
{
    int i,j;
    printf("-------------------------\n");
    for(i=0;i<5;i++)
   { printf("|");
       for(j=0;j<5;j++)
    {   if(arr[i][j]!=0)
        printf("%-2d | ",arr[i][j]);
        else
        printf("   | ");
    }
    printf("\n");
   }

    printf("-------------------------\n");
}
// winning check function
int winner(int arr[][5])
{
    int i,j,k=1;
    for(i=0;i<5;i++)
   { for(j=0;j<5;j++,k++)
        if(arr[i][j]!=k && k!=25)
        break;
    if(j<5)
    break;
   }
        if(j<5)
        return 0;
        return 1;
}
// swap function to swap two numbers
void swap(int *x,int *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
    printf("");
}
// Reads the user input character and return ascii value of that
int readEnteredKey()
{
    char c;
    c=_getch();
    if(c==-32)
    c=_getch();
    return c;
}
// shift up function
int shiftUp(int arr[][5])
{
    int i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
            if(arr[i][j]==0)
            break;
        if(j<5)
        break;
    }
      if(i==3)// shifting not possible
        return 0;
        swap(&arr[i][j],&arr[i+1][j]);// swap numbers
        return 1;// shift up success
}
// shift Down function
int shiftDown(int arr[][5])
{
    int i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
            if(arr[i][j]==0)
            break;
        if(j<5)
        break;
    }
      if(i==0)// shifting not possible
        return 0;
         swap(&arr[i][j],&arr[i-1][j]);// swap numbers

        return 1;// shift down success
}
// shift right function
int shiftRight(int arr[][5])
{
    int i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
            if(arr[i][j]==0)
            break;
        if(j<5)
        break;
    }
      if(j==0)// shifting not possible
        return 0;
             swap(&arr[i][j],&arr[i][j-1]);

        return 1;// shift right success
}
// shift left function
int shiftLeft(int arr[][5])
{
    int i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
            if(arr[i][j]==0)
            break;
        if(j<5)
        break;
    }
      if(j==3)                 // shifting not possible
        return 0;
                swap(&arr[i][j],&arr[i][j+1]);
        return 1;               // shift left success
}
// Game rules
void gameRule(int arr[][5])
{
    system("cls");
    int i,j,x,k=1,f=178,y=24,z=25,a=26,b=27;
printf("_____________________________RULES OF THE GAME_________________________________\n");
printf("1.You can move only 1 step at a time by arrow key on your keyword\n ");
printf("\nMove Up   : by UP arrow ( %c ) key\n",y);
printf("Move Down : by Down arrow ( %c ) key\n",z);
printf("Move Left : by Left arrow ( %c ) key\n",a);
printf("Move Right: by Right arrow ( %c ) key\n",b);
printf("\n2.You can move number at any empty position\n");
printf("\n3. For each valid move : your total number of moves will be decreased by 1");
printf("4.Wining situation : ");
printf("number in a 5*5 matrix should be in order from 1 to 24 ");
printf("\n\n            winning situation:         \n");

    printf("--------------------------\n");
    for(i=0;i<5;i++)
   { printf("| ");
       for(j=0;j<5;j++)
    {   if(arr[i][j]!=0)
        printf("%-2d | ",5*i+j+1);
        else
        printf("   |");
    }
    printf("\n");
   }

    printf("--------------------------\n");
    printf("\n5.You can exit the game at any time by pressing 'E' or 'e' ");


    printf("\nSo Try to win in minimum no of move \n");
    printf("\nEnter any key to start.....   ");
    x   =   readEnteredKey();
}



