#include <stdio.h>
#include <string.h>

struct celestial_object
{
  char name[50];
  float x;
  float y;
  float z;
  char d[20];
  char month[20];
};
void Dijkstra(int Graph[20][20],int n,int start,char st[10],struct celestial_object *o)
{
  int cost[20][20],distance[20],pred[20];
  int visited[20],count,mind,nextnode,i,j;

  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      if(Graph[i][j]==0)
        cost[i][j]=99999;
      else
        cost[i][j]=Graph[i][j];
  for(i=0;i<n;i++)
  {
    distance[i]=cost[start][i];
    pred[i]=start;
    visited[i]=0;
  }

  distance[start]=0;
  visited[start]=1;
  count=1;

  while(count<n-1)
    {
    mind=99999;

    for(i=0;i<n;i++)
      if(distance[i]<mind&&!visited[i])
      {
        mind=distance[i];
        nextnode=i;
      }

    visited[nextnode]=1;
    for(i=0;i<n;i++)
      if(!visited[i])
        if(mind+cost[nextnode][i]<distance[i])
        {
          distance[i]=mind+cost[nextnode][i];
          pred[i]=nextnode;
        }
    count++;
  }
  // printf("\nDistance from Earth to %d: %d", ch, distance[ch]);
   for(i=0;i<n;i++)
   {
        if(strcmp(st,o[i].name)==0)
          {
            printf("\nDistance from Earth to %s planet is %d Million miles.\n",st,distance[i]);
            break;
          }
   }
}
int main()
{
    /*FILE *ptr=NULL;
    char string[50];
    ptr=fopen("STAR MAP.txt","r");
    fscanf(ptr, "%s",string);
    printf("content %s\n",string);*/

    int Graph[20][20],i, n, u;
    n = 10;

    struct celestial_object o[20];

    strcpy(o[0].name,"sun");
    o[0].x=8;
    o[0].y=31;
    o[0].z=37;
    strcpy(o[0].d,"93 Million Miles");
    strcpy(o[0].month,"");

    strcpy(o[1].name,"mercury");
    o[1].x=-0.263;
    o[1].y=-0.090;
    o[1].z=0.010;
    strcpy(o[1].d,"57 Million Miles");

    strcpy(o[2].name,"venus");
    o[2].x=-0.622;
    o[2].y=-0.40;
    o[2].z=0.021;
    strcpy(o[2].d,"25 Million Miles");

    strcpy(o[3].name,"earth");
    o[3].x=0.98;
    o[3].y=0.019;
    o[3].z=-0.001;
    strcpy(o[3].d,"0 Million Miles");

    strcpy(o[4].name,"mars");
    o[4].x=25;
    o[4].y=19;
    o[4].z=17;
    strcpy(o[4].d,"57 Million Miles");

    strcpy(o[5].name,"jupiter");
    o[5].x=1;
    o[5].y=38;
    o[5].z=34;
    strcpy(o[5].d,"390 Million Miles");

    strcpy(o[6].name,"saturn");
    o[6].x=-13;
    o[6].y=52;
    o[6].z=13;
    strcpy(o[6].d,"1.6122Bkm");

    strcpy(o[7].name,"neptune");
    o[7].x=-3;
    o[7].y=21;
    o[7].z=30;
    strcpy(o[7].d,"4.6173Bkm");

    strcpy(o[8].name,"uranus");
    o[8].x=16;
    o[8].y=4;
    o[8].z=49;
    strcpy(o[8].d,"3.0006Bkm");

    strcpy(o[9].name,"pluto");
    o[9].x=-22;
    o[9].y=37;
    o[9].z=54;
    strcpy(o[9].d,"5.3034Bkm");

    char name[20],planet[20],ans[10];
    printf("What is your name?\n");
    scanf("%s",name);
    printf("\n");
    printf("Hello %s!\n",name);
    printf("\n");
    printf("If you could name a newly discovered planet, what would you name it?\n");
    scanf("%s",planet);
    printf("%s! That sounds interesting.",planet);
    printf("\n");
    printf("\n");
    printf("Can i tell you a joke?(yes/no)\n");
    scanf("%s",ans);
    printf("\n");
    if(strcmp(ans,"yes")==0)
    {
        printf("How do you organize a space party? \nYou planet!");
        printf("\n");
        printf("Wanna hear another?\n");
        scanf("%s",ans);
        if(strcmp(ans,"yes")==0)
        {
            printf("Why did the astronaut break up with his girlfriend?\n He needed some space.\n");
            printf("\n");
            printf("Another?\n");
            scanf("%s",ans);
            if(strcmp(ans,"yes")==0)
            {
                printf("Why did the planet go to the doctor? \nBecause it had a meteoroid.\n");
                printf("\n");
                printf("I hope these jokes make you smile!\n");
            }
        }
    }printf("\n");

    printf("Where would you like to go from Earth?\n\nsun\tmercury\tvenus\nearth\tmars\tjupiter\tsaturn\nneptune\turanus\tpluto\n");
      char st[10];
      scanf("%s",st);
      for(i=0;i<n;i++)
      {
          if(strcmp(st,o[i].name)==0)
          {
              printf("\nName: %s\n", o[i].name);
               printf("Position: (%f,%f,%f)\n",o[i].x,o[i].y,o[i].z);
             printf("Distance: %s\n",o[i].d);
           printf("\n");
    break;
          }
      }

  Graph[0][0] = 0;
  Graph[0][1] = 35;
  Graph[0][2] = 0;
  Graph[0][3] = 93;
  Graph[0][4] = 0;
  Graph[0][5] = 0;
  Graph[0][6] = 0;
  Graph[0][7] = 0;
  Graph[0][8] = 0;
  Graph[0][9] = 0;

  Graph[1][0] = 35;
  Graph[1][1] = 0;
  Graph[1][2] = 2;
  Graph[1][3] = 57;
  Graph[1][4] = 0;
  Graph[1][5] = 0;
  Graph[1][6] = 0;
  Graph[1][7] = 0;
  Graph[1][8] = 0;
  Graph[1][9] = 0;

  Graph[2][0] = 0;
  Graph[2][1] = 0;
  Graph[2][2] = 0;
  Graph[2][3] = 25;
  Graph[2][4] = 0;
  Graph[2][5] = 0;
  Graph[2][6] = 0;
  Graph[2][7] = 0;
  Graph[2][8] = 0;
  Graph[2][9] = 0;

  Graph[3][0] = 93;
  Graph[3][1] = 57;
  Graph[3][2] = 25;
  Graph[3][3] = 0;
  Graph[3][4] = 48;
  Graph[3][5] = 390;
  Graph[3][6] = 0;
  Graph[3][7] = 0;
  Graph[3][8] = 0;
  Graph[3][9] = 0;

  Graph[4][0] = 0;
  Graph[4][1] = 0;
  Graph[4][2] = 0;
  Graph[4][3] = 48;
  Graph[4][4] = 0;
  Graph[4][5] = 0;
  Graph[4][6] = 0;
  Graph[4][6] = 0;
  Graph[4][6] = 0;
  Graph[4][6] = 0;

  Graph[5][0] = 0;
  Graph[5][1] = 0;
  Graph[5][2] = 0;
  Graph[5][3] = 390;
  Graph[5][4] = 0;
  Graph[5][5] = 0;
  Graph[5][6] = 0;
  Graph[5][7] = 0;
  Graph[5][8] = 0;
  Graph[5][9] = 0;

  Graph[6][0] = 0;
  Graph[6][1] = 0;
  Graph[6][2] = 0;
  Graph[6][3] = 0;
  Graph[6][4] = 0;
  Graph[6][5] = 484;
  Graph[6][6] = 0;
  Graph[6][7] = 2800;
  Graph[6][8] = 0;
  Graph[6][9] = 0;

  Graph[7][0] = 0;
  Graph[7][1] = 0;
  Graph[7][2] = 0;
  Graph[7][3] = 0;
  Graph[7][4] = 0;
  Graph[7][5] = 2700;
  Graph[7][6] = 2800;
  Graph[7][7] = 0;
  Graph[7][8] = 0;
  Graph[7][9] = 2700;

  Graph[8][0] = 0;
  Graph[8][1] = 0;
  Graph[8][2] = 0;
  Graph[8][3] = 0;
  Graph[8][4] = 0;
  Graph[8][5] = 1900;
  Graph[8][6] = 0;
  Graph[8][7] = 0;
  Graph[8][8] = 0;
  Graph[8][9] = 0;

  Graph[9][0] = 0;
  Graph[9][1] = 0;
  Graph[9][2] = 0;
  Graph[9][3] = 0;
  Graph[9][4] = 0;
  Graph[9][5] = 0;
  Graph[9][6] = 0;
  Graph[9][7] = 2700;
  Graph[9][8] = 3700;
  Graph[9][9] = 0;

    u=3;
  Dijkstra(Graph,n,u,st,o);
}
