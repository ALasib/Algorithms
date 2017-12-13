/*Hints:
Algorithm:

1. If you want to get XOR of array elements in range [I, J], you can do it by taking the XOR of [1, I-1] with XOR[1, J]. (How does this solve the problem? - See next points.)
2. Make a trie of the bit representation of the XOR of elements.

Suppose the array is: 4, 1, 3, 2, 7. and k = 2.

      Binary Rep.     XOR    K=2 Bin = 010

4    100                  100
1    001                  101
3    011                  110
2    010                  100  <-- (example case below)
7    111                  011

For each element of the array,

1. Insert the value 0 to the Trie (test for cases like when there is only one element present and is less than k).
2. Find it's XOR with the previous value (0 if first). Now find how many subarrays are present whose XOR is less than k. How? ->

Consider the case when you've inserted XOR with element 3 and considering the element 2 to pass its XOR to query.
Now k = 2 its binary rep. is 010. Now you take this representation of k and the current XOR value's (for 2 = 100) binary representation to guide your search through the trie.

k1 = 0. Now above the value 2 in the array, all those XORs whose bit at index = 1 is = 1, when taken XOR with "1"00 will give a value 0. These XORs are the ones who may be less than or equal to the value k. Those XOR values who have a 0 in the first bit when taken XOR with "1"00 will give 1 which means that all those XORs are greater than k. Here's the full detail-

Check the first bits below:-

100 ^ 100 -> 000 = (0 in the first position). Can be less than k. This represents the XOR of 1,3,2 as you are taking xor of 4,1,3,2 with 4 so you get xor of 1,3,2.

100 ^ 101 -> 001 = (0 in the first position again). Can be less than k. This represents the XOR of 4,1 with XOR of 4,1,3,2 = XOR of 3, 2.

100 ^ 110 -> 010 = (0 in the first position again). Can be less than k. This represents the XOR of 4,1,3 with XOR of 4,1,3,2 = XOR of 2.

100 ^ 000 (the first 0 we inserted in the trie) -> represents the XOR of 4,1,3,2.

So all the possible sequences ending at 2 have been considered. A trie thus helps to get the answer fast.

3. Do this until the last element of the array has been considered.
*/

#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
int k;

struct prefix_trie
{
    int sz;
    struct Trie
    {
        int next[2];
        int counter[2];
        int endmark;

        void clean()
        {
            for(int i=0;i<2;i++)
            {
                 next[i] = -1;
                 counter[i]=0;
            }
            endmark = 0;
        }
    };

    Trie *arr = new Trie[200099];

    void init()
    {
        arr[0].clean();
        sz = 0;
    }

    void Insert(int mask)
    {
        int idx = 0;

        for(int i=19;i>=0; i--)
        {
            int x = (mask>>i)&1;
            arr[idx].counter[x]++;

            if(arr[idx].next[x] == -1)
            {
                sz++;
                arr[sz].clean();
                arr[idx].next[x] = sz;
            }
            idx = arr[idx].next[x];
        }
        arr[idx].endmark++;
    }

    int query(int mask)
    {
        int idx = 0;
        int ans=0;

        for(int i=19;i>=0; i--)
        {
            int mask_bit=(mask>>i)&1;
            int k_bit=(k>>i)&1;

            if(k_bit)
            {
                if(mask_bit)
                {
                    ans+=arr[idx].counter[1];
                    idx=arr[idx].next[0];
                }
                else
                {
                    ans+=arr[idx].counter[0];
                    idx=arr[idx].next[1];
                }
            }

            else
            {
                if(mask_bit) idx=arr[idx].next[1];
                else idx=arr[idx].next[0];
            }

            if(idx==-1)break;
        }
        return ans;
    }
};

int main()
{
    int test,cs=0,num;
    prefix_trie Tr;
    scanf("%d",&test);

    while(test--)
    {
        scanf("%d%d",&num,&k);
        Tr.init();
        Tr.Insert(0);
        int xor_so_far=0;
        LL res=0;

        for(int i=0;i<num;i++)
        {
            int temp;
            scanf("%d",&temp);
            xor_so_far^=temp;
            res+=Tr.query(xor_so_far);
            Tr.Insert(xor_so_far);
        }
        printf("%lld\n",res);
    }
    return 0;
}

