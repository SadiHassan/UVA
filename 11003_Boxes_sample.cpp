#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int dp[1005][6005] ;
int n ;
int load[1005] , cap[1005] ;

int sol ( int cur , int bal ){

  if ( dp[cur][bal] != -1 )
      return dp[cur][bal] ;

  if ( cur == n || bal < 0)
  return 0 ;


  if ( load[cur] > bal ){
       dp[cur][bal] = sol (cur+1 ,bal) ;
  }
  else  {
        dp[cur][bal] = max ( sol(cur+1, bal) , 1 + sol(cur+1 , min ( bal-load[cur] , cap[cur])));
  }

  return dp[cur][bal];
}


int main(){
int  i , j, k ,l ;
while ( scanf("%d",&n) ){
    if(n == 0)
    break ;
j = 0 ;
for ( i = 0 ; i < n ; i ++){
     scanf("%d %d", load+i , cap+i );
     j = max ( j , cap[i]) ;
}

memset ( dp , -1 ,sizeof dp );
int ans = sol ( 0 , 6002) ;

printf("%d\n",ans);
}
    return 0 ;
}
