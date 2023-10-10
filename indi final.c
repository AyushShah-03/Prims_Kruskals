#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int i,j,k,a,b,u,v,n,ne=1;
int min,mincost=0,cost[9][9],parent[9];
int find(int);
int uni(int,int);

int visited[10]={0},min,costy[10][10];

int find(int i)
{
	while(parent[i])
	i=parent[i];
	return i;
}

int uni(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}

/*Prims*/
void prims()
{
		printf("\n\tImplementation of Prims's algorithm\n");
	printf("\nEnter the number of nodes:");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix:\n");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		scanf("%d",&costy[i][j]);
		if(costy[i][j]==0)
			costy[i][j]=999;
	}
	visited[1]=1;
	printf("\n");
	while(ne < n)
	{
		for(i=1,min=999;i<=n;i++) 
		for(j=1;j<=n;j++)
		if(costy[i][j]< min)
		if(visited[i]!=0)
		{
			min=costy[i][j];
			a=u=i;
			b=v=j;
		}
		if(visited[u]==0 || visited[v]==0)
		{
			printf("\n Edge %d:(%d %d) cost:%d",ne++,a,b,min);
			mincost+=min;
			visited[b]=1;
		}
		costy[a][b]=costy[b][a]=999;
	}
	printf("\n\t Minimun cost=%d\n",mincost);
	getch();
}

/*kruskal*/
void kruskals()
{
	printf("\n\tImplementation of Kruskal's algorithm\n");
	printf("\nEnter the no. of vertices:");
	scanf("%d",&n);
	printf("\nEnter the cost adjacency matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=999;
		}
	}
	printf("The edges of Minimum Cost Spanning Tree are\n");
	while(ne < n)
	{
		for(i=1,min=999;i<=n;i++)
		{
			for(j=1;j <= n;j++)
			{
				if(cost[i][j] < min)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=find(u);
		v=find(v);
		if(uni(u,v))
		{
			printf("%d edge (%d,%d) =%d\n",ne++,a,b,min);
			mincost +=min;
		}
		cost[a][b]=cost[b][a]=999;
	}
	printf("\n\tMinimum cost = %d\n",mincost);
	getch();
}

int main()
{
	int choice;
	choice = 0;
	 printf("\t_____________________________________________________________________________________________________\t\n");
    printf("\n");
    printf("\t********************************{PRIMS AND KRUSKALS ALGORITHM}***************************************\t\n");
    printf("\t_____________________________________________________________________________________________________\t\n");
    printf("\t+++++++++++++++++++++++++++|Methods To Find Minimum Cost Spanning Tree|++++++++++++++++++++++++++++++\n\n");
	while(1)
	{
	printf("\n Which algorithm you want to proceed or want to exit\n");
	printf(" \n1.Prims algorithm \n");
	printf(" \n2.Kruskals algorithm \n");
	printf(" \n3.Exit \n");

	printf(" \n\n Enter your choice (1-3) \n");
	scanf("%d", &choice);

	switch (choice)
	{
	case 1:
		printf("YOU HAVE CHOSEN PRIMS ALGORITHM\n");
		prims();
		break;
	case 2:
		printf("YOU HAVE CHOSEN KRUSKALS ALGORITHM\n");
		kruskals();
		break;
	case 3:
		printf("Exit");
		return 0;
		break;
	default:
		printf("Invalid inut!!");
		break;
	}
	getchar();
	}
}
