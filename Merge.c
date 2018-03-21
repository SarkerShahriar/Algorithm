#include <stdio.h>
#include <stdlib.h>

int a[6]={5,3,7,2,6,4};
int b[6],i,j,k,l;

void merging(int beg,int mid,int ending)
{
    int h;
    h=beg,j=mid+1,k=beg;

    while(h<=mid && j<=ending)
    {

        if(a[h]<=a[j])
        {

            b[k]=a[h];
            h++;
        }
        else
        {

            b[k]=a[j];
            j++;
        }
        k++;
    }

    if(h<=mid)
    {
        for(l=h;l<=mid;++l)
        {
            b[k]=a[l];
            ++k;
        }
    }
    else
    {
        for(l=j;l<=ending;++l)
        {
            b[k]=a[l];
            k++;
        }
    }

    for(k=beg;k<=ending;k++)
    {

        a[k]=b[k];
    }
}

void sorting(int beg,int ending)
{
    int mid;
    if (beg<ending)
    {

        mid=(beg+ending)/2;
        sorting(beg,mid);
        sorting(mid+1,ending);
        merging(beg,mid,ending);
    }
}

int main()
{

    sorting(0,5);
    for(int i=0;i<5;i++)
    {
        printf ("%d ",b[i]);
    }
}
