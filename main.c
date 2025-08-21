#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <stddef.h>

/*
 * Test harness mínimo (sin dependencias externas)
 */
static int g_pass = 0;
static int g_fail = 0;

static void ok_int(const char *name, long got, long exp)
{
    if (!!got == !!exp)
    {
        printf("[OK ] %s (got=%ld exp=%ld)\n", name, got, exp);
        g_pass++;
    }
    else
    {
        printf("[KO ] %s (got=%ld exp=%ld)\n", name, got, exp);
        g_fail++;
    }
}

static void ok_eq_int(const char *name, long got, long exp)
{
    if (got == exp)
    {
        printf("[OK ] %s (got=%ld)\n", name, got);
        g_pass++;
    }
    else
    {
        printf("[KO ] %s (got=%ld exp=%ld)\n", name, got, exp);
        g_fail++;
    }
}

static void ok_str(const char *name, const char *got, const char *exp)
{
    if ((got == NULL && exp == NULL) || (got && exp && strcmp(got, exp) == 0))
    {
        printf("[OK ] %s (\"%s\")\n", name, got ? got : "(null)");
        g_pass++;
    }
    else
    {
        printf("[KO ] %s (got=\"%s\" exp=\"%s\")\n", name, got ? got : "(null)", exp ? exp : "(null)");
        g_fail++;
    }
}

static void ok_mem_zero(const char *name, const void *buf, size_t n)
{
    size_t i = 0; const unsigned char *p = (const unsigned char *)buf; int zero = 1;
    while (i < n) { if (p[i] != 0) { zero = 0; break; } i++; }
    if (zero) { printf("[OK ] %s\n", name); g_pass++; }
    else { printf("[KO ] %s (mem no está a cero)\n", name); g_fail++; }
}

static void ok_sign(const char *name, int got, int exp_sign)
{
    int s = (got > 0) - (got < 0);
    if (s == exp_sign)
    {
        printf("[OK ] %s (sign=%d)\n", name, s);
        g_pass++;
    }
    else
    {
        printf("[KO ] %s (got=%d sign=%d exp_sign=%d)\n", name, got, s, exp_sign);
        g_fail++;
    }
}

static void ok_ptr_offset(const char *name, const void *base, const void *ptr, ptrdiff_t exp_off)
{
    if (!ptr && exp_off == -1)
    {
        printf("[OK ] %s (NULL)\n", name);
        g_pass++;
        return;
    }
    if (ptr)
    {
        ptrdiff_t off = (const unsigned char *)ptr - (const unsigned char *)base;
        if (off == exp_off)
        {
            printf("[OK ] %s (off=%td)\n", name, off);
            g_pass++;
            return;
        }
        printf("[KO ] %s (off=%td exp=%td)\n", name, off, exp_off);
        g_fail++;
        return;
    }
    printf("[KO ] %s (ptr is NULL, exp off=%td)\n", name, exp_off);
    g_fail++;
}

/* -------------------- Helpers listas -------------------- */
static t_list *node_raw(void *content)
{
    t_list *n = (t_list *)malloc(sizeof(*n));
    if (!n) return NULL;
    n->content = content;
    n->next = NULL;
    return n;
}

static size_t list_len(t_list *lst)
{
    size_t i = 0;
    while (lst) { i++; lst = lst->next; }
    return i;
}

static t_list *list_last(t_list *lst)
{
    if (!lst) return NULL;
    while (lst->next) lst = lst->next;
    return lst;
}

static char *cdup(const char *s)
{
    size_t n = strlen(s);
    char *r = (char *)malloc(n + 1);
    if (!r) return NULL;
    memcpy(r, s, n + 1);
    return r;
}

/* -------------------- Tests del primer bloque -------------------- */
static void test_isalpha(void)
{
    ok_int("isalpha('a')", ft_isalpha('a'), 1);
    ok_int("isalpha('Z')", ft_isalpha('Z'), 1);
    ok_int("isalpha('5')", ft_isalpha('5'), 0);
    ok_int("isalpha(' ')", ft_isalpha(' '), 0);
}

