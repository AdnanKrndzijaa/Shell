#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<readline/readline.h>
#include<readline/history.h>
#define MAXLIST 100
#define MAXCOM 1000
#include <limits.h>
#include <sys/stat.h>
#include <dirent.h>
#include <linux/kernel.h>
#include <sys/sysinfo.h>
#include <libgen.h>
#include <signal.h>
#define clear() printf("\033[H\033[J")

void purple()
{
	printf("\033[0;35m");
}
void cyan()
{
	printf("\033[0;36m");
}
void colorReset()
{
	printf("\033[0m");
}
void init_shell()
{
    clear();
    printf("HELLO, welcome to the A&A shell!");
    char* username = getenv("USER");
    printf("\n\nUSER is: @%s", username);
    printf("\n");
    sleep(1);
    clear();
}
void prompt()
{
	char *username;
	char hostname[HOST_NAME_MAX + 1];
	
	username = getlogin(); 
	gethostname(hostname, HOST_NAME_MAX + 1);
	
	cyan();
	printf("%s", hostname);
	printf("@");
	purple();
	printf("%s", username);
	printf(":~$ ");
	colorReset();
}
int inputValue(char* str)
{
    char* buf;
    buf = readline("");
    if (strlen(buf) != 0) {
        add_history(buf);
        strcpy(str, buf);
        return 0;
    } else {
        return 1;
    }
}
int consoleCommands(char** parsed)
{
    int commands = 8;
    int a;
    int switchConsole = 0;
    char* listOfCommands[commands];
    listOfCommands[0] = "exit";
    listOfCommands[1] = "rm";
    listOfCommands[2] = "cat";
    listOfCommands[3] = "clear";
    listOfCommands[4] = "cowsay";
    listOfCommands[5] = "fwe";
    listOfCommands[6] = "poli";
    listOfCommands[7] = "forkbomb";
    for (a = 0; a < commands; a++) 
    {
        if (strcmp(parsed[0], listOfCommands[a]) == 0) 
        {
            switchConsole = a + 1;
            break;
        }
    }
    switch(switchConsole) 
    {
	    case 1: //exit command
		exit(0);
	    case 2: //remove file (rm command)
		if(parsed[1] == "") 
		{
			return printf("rm filename\n");
		}
		int ret;
		ret = remove(parsed[1]);
		if(ret != 0)  
		{
		    printf("rm: Not possible to remove file: File or directory does not exist.\n");
		} 
		return 1;
	    case 3: //cat command (used for concatenation is the process of appending a string to the end of another string)
	
		for (int a = 1; a < MAXLIST; a++) 
		{
		    if (strlen(parsed[a]) == 0)
		    {
		        break;
		    }
		    if (parsed[a] == NULL)
		    {
		        break;
		    }
		    if(parsed[a][0] != '>')
		    {
		        FILE *fp;
		        char c;
		        fp = fopen(parsed[a], "r");
		        if (fp == NULL)
		        {
		            printf("Cannot open file \n");
		            return 1;
		        }
		        c = fgetc(fp);
		        while (c != EOF)
		        {
		            printf ("%c", c);
		            c = fgetc(fp);
		        }
		        fclose(fp);
		        printf("\n");
		    }
		    else
		    {
		        FILE *fp;
		        char* filename = parsed[a] + 1;
		        fp = fopen (filename, "w");
		    }
		}
		return 1;
	    case 4: //clear command
		clear();
		return 1;
	    case 5: //cowsay command (command to print cow with custom message)
		printf(" ");
		for (int a = 1; a < MAXLIST; a++) 
		{
		    if (parsed[a] == NULL) break;
		    if (strlen(parsed[a]) == 0) break;
		    
		    for(int b = 0; b < strlen(parsed[a]) + 1; b++)
		    {
		        printf("-");
		    }
		}
		printf("\n(");
		for (int a = 1; a < MAXLIST; a++) 
		{
		    if (parsed[a] == NULL) break;
		    if (strlen(parsed[a]) == 0) break;
		    
		    printf("%s ",parsed[a]);
		}
		printf(")\n");
		printf(" ");
		for (int a = 1; a < MAXLIST; a++) 
		{
		    if (parsed[a] == NULL) break;
		    if (strlen(parsed[a]) == 0) break;
		    for(int b = 0; b < strlen(parsed[a]) + 1; b++)
		    {
		        printf("-");
		    }
		}
		printf("\n");
		printf("     \\  ^__^\n");
		printf("      \\ (oo)\\_____\n");
		printf("        (__)\\     )\\/\\\n");
		printf("           ||----w |\n");
		printf("           ||     ||\n");
		return 1;
	        
	   case 6: //fork, wait and execv command
		fwe();
		
	   case 7: //dragon 
		printf(" ");
		for (int a = 1; a < MAXLIST; a++) 
		{
		    if (parsed[a] == NULL) break;
		    if (strlen(parsed[a]) == 0) break;
		    for(int b = 0; b < strlen(parsed[a]) + 1; b++)
		    {
		        printf("-");
		    }
		}
		printf("\n(");
		for (int a = 1; a < MAXLIST; a++) 
		{
		    if (parsed[a] == NULL) break;
		    if (strlen(parsed[a]) == 0) break;
		    printf("%s ",parsed[a]);
		}
		printf(")\n");
		printf(" ");
		for (int a = 1; a < MAXLIST; a++) 
		{
		    if (parsed[a] == NULL) break;
		    if (strlen(parsed[a]) == 0) break;
		    for(int b = 0; b < strlen(parsed[a]) + 1; b++)
		    {
		        printf("-");
		    }
		}
		printf("\n");
		printf("  -------------      .---. __\n");
		printf("          ,    \    /     \   \    ||||\n");
		printf("         \\\\      |O___O |    | \\||||\n");
		printf("         \   //    | \_/  |    |  \   /\n");
		printf("          '--/----/|     /     |   |-'\n");
		printf("                 // //  /     -----'\n");
		printf("                //  \\ /      /\n");
		printf("               //  // /      /\n");
		printf("              //  \\ /      /\n");
		printf("             //  // /      /\n");
		printf("            /|   ' /      /\n");
		printf("            /|   ' /      /\n");
		printf("            //\___/      /\n");
		printf("           //   ||\     /\n");
		printf("           \\_  || '---'\n");
		printf("           /' /  \\_.-\n");
		printf("          /  /    --| |\n");
		printf("          '-'      |  |\n");
		printf("                    '-'\n");
		return 1;
		
	    case 8: //forkbomb command
		forkbomb();
		
	    default:
		break;
	    }

	    return 0;
}

