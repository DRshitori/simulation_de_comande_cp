#include<stdlib.h>
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
#include<dirent.h>
#include<unistd.h>


int main (int argc , char *  argv[]){

char buf;

int fd2,fd1;
   if (argc < 3 )
    {   perror("lack of arguments");
        exit(1);
    }
    else if (argc == 3)
    {
        if (access(argv[1],R_OK)!=0)
    {
         perror(argv[1]);
         exit(1);
        }
     
        fd1 = open(argv[1],O_RDONLY);
        printf("fd1 : %d \n",fd1);

        if (fd1 == - 1)
        {
            perror("fail to open directory ");

        }      
        fd2 = open(argv[2],O_WRONLY | O_TRUNC |O_CREAT,0644);

        if (fd2 == -1)
        {
            perror("fail to open directory ");
            exit(1);
        }

        while(read(fd1,&buf,1))
        {
         write(fd2,&buf,1);            
        }
            
        close(fd1);
        close(fd2);
    
    }

    else{

    DIR * directory = opendir(argv[argc-1]);
    
        
     if (directory == NULL)
       {
perror(argv[argc-1]);
exit(1);
       }
           
    struct dirent * fichierLu = readdir(directory);
        while(fichierLu != NULL)
        {
        printf("\n le fichier %s : \n\n",fichierLu->d_name);
        if (strcmp(fichierLu->d_name,".")==0)
        {
        DIR * File = opendir("./tp1");
        struct dirent * f  = readdir(File);
        while(f != NULL)
        {
        printf("\n le file %s : \n",f->d_name);
        f = readdir(File);
        } 
        }
        fichierLu = readdir(directory);
        }       
       for (int i = 1 ; i < argc-1 ; i++)
            {

                int size = strlen(argv[argc-1]) + strlen(argv[i]) + 3;

                char * filePath = (char *)malloc( size* sizeof(char));
                
                filePath = strcpy(filePath,argv[argc-1]);
                if (*(filePath+strlen(argv[argc-1])) != '/')
                   *(filePath+strlen(argv[argc-1])) = '/';

                
                filePath = strcat(filePath,argv[i]);
printf("\nfile path %s \n",filePath);
   
                 fd1 = open(filePath , O_WRONLY | O_CREAT | O_TRUNC,0644 );
                fd2 = open(argv[i] , O_RDONLY);
                if (fd2 == -1)
                {
                    free(filePath);
                    filePath=NULL;
                    perror(filePath);
                    exit(1);
    
                }
                while(read(fd2,&buf,1))
                    {
                        write(fd1,&buf,1);
                     }
                close(fd1);
             close(fd2);
            }
     closedir(directory);
      
 }
     return EXIT_SUCCESS ; }
