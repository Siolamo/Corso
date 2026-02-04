#include <string.h>
#include <stdio.h>
long t_write(int fd, const char *buf, long bytes)
{
    long ret;
    asm volatile(
        "mov $1, %%rax\n"
        "syscall"
        : "=a"(ret)
        : "D"(fd), "S"(buf), "d"(bytes)
        : "rcx", "r11", "memory"
    );

    return ret;
}


long t_read(int fd, char *buf, long bytes)
{
    long ret;

    asm volatile(
        "mov $0, %%rax\n"
        "syscall"
        : "=a"(ret)
        : "D"(fd), "S"(buf), "d"(bytes)
        : "rcx", "r11", "memory"
    );

    return ret;
}

#define BUF_SIZE 256

long t_scanf_str(char *out, long max)
{
    char buf[BUF_SIZE];

    long n = t_read(0, buf, BUF_SIZE - 1); // stdin = 0
    if (n <= 0) return -1;

    buf[n] = 0;

    long i = 0;

    while (i < n && buf[i] != '\n' && i < max - 1)
    {
        out[i] = buf[i];
        i++;
    }

    out[i] = 0;

    return i;
}



#include <stdarg.h>



#define BUF 256

int t_atoi(const char *s)
{
    int r = 0;
    int sign = 1;

    if (*s == '-')
    {
        sign = -1;
        s++;
    }

    while (*s >= '0' && *s <= '9')
    {
        r = r * 10 + (*s - '0');
        s++;
    }

    return r * sign;
}


int t_atob(const char *s)
{
    if (!s) return 0;

    if (s[0] == '1') return 1;

    if (s[0] == 't' || s[0] == 'T') return 1;

    return 0;
}


int t_scanf(const char *fmt, ...)
{
    char input[BUF];
    char *tokens[32];

    long n = t_read(0, input, BUF - 1);
    if (n <= 0) return 0;

    input[n] = 0;

    /* Tokenize */
    int t = 0;
    char *p = input;

    while (*p && t < 32)
    {
        while (*p == ' ' || *p == '\n')
            p++;

        if (!*p) break;

        tokens[t++] = p;

        while (*p && *p != ' ' && *p != '\n')
            p++;

        if (*p)
        {
            *p = 0;
            p++;
        }
    }

    va_list ap;
    va_start(ap, fmt);

    int count = 0;

    for (int i = 0, k = 0; fmt[i] && k < t; i++)
    {
        if (fmt[i] == '%' && fmt[i + 1])
        {
            i++;

            if (fmt[i] == 'd')
            {
                int *x = va_arg(ap, int *);
                *x = t_atoi(tokens[k++]);
                count++;
            }

            else if (fmt[i] == 's')
            {
                char *s = va_arg(ap, char *);

                int j = 0;
                while (tokens[k][j])
                {
                    s[j] = tokens[k][j];
                    j++;
                }
                s[j] = 0;

                k++;
                count++;
            }

            else if (fmt[i] == 'c')
            {
                char *c = va_arg(ap, char *);
                *c = tokens[k++][0];
                count++;
            }

            else if (fmt[i] == 'b')
            {
                int *b = va_arg(ap, int *);
                *b = t_atob(tokens[k++]);
                count++;
            }
        }
    }

    va_end(ap);

    return count;
}


int main()
{
    char *s = "ciao\n";

    t_write(1, s, strlen(s));
    char n[60];
    int i;
    t_scanf("%d %s", &i,n);
    t_write(1,n,60);
    printf("\n%d\n",i);

}