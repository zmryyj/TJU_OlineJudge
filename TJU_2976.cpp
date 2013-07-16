#include<stdio.h>
#define N 101
#define M 10001
#define T  1000000
int main()
{
  long int s[N][N],w,min;
	int i,j,k,n,m,t,u;
	while(1)
	{
        scanf("%d%d",&n,&m);
        if(n==0&&m==0) break;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++){
				s[i][j]=T;
				s[i][i]=0; 
			}
		for(k=1;k<=m;k++)
        {
			scanf("%d %d %d",&u,&t,&w);
			s[u][t]=w;
			s[t][u]=w;
        }
		for(k=1;k<=n;k++)
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
					if(s[i][k]!=T&&s[k][j]!=T){
                            min=s[i][k]+s[k][j];
                            if(s[i][j]>min) s[i][j]=min;
					}
		printf("%ld\n",s[1][n]);
	}
	return 0;
}
