/**
 * @file main.c
 * @author Alex Joseph (josephvalex@gmail.com)
 * @brief: Template code for interfacing SDcard with FRDMKL25Z Board.
 *         Values written in two arrays are written into SDcard. This can be replaced
 *         with  sensor values
 */

#include "mbed.h"
#include "SDFileSystem.h"
 
SDFileSystem sd(PTD2,PTD3,PTD1,PTD0, "sd"); // mosi, miso, sclk, cs; 
DigitalOut MY_LED1(LED1); 

int main() {
    int i=0,j=0,ar1[600],ar2[600];
    printf("Testing SDcard!\n");   
 
    mkdir("/sd/mydir", 0777);
    
    FILE *fp = fopen("/sd/mydir/sdtest.txt", "w");
    if(fp == NULL) {
        error("Could not open file for write\n");
            }
			
    fprintf(fp, "\t\t\t PRE \t\t\t");
    fprintf(fp, "\t\t\t TEMP \t\t\t\n");
    
    for(i=0;i<600; i++){
            ar1[i]= i;
            }

    for(j=0; j<600; j++){
            ar2[j]= j;
            }

    for(int k=0; k<600;k++){
    fprintf(fp,"%d", ar1[k]);
    fprintf(fp,"%d", ar2[k]);
            }

    fclose(fp); 
 
    printf("Test Completed!!\n");
    MY_LED1=1;



}