#include<stdio.h>
#include<string.h>

void view(char *str);
void edit(int argc,char *str[]);


int main(int argc,char *argv[])
{
    if(argc<2)
    {
        printf("Error: Invalid usage\n");
        printf("Usage: \n./a.out -v <mp3_file> or \n./a.out -e <option> <value> <mp3_file> or \n./a.out -h\n");
        return 1;
    }
    if(strcmp(argv[1],"-v")==0)
    {
        view(argv[2]);
    }
    else if(strcmp(argv[1],"-e")==0)
    {
        edit(argc,argv);
    }
    else if(strcmp(argv[1],"-h")== 0)
    {
        printf("MP3 Tag Reader and Editor\n");
        printf("Usage:\n");
        printf("  ./a.out -v <mp3_file>\n");
        printf("  ./a.out -e -t <title> <mp3_file>\n");
        printf("  ./a.out -e -a <artist> <mp3_file>\n");
        printf("  ./a.out -e -A <album> <mp3_file>\n");
        printf("  ./a.out -e -y <year> <mp3_file>\n");
        printf("  ./a.out -e -g <genre> <mp3_file>\n");
        printf("  ./a.out -e -c <comment> <mp3_file>\n\n");
        printf("Options:\n");
        printf("  -v    View MP3 tag information\n");
        printf("  -e    Edit MP3 tag information\n");
        printf("  -t    Edit title\n");
        printf("  -a    Edit artist\n");
        printf("  -A    Edit album\n");
        printf("  -y    Edit year\n");
        printf("  -g    Edit genre\n");
        printf("  -c    Edit comment\n");
        printf("  -h    Display help\n");
    }
    else
    {
        printf("Invalid option\n");
    }
}