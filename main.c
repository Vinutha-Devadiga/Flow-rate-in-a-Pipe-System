#include<stdio.h>
#include<math.h>

float losses (int f , int l , int d)    /* Function to calculate Losses */
{
    float h = (.8 * f * l ) / (9.8 * (d^5));
    return h;
}
struct info        /* Structure to Save Tank's Input */
{
    float  f , l ,d , r  ;
    float q , e;
}tank[3];

main()
{
    int r[3];
    float E_J;
    float Delta_Q ;
    int i , j , l , k;
    char output_s[999999];  /*  String array to save output Values  */
    l=0;
    k=0;
    printf("insert Energy of tank 1 \n");
    scanf("%d",&tank[0].e);
    rewind(stdin);   /* to stop the buffering of scanf */

    printf("insert Energy of tank 2 \n");
    scanf("%d",&tank[1].e);
    rewind(stdin);

    printf("insert Energy of tank 3 \n");
    scanf("%d",&tank[2].e);
    rewind(stdin);

    printf("insert d of pipe 1 \n");
    scanf("%d",&tank[0].d);
    rewind(stdin);

    printf("insert d of pipe 2 \n");
    scanf("%d",&tank[1].d);
    rewind(stdin);

     printf("insert d of pipe 3 \n");
    scanf("%d",&tank[2].d);
    rewind(stdin);

     printf("insert l of pipe 1 \n");
    scanf("%d",&tank[0].l);
    rewind(stdin);

     printf("insert l of pipe 2 \n");
    scanf("%d",&tank[1].l);
    rewind(stdin);

     printf("insert l of pipe 3 \n");
    scanf("%d",&tank[2].l);
    rewind(stdin);

   printf("insert f of pipe 1 \n");
    scanf("%d",&tank[0].f);
    rewind(stdin);

     printf("insert f of pipe 2 \n");
    scanf("%d",&tank[1].f);
    rewind(stdin);

     printf("insert f of pipe 3 \n");
    scanf("%d",&tank[2].f);
    rewind(stdin);

    tank[0].r = losses(tank[0].f , tank[0].l , tank[0].d);    /* Calculate r for Pipes */
    tank[1].r = losses(tank[1].f , tank[1].l , tank[1].d);
    tank[2].r = losses(tank[2].f , tank[2].l , tank[2].d);

E_J = (tank[0].e + tank[2].e ) / 2 ;

while (Delta_Q >0.1 || Delta_Q < -0.1 )   /* Check The Assumption  */
{
        i=0 ;
        tank[0].q = sqrt( (tank[0].e - E_J ) / tank[0].r) ;


        tank[2].q = sqrt( ( E_J - tank[2].e ) / tank[2].r ) ;

        tank[1].q = sqrt( (tank[1].e - E_J ) / tank[1].r) ;

        if ( tank[1].q - E_J < 0 )
            tank[1].q = tank[1].q * -1 ;

            if ( E_J < tank[1].q)
        Delta_Q = tank[0].q - tank[2].q - tank[1].q ;
    else
        Delta_Q = tank[0].q - tank[2].q + tank[1].q ;

    if (Delta_Q > .1)
        E_J += .01 ;
        else if ( Delta_Q < .1 )
            E_J -= .01 ;

            if(i==10){
                printf("%d",E_J);
             i = 0 ;

             output_s[l] = printf("Iteration %d Has E_J Value = %d \n",j,E_J); /* print some output of 100s iteration */
             k++;
            }
 i++;
 j++;
}
printf("Number of iterations = %d \n ",&j);  /* Print number of iteration Program made to calculate the result */
i=0 ;
for (i=0 ; i <= k ; i++ )   /* Print The output */
    printf(" %s ",output_s[i]);
}
