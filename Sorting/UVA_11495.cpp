//ACCEPTED!!! MergeSort/Counting Inversions
#include<iostream>
#include<vector>
#define LI long int
using namespace std;
vector<LI> arr, temp;

LI _merge(int left, int mid, int right)
{
  LI i, j, k;
  LI inv_count = 0;

  i = left; /* i is index for left subarray*/
  j = mid;  /* i is index for right subarray*/
  k = left; /* i is index for resultant merged subarray*/
  while ((i <= mid - 1) && (j <= right))
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];
      inv_count = inv_count + (mid - i);
    }
  }

  /* Copy the remaining elements of left subarray
   (if there are any) to temp*/
  while (i <= mid - 1)
    temp[k++] = arr[i++];

  /* Copy the remaining elements of right subarray
   (if there are any) to temp*/
  while (j <= right)
    temp[k++] = arr[j++];

  /*Copy back the merged elements to original array*/
  for (i=left; i <= right; i++)
    arr[i] = temp[i];

  return inv_count;
}

LI merge_sort(LI left, LI right){
  LI mid, inv_count = 0;
  if (right > left)
  {
    mid = (right + left)/2;

    inv_count  = merge_sort(left, mid);
    inv_count += merge_sort(mid+1, right);
    inv_count += _merge(left, mid+1, right);
  }
  return inv_count;
}

int main(){

LI N, val;

while(cin>>N){
    if(N==0) break;

    for(LI i=0; i<N; i++){
        cin>>val;
        arr.push_back(val);
        temp.push_back(-1);
    }

    LI ans = merge_sort(0,arr.size()-1);
    //cout<<ans<<endl;
    if(ans%2==1) cout<<"Marcelo"<<endl;
    else cout<<"Carlos"<<endl;
    arr.clear();
    temp.clear();
}


return 0;
}