void fwe()
{
	pid_t pid = 0;
	int result;
	pid = fork();
	
	if(pid > 0)
	{
		printf("Value of the a in the Child process is => %d, in the Parent process\n", pid);
		pid = wait(&result);
		
		printf("After end value is => %d\n", pid);
				
		if (WIFEXITED(result))
		{
			printf("Process exited with value => %d\n", WEXITSTATUS(result));
						
		}
		if (WIFSIGNALED(result))
		{
			printf("Process killed with value => %d\n", WTERMSIG(result));
						
		}
	}
	else if(pid == 0)
	{
		char *const result[] = {"/bin/ls", "-l", "/home/arminhrbat/Radna površ/shellProject", NULL};
		execv("/bin/ls", result);
		printf("Value of the output is not expected! Check you code and try again.");
		kill(getpid(), SIGSEGV);
	}
	else
	{
		perror("During fork(): ");
	}
	exit(0);	
}

void forkbomb()
{
	printf("Do you want to delete everything, and crash your device?\n");
	printf("Type YES or NO : ");
	char input[1024] = "";
	fgets(input, 1024, stdin);

	if(input[0] == 'YES')
	{
		printf("XXXXXXXXXXXXX\n");
		printf("GAME OVER!\n");
		printf("XXXXXXXXXXXXX\n");
		while(1){
			fork();
		}
	}
	else if(input[0] == 'NO')
	{
		printf("Oh great, thank you for saving me <3\n");
	}
	else
	{
		printf("Good choice, we hope it is not mistake, please do not delete me.\n");
	}
}

