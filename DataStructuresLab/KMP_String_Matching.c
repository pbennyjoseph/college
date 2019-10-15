#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// KMP algorithm implementation
void kmpmatches(char * haystack,int haystack_sz,char * needle, int needle_sz)
{
    int pi[needle_sz], count = 0;
    pi[0] = -1;
    int k = -1, q = -1;
    for (int j = 1; j < needle_sz; ++j)
    {
        while (k >= 0 && needle[k + 1] != needle[j])
            k = pi[k];
        if (needle[k + 1] == needle[j])
            ++k;
        pi[j] = k;
    }

    for (int i = 0; i < haystack_sz; ++i)
    {
        while (q >= 0 && needle[q + 1] != haystack[i])
            q = pi[q];
        if (needle[q + 1] == haystack[i])
            ++q;
        if (q == needle_sz - 1)
        {
            printf("Pattern found at index: %d\n", i - needle_sz + 1);
            ++count;
            q = pi[q];
        }
    }
}

int main()
{
    char * haystack = "throughthoughtimes";
    char * needle = "th";
    
    kmpmatches(haystack,18,needle,2);

    // Pattern found at index: 0
    // Pattern found at index: 7
    return 0;
}