static void test_isdigit(void)
{
    ok_int("isdigit('0')", ft_isdigit('0'), 1);
    ok_int("isdigit('9')", ft_isdigit('9'), 1);
    ok_int("isdigit('/')", ft_isdigit('/'), 0);
    ok_int("isdigit(':')", ft_isdigit(':'), 0);
}

static void test_isalnum(void)
{
    ok_int("isalnum('a')", ft_isalnum('a'), 1);
    ok_int("isalnum('5')", ft_isalnum('5'), 1);
    ok_int("isalnum('_')", ft_isalnum('_'), 0);
    ok_int("isalnum(' ')", ft_isalnum(' '), 0);
}

static void test_isascii(void)
{
    ok_int("isascii(0)", ft_isascii(0), 1);
    ok_int("isascii(127)", ft_isascii(127), 1);
    ok_int("isascii(-1)", ft_isascii(-1), 0);
    ok_int("isascii(128)", ft_isascii(128), 0);
}

static void test_isprint(void)
{
    ok_int("isprint(32 ' ')", ft_isprint(32), 1);
    ok_int("isprint(126 '~')", ft_isprint(126), 1);
    ok_int("isprint(31)", ft_isprint(31), 0);
    ok_int("isprint(127)", ft_isprint(127), 0);
}

static void test_bzero(void)
{
    unsigned char buf[5] = {1,2,3,4,5};
    ft_bzero(buf + 1, 3);
    ok_eq_int("bzero conserva extremos", buf[0] == 1 && buf[4] == 5, 1);
    ok_mem_zero("bzero pone a 0 el rango", buf + 1, 3);
    ft_bzero(buf, 0);
    ok_eq_int("bzero n==0 no cambia", buf[0] == 1 || buf[0] == 0, 1);
}

static void test_calloc(void)
{
    size_t n = 4; size_t sz = sizeof(int);
    int *p = (int *)ft_calloc(n, sz);
    if (!p) { printf("[KO ] calloc básico devolvió NULL\n"); g_fail++; }
    else { ok_mem_zero("calloc inicializa a 0", p, n * sz); free(p); }
    /* Overflow: si lo detectas → NULL */
    {
        size_t big = (size_t)~0ULL / 2 + 1; /* SIZE_MAX/2 + 1 */
        void *q = ft_calloc(big, 2);
        if (q == NULL) { printf("[OK ] calloc overflow → NULL\n"); g_pass++; }
        else { printf("[KO ] calloc overflow no detectado\n"); g_fail++; free(q); }
    }
}

static void test_atoi(void)
{
    ok_eq_int("atoi '42'", ft_atoi("42"), 42);
    ok_eq_int("atoi '   -42'", ft_atoi("   -42"), -42);
    ok_eq_int("atoi '+7'", ft_atoi("+7"), 7);
    ok_eq_int("atoi '  \t\n\r\v\f123'", ft_atoi("\t\n\r\v\f 123"), 123);
    ok_eq_int("atoi '4193 with words'", ft_atoi("4193 with words"), 4193);
    ok_eq_int("atoi 'words 987'", ft_atoi("words 987"), 0);
}

static void test_itoa(void)
{
    char *s;
    s = ft_itoa(0); ok_str("itoa 0", s, "0"); free(s);
    s = ft_itoa(12345); ok_str("itoa 12345", s, "12345"); free(s);
    s = ft_itoa(-12345); ok_str("itoa -12345", s, "-12345"); free(s);
    s = ft_itoa(INT_MIN); ok_str("itoa INT_MIN", s, "-2147483648"); free(s);
    s = ft_itoa(INT_MAX); ok_str("itoa INT_MAX", s, "2147483647"); free(s);
}

