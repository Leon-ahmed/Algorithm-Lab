#include<stdio.h>
#include<string.h>
int dt[100][100];
int max(int a,int b){
    return a>b? a:b;
}


int LCS(char a[],char b[],int i,int j){

    if(i==0||j==0){
        return dt[i][j]=0;
    }
    if(dt[i][j]!=-1)
        return dt[i][j];
    else if( a[i-1]==b[j-1]){
        return dt[i][j]= 1+LCS(a,b,i-1,j-1);
    }
    else return dt[i][j]= max(
        LCS(a,b,i-1,j),
        LCS(a,b,i,j-1)
    );



}



void seq(char a[],char b[],int i,int j){
     if(i==0 || j==0){
        return ;
     }
     if(a[i-1]==b[j-1]){
          
        seq(a,b,i-1,j-1);
        printf("%c",b[j-1]);
     }
     
     else{
          if(dt[i-1][j]>dt[i][j-1]){

             seq(a,b,i-1,j);
          }else{
            seq(a,b,i,j-1);
          }


     }
}


int main(){
char str1[]="ABCBDAB";
char str2[]="BDCABA";



int x=strlen(str1);
int y=strlen(str2);

for(int i=0;i<=x;i++){
 for(int j=0;j<=y;j++){
     dt[i][j]=-1;
 }   
}

printf("%d ",LCS(str1,str2,x,y));

printf("Sequence: ");
 seq(str1,str2,x,y);



}