#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int x,y,i=0,h,win=0,num;
    char first[6][7],fi[20],si[20],second[10][10],ready[10],pro,k=1,third[9][9],forth[3][3],rx,ry,sen[10];
    int key[7]={0,0,0,0,0,0,0},n,o,m=1,sfi=0,ssi=0,sec,line,p,d,j,count=0;;
    FILE *fp;
    printf("WELLCOME TO OXY GAME \n");
    printf("Add the name of player 1: ");
    scanf("%s",fi);
    printf("Add the name of player 2: ");
    scanf("%s",si);
    while(1)
    {
        printf("Choose (1) for four stars game, (2) for O-X game, (3) for Super O-X game, (4) for stopping and counting points: ");
        scanf("%s",sen);
        if(strcmp(sen,"1")==0)
        {
            ready[0]='T';
            while(strcmp(ready,"R")!=0)//choose that you want tutorials or not
            {
                printf("Choose A for non-tutorials, B for tutorials: ");
                while(strcmp(ready,"A")!=0)
                {
					scanf("%s",ready);
                	if(strcmp(ready,"B")==0)
                	{
                    printf("1. Player 1 choose the column to add a coin by putting a number of column which you want.\n");
                    printf("2. Player 2 choose the column to add a coin by putting a number of column which you want.\n");
                    printf("3. Following step 1&2 until one player can set 4 coins to be straight line (can be horizontal, vertical or crosswise) and the player will win this game. \n\n\n\n");
                    printf("LET’S ENJOY :)\n\n\n\n");
                	}
                	else if(strcmp(ready,"A")!=0)
                	{
                	printf("Enter again\n");
					}
				}
				while(strcmp(ready,"R")!=0)
				{
                	printf("If you ready please ENTER (R) If not ENTER (N) : ");
                	scanf("%s",ready);
                	if(strcmp(ready,"N")==0)
                	{
                    printf("Not ready?\n");
                    printf("1. Player 1 choose the column to add a coin by putting a number of column which you want.\n");
                    printf("2. Player 2 choose the column to add a coin by putting a number of column which you want.\n");
                    printf("3. Following step 1&2 until one player can set 4 coins to be straight line (can be horizontal, vertical or crosswise) and the player will win this game. \n\n\n\n");
                	}
                	else if(strcmp(ready,"R")!=0)
                	{
                	printf("Enter again\n");
					}
				}
        	}
            m=1;
            for(y=5;y>=0;y--)//make the intitial table
            {
                for(x=0;x<7;x++)
                {
                    if(y==5&&x==0)
                    {
                        printf("1 2 3 4 5 6 7\n");
                    }
                    first[x][y]='.';
                    printf("%c ",first[x][y]);
                }
                printf("\n");
            }
            for(i=0;m==1;i++)//playing loop
            {
                if(i%2==0)//input the line you want
                {
                    printf("%s's turn: ",fi);
                    scanf("%d",&n);
                    first[n-1][key[n-1]]='o';
                }
                if(i%2==1)
                {
                    printf("%s's turn: ",si);
                    scanf("%d",&n);
                    first[n-1][key[n-1]]='x';
                }
                if((first[n-1][key[n-1]]==first[n-1][key[n-1]-1])&&(first[n-1][key[n-1]-1]==first[n-1][key[n-1]-2])&&(first[n-1][key[n-1]-3]==first[n-1][key[n-1]-2]))
                {
                    m=0;
                    first[n-1][key[n-1]]='G';
                    first[n-1][key[n-1]-1]='O';
                    first[n-1][key[n-1]-2]='A';
                    first[n-1][key[n-1]-3]='L';
                }
                for(p=4;p>=1;p--)
                {
                    if((first[n-p][key[n-1]]==first[n-(p-1)][key[n-1]])&&(first[n-(p-1)][key[n-1]]==first[n-(p-2)][key[n-1]])&&(first[n-(p-2)][key[n-1]]==first[n-(p-3)][key[n-1]]))
                    {
                        m=0;
                        first[n-p][key[n-1]]='G';
                        first[n-(p-1)][key[n-1]]='O';
                        first[n-(p-2)][key[n-1]]='A';
                        first[n-(p-3)][key[n-1]]='L';
                    }
                    if((first[n-(p-3)][key[n-1]+(4-p)]==first[n-(p-2)][key[n-1]+(3-p)])&&(first[n-(p-2)][key[n-1]+(3-p)]==first[n-(p-1)][key[n-1]+(2-p)])&&(first[n-(p-1)][key[n-1]+(2-p)]==first[n-p][key[n-1]+(1-p)]))
                    {
                        m=0;
                        first[n-(p-3)][key[n-1]+(4-p)]='G';
                        first[n-(p-2)][key[n-1]+(3-p)]='O';
                        first[n-(p-1)][key[n-1]+(2-p)]='A';
                        first[n-p][key[n-1]+(1-p)]='L';
                    }
                }
                if((first[n-1][key[n-1]]==first[n][key[n-1]-1])&&(first[n][key[n-1]-1]==first[n+1][key[n-1]-2])&&(first[n+1][key[n-1]-2]==first[n+2][key[n-1]-3]))
                {
                    m=0;
                    first[n-1][key[n-1]]='G';
                    first[n][key[n-1]-1]='O';
                    first[n+1][key[n-1]-2]='A';
                    first[n+2][key[n-1]-3]='L';
                }
                if((first[n-2][key[n-1]+1]==first[n-1][key[n-1]])&&(first[n-1][key[n-1]]==first[n][key[n-1]-1])&&(first[n][key[n-1]-1]==first[n+1][key[n-1]-2]))
                {
                    m=0;
                    first[n-2][key[n-1]+1]='G';
                    first[n-1][key[n-1]]='O';
                    first[n][key[n-1]-1]='A';
                    first[n+1][key[n-1]-2]='L';
                }
                if((first[n][key[n-1]-1]==first[n-1][key[n-1]])&&(first[n-1][key[n-1]]==first[n-2][key[n-1]]+1)&&(first[n-2][key[n-1]+1]==first[n-3][key[n-1]+2]))
                {
                    m=0;
                    first[n-3][key[n-1]+2]='G';
                    first[n-2][key[n-1]+1]='O';
                    first[n-1][key[n-1]]='A';
                    first[n][key[n-1]-1]='L';
                }
                if((first[n-1][key[n-1]]==first[n-2][key[n-1]+1])&&(first[n-2][key[n-1]+1]==first[n-3][key[n-1]+2])&&(first[n-3][key[n-1]+2]==first[n-4][key[n-1]+3]))
                {
                    m=0;
                    first[n-4][key[n-1]+3]='G';
                    first[n-3][key[n-1]+2]='O';
                    first[n-2][key[n-1]+1]='A';
                    first[n-1][key[n-1]]='L';
                }
                if((first[0][5]!='.')&&(first[1][5]!='.')&&(first[2][5]!='.')&&(first[3][5]!='.')&&(first[4][5]!='.')&&(first[5][5]!='.')&&(first[6][5]!='.'))
                {
                    m=2;
                    printf("DRAW");
                    sfi++;
                    ssi++;
                }
                printf("%d %d   ",i,m);
                system("CLS");
                for(y=5;y>=0;y--)
                {
                    for(x=0;x<7;x++)
                    {
                        if(y==5&&x==0)
                        {
                            printf("1 2 3 4 5 6 7\n");
                        }
                        printf("%c ",first[x][y]);
                    }
                    printf("\n");
                }
                key[n-1]++;
            }
            if(m==0)
            {
                if(i%2==0)
                {
                    printf("%s W I N \n",si);
                    ssi++;
                }
                else if(i%2==1)
                {
                    printf("%s W I N \n",fi);
                    sfi++;
                }
            }
            for(i=0;i<7;i++)
            {
                key[i] = 0;
            }
        }
        else if(strcmp(sen,"2")==0)
        {
            ready[0]='T';
            while(strcmp(ready,"R")!=0)//choose that you want tutorials or not
            {
                printf("Choose A for non-tutorials, B for tutorials: ");
                while(strcmp(ready,"A")!=0)
                {
					scanf("%s",ready);
                	if(strcmp(ready,"B")==0)
                	{
                    printf("1. Have a decision with your partners and choose the size of table that you want to play ( 3x3, 4x4, 5x5, ...., 9x9 ) by putting a number of size of table ex:3\n");
                    printf("2. Have a decision with your partners again for choosing amount of consecutive variables ( O & X ) to win\n");
                    printf("   Table 3x3 and 4x4 -> can choose only 3\n   Table 5x5 ,6x6 and 7x7 -> can choose 3,4\n   Table 8x8 and 9x9 -> can choose only 3,4,5\n");
                    printf("3. Player 1 add an variable in the table by putting coordinate which you want ex:3 2 (has space bar)\n");
                    printf("4. Player 2 add an variable in the table by putting coordinate which you want ex:3 2 (has space bar)\n");
                    printf("5. Following step 3&4 until one player can set variables to be straight line (can be horizontal, vertical or crosswise) and the player will win this game.\n\n\n");
                    printf("LET’S ENJOY :)\n\n\n\n");
                	}
                	else if(strcmp(ready,"A")!=0)
                	{
                	printf("Enter again\n");
					}
				}
				while(strcmp(ready,"R")!=0)
				{
                	printf("If you ready please ENTER (R) If not ENTER (N) : ");
                	scanf("%s",ready);
                	if(strcmp(ready,"N")==0)
                	{
                    printf("Not ready?\n");
                    printf("1. Have a decision with your partners and choose the size of table that you want to play ( 3x3, 4x4, 5x5, ...., 9x9 ) by putting a number of size of table ex:3\n");
                    printf("2. Have a decision with your partners again for choosing amount of consecutive variables ( O & X ) to win\n");
                    printf("   Table 3x3 and 4x4 -> can choose only 3\n   Table 5x5 ,6x6 and 7x7 -> can choose 3,4\n   Table 8x8 and 9x9 -> can choose only 3,4,5\n");
                    printf("3. Player 1 add an variable in the table by putting coordinate which you want ex:3 2 (has space bar)\n");
                    printf("4. Player 2 add an variable in the table by putting coordinate which you want ex:3 2 (has space bar)\n");
                    printf("5. Following step 3&4 until one player can set variables to be straight line (can be horizontal, vertical or crosswise) and the player will win this game.\n\n\n");
                	}
                	else if(strcmp(ready,"R")!=0)
                	{
                	printf("Enter again\n");
					}
				}
            }
            printf("choose OX table size (3 to 9) : ");
            scanf("%d",&sec);
            printf("choose consecutive variable : ");
            scanf("%d",&line);
            m=1;
            for(y=sec-1;y>=0;y--)
            {
                if(y==sec-1)
                {
                    for(num=0;num<=sec;num++)
                    {
                        printf("%d ",num);
                        if(num==sec)
                        {
                            printf("\n");
                        }
                    }
                }
                for(x=0;x<sec;x++)
                {
                    if(x==0)
                    {
                        printf("%d ",y+1);
                    }
                    second[x][y]='.';
                    printf("%c ",second[x][y]);
                }
                printf("\n");
            }
            for(i=0;m==1;i++)//playing loop
            {
                while(k==1)//choosethe intercept
                {
                    if(i%2==0)
                    {
                        printf(" %s's turn: ",fi);
                        scanf("%d %d",&n,&o);
                    }
                    else if(i%2==1)
                    {
                        printf(" %s's turn: ",si);
                        scanf("%d %d",&n,&o);
                    }
                    if(second[n-1][o-1]=='.')
                    {
                        if(i%2==0)
                        {
                            second[n-1][o-1]='o';
                        }
                        else if(i%2==1)
                        {
                            second[n-1][o-1]='x';
                        }
                        k=0;
                    }
                    else
                    {
                        printf("This spot was choosen");
                    }
                }
                if(line==3)//check the 3 connection
                {
                    for(p=3;p>=1;p--)
                    {
                        if(second[n-1][o-(p-2)]==second[n-1][o-(p-1)]&&second[n-1][o-(p-1)]==second[n-1][o-p])
                        {
                            m=0;
                            second[n-1][o-(p-2)]='w';
                            second[n-1][o-(p-1)]='o';
                            second[n-1][o-p]='w';
                        }
                        if(second[n-(p-2)][o-1]==second[n-(p-1)][o-1]&&second[n-(p-1)][o-1]==second[n-p][o-1])
                        {
                            m=0;
                            second[n-(p-2)][o-1]='w';
                            second[n-(p-1)][o-1]='o';
                            second[n-p][o-1]='w';
                        }
                        if(second[n-(p-2)][o-(p-2)]==second[n-(p-1)][o-(p-1)]&&second[n-(p-1)][o-(p-1)]==second[n-p][o-p])
                        {
                            m=0;
                            second[n-(p-2)][o-(p-2)]='w';
                            second[n-(p-1)][o-(p-1)]='o';
                            second[n-p][o-p]='w';
                        }
                    }
                    if(second[n-1][o-1]==second[n][o-2]&&second[n-1][o-1]==second[n+1][o-3])
                    {
                        m=0;
                        second[n-1][o-1]='w';
                        second[n][o-2]='o';
                        second[n+2][o-3]='w';
                    }
                    if(second[n-1][o-1]==second[n-2][o]&&second[n-1][o-1]==second[n][o-2])
                    {
                        m=0;
                        second[n-2][o]='w';
                        second[n-1][o-1]='o';
                        second[n][o-2]='w';
                    }
                    if(second[n-1][o-1]==second[n-3][o+1]&&second[n-1][o-1]==second[n-2][o])
                    {
                        m=0;
                        second[n-3][o+1]='w';
                        second[n-2][o]='o';
                        second[n-1][o-1]='w';
                    }
                }
                if(line==4&&sec!=3&&sec!=4)//check the 4 connection
                {
                    for(p=4;p>=1;p--)
                    {
                        if((second[n-p][o-1]==second[n-(p-1)][o-1])&&(second[n-(p-1)][o-1]==second[n-(p-2)][o-1])&&(second[n-(p-2)][o-1]==second[n-(p-3)][o-1])&&(second[n-(p-3)][o-1]!='.'))
                        {
                            m=0;
                            second[n-p][o-1]='G';
                            second[n-(p-1)][o-1]='O';
                            second[n-(p-2)][o-1]='A';
                            second[n-(p-3)][o-1]='L';
                        }
                        if((second[n-1][o-p]==second[n-1][o-(p-1)])&&(second[n-1][o-(p-1)]==second[n-1][o-(p-2)])&&(second[n-1][o-(p-2)]==second[n-1][o-(p-3)])&&(second[n-1][o-(p-2)]!='.'))
                        {
                            m=0;
                            second[n-1][o-p]='L';
                            second[n-1][o-(p-1)]='A';
                            second[n-1][o-(p-2)]='O';
                            second[n-1][o-(p-3)]='G';
                        }
                        if((second[n-(p-3)][o-(p-3)]==second[n-(p-2)][o-(p-2)])&&(second[n-(p-2)][o-(p-2)]==second[n-(p-1)][o-(p-1)])&&(second[n-(p-1)][o-(p-1)]==second[n-p][o-p])&&(second[n-(p-1)][o-(p-1)]!='.'))
                        {
                            m=0;
                            second[n-(p-3)][o-(p-3)]='L';
                            second[n-(p-2)][o-(p-2)]='A';
                            second[n-(p-1)][o-(p-1)]='O';
                            second[n-p][o-p]='G';
                        }
                    }
                    if((second[n-1][o-1]==second[n-2][o])&&(second[n-2][o]==second[n-3][o+1])&&(second[n-3][o+1]==second[n-4][o+2])&&(second[n-3][o+1]!='.'))
                    {
                        m=0;
                        second[n-1][o-1]='L';
                        second[n-2][o]='A';
                        second[n-3][o+1]='O';
                        second[n-4][o+2]='G';
                    }
                    if((second[n-1][o-1]==second[n-2][o])&&(second[n-2][o]==second[n-3][o+1])&&(second[n-3][o+1]==second[n][o-2])&&(second[n-3][o+1]!='.'))
                    {
                        m=0;
                        second[n][o-2]='L';
                        second[n-1][o-1]='A';
                        second[n-2][o]='O';
                        second[n-3][o+1]='G';
                    }
                    if((second[n-1][o-1]==second[n-2][o])&&(second[n-2][o]==second[n+1][o-3])&&(second[n+1][o-3]==second[n][o-2])&&(second[n+1][o-3]!='.'))
                    {
                        m=0;
                        second[n+1][o-3]='L';
                        second[n][o-2]='A';
                        second[n-1][o-1]='O';
                        second[n-2][o]='G';
                    }
                    if((second[n-1][o-1]==second[n+2][o-4])&&(second[n+2][o-4]==second[n+1][o-3])&&(second[n+1][o-3]==second[n][o-2])&&(second[n+1][o-3]!='.'))
                    {
                        m=0;
                        second[n+2][o-4]='L';
                        second[n+1][o-3]='A';
                        second[n][o-2]='O';
                        second[n-1][o-1]='G';
                    }
                }
                if(line==5&&(sec==8||sec==9))//check the 5 connection
                {
                    if((second[n-1][o-1]==second[n][o-2])&&(second[n][o-2]==second[n+1][o-3])&&(second[n+1][o-3]==second[n+2][o-4])&&(second[n+2][o-4]==second[n+3][o-5])&&(second[n-1][o-1]!='.'))
                    {
                        m=0;
                        second[n-1][o-1]='G';
                        second[n][o-2]='R';
                        second[n+1][o-3]='E';
                        second[n+2][o-4]='A';
                        second[n+3][o-5]='T';
                    }
                    if((second[n-1][o-1]==second[n][o-2])&&(second[n][o-2]==second[n+1][o-3])&&(second[n+1][o-3]==second[n+2][o-4])&&(second[n+2][o-4]==second[n-2][o])&&(second[n-1][o-1]!='.'))
                    {
                        m=0;
                        second[n-2][o]='G';
                        second[n-1][o-1]='R';
                        second[n][o-2]='E';
                        second[n+1][o-3]='A';
                        second[n+2][o-4]='o';
                    }
                    if((second[n-1][o-1]==second[n][o-2])&&(second[n][o-2]==second[n+1][o-3])&&(second[n+1][o-3]==second[n-3][o+1])&&(second[n-3][o+1]==second[n-2][o])&&(second[n-1][o-1]!='.'))
                    {
                        m=0;
                        second[n-3][o+1]='G';
                        second[n-2][o]='R';
                        second[n-1][o-1]='E';
                        second[n][o-2]='A';
                        second[n+1][o-3]='p';
                    }
                    if((second[n-1][o-1]==second[n][o-2])&&(second[n][o-2]==second[n-4][o+2])&&(second[n-4][o+2]==second[n-3][o+1])&&(second[n-3][o+1]==second[n-2][o])&&(second[n-1][o-1]!='.'))
                    {
                        m=0;
                        second[n-4][o+2]='G';
                        second[n-3][o+1]='R';
                        second[n-2][o]='E';
                        second[n-1][o-1]='A';
                        second[n][o-2]='q';
                    }
                    if((second[n-5][o+3]==second[n-4][o+2])&&(second[n-1][o-1]==second[n-2][o])&&(second[n-4][o+2]==second[n-3][o+1])&&(second[n-3][o+1]==second[n-2][o])&&(second[n-1][o-1]!='.'))
                    {
                        m=0;
                        second[n-5][o+3]='G';
                        second[n-4][o+2]='R';
                        second[n-3][o+1]='E';
                        second[n-2][o]='A';
                        second[n-1][o-1]='r';
                    }
                    for(p=5;p>=1;p--)
                    {
                        if((second[n-(p-4)][o-(p-4)]==second[n-(p-3)][o-(p-3)])&&(second[n-(p-3)][o-(p-3)]==second[n-(p-2)][o-(p-2)])&&(second[n-(p-2)][o-(p-2)]==second[n-p][o-p])&&(second[n-p][o-p]==second[n-(p-1)][o-(p-1)])&&(second[n-1][o-1]!='.'))
                        {
                            m=0;
                            second[n-(p-4)][o-(p-4)]='G';
                            second[n-(p-3)][o-(p-3)]='R';
                            second[n-(p-2)][o-(p-2)]='E';
                            second[n-(p-1)][o-(p-1)]='A';
                            second[n-p][o-p]='T';
                        }
                        if((second[n-1][o-(p-4)]==second[n-1][o-(p-3)])&&(second[n-1][o-(p-3)]==second[n-1][o-(p-2)])&&(second[n-1][o-(p-2)]==second[n-1][o-p])&&(second[n-1][o-p]==second[n-1][o-(p-1)])&&(second[n-1][o-1]!='.'))
                        {
                            m=0;
                            second[n-1][o-(p-4)]='G';
                            second[n-1][o-(p-3)]='R';
                            second[n-1][o-(p-2)]='E';
                            second[n-1][o-(p-1)]='A';
                            second[n-1][o-p]='T';
                        }
                        if((second[n-(p-4)][o-1]==second[n-(p-3)][o-1])&&(second[n-(p-3)][o-1]==second[n-(p-2)][o-1])&&(second[n-(p-2)][o-1]==second[n-p][o-1])&&(second[n-p][o-1]==second[n-(p-1)][o-1])&&(second[n-1][o-1]!='.'))
                        {
                            m=0;
                            second[n-p][o-1]='G';
                            second[n-(p-1)][o-1]='R';
                            second[n-(p-2)][o-1]='E';
                            second[n-(p-3)][o-1]='A';
                            second[n-(p-4)][o-1]='T';
                        }
                    }
                }
                for(y=sec-1;y>=0;y--)//print the new table
                {
                    if(y==sec-1)
                    {
                        for(num=0;num<=sec;num++)
                        {
                            printf("%d ",num);
                            if(num==sec)
                            {
                                printf("\n");
                            }
                        }
                    }
                    for(x=0;x<sec;x++)
                    {
                        if(x==0)
                        {
                            printf("%d ",y+1);
                        }
                        printf("%c ",second[x][y]);
                    }
                    printf("\n");
                }
                for(y=sec-1;y>=0;y--)//print the new table
                {
                    for(x=0;x<sec;x++)
                    {
                        if(second[x][y]!='.')
                        {
                            count++;
                        }
                    }
                }
                if(count==(sec*sec)&&m==1)
                {
                    m=2;
                }
                count=0;
                k=1;
            }
            if((m+1)==1)
            {
                if(i%2==0)
                {
                    printf("%s W I N \n",si);
                    ssi++;
                }
                else if(i%2==1)
                {
                    printf("%s W I N \n",fi);
                    sfi++;
                }
            }
            else if(m==2)
            {
                printf("YOU DRAW\n");
                sfi++;
                ssi++;
            }
        }
        else if(strcmp(sen,"3")==0)
        {
            ready[0]='T';
            while(strcmp(ready,"R")!=0)//choose that you want tutorials or not
            {
                printf("Choose A for non-tutorials, B for tutorials: ");
                while(strcmp(ready,"A")!=0)
                {
					scanf("%s",ready);
                	if(strcmp(ready,"B")==0)
                	{
                    printf("1. This game you have to put variables in 9x9 table. 9x9 table is separated into 3x3 table to consider who is winner for 3x3 table and when you win in any 3x3 table, that table will be your big variable.\n");
                    printf("2. But the way to win this game is you have to set your big variables to be straight line (can be horizontal, vertical or crosswise).\n");
                    printf("3. Player 1 add an variable in any space on the table by putting coordinate which you want ex:3 2 (has space bar)\n");
                    printf("4. Player 2 add an variable in any space on the table by putting coordinate which you want ex:3 2 (has space bar)\n");
                    printf("5. Following step 3&4 until one player can set big variables to be straight line (can be horizontal, vertical or crosswise) and the player will win this game.\n\n\n");
                    printf("LET’S ENJOY :)\n\n\n\n");
                	}
                	else if(strcmp(ready,"A")!=0)
                	{
                	printf("Enter again\n");
					}
				}
				while(strcmp(ready,"R")!=0)
				{
                	printf("If you ready please ENTER (R) If not ENTER (N) : ");
                	scanf("%s",ready);
                	if(strcmp(ready,"N")==0)
                	{
                    printf("Not ready?\n");
                    printf("1. This game you have to put variables in 9x9 table. 9x9 table is separated into 3x3 table to consider who is winner for 3x3 table and when you win in any 3x3 table, that table will be your big variable.\n");
                    printf("2. But the way to win this game is you have to set your big variables to be straight line (can be horizontal, vertical or crosswise).\n");
                    printf("3. Player 1 add an variable in any space on the table by putting coordinate which you want ex:3 2 (has space bar)\n");
                    printf("4. Player 2 add an variable in any space on the table by putting coordinate which you want ex:3 2 (has space bar)\n");
                    printf("5. Following step 3&4 until one player can set big variables to be straight line (can be horizontal, vertical or crosswise) and the player will win this game.\n\n\n");
                	}
                	else if(strcmp(ready,"R")!=0)
                	{
                	printf("Enter again\n");
					}
				}
            }
            for(n=0;n<3;n++)
            {
                for(j=0;j<3;j++)
                {
                    forth[n][j]='.';
                }
            }
            for(y=0;y<9;y++)//create a 9x9 table
            {
                for(x=0;x<9;x++)
                {
                    third[x][y]='.';
                    printf(" %c",third[x][y]);
                    if(x%3==2)
                    {
                        printf("  ");
                    }
                }
                printf("\n");
                if(y%3==2)
                {
                    printf("\n\n");
                }
            }
            for(i=0;m==1;i++)//playing
            {
                while(k==1)//loop for receive coordinates & check whether it is available or not
                {
                    if(i%2==0)
                    {
                        printf(" %s's turn: ",fi);
                        scanf("%d %d",&n,&o);
                    }
                    else if(i%2==1)
                    {
                        printf(" %s's turn: ",si);
                        scanf("%d %d",&n,&o);
                    }
                    if(third[n-1][o-1]=='.')//mark the coordinate
                    {
                        if(i%2==0)
                        {
                            third[n-1][o-1]='o';
                        }
                        else if(i%2==1)
                        {
                            third[n-1][o-1]='x';
                        }
                        k=0;
                    }
                    else//for incase have to input again
                    {
                        printf("please ENTER again\n");
                    }
                }
                k=1;
                x=0;
                y=0;
                win=0;
                for(y=0;y<7;y=y+3)//check for a winner in each zone
                {
                    for(x=0;x<7;x=x+3)
                    {
                        for(d=0;d<=2;d++)
                        {
                            printf("%d %d %d %c %c %c\n",d,x,y,third[x][y+d],third[1+x][y+d],third[2+x][y+d]);
                            if(third[x][y+d]==third[1+x][y+d]&&third[1+x][y+d]==third[2+x][y+d]&&third[x][y+d]!='.')//horizontal case
                            {

                                third[x][y+d]='w';
                                third[1+x][y+d]='i';
                                third[2+x][y+d]='n';
                                win=1;
                                rx=x;
                                ry=y;
                            }
                            if(third[x+d][y]==third[x+d][y+1]&&third[x+d][y+1]==third[x+d][y+2]&&third[x+d][y]!='.')//vertical case
                            {
                                third[x+d][y]='w';
                                third[x+d][y+1]='i';
                                third[x+d][y+2]='n';
                                win=1;
                                rx=x;
                                ry=y;
                            }
                        }
                        if(third[x][y]==third[x+1][y+1]&&third[x+1][y+1]==third[x+2][y+2]&&third[x+2][y+2]!='.')//diagonal(increase) case
                        {
                            third[x][y]='w';
                            third[x+1][y+1]='i';
                            third[x+2][y+2]='n';
                            win=1;
                            rx=x;
                            ry=y;
                        }
                        if(third[x][y+2]==third[x+1][y+1]&&third[x+1][y+1]==third[x+2][y]&&third[x][y+2]!='.')//diagonal(decrease) case
                        {
                            win=1;
                            third[x][y+2]='w';
                            third[x+1][y+1]='i';
                            third[x+2][y]='n';
                            rx=x;
                            ry=y;
                        }
                        count=0;
                        for(h=y;h<y+3;h++)
                        {
                            for(n=x;n<x+3;n++)
                            {
                                if(third[n][h]!='.')
                                {
                                    count++;
                                }
                            }
                        }
                        if(count==9&&win==0)
                        {
                            win=2;
                            rx=x;
                            ry=y;
                        }
                        count=0;
                    }
                }
                if(win==1)//show the winner of each zone
                {
                    for(h=0;h<3;h++)
                    {
                        for(n=0;n<3;n++)
                        {
                            if((n+h)%2==0&&third[rx+n][ry+h]!='w'&&third[rx+n][ry+h]!='i'&&third[rx+n][ry+h]!='n')
                            {
                                if(i%2==0)
                                {
                                    third[rx+n][ry+h]='o';
                                }
                                else
                                {
                                    third[rx+n][ry+h]='x';
                                }
                            }
                            else if(third[rx+n][ry+h]!='w'&&third[rx+n][ry+h]!='i'&&third[rx+n][ry+h]!='n')
                            {
                                third[rx+n][ry+h]='*';
                            }
                        }
                    }
                }
                for(n=8;n>=0;n--)
                {
                    for(h=0;h<9;h++)
                    {
                        printf(" %c",third[h][n]);
                        if(h%3==2)
                        {
                            printf("  ");
                        }
                    }
                    printf("\n");
                    if(n%3==0)
                    {
                        printf("\n\n");
                    }
                }
                printf("%d %d\n",rx,ry);
                if(i%2==0&&win==1)//to record the score to new table
                {
                    forth[rx/3][ry/3]='o';
                }
                else if(win==1)
                {
                    forth[rx/3][ry/3]='x';
                }
                else if(win==2&&forth[rx/3][ry/3]=='.')
                {
                    forth[rx/3][ry/3]='p';
                }
                win=0;
                for(n=0;n<3;n++)
                {
                    for(h=0;h<3;h++)
                    {
                        printf(" %c",forth[h][n]);
                    }
                printf("\n");
                }
                for(n=0;n<3;n++)//check for a winner of the big table
                {
                    if(forth[0][n]==forth[1][n]&&forth[1][n]==forth[2][n]&&forth[0][n]!='.')
                    {
                        n=4;
                        break;
                    }
                    if(forth[n][0]==forth[n][1]&&forth[n][1]==forth[n][2]&&forth[n][0]!='.')
                    {
                        n=4;
                        break;
                    }
                }
                if(n==4)
                {
                    break;
                }
                if(forth[1][1]==forth[2][2]&&forth[2][2]==forth[0][0]&&forth[2][2]!='.')
                {
                    break;
                }
                if(forth[0][2]==forth[1][1]&&forth[1][1]==forth[2][0]&&forth[1][1]!='.')
                {
                    break;
                }
            }
            count=0;
            for(y=0;y<sec;y++)
            {
                for(x=0;x<sec;x++)
                {
                    if(forth[x][y]!='.')
                    {
                        count++;
                    }
                }
            }
            if(count==9)
            {
                d=8;
            }
            if(d==8)
            {
                printf("YOU DRAW\n");
                sfi++;
                ssi++;
            }
            else
            {
                if(i%2==0)
                {
                    printf("%s W I N \n",fi);
                    sfi++;
                }
                else if(i%2==1)
                {
                    printf("%s W I N \n",si);
                    ssi++;
                }
            }
        }
        else if(strcmp(sen,"4")==0)
        {
            if(ssi==0&&sfi==0)
            {
                printf("Please play first!!!\n");
            }
            else
            {
                if(ssi>sfi)
                {
                    printf("%s WIN THE MATCH!!!\n",si);
                }
                else if(ssi<sfi)
                {
                    printf("%s WIN THE MATCH!!!\n",fi);
                }
                else
                {
                    printf("YOU DRAW\n");
                }
            printf("%s         :         %s\n",fi,si);
            printf("%d         :         %d\n",sfi,ssi);
            }
        }
        else
        {
            printf("Enter again\n");
        }
    }
}

