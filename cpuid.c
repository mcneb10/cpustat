#include "cpuid.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"

#define bool(i) \
    (i ? "true" : "false")

char* inttochars(int i) {
    char *res=malloc(5);
    res[0]=(char)(i);
    res[1]=(char)(i>>8);
    res[2]=(char)(i>>16);
    res[3]=(char)(i>>24);
    res[4]=0;
    return res;
}
char* getbool(int i, int n) {
    return bool((i>>n)&1);
}

int main(int argc, char const *argv[])
{
    int a, b, c, d;
    __cpuid(0, a, b, c, d);
    char* cvsstart = inttochars(b);
    printf("CPU vendor string: %s%s%s\n",inttochars(b),inttochars(d),inttochars(c));
    int highestbasiccallingparameter=a; //Highest calling parameter (useful for determining cpu family)
    printf("Highest calling parameter: %i\n",highestbasiccallingparameter);
    __cpuid(1,a,b,c,d);
    int cpumodel = (a >> 4) & 0b1111;
    int revision = a & 0b1111;
    int cputype = (a >> 12)&0b11;
    char* cputypestring = "Unknown";
    if(a&0b11000000000||a&0b111100000000) { //cpu model is not in mode field for some reason
        //not implemented
    }
    switch (cputype)
    {
    case 0:
        cputypestring = "OEM Processor";
        break;
    case 1:
        cputypestring = "Intel Overdrive Processor";
        break;
    case 2:
        cputypestring = "Dual Processor";
        break;
    case 3:
        cputypestring = "Reserved";
        break;
    }
    printf("CPU \"Model\": %i\n",cpumodel);
    printf("CPU revision: %i\n",revision);
    printf("CPU \"type\": %s\n",cputypestring);
    printf("CPU brand index: %i\n",b&0b11111111);
    printf("CLFLUSH line size: %i\n",(b>>8)&0b11111111);
    printf("Max number of adressable IDs for physical processors: %i\n",(b>>16)&0b11111111);
    printf("APIC ID (Executing logical processor): %i\n",(b>>24)&0b11111111);
    printf("Has onboard FPU: %s\n",getbool(d,0));
    printf("Supports virtual 8086 extentions: %s\n",getbool(d,1));
    printf("Supports debugging extensions: %s\n",getbool(d,2));
    printf("Supports page size extension: %s\n",getbool(d,3));
    printf("Supports the Time stamp counter: %s\n",getbool(d,4));
    printf("Supports model specific registers: %s\n",getbool(d,5));
    printf("Supports the Physical Address Extensions: %s\n",getbool(d,6));
    printf("Supports Machine Check Exceptions: %s\n",getbool(d,7));
    printf("Supports CMPXCHG8 (Compare and Swap): %s\n",getbool(d,8));
    printf("Has onboard APIC: %s\n",getbool(d,9));
    printf("Supports SYSENTER and SYSEXIT: %s\n",getbool(d,11));
    printf("Supports Memory Type Range Registers: %s\n",getbool(d,12));
    printf("Page global enable bit set: %s\n",getbool(d,13));
    printf("Supports Machine Check Architecture: %s\n",getbool(d,14));
    printf("Supports Conditional Move and Floating Point Conditional Move: %s\n",getbool(d,15));
    printf("Supports Page Attribute Table: %s\n",getbool(d,16));
    printf("Supports 32-bit Page Size Extension: %s\n",getbool(d,17));
    printf("Supports Processor Serial Number: %s\n",getbool(d,18));
    printf("Supports CFLUSH extension: %s\n",getbool(d,19));
    printf("Supports Debug Store: %s\n",getbool(d,21));
    printf("Supports Thermal Control MSR for ACPI: %s\n",getbool(d,22));
    printf("Supports MMX: %s\n",getbool(d,23));
    printf("Supports FXSAVE and FXRSTOR: %s\n",getbool(d,24));
    printf("Supports SSE: %s\n",getbool(d,25));
    printf("Supports SSE2: %s\n",getbool(d,26));
    printf("CPU cache supports self snoop: %s\n",getbool(d,27));
    printf("Supports Hyper-Threading: %s\n",getbool(d,28));
    printf("Supports Automatic Temparature Limiting: %s\n",getbool(d,29));
    printf("Itanium emulating x86: %s\n",getbool(d,30));
    printf("Supports Pending Break Enable Wakeup: %s\n",getbool(d,31));
    printf("Supports SSE3: %s\n",getbool(c,0));
    printf("Supports Carry-Less Multiplication: %s\n",getbool(c,1));
    printf("Supports 64-bit debug store: %s\n",getbool(c,2));
    printf("Supports MONITOR and MWAIT instructions: %s\n",getbool(c,3));
    printf("Supports CPL compliant debug store: %s\n",getbool(c,4));
    printf("Supports Virtual Machine Extensions: %s\n",getbool(c,5));
    printf("Supports Safer Mode Extensions: %s\n",getbool(c,6));
    printf("Supports Enhanced Speed Step: %s\n",getbool(c,7));
    printf("Supports Thermal Monitor 2: %s\n",getbool(c,8));
    printf("Supports SSSE3: %s\n",getbool(c,9));
    printf("Supports L1 Context ID: %s\n",getbool(c,10));
    printf("Supports Silicon Debug Interface: %s\n",getbool(c,11));
    printf("Supports Fused Multiply Add: %s\n",getbool(c,12));
    printf("Supports CMPXCHG16B: %s\n",getbool(c,13));
    printf("Supports Disabling Task Priority Messages: %s\n",getbool(c,14));
    printf("Supports Perfmon and Debugging Capability: %s\n",getbool(c,15));
    printf("Supports Process Context Identifiers: %s\n",getbool(c,17));
    printf("Supports Direct Cache Access for DMA writing: %s\n",getbool(c,18));
    printf("Supports SSE4.1: %s\n",getbool(c,19));
    printf("Supports SSE4.2: %s\n",getbool(c,20));
    printf("Has x2APIC: %s\n",getbool(c,21));
    printf("Supports MOVBE instruction: %s\n",getbool(c,22));
    printf("Supports POPCNT instruction: %s\n",getbool(c,23));
    printf("PIC supports deadline/oneshot: %s\n",getbool(c,24));
    printf("Supports AES instruction set: %s\n",getbool(c,25));
    printf("Supports XSAVE, XRESTORE, XSETB, and XGETBV: %s\n",getbool(c,26));
    printf("XSAVE is enabled by the operating system: %s\n",getbool(c,27));
    printf("Supports Advanced Vector Instructions: %s\n",getbool(c,28));
    printf("Supports Conversion Between Single and Half precision floating point numbers: %s\n",getbool(c,29));
    printf("Supports RDRAND(on chip random number generation): %s\n",getbool(c,30));
    printf("Running under Hypervisor: %s\n",getbool(c,31));
    //printf("EAX: 0x%x\n",a);
    //printf("EBX: 0x%x\n",b);
    //printf("ECX: 0x%x\n",c);
    //printf("EDX: 0x%x\n",d);
    //leafs 2,3,4,and B not implemented
    __cpuid(6,a,b,c,d); 
    printf("Supports Digital Thermal Sensor: %s\n",getbool(a,0));
    printf("Supports Intel Turbo Boost: %s\n",getbool(a,1));
    printf("Supports Always Running APIC Timer: %s\n",getbool(a,2));
    printf("Supports Power Limit Notification: %s\n",getbool(a,4));
    printf("Supports Extended Clock Modulation Duty: %s\n",getbool(a,5));
    printf("Supports Package Thermal Management Capability: %s\n",getbool(a,6));
    printf("Interupt Thresholds: %i\n",b&0b1111);
    printf("Supports Hardware Coordination Feedback: %s\n",getbool(c,0));
    printf("Supports ACNT2: %s\n",getbool(c,0));
    printf("Supports Performance-Energy Bias: %s\n",getbool(c,0));
    //leaf 7 subleaf 0 not implemented
    __cpuid_count(7,1,a,b,c,d);
    printf("Supports AVX-512 BFLOAT16: %s\n",getbool(a,5));
    __cpuid(0x80000000,a,b,c,d);
    int highestextendedcallingparameter = a;
    printf("Maximum Basic Parameter: 0x%x\nMaximum Extended Parameter: 0x%x\n",highestbasiccallingparameter,highestextendedcallingparameter);
    __cpuid(0x80000001,a,b,c,d);
    printf("Multiprocessor Capable: %s\n",getbool(d,19));
    printf("NX bit set: %s\n",getbool(d,20));
    printf("Supports extended MMX: %s\n",getbool(d,22));
    printf("Supports gigabyte pages: %s\n",getbool(d,26));
    printf("Supports RDTSCP Instruction: %s\n",getbool(d,27));
    printf("Long Mode active: %s\n",getbool(d,29));
    printf("Supports Extended 3DNow!: %s\n",getbool(d,30));
    printf("Supports 3DNow!: %s\n",getbool(d,31));
    printf("Supports LAHF and SAHF in long mode: %s\n",getbool(c,0));
    printf("Supports Core Multi-Processing Legacy Mode: %s\n",getbool(c,1));
    printf("Supports Secure Virtual Machine: %s\n",getbool(c,2));
    printf("Supports Extended APIC space: %s\n",getbool(c,3));
    printf("Supports CR8 in 32-bit protected mode: %s\n",getbool(c,4));
    printf("Supports Advanced bit manipulation: %s\n",getbool(c,5));
    printf("Supports SSE4a: %s\n",getbool(c,6));
    printf("Supports misaligned SSE mode: %s\n",getbool(c,7));
    printf("Supports PREFETCH and PREFETCHW (3DNow! prefetch): %s\n",getbool(c,8));
    printf("Supports OS Visible Workaround: %s\n",getbool(c,9));
    printf("Supports Instrucion Based Sampling: %s\n",getbool(c,10));
    printf("Supports XOP instruction set: %s\n",getbool(c,11));
    printf("Supports SKINIT and STGI instructions: %s\n",getbool(c,12));
    printf("Supports Watchdog Timer: %s\n",getbool(c,13));
    printf("Supports Light Weight Profiling: %s\n",getbool(c,15));
    printf("Supports 4 operands fused multiply add: %s\n",getbool(c,16));
    printf("Supports Translation Cache Extension: %s\n",getbool(c,17));
    printf("Supports NodeId MSR: %s\n",getbool(c,19));
    printf("Supports Trailing Bit Manipulation: %s\n",getbool(c,21));
    printf("Supports Topology Extensions: %s\n",getbool(c,22));
    printf("Supports Core performance counter extensions: %s\n",getbool(c,23));
    printf("Supports NB performance conter extensions: %s\n",getbool(c,24));
    printf("Supports Data Breakpoint extensions: %s\n",getbool(c,26));
    printf(": %s\n",getbool(c,27));
    printf("Supports L2I performance conter extensions: %s\n",getbool(c,28));
    __cpuid(0x80000002,a,b,c,d);
    printf("Processor Brand String: %s%s%s%s",inttochars(a),inttochars(b),inttochars(c),inttochars(d));
    __cpuid(0x80000003,a,b,c,d);
    printf("%s%s%s%s",inttochars(a),inttochars(b),inttochars(c),inttochars(d));
    __cpuid(0x80000004,a,b,c,d);
    printf("%s%s%s%s\n",inttochars(a),inttochars(b),inttochars(c),inttochars(d));
    __cpuid(0x80000008,a,b,c,d);
    int corecount = (c&0b11111111)+1;
    printf("Amount of physical cores: %i\n",corecount);
    //IT'S HAMMER TIME!
    __cpuid(0x8FFFFFFF,a,b,c,d);
    if(a) {
        printf("Has AMD easter egg: true\n");
        printf("%s%s%s%s\n",inttochars(a),inttochars(b),inttochars(c),inttochars(d));
    } else {
        printf("Has AMD easter egg: false :(\n");
    }
    return 0;
}