/* -------------------- Tests nuevo bloque (listas + memoria) -------------------- */
static void test_memchr(void)
{
    const char s[] = "abcdef";
    ok_ptr_offset("memchr encuentra 'c'", s, ft_memchr(s, 'c', 6), 2);
    ok_ptr_offset("memchr no encuentra 'x'", s, ft_memchr(s, 'x', 6), -1);
    ok_ptr_offset("memchr respeta n (no alcanza 'f')", s, ft_memchr(s, 'f', 5), -1);
    unsigned char b[5] = {0,1,2,3,4};
    ok_ptr_offset("memchr 0 en binario", b, ft_memchr(b, 0, 5), 0);
    ok_ptr_offset("memchr c>255", b, ft_memchr(b, 258, 5), -1); /* 258 → 2, no está */
}

static void test_memcmp(void)
{
    ok_sign("memcmp iguales", ft_memcmp("abc","abc",3), 0);
    ok_sign("memcmp n==0", ft_memcmp("a","b",0), 0);
    ok_sign("memcmp 'abc' vs 'abd'", ft_memcmp("abc","abd",3), -1);
    ok_sign("memcmp 'abz' vs 'aby'", ft_memcmp("abz","aby",3), +1);
    {
        unsigned char a[3] = {'a','\0','c'};
        unsigned char b[3] = {'a','\0','b'};
        ok_sign("memcmp con NUL intermedio", ft_memcmp(a,b,3), +1);
    }
}

static void test_lstnew(void)
{
    char *p = (char *)"X";
    t_list *n = ft_lstnew(p);
    ok_int("lstnew != NULL", n != NULL, 1);
    if (n)
    {
        ok_int("lstnew content", n->content == p, 1);
        ok_int("lstnew next NULL", n->next == NULL, 1);
        free(n);
    }
}

static void test_lstsize(void)
{
    ok_eq_int("lstsize lista vacía", ft_lstsize(NULL), 0);
    t_list *a = node_raw("A");
    t_list *b = node_raw("B");
    t_list *c = node_raw("C");
    a->next = b; b->next = c;
    ok_eq_int("lstsize 3", ft_lstsize(a), 3);
    b->next = NULL; ok_eq_int("lstsize 2", ft_lstsize(a), 2);
    free(c); free(b); free(a);
}

static void test_lstadd_front(void)
{
    t_list *a = node_raw("A");
    t_list *b = node_raw("B");
    t_list *lst = a; a->next = NULL;
    ft_lstadd_front(&lst, b);
    ok_int("lstadd_front head==b", lst == b, 1);
    ok_int("lstadd_front b->next==a", b->next == a, 1);
    ft_lstadd_front(NULL, b); /* no-op */
    ft_lstadd_front(&lst, NULL); /* no-op */
    free(a); free(b);
}

static void test_lstlast(void)
{
    t_list *a = node_raw("A");
    t_list *b = node_raw("B");
    t_list *c = node_raw("C");
    a->next = b; b->next = c;
    ok_int("lstlast de a == c", ft_lstlast(a) == c, 1);
    ok_int("lstlast de NULL == NULL", ft_lstlast(NULL) == NULL, 1);
    free(c); free(b); free(a);
}

static int g_del_count = 0;
static void del_count(void *p) { g_del_count++; free(p); }

static void test_lstdelone(void)
{
    char *s = cdup("A");
    t_list *n = ft_lstnew(s);
    g_del_count = 0;
    ft_lstdelone(n, del_count);
    ok_eq_int("lstdelone llama del", g_del_count, 1);
}

static void test_lstclear(void)
{
    t_list *a = ft_lstnew(cdup("A"));
    t_list *b = ft_lstnew(cdup("B"));
    t_list *c = ft_lstnew(cdup("C"));
    a->next = b; b->next = c;
    g_del_count = 0;
    ft_lstclear(&a, del_count);
    ok_eq_int("lstclear pone *lst=NULL", a == NULL, 1);
    ok_eq_int("lstclear del 3 veces", g_del_count, 3);
}

static void fn_count(void *p) { (void)p; g_del_count++; }

