/*
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1

>>>For nums array1: 3 1 2
Next permutation: 3 2 1

>>>For nums array2: 3 2 1
Next permutation: 1 2 3
*/

/*Brute force
i> Find all the permutations in sorted manner using recursion
ii> Linear search
iii> next index
This will take TC = O(n! * n) which is very high
*/


/*Better solution - Using STL
void nextPermutation(vector<int>& nums) {
    next_permutation(nums.begin(), nums.end());
}
*/


//Best solution
/*> 2 1 5 4 3 0 0
i> longer prefix match -> a[i] < a[i+1]    -> 2 1 | 5 4 3 0 0   (Since from last index till third there was continuous increment,
further it got a break point at index 1)
idx = -1
for(i=n-2; i>=0; i--){
  if(a[i] < a[i+1]){
      idx = i;
      break;
  }
}

ii> find someone greater than the break point, but the smallest one, to stay close    -> 2 3 _ _ _ _ _ [5 4 1 0 0]
So when got the break point, mark it, and then just swap when found the closest greater element
for(int i=n-1; i>idx; i--){
  if(arr[i] > arr[idx]){
      swap(arr[i], arr[idx]);
      break;
  }
}

iii> try to place the remaining in sorted order
reverse(arr, idx+1, n-1);  -> through this we can reverse and get the sorted array. [0 0 1 4 5]

Note1: edge case: 5 4 3 2 1, so in this case theirs no break point, as it's continuously increasing, 
and can conclude it to be lexicographically the largest one, hence just reverse the array

Note2: 1 2 3 4 5, so here the breakpoint is at 4th index, hence we can assume for all the cases, 
that possibly 4th index could have the first break point, and hence will start the index from i = n-2


TC: O(n) + O(n) + O(n)  ~  O(3n) [Worst case]
SC: constant
*/

vector<int> nextPermutation(vector<int> &perm, int n)
{
    int idx = -1;
    for(int i=n-2; i>=0; i--){
        if(perm[i] < perm[i+1]){
            idx = i;
            break;
        }
    }

    if(idx == -1){
        reverse(perm.begin(), perm.end());
        return perm;
    }

    for(int i=n-1; i>=0; i--){
        if(perm[i] > perm[idx]){
            swap(perm[i], perm[idx]);
            break;
        }
    }
    reverse(perm.begin() + idx + 1, perm.end());
    return perm;
}
