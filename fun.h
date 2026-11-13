void convert_endians(int *s)
{
    int i=0,j=sizeof(*s)-1;
    char *ptr=(char *)s;
    char temp;
    while(i<j)
    {
        temp=ptr[i];
        ptr[i]=ptr[j];
        ptr[j]=temp;
        i++;
        j--;
    }
}