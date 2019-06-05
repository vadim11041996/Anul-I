////////////////////////
//Lab2                //
//Matematica discreta //
//Braduleac Vadim     //
////////////////////////
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
void BKmin(int** pd,int g,int n)
{int a[40][40],b[40][40],c[40],v[40],d[40][40],aux[40],t,g2=0,num,exist[40],t_i;
int z,i,j,s=0,m,mi=1,min,h,i_h,j_h,i_h2,h_j,h_i,rec,max,p=1,k,q=0,l,x_i,x_j,r;

printf("\n");
printf("\n");
printf("\t\t\t\tDati virful final: x");
scanf("%d",&h);
printf("\n");

  for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
  a[i][j]=1000;

  for(i=1;i<=n;i++)
  a[i][i]=0;

  for(i=1;i<g;i++)
  {h_i=*(*(pd+i)+1);
  h_j=*(*(pd+i)+2);
  a[h_i][h_j]=*(*(pd+i)+3);}

for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
b[i][j]=a[i][j];

q=n+1;

for(i=1;i<=n;i++)
b[q][i]=a[i][h];

while(r!=n)
{r=0;
min=10000;

k=1;
for(i=1;i<=n;i++)
{for(j=1;j<=n;j++)
if(b[i][j]+b[q][j]<min)
min=b[i][j]+b[q][j];
v[k]=min;
min=10000;
k++;}
q++;
for(k=1;k<=n;k++)
b[q][k]=v[k];


for(j=1;j<=n;j++)
if(b[q-1][j]==b[q][j])
r++;
}
int pas;
pas=0;

for(j=1;j<=n;j++)
if(b[q][j]>500) exist[j]=1;



for(z=1;z<=n;z++)
if(z!=h&&exist[z]!=1)
{
printf("\n");
printf("Drumurile de valoare minima dmin(x%d,x%d) sunt:\n",z,h);
//printf("\n");
min=10000;
t=1;
d[1][t]=z;
t++;

i_h=z;
while(i_h!=h)
{for(j=1;j<=n;j++)
    if(b[i_h][j]+b[q][j]<min&&i_h!=j)
        {min=b[i_h][j]+b[q][j];
        d[1][t]=j;}
 for(j=1;j<=n;j++)
     if(b[i_h][j]+b[q][j]==min&&i_h!=j&&d[1][t]!=j)
            d[2][t]=j;

    min=10000;
    i_h=d[1][t];
    t++;
    }

for(i=1;i<t;i++)
{c[i]=d[1][i];
if(d[2][i]>0)
{g2=i;
l=d[2][i];}
p++;
}

if(g2!=0)
{
for(i=1;i<g2;i++)
d[2][i]=d[1][i];

min=10000;
t=g2+1;
int i_h2;
i_h2=l;
while(i_h2!=h)
{for(j=1;j<=n;j++)
    if(b[i_h2][j]+b[q][j]<min&&i_h2!=j)
        {min=b[i_h2][j]+b[q][j];
        d[2][t]=j;}
    min=10000;
    i_h2=d[2][t];
    t++;}

if(g2!=0)
printf("\tdmin(x%d,x%d)= %d =( ",z,h,b[q][z]);

for(j=1;j<t;j++)
if(d[2][j]>0)
printf("x%d ",d[2][j]);
if(d[2][1]>0)
printf(")\n",z,h);
printf("\n");
}

printf("\tdmin(x%d,x%d)= %d =( ",z,h,b[q][z]);
for(i=1;i<p;i++)
printf("x%d ",c[i]);
printf(")\n");
printf("\n");


for(i=1;i<15;i++)
{
    d[1][i]=0;
    d[2][i]=0;
}

for(i=1;i<=15;i++)
c[i]=0;

p=1;

g2=0;
l=0;
printf("\n");
}else{
        printf("Drumuri din x%d in x%d NU EXISTA\n",z,h);
        for(i=1;i<15;i++)
        {
            d[1][i]=0;
            d[2][i]=0;
        }


        for(i=1;i<=15;i++)
        c[i]=0;

        p=1;

        g2=0;
        l=0;
        printf("\n");
    }

for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
  a[i][j]=0;

for(j=1;j<=n;j++)
    exist[j]=0;

q=0;
r=0;

getch();
}

