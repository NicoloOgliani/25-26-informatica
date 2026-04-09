/*aprire /creare un file binario*/
#include <stdio.h>
int main(){
    FILE *fp=fopen("numeri.bin", "rb");
    int numeri[3], i;

    if(fp==NULL){
        printf("Errore di apertura file");
        return 1;
    }
    fread(numeri, sizeof(int), 3, fp);
    for(i=0; i<3; i++){
        printf("%d\n", numeri[i]);
    }
    fclose(fp);
}