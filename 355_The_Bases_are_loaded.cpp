//ACCEPTED!!!
#include<stdio.h>
#include<string.h>

unsigned long long my_pow(int val, int p){
    unsigned long long sum=1;
    for(int i=1;i<=p; i++) sum = sum*val;
    return sum;
}

unsigned long long get_num(char* str, int base){

    unsigned long long sum=0;
    int p=0, val;

    for(int i = (int)strlen(str)-1; i>=0; i--){
            if(str[i]>='A'&&str[i]<='Z')
                val = 10 + str[i] - 'A';
            else val = str[i] - 48;

            sum = sum + val*my_pow(base,p);
            //printf("%d %d %d\n",val,p,my_pow(val,p));
            p++;
    }

    return sum;
}
int main(){

int base1, base2, val;
unsigned long long num10;
char str[20];
bool valid;

while(scanf("%d %d %s",&base1,&base2,str)==3){

    valid = true;

    for(int i=0; i<strlen(str);i++){
        if(str[i]>='A'&&str[i]<='Z')
                val = 10 + str[i] - 'A';
            else val = str[i] - 48;

        if(val>=base1) {valid=false;break;}
    }
    if(!valid){
        printf("%s is an illegal base %d number\n",str,base1);
        continue;
    }
    num10 = get_num(str,base1);
    int ind=0;
    char ans[200];

    while(num10>=0){
        val = num10%base2;
        if(val>=0&&val<=9) ans[ind] = val+48;
        else ans[ind] = val-10 + 'A';
        ind++;
        num10 = num10/base2;
        if(num10==0) break;
    }
    ans[ind] = '\0';
    printf("%s base %d = ",str,base1);
    for(int i=ind-1;i>=0;i--) printf("%c",ans[i]);
    printf(" base %d\n",base2);

}

return 0;
}
