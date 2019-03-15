#include <stdio.h>
#include <stdlib.h>

int main(){

    int i,j;
    double a[3][4], b[3][4], n, c[3][4];
    double x1, x2, x3;
    for(i=0;i<3;i++)
        for(j=0;j<4;j++){
            printf ("введите элемент [%d,%d]=",i+1,j+1);
            scanf ("%lf",&a[i][j]);}
    printf("\n");
    for(i=0;i<3;i++){
        for(j=0;j<4;j++)
            printf (" %.4f ",a[i][j]);
        printf ("\n");
        b[0][0]=a[0][0];}
    
    for(j=0;j<4;j++){
        a[0][j]/=b[0][0];
    }
    for(j=0;j<4;j++){
        c[0][j]=a[0][j];}
    for(j=0;j<4;j++){
        b[0][j]=a[0][j];
    }
    for(j=0;j<4;j++){
        a[0][j]*=-a[1][0];
    }
    for(j=0;j<4;j++){
        b[1][j]= a[0][j]+a[1][j];
    }
    
    for(j=0;j<4;j++){
        b[0][j]*=-a[2][0];
    }
    
    for(j=0;j<4;j++){
        b[2][j]=b[0][j]+a[2][j];
    }
    n=b[1][1];
    for(j=0;j<4;j++){
        b[1][j]/=n;
    }
    for(j=0;j<4;j++){
        c[1][j]=b[1][j];}
    for(j=0;j<4;j++){
        b[1][j]*=-b[2][1];
    }
    for(j=0;j<4;j++) {
        a[2][j]=b[1][j]+b[2][j];
    }
    n=a[2][2];
    for(j=0;j<4;j++){
        a[2][j]/=n;
    }
    for(j=0;j<4;j++){
        c[2][j]=a[2][j];}
    printf ("\n");
    
    for(i=0;i<3;i++){
        for(j=0;j<4;j++)
            printf (" %.4f ",c[i][j]);
        printf ("\n");
    }
    printf ("\n");
    x3=c[2][3];
    x2=c[1][3]-x3*(c[1][2]);
    x1=c[0][3]-x3*(c[0][2])-x2*(c[0][1]);
    printf (" x1 равен %.4f\n x2 равен %.4f\n x3 равен %.4f\n", x1, x2, x3);
    return 0;
}
