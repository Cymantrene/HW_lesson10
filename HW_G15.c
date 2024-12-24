#include <stdio.h>
#define MAX_LEN  1001
static size_t slen(const char* s);
static int sncmp(const char* s, const char* w, size_t n);
char* str_replace(size_t m, char* s, const char* w1, const char* w2);

int main(void)
{
    char s[MAX_LEN] = "Cao, Cao, Cao and Cao!!!";
    puts(s);
    puts( str_replace(MAX_LEN - 1, s, "Cao", "Ling") );
    return 0;
}

// w1 -> w2 || w2 -> w1
char* str_replace(size_t m, char* s, const char* w1, const char* w2){
    size_t i, j, n, l;
    char*  p, *e, *q, *d, *t = s;
    const char*  ws[2] = { w1, w2 };
    const size_t ns[2] = { slen(w1), slen(w2) };

    n = slen(s);
    if((n <= 1) || (n >= m) || !ns[0] || !ns[1])
        return t;

    e = s + n;
    while(*s){
        for(i = 0; i < 2; ++i){
            if(sncmp(s, ws[i], ns[i])){
                j = i ^ 1;
                if(ns[i] < ns[j]){//растяжение
                    l = ns[j] - ns[i];
                    if((n + l) >= m)
                        return t;

                    n += l;
                    e += l;
                    for(q = e; q > s; --q)
                        *q = *(q - l);
                }

                w1 = ws[j];
                p  = s;
                while(*w1)
                    *p++ = *w1++;

                if(ns[i] > ns[j]){//compress
                    n -= l;
                    l  = ns[i] - ns[j];
                    for(q = p, d = p + l; *q; *q++ = *d++);
                }
                s = p - 1;
                break;
            }
        }
        ++s;
    }
    return t;
}

//kolvo
static size_t slen(const char* s){
    const char* t = s;
    while(*s)
        ++s;
    return (size_t)(s - t);
}

//sravnit
static int sncmp(const char* s, const char* w, size_t n){
    size_t i = 0;
    while(*s && (i < n) && (*s == *w)){
        ++s;
        ++w;
        ++i;
    }
    return (i == n) && (! *w);
}
