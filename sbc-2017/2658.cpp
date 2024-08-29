#include <iostream>

using namespace std;


void buildRec(int *T, int *A, int node, int start, int end)
{
    if(start == end)
    {
        T[node] = A[start];
    }
    else
    {
        int mid = (start + end) / 2;

        buildRec(T, A, 2 * node, start, end);

        buildRec(T, A, 2 * node + 1, mid+1, end);

        T[node] = T[2 * node] + T[2 * node + 1];
    }
}

void build(int *T, int *A, int n)
{
    buildRec(T, A, 1, 0, n-1);
}

int queryRec(int *T, int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
    {
        return 0;
    }

    int mid = (start + end) / 2;
    int p1 = queryRec(T, 2 * node, start, mid, l, r);
    int p2 = queryRec(T, 2 * node + 1, mid + 1, end, l, r);
    return (p1 + p2);
}

int query(int *T, int n, int l, int r)
{
    return queryRec(T, 1, 0, n-1, l, r);
}

void updateRec(int *T, int *A, int node, int start, int end, int idx, int val)
{
    if (start == end)
    {
        A[idx] += val;
        T[node] += val;
    }
    else
    {
        int mid = (start + end) / 2;

        if (start <= idx and idx <= mid)
        {
            updateRec(T, A, 2 * node, start, mid, idx, val);
        }
        else
        {
            updateRec(T, A, 2 * node + 1, mid + 1, end, idx, val);
        }

        T[node] = T[2 * node] + T[2 * node + 1];
    }
}

void update(int *T, int *A, int n, int idx, int val)
{
    updateRec(T, A, 1, 0, n - 1, idx, val);
}

// Exemplo
int main() {

    /**
     * Escreva a sua solução aqui
     * Code your solution here
     * Escriba su solución aquí
     */

    int n = 6; // tamanho do vetor A
    int A[] = {1, 3, 5, 7, 9, 11};
    int T[4*n] = {0};

    

    return 0;
}