void BKmax(int** pd,int g,int n)
{int a[40][40],b[40][40],c[40],v[40],d[40][40],aux[40],t,g2=0;
int num,exist[40],t_i,z,i,j,s=0,m,mi=1,min,h,i_h,j_h,i_h2,h_j,h_i,rec,max,p=1,k,q=0,l,x_i,x_j,r;

printf("\n");
printf("\n");
printf("\t\t\t\tDati virful final: x");
scanf("%d",&h);
printf("\n");;

  for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
  a[i][j]=-999;

for(i=1;i<15;i++)
{
    d[1][i]=0;
    d[2][i]=0;
}

  for(i=1;i<=n;i++)
  a[i][i]=0;

   for(i=1;i<g;i++)
  {h_i=*(*(pd+i)+1);
  h_j=*(*(pd+i)+2);
  a[h_i][h_j]=*(*(pd+i)+3);}

    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    b[i][j]=a[i][j];

    q=n+1;

for(i=1;i<=n;i++)
b[q][i]=a[i][h];


while(r!=n)
{r=0;
max=-10000;

k=1;
for(i=1;i<=n;i++)
{for(j=1;j<=n;j++)
if(b[i][j]+b[q][j]>max)
max=b[i][j]+b[q][j];
v[k]=max;
max=-10000;
k++;}
q++;
for(k=1;k<=n;k++)
b[q][k]=v[k];


for(j=1;j<=n;j++)
if(b[q-1][j]==b[q][j])
r++;
}

for(j=1;j<=n;j++)
if(b[q][j]<-500) exist[j]=1;


for(z=1;z<=n;z++)
if(z!=h&&exist[z]!=1)
{
printf("\n");
printf("Drumurile de valoare maxima dmax(x%d,x%d) sunt:\n",z,h);
//printf("\n");
max=-9999;
t=1;
d[1][t]=z;
t++;

i_h=z;
while(i_h!=h)
{for(j=1;j<=n;j++)
    if(b[i_h][j]+b[q][j]>max&&i_h!=j)
        {max=b[i_h][j]+b[q][j];
        d[1][t]=j;}
 for(j=1;j<=n;j++)
    if(b[i_h][j]+b[q][j]==max&&i_h!=j&&d[1][t]!=j)
            d[2][t]=j;

    max=-9999;
    i_h=d[1][t];
    t++;
    }

for(i=1;i<t;i++)
{c[i]=d[1][i];
if(d[2][i]>0)
{g2=i;
l=d[2][i];}
p++;
}

if(g2!=0)
{
for(i=1;i<g2;i++)
d[2][i]=d[1][i];

max=-9999;
t=g2+1;
int i_h2;
i_h2=l;
while(i_h2!=h)
{for(j=1;j<=n;j++)
    if(b[i_h2][j]+b[q][j]>max&&i_h2!=j)
        {max=b[i_h2][j]+b[q][j];
        d[2][t]=j;}
    max=10000;
    i_h2=d[2][t];
    t++;}

if(g2!=0)
printf("\tdmax(x%d,x%d)= %d =( ",z,h,b[q][z]);

for(j=1;j<t;j++)
if(d[2][j]>0)
printf("x%d ",d[2][j]);
if(d[2][1]>0)
printf(")\n",z,h);
printf("\n");
}

printf("/tdmax(x%d,x%d)= %d =( ",z,h,b[q][z]);
for(i=1;i<p;i++)
printf("x%d ",c[i]);
printf(")\n");
printf("\n");

for(i=1;i<15;i++)
{
    d[1][i]=0;
    d[2][i]=0;
}

for(i=1;i<=15;i++)
c[i]=0;

p=1;

g2=0;
l=0;
printf("\n");
}else{
        printf("Drumuri din x%d in x%d NU EXISTA\n",z,h);
        for(i=1;i<15;i++)
        {
            d[1][i]=0;
            d[2][i]=0;
        }

        for(i=1;i<=15;i++)
        c[i]=0;

        p=1;

        g2=0;
        l=0;
        printf("\n");
    }

for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
  a[i][j]=0;

q=0;
r=0;

for(j=1;j<=n;j++)
    exist[j]=0;

getch();
}

