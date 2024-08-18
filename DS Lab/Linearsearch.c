#include<stdio.h>
void main()
{
   int n,i,key,flag=0,count=0;                       
   printf("Enter the limit of array :"); count++;
   scanf("%d",&n);count++;
   int a[n];
   printf("Enter the elements of array : \n"); count++;
   for(i=0;i<n;i++)
   { count++;
     scanf("%d",&a[i]);count++;
   }
   printf("Enter the search key :");count++;
   scanf("%d",&key);count++;
   for(i=0;i<n;i++) 
   {count++;
     if(a[i]==key)
     {count++;
      flag=1;count++;
      break;count++;
     }   
   }
   if(flag==1) 
     {count++;
     printf("The search key %d is found at %d th postion",key,i+1);count++;
     }  
   else
     {count++;
     printf("The search key %d is not found",key);count++;
     }
      printf(" %d time",count);
}    
