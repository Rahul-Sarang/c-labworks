#include<stdio.h>
void main()
{
   int i,j,n,mid,key;
   printf("Enter the limit of array :");
   scanf("%d",&n);
   int a[n];
   printf("Enter the elements of array  accending order sorted  : \n");
   for(i=0;i<n;i++)
   { 
     scanf("%d",&a[i]);
   }
   printf("Enter the search key :");
   scanf("%d",&key);
   
   int left=0,right=n-1;
  while (left<=right)
   { 
        mid=(left+right)/2;
       if (a[mid]==key)
         {
         printf("The key is found at %d th position",mid+1);
         break;
         } 
      else if(key<a[mid])
         {
           right=mid-1;
         }
      else 
      {
        left=mid+1; 
      }
     
   }
   
    if(left>right) 
            {
                    printf("The key is not found");
             }    
  
}
