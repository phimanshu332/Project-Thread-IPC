#include<stdio.h>

#include<stdlib.h>

#include<unistd.h>

#include<sys/types.h>

#include<string.h>

#include<sys/wait.h>


int main()

{

    
int fd1[2];   
int fd2[2];      
char input_str[100];
    
pid_t p;

    
if (pipe(fd1)==-1)
    
{
        
printf("Pipe Failed");
        
return 1;
    
}
    
if (pipe(fd2)==-1)
    
{
        
printf("Pipe Failed");
        
return 1;
    
}
    
int len;

    
if(len=read(0,input_str,100))
	
{
p = fork();

    
if (p < 0)
    
{
        
printf("Fork Failed");
        
return 1;
    
}

      
else if (p > 0)
    
{
        
close(fd1[0]);  
        
write(fd1[1], input_str, len);
        
close(fd1[1]);

        
       
 wait(NULL);

        
close(fd2[1]);        
read(fd2[0], input_str, 100);
        
printf("%s\n", input_str);
        
close(fd2[0]);
    
}

        
else
    
{
        
close(fd1[1]);               
char buffer[100];
        
int n=read(fd1[0], buffer, 100);
        
int i;
        
for (i=0; i<n; i++)
            
{
                
if(buffer[i]<65||(buffer[i]>90&&buffer[i]<97)||buffer[i]>122)
                    
continue;
                
else 
{
                        
if(buffer[i]>=65&&buffer[i]<=90)
                        
{
                            
buffer[i]+=32;
                        
}
                        
else buffer[i]-=32;
                
}

            
}

        
close(fd1[0]);
        
close(fd2[0]);

          
write(fd2[1], buffer,n);
        
close(fd2[1]);

        
exit(0);
    
}}
}
