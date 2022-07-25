#include <stdio.h>
#include <netinet/in.h>
#include <netinet/in.h>

int main(int argc, char* argv[]){
    uint32_t n1,n2;
    int result;
    int check1,check2=0;

    //File read and open
    //use rb because this is binary
    FILE *fp1=fopen(argv[1],"rb");
    FILE *fp2=fopen(argv[2],"rb");

    //If there is a Wrong Filename print error
    if (fp1==NULL)
    {
        printf("There is no %s \n",argv[1]);
        return 0;
    }
    if (fp2==NULL)
    {
        printf("There is no %s \n",argv[2]);
        return 0;
    }

    //Check fread
    check1 = fread(&n1,sizeof(uint32_t),1,fp1);
    check2 = fread(&n2,sizeof(uint32_t),1,fp2);
    if(check1!=0 and check2!=0){
        n1 = ntohl(n1);
        n2 = ntohl(n2);
    }
    result = n1 + n2;

    printf("%d(%X) + %d(%X) = %d(%X)\n",n1,n1,n2,n2,result,result);

    fclose(fp1);
    fclose(fp2);
    return 0;

}




