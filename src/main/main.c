#include <stdio.h>			
#include <gmp.h>

int main(int argc, char *argv[]){

mpf_t f_a, f_b, f_c;
mpf_t disc, d1, d2, num; //for discriminant
mpf_t square, firstNum, secondNum, denom;
float i_a, i_b, i_c; //input use
int resultingType;

mpf_init(f_a); //initialize argument to 0
mpf_init(f_b);
mpf_init(f_c); 

mpf_init(d1); 
mpf_init(d2); 
mpf_init(disc); 

mpf_init(square);
mpf_init(firstNum);
mpf_init(secondNum);
mpf_init(denom);

mpf_set_d(num, -4);

if(argc<4){

    printf("%s","Please input 3 floating point numbers");
        scanf("%f",&i_a);
        scanf("%f",&i_b);
        scanf("%f",&i_c);

} 

else{

    sscanf(argv[1], "%f", &i_a);
    sscanf(argv[2], "%f", &i_b);
    sscanf(argv[3], "%f", &i_c);

}

mpf_set_d(f_a,i_a);
mpf_set_d(f_b,i_b);
mpf_set_d(f_c,i_c);

mpf_mul(d1, f_b, f_b);
mpf_mul(d2, f_a, f_c);
mpf_mul(d2, num, d2);
mpf_add(disc, d1, d2);

mpf_set_d(num, 2);
mpf_mul(denom, num, f_a);

mpf_set_d(num, 0);
resultingType = mpf_cmp(disc, num);
mpf_set_d(num, 2);

}