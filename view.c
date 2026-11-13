#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void view(char *str)
{
   FILE *fptr=fopen(str,"rb");
   if(fptr==NULL)
   {
      printf("Error opening file\n");
      return;
   }
   fseek(fptr,10,SEEK_SET);
   printf("------------------------------------------------------------------\n");
   printf("                      MP3 TAG READER INFORMATION                  \n");
   printf("------------------------------------------------------------------\n"); 
   int count=0;
   char title[5];
   int size=0;
   while(count<6)
   {
            fread(title,1,4,fptr);
            title[4]='\0';
            fread(&size,1,4,fptr);
            int i=0,j=sizeof(size)-1;
            char *ptr=(char *)&size;
            while(i<j)
            {
               char temp=ptr[i];
               ptr[i]=ptr[j];
               ptr[j]=temp;
               i++;
               j--;
            }
            fseek(fptr,3,SEEK_CUR);
            char *data=malloc(size);
            if(data == NULL)
            {
                printf("Memory allocation failed\n");
                break;
            }
            fread(data,1,size-1,fptr);
            data[size-1]='\0';
            if(strcmp(title,"TIT2")==0)
            {
               printf("Title   : %s\n",data);
               free(data);
               count++;
            }
            else if(strcmp(title,"TPE1")==0)
            {
               printf("Artist  : %s\n",data);
               free(data);
               count++;
            }
            else if(strcmp(title,"TALB")==0)
            {
               printf("Album   : %s\n",data);
               free(data);
               count++;
            }
            else if(strcmp(title,"TYER")==0)
            {
               printf("Year    : %s\n",data);
               free(data);
               count++;
            }
            else if(strcmp(title,"COMM")==0)
            {
               printf("Comment : %s\n",data);
               free(data);
               count++;
            }
            else if(strcmp(title,"TCON")==0)
            {
               printf("Genre   : %s\n",data);
               free(data);
               count++;
            }
   }
   printf("------------------------------------------------------------------\n");
   if(count!=6)
   {
      printf("Some tags are missing\n");
   }
   fclose(fptr);
}