void Fmin(int** pd,int g,int n)
{int a[40][40],b[40][40],c[40],v[40],d[40][40],aux[40],t,num,t_i,z,i,j,s=0,m,mi=1,min,h,h_j,h_i,max,p=1,k,q,l,x_i,x_j,hx_i,hx_j,r;
  printf("Algoritmul Ford minim.\n");
  printf("\n");
for(i=1;i<=n;i++)
c[i]=1000;

printf("\t\t\t\tDati virful initial: x");
scanf("%d",&z);
printf("\t\t\t\tDati virful final: x");
scanf("%d",&h);

c[z]=0;

for(i=1;i<=n;i++)
aux[i]=0;

for(i=1;i<=n;i++)
printf("%d ",c[i]);
printf("\n");

for(i=1;i<g;i++)
{
    for(j=1;j<=3;j++)
    printf("%d\t",*(*(pd+i)+j));
    printf("\n");
}

r=0;
while(r!=n)
{ r=0;

for(i=1;i<g;i++)
{   h_j=*(*(pd+i)+2);
    h_i=*(*(pd+i)+1);
    if(c[h_j]-c[h_i]>*(*(pd+i)+3));
    c[h_j]=c[h_i]+*(*(pd+i)+3);}

for(i=1;i<=n;i++)
if(aux[i]==c[i])
r++;

for(i=1;i<=n;i++)
aux[i]=c[i];
}

printf("\n");
for(i=1;i<=n;i++)
printf("%d\t",c[i]);
printf("\n");

a[1][1]=h;
t=2;
t_i=1;
num=0;
for(i=h;i>=1;i--)
for(j=i-1;j>=1;j--)
for(k=g-1;k>=1;k--)
if(c[i]-c[j]==*(*(pd+k)+3)&&*(*(pd+k)+1)==j&&*(*(pd+k)+2)==i)
   {a[1][t]=*(*(pd+k)+1);
    t++;
    i=j;
    }

printf("\n");
printf("Drumurile de valoare minima dmin(x%d,x%d) sunt:\n",z,h);
//printf("\n");

printf("\tdmin(x%d,x%d)=( ",z,h);
for(i=t-1;i>=1;i--)
printf("x%d ",a[1][i]);
printf(" )\n");

getch();

}

void Fmax(int** pd,int g,int n)
{int a[40][40],b[40][40],c[40],v[40],d[40][40],aux[40],t,num,t_i,z,i,j,s=0,m,mi=1,min,h,h_j,h_i,max,p=1,k,q,l,x_i,x_j,hx_i,hx_j,r;
  printf("Algoritmul Ford maxim.\n");
  printf("\n");
for(i=1;i<=n;i++)
c[i]=1000;

printf("\t\t\t\tDati virful initial: x");
scanf("%d",&z);
printf("\t\t\t\tDati virful final: x");
scanf("%d",&h);

c[z]=0;

for(i=1;i<=n;i++)
aux[i]=0;

for(i=1;i<=n;i++)
printf("%d ",c[i]);
printf("\n");

for(i=1;i<g;i++)
{
    for(j=1;j<=3;j++)
    printf("%d\t",*(*(pd+i)+j));
    printf("\n");
}

r=0;
while(r!=n)
{ r=0;

for(i=1;i<g;i++)
{   h_j=*(*(pd+i)+2);
    h_i=*(*(pd+i)+1);
    if(c[h_j]-c[h_i]<*(*(pd+i)+3));
    c[h_j]=c[h_i]+*(*(pd+i)+3);}

for(i=1;i<=n;i++)
if(aux[i]==c[i])
r++;

for(i=1;i<=n;i++)
aux[i]=c[i];
}

printf("\n");
for(i=1;i<=n;i++)
printf("%d\t",c[i]);
printf("\n");

a[1][1]=h;
t=2;
t_i=1;
num=0;
for(i=h;i>=1;i--)
for(j=i-1;j>=1;j--)
for(k=g-1;k>=1;k--)
if(c[i]-c[j]==*(*(pd+k)+3)&&*(*(pd+k)+1)==j&&*(*(pd+k)+2)==i)
   {a[1][t]=*(*(pd+k)+1);
    t++;
    i=j;
    }

printf("\n");
printf("Drumurile de valoare maxima dmax(x%d,x%d) sunt:\n",z,h);
printf("\n");

printf("\tdmax(x%d,x%d)=( ",z,h);
for(i=t-1;i>=1;i--)
printf("x%d ",a[1][i]);
printf(" )\n");

getch();

}