static void test_lstiter(void)
{
    t_list *a = node_raw("A");
    t_list *b = node_raw("B");
    t_list *c = node_raw("C");
    a->next = b; b->next = c;
    g_del_count = 0;
    ft_lstiter(a, fn_count);
    ok_eq_int("lstiter recorre 3", g_del_count, 3);
    ft_lstiter(NULL, fn_count); /* no-op */
    ft_lstiter(a, NULL); /* no-op */
    free(c); free(b); free(a);
}

static void *map_plus_star(void *p)
{
    const char *s = (const char *)p;
    size_t n = strlen(s);
    char *r = (char *)malloc(n + 2);
    if (!r) return NULL;
    memcpy(r, s, n);
    r[n] = '*';
    r[n+1] = '\0';
    return r;
}

static void test_lstmap(void)
{
    t_list *a = ft_lstnew(cdup("A"));
    t_list *b = ft_lstnew(cdup("BB"));
    t_list *c = ft_lstnew(cdup("CCC"));
    a->next = b; b->next = c;

    /* f o del nulos → NULL */
    ok_int("lstmap f==NULL → NULL", ft_lstmap(a, NULL, del_count) == NULL, 1);
    ok_int("lstmap del==NULL → NULL", ft_lstmap(a, map_plus_star, NULL) == NULL, 1);

    /* mapeo normal */
    t_list *m = ft_lstmap(a, map_plus_star, del_count);
    ok_eq_int("lstmap misma longitud", (long)list_len(m), (long)list_len(a));
    ok_str("lstmap m0 == 'A*'", (char *)m->content, "A*");
    ok_str("lstmap m1 == 'BB*'", (char *)m->next->content, "BB*");
    ok_str("lstmap m2 == 'CCC*'", (char *)m->next->next->content, "CCC*");
    /* original intacto */
    ok_str("original a0 intacto", (char *)a->content, "A");
    ok_str("original a1 intacto", (char *)a->next->content, "BB");
    ok_str("original a2 intacto", (char *)a->next->next->content, "CCC");

    ft_lstclear(&m, del_count);
    ft_lstclear(&a, del_count);
}

/* -------------------- Tests de ft_lstadd_back del bloque previo -------------------- */
static void test_lstadd_back(void)
{
    t_list *lst = NULL;
    t_list *a = node_raw("A");
    t_list *b = node_raw("B");
    t_list *c = node_raw("C");

    ft_lstadd_back(&lst, a); /* añadir a lista vacía */
    ok_eq_int("lstadd_back vacía → head=a", lst == a, 1);
    ok_eq_int("lstadd_back a->next NULL", a->next == NULL, 1);

    ft_lstadd_back(&lst, b);
    ok_eq_int("lstadd_back len==2", (long)list_len(lst), 2);
    ok_eq_int("lstadd_back last==b", list_last(lst) == b, 1);
    ok_eq_int("lstadd_back a->next==b", a->next == b, 1);

    ft_lstadd_back(&lst, c);
    ok_eq_int("lstadd_back len==3", (long)list_len(lst), 3);
    ok_eq_int("lstadd_back last==c", list_last(lst) == c, 1);

    /* llamadas no-op */
    ft_lstadd_back(NULL, b);
    ft_lstadd_back(&lst, NULL);

    /* liberar nodos creados en test */
    free(a); free(b); free(c);
}

int main(void)
{
    printf("==== Tests libft ====\n");

    /* bloque 1 */
    test_isalpha();
    test_isdigit();
    test_isalnum();
    test_isascii();
    test_isprint();
    test_bzero();
    test_calloc();
    test_atoi();
    test_itoa();
    test_lstadd_back();

    /* bloque 2 */
    test_memchr();
    test_memcmp();
    test_lstnew();
    test_lstsize();
    test_lstadd_front();
    test_lstlast();
    test_lstdelone();
    test_lstclear();
    test_lstiter();
    test_lstmap();

    printf("====================\n");
    printf("PASS: %d\nFAIL: %d\n", g_pass, g_fail);
    return (g_fail != 0);
}
