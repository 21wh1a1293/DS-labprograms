#include<stdio.h>
# define MAX_SIZE 100
int queue[MAX_SIZE];
int front=-1,rear=-1;
void push(int var)
{
	if(rear == MAX_SIZE-1)
	{
	  printf("queue overflow\n");
	}
	else
	{
	  if(front == -1)
	  {
	   front = 0;
	  }
	  rear++;
	  queue[rear]=var;
          }
} 
void pop()
{
	if(front == -1||front>rear)
	{
		printf("queue underflow");
	}
	else
	{
		front++;
	}
}
int main()
{
	int N;
	printf("enter the number of nodes in the graph");
	scanf("%d",&N);
	int graph[N][N];
	printf("enter the adjacency matrix");
	for(int i=0;i<N;i++)
	{
	 for( int j=0;j<N;j++)
	  {
	    scanf("%d",&graph[i][j]);
	  }
	}
	int visited[N];
	for(int i=0;i<N;i++)
	{
		visited[i]=0;
	}
	int start_node;
	printf("enter the starting node for bfs traversal:");
	scanf("%d",&start_node);
	push(start_node);
	visited[start_node-1]=1;
	while(front<=rear)
	{
	 int current = queue[front];
	 printf("%d",current);
	 pop();
	 for(int i = 0;i<N;i++)
	 {
		 if((graph[current-1][i]==1)&&(visited[i]==0))
		 {
			 visited[i]=1;
			 push(i+1);
		 }
	 }
	}
	return 0;
}


           
