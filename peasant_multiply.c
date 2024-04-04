#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long ulong;
typedef unsigned char uchar;

// modifies the original string. reverse the order of the string.
char * reverseString(char *str) {
    char *start = str;
    char *end = str + strlen(str) - 1;
    char temp;

    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    return str;
}

// returns dynamically allocated string containing binary representation of parameter. aborts if NULL returned from strdup.
char * decToBinary(ulong n) {
    char bit_array[67];
    int index=0; 
    memset(bit_array,0,sizeof(bit_array));
    int foundSignificantDigit = 0; //eat leading zeros.
    uchar num_bits = sizeof(uchar)*8-1;
    for (char i = num_bits; i >= 0; i--) {
        int bit = (n >> i) & 1;
        if (bit == 1 || foundSignificantDigit) {
            bit_array[index++]=bit+'0';
            foundSignificantDigit = 1;
        }
    }
    if (!foundSignificantDigit)
            bit_array[index++]='0';
    char * temp = strdup(bit_array);
    assert(temp != NULL);
    return temp;
}

void modified_russian_multiply(ulong multiplicand, ulong multiplier) {

    printf("Modified Russian peasant multiply: %lu x %lu\n",multiplicand,multiplier);
    uchar maxvals=100,
        powers2_index=0,
        composites_index=0;
    ulong powers2[maxvals],
        composites[maxvals];
    // use binary number to identify factors
    char * bmultiplicand = reverseString(decToBinary(multiplicand));
    ulong p2=1,composite=multiplier;
    int index=0;
    for ( ;p2<=multiplicand;p2=p2+p2,composite=composite+composite,index++) {
        char c=(bmultiplicand[index]=='1')?'*':' ';
        if ( bmultiplicand[index]== '1') {
            powers2[powers2_index++]=p2;
            composites[composites_index++]=composite;
        }
        printf("%9lu\t%c\t%9lu\n",p2,c,composite);
    }    
    printf("======================\n");
    ulong total=0L;
    for (int i=0;i<powers2_index;i++){
        total += powers2[i];
        if (i==0) {
            printf("%ld",powers2[i]);
        } else {
            printf(" + %ld",powers2[i])  ;
        }
    }
    printf(" = %ld\n",total);
    printf("======================\n");
    total=0L;
    for (int i=0;i<composites_index;i++){
        total += composites[i];
        if (i==0) {
            printf("NO MULTIPLY ANSWER %ld",composites[i]);
        } else {
            printf(" + %ld",composites[i])  ;
        }
    }
    printf(" = %ld\n",total);
    printf("======================\n");
    printf("CHECK ANSWER %ld x %ld = %ld\n", multiplicand, multiplier, total);
    free(bmultiplicand);
}
#ifdef MAIN
int main(int argc, char *argv[]){
    if (argc != 3) {
        fprintf(stderr,"Remember: Multiplicand × Multiplier = Product\n");
        fprintf(stderr,"Multiply using the MODIFIED Russian peasant multipliction.(Only addition needed.)\nUsage: %s multiplicand multiplier\n", argv[0]);
        fprintf(stderr,"Add the numbers in left column marked with asterisk and it totals the multiplicand.\nDoubling 1, produces the powers of two.\n");
        fprintf(stderr,"Add the numbers in right column marked with asterisk and it totals the product.\nCreated by doubling the multiplier.\n");
        fprintf(stderr,"%s 10 10\n", argv[0]);
        fprintf(stderr,"Modified Russian peasant multiply: 10 x 10\n");
        fprintf(stderr,"        1	 	       10\n");
        fprintf(stderr,"        2	*	       20\n");
        fprintf(stderr,"        4 		       40\n");
        fprintf(stderr,"        8	*	       80\n");
        fprintf(stderr,"\n\n** Limited by 64-bit integers\n");
        fprintf(stderr,"======================\n");
        fprintf(stderr,"2 + 8 = 10\n");
        fprintf(stderr,"======================\n");
        fprintf(stderr,"NO MULTIPLY ANSWER 20 + 80 = 100\n");
        fprintf(stderr,"======================\n");
        fprintf(stderr,"CHECK ANSWER 10 x 10 = 100\n");

        return 1;
    }
   ulong multiplicand = atol(argv[1]),
         multiplier   = atol(argv[2]);
   modified_russian_multiply(multiplicand, multiplier) ;
   return 0;
}
#endif
