//ACCEPTED!!!
#include<stdio.h>
#include<string.h>
char str1[10000], str2[10000];
unsigned long long arr1[40], arr2[40];
int base_arr1[40], base_arr2[40];

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

while(scanf("%s %s",str1,str2)==2){
        base1 = 1;
        base2 = 1;

        for(int i=0; i<strlen(str1);i++){
            if(str1[i]>='A'&&str1[i]<='Z')
                val = 10 + str1[i] - 'A';
            else val = str1[i] - 48;

            if(base1<val) base1 = val;
        }

        for(int i=0; i<strlen(str2);i++){
            if(str2[i]>='A'&&str2[i]<='Z')
                val = 10 + str2[i] - 'A';
            else val = str2[i] - 48;

            if(base2<val) base2 = val;
        }

        base1++; base2++;
        int ind1=0, ind2=0;

        while(base1<=36){
              base_arr1[ind1] = base1;
              arr1[ind1] = get_num(str1,base1);
              ind1++;
              base1++;
        }

        while(base2<=36){
              base_arr2[ind2] = base2;
              arr2[ind2] = get_num(str2,base2);
              ind2++;
              base2++;
        }

        int ans_ind1 = -1, ans_ind2 = -1 ;

        for(int i=0; i<ind1; i++){
            for(int j=0; j<ind2; j++)
                if(arr1[i]==arr2[j]){
                    ans_ind1 = i;
                    ans_ind2 = j;
                    break;
                }
            if(ans_ind1!=-1) break;
        }

        if(ans_ind1==-1)
            printf("%s is not equal to %s in any base 2..36\n",str1,str2);
        else
            {
                printf("%s (base %d) = %s (base %d)\n",str1,base_arr1[ans_ind1],str2,base_arr2[ans_ind2]);
                //printf("%d %d\n",(int)arr1[ans_ind1],(int)arr2[ans_ind2]);
            }
}

return 0;
}