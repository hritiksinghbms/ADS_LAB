#include <stdio.h>
#include <stdlib.h>
int parent[100];
int n;
void makeSet(int n)
{
    for (int i=0;i<n;i++)
        parent[i] = i;
}
int find(int x)
{
    if (parent[x]!=x)
        return find(parent[x]);
    return parent[x];
}

void Union(int e1,int e2)
{
    int root1=find(e1);
    int root2=find(e2);

    if(root1!=root2)
    {
        parent[root1]=parent[root2];
    }

}

int countIslands(int a[n][n],int n)
{
    int size;
    size=n*n;
    makeSet(size);
    for(int j=0;j<n;j++){
        for(int k=0;k<n;k++){
            if(a[j][k] == 0)
                continue;
            if(j + 1 < n && a[j + 1][k] == 1)
                Union(j*(n)+k,(j+1)*(n)+k);
            if(j - 1 >= 0 && a[j - 1][k] == 1)
                Union(j*(n)+k,(j-1)*(n)+k);
            if(k + 1 < n && a[j][k + 1] == 1)
                Union(j*(n)+k,(j)*(n)+k+1);
            if(k - 1 >= 0 && a[j][k - 1] == 1)
                Union(j*(n)+k,(j)*(n)+k-1);
            if(j + 1 < n && k + 1 < n &&a[j + 1][k + 1] == 1)
                Union(j*(n)+k,(j+1)*(n)+k+1);
            if(j + 1 < n && k - 1 >= 0 && a[j + 1][k - 1] == 1)
                Union(j*(n)+k,(j+1)*(n)+k-1);
            if(j - 1 >= 0 && k + 1 < n && a[j - 1][k + 1] == 1)
                Union(j*(n)+k,(j-1)*(n)+k+1);
            if(j - 1 >= 0 && k - 1 >= 0 && a[j - 1][k - 1]==1)
                Union(j*(n)+k,(j-1)*(n)+k-1);
        }
    }
    int c[size];
    int totalIslands = 0;
    for(int i=0;i<size;i++){
        c[i]=0;
    }
    for(int j=0;j<n;j++){
        for(int k=0;k<n;k++){
            if (a[j][k] == 1){
                int x = find(j*n+k);
                if(c[x]==0){
                    totalIslands++;
                    c[x]++;
                }
                else
                    c[x]++;
            }
        }
    }
    return totalIslands;
}
int main()
{
    printf("Enter size of matrix : ");
    scanf("%d",&n);
    int a[n][n];
    printf("Enter values of matrix (either 0 or 1) : \n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    printf("No. of islands : %d\n",countIslands(a,n));
}
