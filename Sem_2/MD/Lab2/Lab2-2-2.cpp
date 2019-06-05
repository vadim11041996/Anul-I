#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define N 50

int t_lista[N][N], t_pondere[N][N], v_drum[N], n_virfuri, v_initial, v_final, v_intermediar, pon_max=0, item, ultimul_rind;

int menu(){
int i;
meniu:
printf("\n");
system("Color 21");
            printf("                     ÕÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸\n");
            printf("                     ³        Alegeti algoritmul dorit!          ³\n");
            printf("                     ÆÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍµ\n");
            printf("                     ³ 1.Algoritmul Bellman Kalaba (drum minim)  ³\n");
            printf("                     ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´\n");
            printf("                     ³ 2.Algoritmul Bellman Kalaba (drum maxim)  ³\n");
            printf("                     ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´\n");
            printf("                     ³ 3.Algoritmul Ford (drum minim)            ³\n");
            printf("                     ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´\n");
            printf("                     ³ 4.Algoritmul Ford (drum maxim)            ³\n");
            printf("                     ÔÍÄÍÄÍÄÍÄÍÄÍÄÍÄÍÄÍÄÍÄÍÄÍÄÍÄÍÄÍÄÍÄÍÄÍÄÍÄÍÄÍÄÍ¾\n");
scanf("%d",&i);
while(i!=1 && i!=2 && i!=3 && i!=4){
    printf("                        Ati ales optiune gresita!!!\n");
    Sleep(2500);
    system("cls");
    goto meniu;
}
return(i);
}

void citire_lista_adiacenta(int t[N][N], int x){
int i, j, k;
printf("                   Introduceti lista de adiacenta a grafului:\n");
for(i=1; i<=x; i++){
    for(j=1; j<=x; j++){
        printf("F(X%d)[%d]=",i,j);
        scanf("%d",&t[i][j]);
        for(k=1; k<=j; k++)
        if(t[i][k]==t[i][j] && k!=j){
            printf("Aceste arc deja a fost introdus!\n");
            t[i][j]=0;
            j--;
            continue;
        }
        if(t[i][j]<0 || t[i][j]>x || t[i][j]==i){
            printf("Eroare la valoare!\n");
            t[i][j]=0;
            j--;
            continue;
        }
        if(t[i][j]==0) break;
    }
}
}

void citire_pondere_lista(int t1[N][N], int t2[N][N], int x){
int i, j;
printf("\n                  Introduceti ponderea pentru urmatoarele arce:\n");
for(i=1; i<=x; i++)
    for(j=1; j<=x; j++){
    if(t1[i][j]==0) break;
    printf("P(X%d,X%d)=",i,t1[i][j]);
    scanf("%d",&t2[i][t1[i][j]]);
    if(pon_max<t2[i][t1[i][j]]) pon_max=t2[i][t1[i][j]];
    if(t2[i][t1[i][j]]<0){
        printf("Ponderea nu poate fi negativa!\n");
        j--;
    }
    }
for(i=1; i<=x; i++)
    for(j=1; j<=x; j++)
        if(t2[i][j]==0 && i!=j){
            if(item==1 || item==3)
                t2[i][j]=3*pon_max;
            if(item==2 || item==4)
                t2[i][j]=(-3)*pon_max;
        }

}

void golire(int t[N][N]){
int i, j;
for(i=0; i<N; i++)
    for(j=0; j<N; j++)
    t[i][j]=0;
}

void golire_vector(int v[N]){
int i;
for(i=0; i<N; i++)
    v[i]=0;
}

int minim_vector(int v[N], int *pozitia, int x){
int i;
int minim=v[1];
*pozitia=1;
for(i=2; i<=x; i++)
    if(v[i]<minim){
        minim=v[i];
        *pozitia=i;
    }
return(minim);
}

int maxim_vector(int v[N], int *pozitia, int x){
int i;
int maxim=v[1];
*pozitia=1;
for(i=2; i<=x; i++)
    if(v[i]>maxim){
        maxim=v[i];
        *pozitia=i;
    }
return(maxim);
}

