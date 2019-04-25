#include <bits/stdc++.h>

using namespace std;

int main()
{
    int sum[2], n;
    cin >> n;
    int nums[n];
    for(int i = 0; i < n; i++)
        cin >> nums[i];
    sum[0] = sum[1] = 0;
    int l = 0, r = n-1, k = 0;
    while(l <= r){
        int choosed = nums[l];
        if(nums[l] < nums[r]){
            choosed = nums[r--];
        }else l++;
        sum[k%2] += choosed;
        k++;
    }

    printf("%d %d\n", sum[0], sum[1]);

    return 0;
}