void Fmin2(int** pd,int g,int n)
{int a[40][40],b[40][40],c[40],v[40],d[40][40],aux[40],t,g2=0,num,exist[40],t_i;
int z,i,j,s=0,m,mi=1,min,h,i_h,j_h,i_h2,h_j,h_i,rec,max,p=1,k,q=0,l,x_i,x_j,r;

printf("\n");
printf("\n");
printf("\t\t\t\tDati virful initial: x");
scanf("%d",&z);
printf("\n");

for(h=1;h<=n;h++)
{
  for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
  a[i][j]=1000;

  for(i=1;i<=n;i++)
  a[i][i]=0;

  for(i=1;i<g;i++)
  {h_i=*(*(pd+i)+1);
  h_j=*(*(pd+i)+2);
  a[h_i][h_j]=*(*(pd+i)+3);}

for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
b[i][j]=a[i][j];

q=n+1;

for(i=1;i<=n;i++)
b[q][i]=a[i][h];

while(r!=n)
{r=0;
min=10000;

k=1;
for(i=1;i<=n;i++)
{for(j=1;j<=n;j++)
if(b[i][j]+b[q][j]<min)
min=b[i][j]+b[q][j];
v[k]=min;
min=10000;
k++;}
q++;
for(k=1;k<=n;k++)
b[q][k]=v[k];


for(j=1;j<=n;j++)
if(b[q-1][j]==b[q][j])
r++;
}

int pas;
pas=0;

for(j=1;j<=n;j++)
if(b[q][j]>500) exist[j]=1;

if(z!=h&&exist[z]!=1)
{
printf("\n");
printf("Drumurile de valoare minima dmin(x%d,x%d) sunt:\n",z,h);
printf("\n");
min=10000;
t=1;
d[1][t]=z;
t++;

i_h=z;
while(i_h!=h)
{for(j=1;j<=n;j++)
    if(b[i_h][j]+b[q][j]<min&&i_h!=j)
        {min=b[i_h][j]+b[q][j];
        d[1][t]=j;}
 for(j=1;j<=n;j++)
     if(b[i_h][j]+b[q][j]==min&&i_h!=j&&d[1][t]!=j)
            d[2][t]=j;

    min=10000;
    i_h=d[1][t];
    t++;
    }

for(i=1;i<t;i++)
{c[i]=d[1][i];
if(d[2][i]>0)
{g2=i;
l=d[2][i];}
p++;
}
if(g2!=0)
{
for(i=1;i<g2;i++)
d[2][i]=d[1][i];

min=10000;
t=g2+1;
int i_h2;
i_h2=l;
while(i_h2!=h)
{for(j=1;j<=n;j++)
    if(b[i_h2][j]+b[q][j]<min&&i_h2!=j)
        {min=b[i_h2][j]+b[q][j];
        d[2][t]=j;}
    min=10000;
    i_h2=d[2][t];
    t++;}


if(g2!=0)
printf("\tdmin(x%d,x%d)= %d =( ",z,h,b[q][z]);

for(j=1;j<t;j++)
if(d[2][j]>0)
printf("x%d ",d[2][j]);
if(d[2][1]>0)
printf(")\n",z,h);
printf("\n");
}

printf("\tdmin(x%d,x%d)= %d =( ",z,h,b[q][z]);
for(i=1;i<p;i++)
printf("x%d ",c[i]);
printf(")\n");
printf("\n");


for(i=1;i<15;i++)
{
    d[1][i]=0;
    d[2][i]=0;
}

for(i=1;i<=15;i++)
c[i]=0;

p=1;

g2=0;
l=0;
printf("\n");

}else{
        printf("Drumuri din x%d in x%d Nu exista\n",z,h);
        for(i=1;i<15;i++)
        {
            d[1][i]=0;
            d[2][i]=0;
        }
        for(i=1;i<=15;i++)
        c[i]=0;

        p=1;

        g2=0;
        l=0;
        printf("\n");
    }

for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
  a[i][j]=0;

for(j=1;j<=n;j++)
    exist[j]=0;

q=0;
r=0;

}
getch();
}

