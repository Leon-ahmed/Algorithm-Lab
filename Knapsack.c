#include<stdio.h>

int main()
{
    int n=4, max_c = 7;

    int p[n+1], w[n+1];
    int v[n+1][max_c+1];

    for(int i=1; i<=n; i++){
        printf("Enter the weight and profit of %d No. item: ", i);
        scanf("%d %d", &w[i], &p[i]);
    }

    for(int i=1; i<=n; i++){
        printf("%d\t%d", w[i], p[i]);
        printf("\n");

    }

    for(int i=0;  i<=n; i++){
        v[i][0] = 0;
    }

    for(int i=0;  i<=max_c; i++){
        v[0][i] = 0;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=max_c; j++){
        int prev_max = v[i-1][j];
        int cur_max;
        if(j-w[i]<0){
            cur_max = 0;
        }else{
            cur_max = v[i-1][j-w[i]] + p[i];
        }


        if(prev_max > cur_max){
            v[i][j] = prev_max;
        }else{
            v[i][j] = cur_max;
        }

        }

    }

    int max_prof = 0;

    for(int i=1; i<=n; i++){
        for(int j=0; j<=max_c; j++){
            printf("%d\t", v[i][j]);


            if (v[i][j]>max_prof){
                max_prof = v[i][j];
            }

        }
        printf("\n");

    }

    printf("Maximum Profit = %d", max_prof);



    return 0;
}
