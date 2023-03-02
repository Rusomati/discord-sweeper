#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void draw(int maxX,int maxY,char grid[][maxY])
{
        for(int i=0;i<maxY;i++)
        {
                for(int ii=0;ii<maxX;ii++)
                {
                        if(grid[ii][i]=='#')printf("||:boom:||");
                        if(grid[ii][i]=='0')printf("||:blue_square:||");
                        if(grid[ii][i]=='1')printf("||:one:||");
                        if(grid[ii][i]=='2')printf("||:two:||");
                        if(grid[ii][i]=='3')printf("||:three:||");
                        if(grid[ii][i]=='4')printf("||:four:||");
                        if(grid[ii][i]=='5')printf("||:five:||");
                        if(grid[ii][i]=='6')printf("||:six:||");
                        if(grid[ii][i]=='7')printf("||:seven:||");
                        if(grid[ii][i]=='8')printf("||:eight:||");
                }printf("\n");
        }

}
void genCell(int maxX,int maxY,int x,int y,char grid[][maxY])
{
        //printf("%d %d %c ",x,y,grid[x][y]);
        grid[x][y]='#';
        //printf("bomb at X:%d Y:%d\n",x,y);
        if(grid[x-1][y]!='#')if((x-1)>=0)grid[x-1][y]=grid[x-1][y]+1;
        if(grid[x+1][y]!='#')if((x+1)<maxX)grid[x+1][y]=grid[x+1][y]+1;
        if(grid[x][y-1]!='#')if((y-1)>=0)grid[x][y-1]=grid[x][y-1]+1;
        if(grid[x][y+1]!='#')if((y+1)<maxY)grid[x][y+1]=grid[x][y+1]+1;
        if(grid[x-1][y-1]!='#')if((y-1)>=0)if((x-1)>=0)grid[x-1][y-1]=grid[x-1][y-1]+1;
        if(grid[x+1][y-1]!='#')if((y-1)>=0)if((x+1)<maxX)grid[x+1][y-1]=grid[x+1][y-1]+1;
        if(grid[x-1][y+1]!='#')if((y+1)<maxY)if((x-1)>=0)grid[x-1][y+1]=grid[x-1][y+1]+1;
        if(grid[x+1][y+1]!='#')if((y+1)<maxY)if((x+1)<maxX)grid[x+1][y+1]=grid[x+1][y+1]+1;


}
int main(int argc,char *argv[])
{
        int maxX=10;
        int maxY=10;
        //printf("%d\n",time(0)); prints time since unix epoch or smth
        srand(time(0)); //no need to update srand as it is automaticly updated
        //printf("%d\n",rand()%3);prints random numbers from 0-2
        char grid[maxX][maxY];
        memset(grid,'0',sizeof grid);//zero out for loops.

        for(int i=0;i<maxY;i++)
        {
                for(int ii=0;ii<maxX;ii++)
                {
                        if((rand() % 5)==0)
                        {
                                genCell(maxX,maxY,ii,i,grid);
                        }
                }
        }

        draw(maxX,maxY,grid);
        //for(int i=0;i<maxY;i++)
        //{
        //for(int ii=0;ii<maxX;ii++)
        //printf("%c",grid[ii][i]);printf("\n");
        //}


        return 0;
}