void execArgs(char** parsed)
{
    if(consoleCommands(parsed))
    {
        return;
    }
    pid_t pid = fork(); 
    if (pid == -1) 
    {
        printf("\nFailed forking child.");
        return;
    } 
    else if (pid == 0) 
    {
        if (execv(parsed[0], parsed) < 0) 
        {
            printf("Could not execute command.\n\n");
        }
        exit(0);
    } 
    else 
    {     
        wait(NULL); 
        return;
    }
}

void execArgsPiped(char** parsed, char** parsedpipe)
{
    int pipefd[2];
    pid_t p1, p2;
    if (pipe(pipefd) < 0) 
    {
        printf("\nPipe could not be initialized");
        return;
    }
    p1 = fork();
    if (p1 < 0) 
    {
        printf("\nCould not fork");
        return;
    }
    if (p1 == 0) 
    {
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);
        if (execv(parsed[0], parsed) < 0) 
        {
            printf("\nCould not execute command 1.");
            exit(0);
        }
    } 
    else {
        
        p2 = fork();
        if (p2 < 0) 
        {
            printf("\nCould not fork");
            return;
        }
        if (p2 == 0) 
        {
            close(pipefd[1]);
            dup2(pipefd[0], STDIN_FILENO);
            close(pipefd[0]);
            if (execv(parsedpipe[0], parsedpipe) < 0) 
            {
                printf("\nCould not execute command 2..");
                exit(0);
            }
        } 
        else 
        {  
            wait(NULL);
            wait(NULL);
        }
    }
}
  
int parsePipe(char* str, char** strpiped)
{
    int a;
    for (a = 0; a < 2; a++) {
        strpiped[a] = strsep(&str, "|");
        if (strpiped[a] == NULL)
            break;
    }
  
    if (strpiped[1] == NULL)
        return 0;
    else {
        return 1;
    }
}

void parseSpace(char* str, char** parsed)
{
    int a;
    for (a = 0; a < MAXLIST; a++) {
        parsed[a] = strsep(&str, " ");
        if (parsed[a] == NULL)
        {
            break;
        }
        if (strlen(parsed[a]) == 0)
        {
            a--;
    	}
    }
}
  
int processString(char* str, char** parsed, char** parsedpipe)
{
    char* strpiped[2];
    int piped = 0;
    piped = parsePipe(str, strpiped);
    if (piped) {
        parseSpace(strpiped[0], parsed);
        parseSpace(strpiped[1], parsedpipe);
    } else {
        parseSpace(str, parsed);
    }
    return 1 + piped;
}
  
int main()
{
    char inputString[MAXCOM], *parsedArgs[MAXLIST];
    char* parsedArgsPiped[MAXLIST];
    int execFlag = 0;
    init_shell();
    char hostbuffer[256];
    char *IPbuffer;
    struct hostent *host_entry;
    int hostname;
    hostname = gethostname(hostbuffer, sizeof(hostbuffer));
    host_entry = gethostbyname(hostbuffer);
    char* username = getenv("USER");
    while (1) 
    {
        prompt();
        if (inputValue(inputString))
        {
            continue;
		}
        execFlag = processString(inputString, parsedArgs, parsedArgsPiped);
        if (execFlag == 1)
        {
            execArgs(parsedArgs);
        }
        if (execFlag == 2)
        {
            execArgsPiped(parsedArgs, parsedArgsPiped);
        }
    }
    return 0;
}