void adunare_vectori(int v1[N], int v2[N], int v3[N], int x){
int i;
for(i=1; i<=x; i++)
    v3[i]=v1[i]+v2[i];
}

int comparare_vectori(int v1[N], int v2[N], int x){
int i, j;
j=0;
for(i=1; i<=x; i++)
    if(v1[i]==v2[i]) j++;
if(j==x) return(1);
else return(0);
}

void transpunere_matrice(int t[N][N], int x){
int t2[N][N], i, j;
for(i=1; i<=x; i++)
    for(j=1; j<=x; j++)
    t2[i][j]=t[j][i];
for(i=1; i<=x; i++)
    for(j=1; j<=x; j++)
        t[i][j]=t2[i][j];
}

void inversare_vector(int v[N], int x){
int i, j=1, vec[N];
golire_vector(vec);
for(i=x; i>=1; i--)
    if(v[i]!=0){
        vec[j]=v[i];
        j++;
    }
for(i=1; i<=x; i++)
    v[i]=vec[i];
}

void completare_liste_min(int t[N][N], int x){
int i, j, a, vec[N];
virf_final1:
system("cls");
if(item==1)
printf("\n                       Care este virful fixat(final)?\n");
if(item==3)
printf("\n                       Care este virful fixat(initial)?\n");
scanf("%d",&v_final);
if(v_final<=0 || v_final>n_virfuri){
    printf("\n            Ati introdus un virf gresit, mai introduceti odata!\n");
    fflush(stdin);
    Sleep(4000);
    goto virf_final1;
}
for(j=1; j<=x; j++)
    t[x+1][j]=t[j][v_final];
for(j=1; j<=x; j++){
    adunare_vectori(t[x+1],t[j],vec,x);
    t[x+2][j]=minim_vector(vec,&a,x);
}
i=x+2;
while((comparare_vectori(t[i-1],t[i],x))==0){
    for(j=0; j<=x; j++){
    adunare_vectori(t[i],t[j],vec,x);
    t[i+1][j]=minim_vector(vec,&a,x);
    }
    i++;
}
ultimul_rind=i;
}

void completare_liste_max(int t[N][N], int x){
int i, j, a, vec[N];
virf_final2:
system("cls");
if(item==2)
printf("\n                       Care este virful fixat(final)?\n");
if(item==4)
printf("\n                       Care este virful fixat(initial)?\n");
scanf("%d",&v_final);
if(v_final<=0 || v_final>n_virfuri){
    printf("\n            Ati introdus un virf gresit, mai introduceti odata!\n");
    fflush(stdin);
    Sleep(4000);
    goto virf_final2;
}
for(j=1; j<=x; j++)
    t[x+1][j]=t[j][v_final];
for(j=1; j<=x; j++){
    adunare_vectori(t[x+1],t[j],vec,x);
    t[x+2][j]=maxim_vector(vec,&a,x);
}
i=x+2;
while((comparare_vectori(t[i-1],t[i],x))==0){
    for(j=0; j<=x; j++){
    adunare_vectori(t[i],t[j],vec,x);
    t[i+1][j]=maxim_vector(vec,&a,x);
    }
    i++;
}
ultimul_rind=i;
}

void afisare_rezultat(int t[N][N], int x){
int i;
for(i=1; i<=x; i++)
    printf("\tX%d",i);
printf("\n");
for(i=1; i<=x; i++){
    if(t[ultimul_rind][i]==(3*pon_max)){
        printf("\t~");
        continue;
    }
    if(t[ultimul_rind][i]<0){
        printf("\t-~");
        continue;
    }
    printf("\t%d",t[ultimul_rind][i]);
}
}

void completare_drum_minim(int t[N][N], int v[N], int x){
int i=1, pozitia, vec[N], v1=v_initial, v2=v_final;
v[1]=v_initial;
while(v[i]!=v_final){
    adunare_vectori(t_pondere[ultimul_rind],t_pondere[v[i]],vec,x);
    minim_vector(vec,&pozitia,x);
    i++;
    v[i]=pozitia;
}
v_initial=v1;
v_final=v2;
}

