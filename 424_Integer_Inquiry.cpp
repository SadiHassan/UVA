//ACCEPTED!!!
#include<stdio.h>
#include<string.h>

char str[110][110];
char s[110];
int ans[110], ans_index;
int row, len;

int main(){

row=0;
len=0;
ans_index = 0;

while(scanf("%s",s)){
    //getchar();
    if(strcmp(s,"0")==0) break;
    strcpy(str[row],s);

    if( len < strlen(str[row]) ) len = strlen(str[row]);
    //printf("%s\n",str[ind]);
    row++;
}

int i, j;
int sum, carry;

sum=0;
carry=0;
int col;

for(j=1;j<=len;j++){

    for(i=0;i<row;i++){

        //if( len-j > strlen(str[i]) ) continue;
        if( (int)strlen(str[i]) - j >= 0 )
            {
                col = strlen(str[i]) - j;
                sum = sum + (str[i][col] - 48);
                //printf("--> %d ",strlen(str[i]) - j);
                //printf(" sum : %d \n",sum);
            }

    }
    //printf("\n");

            sum += carry;
            ans[ans_index] = sum%10;
            //printf("now-->%d  %d\n",ans_index,ans[ans_index]);
            ans_index++;
            carry = sum/10;

            sum=0;
            //carry=0;

}

if(carry!=0) ans[ans_index++] = carry;

for(i=ans_index-1; i>=0; i--) printf("%d",ans[i]);
printf("\n");

return 0;
}
