#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

using std::vector;

int main(int argc, char *argv[]) 
{
    if(argc == 1) 
    {

    std::cout <<"Usage: ./stderr FILE [ARGS]..." << std::endl;

    }
    else
    {   close(STDERR_FILENO);
        open(argv[1], O_CREAT | O_WRONLY | O_TRUNC , S_IRWXU );
        close(atoi(argv[1]));
        std::vector<char *> myargs;
        for (int i = 2; i < argc; i++) 
        {
            myargs.push_back(argv[i]);
        }
        myargs.push_back(NULL);
        execvp(myargs[0], myargs.data());
      
       
       
       
    }
    
}

