#include<stdio.h>

void main() {
    int n, i, key, flag = 0, count = 0; 

    
    printf("Enter the limit of array: "); 
    scanf("%d", &n);
    count += 2;  

    int a[n];  

    
    printf("Enter the elements of array: \n");
    count++;
    for (i = 0; i < n; i++)
    { 
        scanf("%d", &a[i]);
        count += 2;  
    }
    count ++;  

    
    printf("Enter the search key: "); 
    scanf("%d", &key);
    count += 2;  

    
    for (i = 0; i < n; i++) 
    { 
        if (a[i] == key)
        { 
            flag = 1; 
            break;  
        }
        count += 3;  
    }
    count++;  

    if (flag == 1)
    { 
        printf("The search key %d is found at %dth position", key, i + 1);
        count += 2;  
    }
    else
    { 
        printf("The search key %d is not found", key);
        count += 2;  
    }

    count++;
    printf(" %d times", count);  // 
}
