#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define BLOCKSIZE 512

//defining the recap
int inputError()
{
    printf("Usage: ./recover image\n");
    return 1;
}

int fileError(char filename[])
{
     printf("Can't open the file: %s\n", filename);
     return 1;
}

//defining bool logic
bool isJpgHeader(uint8_t buffer[])
{
    return buffer[0] == 0xff
    && buffer[1] == 0xd8
    && buffer[2] == 0xff
    && (buffer[3] & 0xf0) == 0xe0;
}

//defining the recap
int main(int argc, char *argv[])
{
    //checking arguments
    if(argc!=2)
    {
        return inputError();
    }
    
    char* inputFile = argv[1];
    
    //checking if the inputfile is null
    if(inputFile == NULL)
    {
        return inputError();
    }
    
    //opening the pointer for reading
    FILE* inputPtr = fopen(inputFile, "r");
    if(inputPtr == NULL)
    {
      return fileError(inputFile);
    }
    
    // it is 8 beacuse Harvard wanted ***.jpg so it has to have 7 characters plus \0
    char filename[8];
    FILE* outputPtr = NULL;
    uint8_t buffer[BLOCKSIZE];
    int jpgCounter=0;
    
    //checking if the pointer is at the end
    while(fread(buffer, sizeof(uint8_t), BLOCKSIZE, inputPtr) || feof(inputPtr)==0)
    {
        if(isJpgHeader(buffer))
        {
            //closing if it is not null
            if(outputPtr!=NULL)
            {
                fclose(outputPtr);
            }
            sprintf(filename, "%03i.jpg", jpgCounter);
            outputPtr = fopen(filename, "w");
            jpgCounter++;
        }
        if(outputPtr!=NULL)
        {
            fwrite(buffer, sizeof(buffer), 1, outputPtr);
        }
    }
    //closing all pointers one by one 
    if(inputPtr==NULL)
    {
        fclose(inputPtr);
    }
    
    if(outputPtr==NULL)
    {
        fclose(outputPtr);
    }
    return 0;
}