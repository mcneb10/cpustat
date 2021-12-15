#include "cpuid.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

char* inttochars(int i) {
    char *res=malloc(5);
    res[0]=(char)(i);
    res[1]=(char)(i>>8);
    res[2]=(char)(i>>16);
    res[3]=(char)(i>>24);
    res[4]=0;
    return res;
}

int main(int argc, char const *argv[])
{
    int a, b, c, d;
    __cpuid(0, a, b, c, d);
    printf("CPU vendor string: %s%s%s\n",inttochars(b),inttochars(d),inttochars(c));
    int highestbasiccallingparameter=a; //Highest calling parameter (useful for determining cpu family)
    printf("Highest calling parameter: %i\n",highestbasiccallingparameter);
    __cpuid(1,a,b,c,d);
    int cpumodel = (a >> 4) & 0b1111;
    int revision = a & 0b1111;
    if(a|0b11000000000||a|0b111100000000) { //cpu model is not in mode field for some reason
        //not implemented
    }
    printf("CPU \"Model\": %i\n",cpumodel);
    printf("CPU revision: %i\n",revision); 
    return 0;
}
