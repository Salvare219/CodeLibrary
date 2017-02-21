#include<stdio.h> 

 #include<string.h> 

 #include<math.h> 

 #define maxn 300 

 #define INF 0x7fffffff 

 int min(int x,int y) 

 { 

     return x<y?x:y; 

 } 

 int map[maxn][maxn],vis[maxn],cap[maxn][maxn],dis[maxn]; 

 int que[maxn],pre[maxn]; 

 int num,ans; 

 int SPFA()  

 { 

     int i,k; 

     int head,tail; 

     memset(vis,0,sizeof(vis)); 

     for(i=0;i<=num;i++) 

     dis[i]=INF; 

     dis[0]=0; 

     vis[0]=1; 

     head=tail=0; 

     que[0]=0; 

     tail++; 

     while(head<tail) 

     { 

        k=que[head]; 

        vis[k]=0; 

        for(i=0;i<=num;i++) 

        { 

            if(cap[k][i]&&dis[i]>dis[k]+map[k][i]) 

            { 

                dis[i]=dis[k]+map[k][i]; 

                pre[i]=k; 

                if(!vis[i]) 

                { 

                    vis[i]=1; 

                    que[tail++]=i; 

                } 

            } 

        } 

        head++; 

     } 

     if(dis[num]<INF) 

     return 1; 

     return 0; 

 } 

 void end() 

 { 

     int i,sum=INF; 

     for(i=num;i!=0;i=pre[i]) 

     sum=min(sum,cap[pre[i]][i]); 

     for(i=num;i!=0;i=pre[i]) 

     { 

         cap[pre[i]][i]-=sum; 

         cap[i][pre[i]]+=sum; 

         ans+=map[pre[i]][i]*sum; 

     } 

 } 

 int main() 

 { 

     int N,M,K,i,j,k; 

     int need[maxn][maxn],needk[maxn]; 

     int have[maxn][maxn],havek[maxn]; 

     int flag; 

     while(scanf("%d%d%d",&N,&M,&K),N) 

     { 

         memset(needk,0,sizeof(needk)); 

         for(i=1;i<=N;i++)

         for(j=1;j<=K;j++) 

         { 

             scanf("%d",&need[i][j]); 

             needk[j]+=need[i][j]; 

         } 

         memset(havek,0,sizeof(havek));  

         for(i=1;i<=M;i++)

         for(j=1;j<=K;j++) 

         { 

             scanf("%d",&have[i][j]); 

             havek[j]+=have[i][j]; 

         } 

         flag=1; 

         for(i=1;i<=K;i++) 

         if(needk[i]>havek[i]) 

         { 

             flag=0; 

             break; 

         } 

         ans=0; 

         num=N+M+1; 

         for(k=1;k<=K;k++)

         { 

             memset(cap,0,sizeof(cap));  

             memset(map,0,sizeof(map)); 

             for(i=1;i<=N;i++) 

             for(j=1;j<=M;j++) 

             { 

                 scanf("%d",&map[j][M+i]); 

                 map[M+i][j]=-map[j][M+i]; 

                 cap[j][M+i]=have[j][k]; 

                 cap[M+i][j]=0; 

             } 

             if(!flag) 

             continue; 

             for(i=1;i<=M;i++)

             { 

                 cap[0][i]=have[i][k]; 

                 map[0][i]=map[i][0]=0; 

             } 

             for(i=1;i<=N;i++)

             { 

                 cap[M+i][num]=need[i][k]; 

                 map[M+i][num]=map[num][M+i]=0; 

             } 

             while(SPFA()) 

             end(); 

         } 

         if(flag) 

         printf("%d\n",ans); 

         else 

         printf("-1\n"); 

     } 

     return 0; 

 } 