#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "fun.h"

void edit(int argc,char *str[])
{
    FILE *fptr=fopen(str[argc-1],"rb");
    FILE *fptr1=fopen("temp1.mp3","wb");
    if(fptr==NULL || fptr1==NULL)
    {
        printf("Error opening file\n");
        return;
    }
    char buf[10];
    fread(buf,1,10,fptr);
    fwrite(buf,1,10,fptr1);
    char title[5];
    int size;
    int write_size;
    char flag[2];
    char *data;
    int count=0;
    while(1)
    {
        fread(title,1,4,fptr);
        title[4]='\0';
        fread(&size,1,4,fptr);
        convert_endians(&size);
        fread(flag,1,2,fptr);
        data=malloc(size);
        fread(data,1,size,fptr);
        char *tag=NULL;
        if(strcmp(str[2],"-t")==0)
            tag="TIT2";
        else if(strcmp(str[2],"-a")==0)
            tag="TPE1";
        else if(strcmp(str[2],"-y")==0)
            tag="TYER";
        else if(strcmp(str[2],"-A")==0)
            tag="TALB";
        else if(strcmp(str[2],"-g")==0)
            tag="TCON";
        else if(strcmp(str[2],"-c")==0)
            tag="COMM";
        if(strcmp(title,tag)==0)
        {
            int newsize=strlen(str[3])+1;
            write_size=newsize;
            convert_endians(&write_size);
            data=realloc(data, newsize);
            strcpy(data, str[3]);
            count++;
            char encoding=0;
            fwrite(title,1,4,fptr1);
            fwrite(&write_size,1,4,fptr1);
            fwrite(flag,1,2,fptr1);
            fwrite(&encoding,1,1,fptr1);
            fwrite(data,1,newsize-1,fptr1);
            printf("%s data updated successfully\n", tag);
            free(data);
            break;
        }
        write_size=size;
        convert_endians(&write_size);
        fwrite(title,1,4,fptr1);
        fwrite(&write_size,1,4,fptr1);
        fwrite(flag,1,2,fptr1);
        fwrite(data,1,size,fptr1);
        free(data);
    }
    char buffer[1000];
    int n;
    while((n=fread(buffer,1,1000,fptr))>0)
    {
        fwrite(buffer,1,n,fptr1);
    }
    printf("All data updated successfully into temp.mp3\n");
    printf("Replaced original file with updated file\n");
    fclose(fptr);
    fclose(fptr1);
    remove(str[argc-1]);
    rename("temp1.mp3",str[argc-1]);
}