void Fmax2(int** pd,int g,int n)
{int a[40][40],b[40][40],c[40],v[40],d[40][40],aux[40],t,g2=0;
int num,exist[40],t_i,z,i,j,s=0,m,mi=1,min,h,i_h,j_h,i_h2,h_j,h_i,rec,max,p=1,k,q=0,l,x_i,x_j,r;

printf("\n");
printf("\n");
printf("\t\t\t\tDati virful initial: x");
scanf("%d",&z);
printf("\n");;

for(h=1;h<=n;h++)
{

  for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
  a[i][j]=-999;

for(i=1;i<15;i++)
{
    d[1][i]=0;
    d[2][i]=0;
}

  for(i=1;i<=n;i++)
  a[i][i]=0;

   for(i=1;i<g;i++)
  {h_i=*(*(pd+i)+1);
  h_j=*(*(pd+i)+2);
  a[h_i][h_j]=*(*(pd+i)+3);}


    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    b[i][j]=a[i][j];

    q=n+1;

for(i=1;i<=n;i++)
b[q][i]=a[i][h];


while(r!=n)
{r=0;
max=-10000;

k=1;
for(i=1;i<=n;i++)
{for(j=1;j<=n;j++)
if(b[i][j]+b[q][j]>max)
max=b[i][j]+b[q][j];
v[k]=max;
max=-10000;
k++;}
q++;
for(k=1;k<=n;k++)
b[q][k]=v[k];


for(j=1;j<=n;j++)
if(b[q-1][j]==b[q][j])
r++;
}

for(j=1;j<=n;j++)
if(b[q][j]<-500) exist[j]=1;

if(z!=h&&exist[z]!=1)
{
printf("\n");
printf("Drumurile de valoare maxima dmax(x%d,x%d) sunt:\n",z,h);
printf("\n");
max=-9999;
t=1;
d[1][t]=z;
t++;

i_h=z;
while(i_h!=h)
{for(j=1;j<=n;j++)
    if(b[i_h][j]+b[q][j]>max&&i_h!=j)
        {max=b[i_h][j]+b[q][j];
        d[1][t]=j;}
 for(j=1;j<=n;j++)
    if(b[i_h][j]+b[q][j]==max&&i_h!=j&&d[1][t]!=j)
            d[2][t]=j;

    max=-9999;
    i_h=d[1][t];
    t++;
    }

for(i=1;i<t;i++)
{c[i]=d[1][i];
if(d[2][i]>0)
{g2=i;
l=d[2][i];}
p++;
}

if(g2!=0)
{
for(i=1;i<g2;i++)
d[2][i]=d[1][i];

max=-9999;
t=g2+1;
int i_h2;
i_h2=l;
while(i_h2!=h)
{for(j=1;j<=n;j++)
    if(b[i_h2][j]+b[q][j]>max&&i_h2!=j)
        {max=b[i_h2][j]+b[q][j];
        d[2][t]=j;}
    max=10000;
    i_h2=d[2][t];
    t++;}

if(g2!=0)
printf("\tdmax(x%d,x%d)= %d =( ",z,h,b[q][z]);

for(j=1;j<t;j++)
if(d[2][j]>0)
printf("x%d ",d[2][j]);
if(d[2][1]>0)
printf(")\n",z,h);
printf("\n");
}

printf("\tdmax(x%d,x%d)= %d =( ",z,h,b[q][z]);
for(i=1;i<p;i++)
printf("x%d ",c[i]);
printf(")\n");
printf("\n");

for(i=1;i<15;i++)
{
    d[1][i]=0;
    d[2][i]=0;
}

for(i=1;i<=15;i++)
c[i]=0;

p=1;

g2=0;
l=0;
printf("\n");
}else{
        printf("Drumuri din x%d in x%d NU EXISTA\n",z,h);
        for(i=1;i<15;i++)
        {
            d[1][i]=0;
            d[2][i]=0;
        }
        for(i=1;i<=15;i++)
        c[i]=0;
        p=1;
        g2=0;
        l=0;
        printf("\n");
    }

for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
  a[i][j]=0;

q=0;
r=0;

for(j=1;j<=n;j++)
    exist[j]=0;
}
getch();
}
int main()
{int a[40][40],b[40][40],c[40],v[40],d[40][40],aux[40],la[40][40],t,num,t_i,z,i,j,s=0,n,m,mi=1,min,h,h_j,h_i,max,p=1,k,q,g=0,l,x_i,x_j,r;

int** pd;
system("Color 21");
pd=(int**)malloc(40*sizeof(int*));
for (i=0;i<40;i++){
    pd[i]=(int*)malloc(40*sizeof(int));
}

printf(" \t\t\t\tDati numarul de virfuri: ");
scanf("%d",&n);
printf("\n");

for(x_i=1;x_i<=n;x_i++)
for(x_j=1;x_j<=n;x_j++)
la[x_i][x_j]=-9;

for(x_i=1;x_i<=n+1;x_i++)
for(x_j=1;x_j<=n;x_j++)
{
m99:system("cls");
printf("\n");
printf(" \t\t\t\tLista de adiacenta: \n");
printf("ี");
for(j=1;j<=n+1;j++)
printf("ออออ");
printf("ธ");
printf("\n");

printf("ณ x ");
printf("|F(x)");
for(j=1;j<=n-1;j++)
printf("    ");
printf("|\n");

printf("อออออ");
for(j=1;j<=n;j++)
printf("ออออ");
printf("\n");

for(i=1;i<=n;i++)
{
    printf("| x%d|",i);

    for(j=1;j<=n;j++)
        if (la[i][j]<=n&&la[i][j]>=0)
            printf("% d ,",la[i][j]);
            else printf("    ");
            printf("|");
            printf("\n");
for(j=1;j<=n+1;j++)
printf("ออออ");
printf("\n");

}

if (x_i <= n)
    {printf("[%d][%d]= ",x_i,x_j);
    m1: scanf("%d",&la[x_i][x_j]);}
     if(la[x_i][x_j]==99){x_j=x_j-1; goto m99;}
        if(la[x_i][x_j]==88){x_i=x_i-1; x_j=n; goto m99;}
    if(la[x_i][x_j]>n) goto m1;
    if(la[x_i][x_j]==0) break;
}
g=1;
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
if(la[i][j]>0&&la[i][j]<80)
{pd[g][1]=i;
pd[g][2]=la[i][j];
g++;} else continue;

for(i=1;i<g;i++)
{m77:printf("(x%d , x%d)= ",pd[i][1],pd[i][2]);
scanf("%d",&v[i]);
if(v[i]==77)
{
    i=i-1;
    goto m77;
}
   }

for(i=1;i<g;i++)
pd[i][3]=v[i];
getch();


int ord;
system("cls");
system("color 21");
m4:printf("Alegeti algoritmul dorit:\n");
printf("\n");
printf("                    ีออออออออออออออออออออออออออออออออออออออธ\n");
printf("                    ณ  1.Algoritmul Bellman-Kalaba  minim. ณ\n");
printf("                    ฦออออออออออออออออออออออออออออออออออออออต\n");
printf("                    ณ  2.Algoritmul Bellman-Kalaba  maxim. ณ\n");
printf("                    ฦออออออออออออออออออออออออออออออออออออออต\n");
printf("                    ณ  3.Algoritmul Ford minim.            ณ\n");
printf("                    ฦออออออออออออออออออออออออออออออออออออออต\n");
printf("                    ณ  4.Algoritmul Ford maxim.            ณ\n");
printf("                    ิออออออออออออออออออออออออออออออออออออออพ\n\n");
scanf("%d",&ord);
while(ord!=0)
{
if(ord==1){system("cls"); printf("Algoritmul Bellman-Kalaba  minim.\n");BKmin(pd,g,n);system("cls");goto m4;  }
if(ord==2){system("cls"); printf("Algoritmul Bellman-Kalaba  maxim.\n");BKmax(pd,g,n);system("cls");goto m4;  }
if(ord==3){system("cls"); printf("Algoritmul Ford minim.\n");Fmin2(pd,g,n);system("cls");goto m4;  }
if(ord==4){system("cls"); printf("Algoritmul Ford maxim.\n");Fmax2(pd,g,n);system("cls");goto m4;  }
if(ord==5){system("cls");Fmin(pd,g,n);system("cls");goto m4;}
if(ord==6){system("cls");Fmax(pd,g,n);system("cls");goto m4;}
}
getch();
}
