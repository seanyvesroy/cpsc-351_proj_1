#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) 
{

    if(argc == 1) 
    {

    std::cout <<"Usage: ./thrice PROG [ARGS]..." << std::endl;

    }

    std::vector<char *> myargs;
    for (int i = 1; i < argc; i++) 
    {
        myargs.push_back(argv[i]);
    }
    myargs.push_back(NULL);
    
    int counter = 3;
    
    while(counter > 0)
    {
        auto rc = fork();
        if(rc == 0)
        { 
           execvp(argv[1], myargs.data());
        }
        else { 
            auto cc = wait(NULL);
            assert(cc>=0);     
        }
        counter --;      
    }
    return EXIT_SUCCESS; 

}