#include <stdio.h>
#include<stdlib.h>
#include<string.h>

// func for valid address
int validipaddress(int o1,int o2,int o3,int o4) 
{
     if((0<o1&&o1<256) && 
        (0<=o2&&o2<256) && 
        (0<=o3&&o3<256) && 
        (0<=o4&&o4<256))
        {
         printf("VALID IPV4 IP ADDRESS \n");
         return 1;
     }
     else{
      return 0;
     }
}
char findClass(int o1)//find class
{

     if(o1>0 && o1<127)
     {
         return 'a';
     }
     else if(o1>126 && o1<192)
     {
          return 'b';
     }
     else if(o1>191 && o1<224)
     {
          return 'c';
     }
     else if((o1>223 && o1<240))
     {
         return 'd';
     }
     else 
     {
         return 'e';
     }
}
// Function to separate Network ID as well as
// Host ID and print them
void separate(int o1,int o2,int o3,int o4,char ipClass)
{
    if (ipClass=='a')
    {
        printf("Network ID is %d \n",o1);
        printf("Host ID is %d.%d.%d \n",o2,o3,o4);
    }
     if (ipClass=='b')
    {
        printf("Network ID is %d.%d \n ",o1,o2);
        printf("Host ID is %d.%d \n",o3,o4);
    }
    if (ipClass=='c')
    {
        printf("Network ID is %d.%d.%d\n ",o1,o2,o3);
        printf("Host ID is %d \n",o4);
    }
   
    else
        printf("In this Class, IP address is not"
           " divided into Network and Host ID\n");
}
 
// Driver function is to test above function
int main()
{
    char str[20]; 
    printf("enter the IP address: \n");
    scanf("%s",str);
    int o1,o2,o3,o4;
    sscanf(str,"%d.%d.%d.%d ",&o1,&o2,&o3,&o4);
    if(validipaddress(o1,o2,o3,o4))
    {
    //printf("VALID IPV4 IP ADDRESS\n");
    char ipClass = findClass(o1);
    printf("Given IP address belongs to Class %c\n",
                                           ipClass);
    separate(o1,o2,o3,o4, ipClass);
    }
    else
    {
        printf("INVALID IP ADDRESS\n");
    }
    return 0;

}
