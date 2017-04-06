#include<iostream>
#include<string.h>
using namespace std;
#define d 256
void search(string pat, string txt, int q)
{
    int M = pat.size();
    int N = txt.size();

    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;
 
    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M-1; i++)
    {
       h = (h*d)%q;
}
   
    for (i = 0; i < M; i++)
    {
        p = (d*p + pat[i])%q;
        t = (d*t + txt[i])%q;
    }
    for (i = 0; i <= N - M; i++)
    {
 
               if ( p == t )
        {

            for (j = 0; j < M; j++)
            {
                if (txt[i+j] != pat[j])
                    break;
            }
 
            // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
            if (j == M)
                cout<<i;
        }
 
        if ( i < N-M )
        {
            t = (d*(t - txt[i]*h) + txt[i+M])%q;
            if (t < 0)
            t = (t + q);
        }
    }
}
int main()
{
    string txt;
    string pat;
    cin>>txt;
    cin>>pat;
    int q = 101; // A prime number
    search(pat, txt, q);
    return 0;
}
