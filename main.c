#include <stdio.h>
#include<conio.h>
#include<stdlib.h> 
 char arr[9]={'0','1','2','3','4','5','6','7','8'};
 int temparr[9]={-1,-1,-1,-1,-1,-1,-1,-1,-1};
 int turn=0;
 int player;
 int choice;
 int win=0;
 int condition=0;
int main() //main begin
{

    while((win!=1)&&(turn!=9))
    {
    MoreThanEight: //Goto's Label
    system("cls");
    printf("================Tic-Tac-Toe==============\n\n");
    board_print();
    if((turn%2)==0)
        player=1; //First Player
    else
        player=2;// Second Player


    printf("Player %d Turn, Select the Position:  ",player);
    scanf("%d",&choice);
    if(choice>8)
     {
        printf("Wrong Choice Try Again .. Press any Key: ");
        getch();
        goto MoreThanEight;
    }
    //This for loop is going to be used for checking if the space is vacant or not
    for(int i=0;i<=8;i++)
    {
        if(choice==temparr[i])
            {condition=1;//Already Present
            break;}
        if(temparr[i]==-1)
            {
            temparr[i]=choice;//Was not present and hence added to the list
            condition=0;
            break;
            }
        //else continue;
    }
    if((player==1)&&(condition==0))
        arr[choice]='O';
    else if((player=2)&&(condition==0))
        arr[choice]='X';
    else if(condition==1)
    {printf("\nWrong_Choice-press any key to continue\n");
    getch();
    continue;
    }
    //Now Checking For A Win:
    win=check();
    //printf("Value Of Win: %d   Press any key to continue",win);
    //getch();
    //if(win!=0)
      //  break;
    turn++;
    system("cls");
    }
    system("cls");
    board_print();
    if(win!=0)
        printf("Player %d Won",player);
    else
    printf("Its A tie");
    getch();
    return 0;
}
void board_print()
{
    printf("\t\t%c | %c | %c",arr[0],arr[1],arr[2]);
    printf("\n\t\t__|___|__\n");
    printf("\t\t%c | %c | %c",arr[3],arr[4],arr[5]);
    printf("\n\t\t__|___|__\n");
    printf("\t\t%c | %c | %c",arr[6],arr[7],arr[8]);
    printf("\n\n");
}

int check()
{
    //diagonal

    if((arr[0]==arr[4])&&(arr[4]==arr[8]))   //Lesson Learned: x===y==z doesn't works!..This Works: if((x==y)&&(y==z))
        return 1;
    else if((arr[2]==arr[4])&&(arr[4]==arr[6]))
        return 1;
    // Horizontal
    else if((arr[0]==arr[1])&&(arr[1]==arr[2]))
        return 1;
    else if((arr[3]==arr[4])&&(arr[4]==arr[5]))
        return 1;
    else if((arr[6]==arr[7])&&(arr[7]==arr[8]))
        return 1;
    //Verical
    else if((arr[0]==arr[3])&&(arr[3]==arr[6]))
        return 1;
    else if((arr[1]==arr[4])&&(arr[4]==arr[7]))
        return 1;
    else if((arr[2]==arr[5])&&(arr[5]==arr[8]))
        return 1;
else
return 0;
}
