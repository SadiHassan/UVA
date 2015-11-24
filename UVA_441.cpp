//ACCEPTED!!!
#include <stdio.h>

int main(){

int arr[30], K, f=1, i, j, k, l, m, n;

while(scanf("%d",&K)==1){

    if(K==0) break;

    if(f==0) printf("\n");

    f = 0;

    for(i=0;i<K;i++) scanf("%d",&arr[i]);

    for(i=0;i+5<K;i++)
        for(j=i+1;j<K;j++)
            for(k=j+1;k<K;k++)
                for(l=k+1;l<K;l++)
                    for(m=l+1;m<K;m++)
                        for(n=m+1;n<K;n++)
                            printf("%d %d %d %d %d %d\n",arr[i],arr[j],arr[k],arr[l],arr[m],arr[n]);
}

return 0;
}