void completare_drum_maxim(int t[N][N], int v[N], int x){
int i=1, pozitia, vec[N], v1=v_initial, v2=v_final;
v[1]=v_initial;
while(v[i]!=v_final){
    adunare_vectori(t_pondere[ultimul_rind],t_pondere[v[i]],vec,x);
    maxim_vector(vec,&pozitia,x);
    i++;
    v[i]=pozitia;
}
v_initial=v1;
v_final=v2;
}

void afisare_drum(int v[N], int x){
int i;
for(i=1; i<=x; i++){
    if(v[i+1]==0){
        printf("X%d.",v[i]);
        break;
    }
    else
        printf("X%d, ",v[i]);
}
}

main(){
int i, j;
golire(t_lista);
golire(t_pondere);
golire_vector(v_drum);
item=menu();
numarul_virfuri:
system("cls");
printf("\n                        Care este numarul virfurilor?\n");
scanf("%d",&n_virfuri);
if(n_virfuri<=0 || n_virfuri>45){
    printf("\n            Ati introdus un numar gresit, mai introduceti odata!\n");
    fflush(stdin);
    Sleep(4000);
    goto numarul_virfuri;
}
citire_lista_adiacenta(t_lista,n_virfuri);
system("cls");
citire_pondere_lista(t_lista,t_pondere,n_virfuri);
system("cls");
switch(item){
case(1):
    completare_liste_min(t_pondere,n_virfuri);
    break;
case(2):
    completare_liste_max(t_pondere,n_virfuri);
    break;
case(3):
    transpunere_matrice(t_pondere,n_virfuri);
    completare_liste_min(t_pondere,n_virfuri);
    break;
case(4):
    transpunere_matrice(t_pondere,n_virfuri);
    completare_liste_max(t_pondere,n_virfuri);
    break;
}
if(item==1)
printf("    Ponderea drumurilor minime de la toate virfurile la virful final X%d este:\n\n",v_final);
if(item==2)
printf("    Ponderea drumurilor maxime de la toate virfurile la virful final X%d este:\n\n",v_final);
if(item==3)
printf("\n  Ponderea drumurilor minime de la virful initial X%d la toate virfurile este:\n\n",v_final);
if(item==4)
printf("\n  Ponderea drumurilor maxime de la virful initial X%d la toate virfurile este:\n\n",v_final);
afisare_rezultat(t_pondere,n_virfuri);
printf("\n\n                     Pentru a continua apasati un buton...\n");
getch();
virf_initial:
system("cls");
if(item==1 || item==2)
printf("\n                           Care este virful initial?\n");
if(item==3 || item==4)
printf("\n                            Care este virful final?\n");
scanf("%d",&v_initial);
if(v_initial==v_final || v_initial<=0 || v_initial>n_virfuri){
    printf("\n            Ati introdus un virf gresit, mai introduceti odata!\n");
    fflush(stdin);
    Sleep(4000);
    goto virf_initial;
}
if(item==1 || item==3){
for(i=1; i<=n_virfuri; i++)
    t_pondere[i][i]=3*pon_max;
    completare_drum_minim(t_pondere,v_drum,n_virfuri);
    if(item==3){
        v_intermediar=v_initial;
        v_initial=v_final;
        v_final=v_intermediar;
    }
    printf("\n                 Drumul minim din virful X%d in virful X%d este:\n",v_initial,v_final);
}
if(item==2 || item==4){
for(i=1; i<=n_virfuri; i++)
    t_pondere[i][i]=(-3)*pon_max;
    completare_drum_maxim(t_pondere,v_drum,n_virfuri);
    if(item==4){
        v_intermediar=v_initial;
        v_initial=v_final;
        v_final=v_intermediar;
    }
    printf("\n                 Drumul maxim din virful X%d in virful X%d este:\n",v_initial,v_final);

}
if(item==3 || item==4)
    inversare_vector(v_drum,n_virfuri);
afisare_drum(v_drum,n_virfuri);
printf("\n");
getch();
}
