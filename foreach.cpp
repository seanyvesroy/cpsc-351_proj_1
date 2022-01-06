#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <vector>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <iostream>

int main(int argc, char** argv)
{
    
       
    if (argc <= 1)
    {
        std::cout <<" Usage: ./foreach [-p] [-n NUM] [ARGS]... PROG" << 
        std::endl;
    }
    int argCounter = argc;
    char* command = argv[argc - 1];   
    std::vector<char *> myArgs;
    char optCase = getopt(argc, argv, argv[1]);
    

    if (optCase == 'n')
    {
        int counter = atoi(argv[2]);

        while (counter > 0)
        {
            {
                auto rc = fork();
                if (rc == 0)
                {
            
                }
                else
                {    
                myArgs.push_back(command);       
                    for (int i = 3; i < (argc -1); ++i) 
                        {
                        myArgs.push_back(argv[i]);
                        }   
                myArgs.push_back(NULL);
                execvp(command, myArgs.data());   
                }
    
            }
            --counter;
            
        }return EXIT_SUCCESS;
    }
    if (optCase == 'p' )
    {
        auto rc = fork();
        if (rc == 0)
        {
                myArgs.push_back(command);
                
                    for (int i = 2; i < (argc -2); ++i) 
                        {
                        myArgs.push_back(argv[i]);
                        }   
                myArgs.push_back(NULL);
                execvp(command, myArgs.data());   
        }
        else
        { 
    
                myArgs.push_back(command);       
                    for (int i = 3; i < (argc -1); ++i) 
                        {
                        myArgs.push_back(argv[i]);
                        }   
                myArgs.push_back(NULL);
                execvp(command, myArgs.data());   
        }
        return EXIT_SUCCESS;   
    }
    


    if (argc == 2)
    {
        myArgs.push_back(command);
        myArgs.push_back(argv[1]);
        myArgs.push_back(NULL);    
        execvp(command, myArgs.data());
    }
    

    if (argCounter > 2)
    {
        auto rc = fork();
        if (rc == 0)
        {
                myArgs.push_back(command);
                
                    for (int i = 1; i < (argc -2); ++i) 
                        {
                        myArgs.push_back(argv[i]);
                        }   
                myArgs.push_back(NULL);
                execvp(command, myArgs.data());   
        }
        else
        { 
            auto cc = wait(NULL);
            assert(cc>=0);
                myArgs.push_back(command);       
                    for (int i = 2; i < (argc -1); ++i) 
                        {
                        myArgs.push_back(argv[i]);
                        }   
                myArgs.push_back(NULL);
                execvp(command, myArgs.data());   
        }
        return EXIT_SUCCESS;    
    }
}