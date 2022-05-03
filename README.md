# A&A Shell

## Group members
- Armin Hrbat
- Adnan Krndžija

## Submission files:
[shell.c](/shell.c)

## Answers
### Question 1: What does ```mmap()``` do?
- To map between the process address space and files or devices, use the mmap() function. 
When a file is mapped to the process address space, it can be accessed in the same way that a string is accessed in a program. 
This is one of the most efficient ways to retrieve data in a file, and it gives a natural encoding interface for a data structure that can be evaluated without having to deal with the abstraction of reading and writing a file. 
We'll look at how to utilize the mmap() function in Linux in this post.
- The function has 6 arguments: 
1. Address: This option specifies the desired mapping address at the start. If the second mapping is missing, the core will select a nearby page limit and build the mapping; otherwise, the kernel will select a new address. If this parameter is null, the core is free to place the mapping anywhere it sees fit.
2. Length: The number of bytes to be mapped is specified here.
3. Protect: This parameter is used to restrict the types of access that are permitted. The following code can be a logical 'OR' argument.
4. Flags: This argument is used to modify the map's appearance. Here are a few examples of popular flag values: **MAP_SHARED**, **MAP_PRIVATE**, **MAP_ANONYMOUS / MAP_ANON** and **MAP_FIXED**
5. Filedes: It is necessary to map this file descriptor.
6. Offset: This is a change from the beginning of the file mapping. Simply stated, when a file is opened on the applicants descriptor, mapping is associated with (offset) to (offset + length-1) bytes.

- Example of ```mmap()``` from [here](https://linuxhint.com/using_mmap_function_linux/#:~:text=The%20mmap()%20function%20is,an%20array%20in%20the%20program).
```
#include <stdio.h>
#include <sys/mman.h>

int main(){

int N=5;
int *ptr = mmap ( NULL, N*sizeof(int),
 PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0 );

if(ptr == MAP_FAILED){
    printf("Mapping Failed\n");
    return 1;
}

for(int i=0; i<N; i++)
    ptr[i] = i*10;

for(int i=0; i<N; i++)
    printf("[%d] ",ptr[i]);

printf("\n");
int err = munmap(ptr, 10*sizeof(int));
if(err != 0){
    printf("UnMapping Failed\n");
    return 1;
}

return 0;
}
```
### Question 2: What happens during a context switch? Do we want the OS to perform many or few context switches? Explain.
- Context switching is the process of storing a process's context or state such that it can be reloaded and execution continued from the same point as before. A multitasking operating system has this capability, which allows numerous programs to share a single CPU.
- Context switching occurs as a result of three major factors. This is what they are: 
   - Multitasking: In a multitasking environment, one process is switched off the CPU so that another can execute. The state of the old process is saved, and the state of the new process is loaded. The scheduler on a pre-emptive system may switch off processes. 
   - Interrupt Handling: When an interrupt occurs, the hardware shifts a portion of the context. This happens on its own. To reduce the amount of time it takes to handle the interrupt, only a portion of the context is updated. 
   - User and Kernel Mode Switching: When the operating system requires a move from user mode to kernel mode, a context switch may occur.
- The present state of the process must be maintained so that it can be restored when it is rescheduled for execution. All of the registers that the process may use, especially the program counter, are included in the process state, as well as any other operating system-specific data that may be required. A process control block (PCB) or switchframe is a data structure that stores this information. The PCB may be stored in kernel memory on a per-process stack (rather than the user-mode call stack), or it could be placed in a particular operating system-defined data structure. A handle to the PCB is added to a queue of ready-to-run processes, known as the ready queue.
- Because one process' execution has been effectively halted, the operating system can now swap context by selecting a process from the ready queue and restoring its PCB. The program counter from the PCB is loaded as a result, and execution can continue in the selected process. The priority of the process and the thread can determine which process is selected from the ready queue (i.e., it may be a priority queue).
##### Steps for Content Switching
![alt figure](https://static.javatpoint.com/operating-system/images/what-is-the-context-switching-in-the-operating-system.png)
## Description
##### You can run A&A Shell as follows:
```
sudo apt-get install libreadline-dev
```
```
gcc shell.c -lreadline
./a.out
```

- We made an initialization of the shell, where at start the user can see the Welcome message and his/her username printed on the terminal screen.
- Immediately upon entering the shell, a prompt is displayed with a precisely defined layout according to the instructions. Two colors are applied to the appearance of the prompt, purple and cyan, which are made via functions, ```purple()``` and ```cyan()```, as well as the ```colorReset()``` function, which resets the color of the letters each time and returns to the technical settings.
```
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
```
- Also one interesting and very useful thing that we have implemented is the console with all the commands in our shell, ```consoleCommands()```, which greatly simplifies the management and entry of command names in our shell.
```
listOfCommands[0] = "exit";
listOfCommands[1] = "rm";
listOfCommands[2] = "cat";
listOfCommands[3] = "clear";
listOfCommands[4] = "cowsay";
listOfCommands[5] = "fwe";
listOfCommands[6] = "poli";
listOfCommands[7] = "forkbomb";
```
- Almost all commands in this function are defined via **switch statement** with the help of cases.
##### *rm command*
We have implemented a rm (remove) command that will delete files, and it is called simply using ```rm filename```.

##### *cat command*
We have implemented a cat (concatenate) command that will concatenate and display files, and it is called simply using ```cat filename1 filename2```.

##### *clear command*
We have implemented a clear command that will clear terminal screen, and it is called simply using ```clear```.

##### *cowsay command*
We have implemented a cowsay command that will display cow with custom text message, and it is called simply using ```cowsay TextMessage```.

##### *poli command*
We have implemented a poli command that will display hot dog mascot with custom text message, and it is called simply using ```poli TextMessage```.

##### *fwe command*
We have implemented a fork, wait and exec commands that will execute these 3 commands and display a custom feedback, and it is called simply using ```fwe```.

##### *exit command*
We have implemented a exit command that will which will shut down the A&A shell and return to the primary terminal, and it is called simply using ```exit```.

##### *forkbomb command*
We have implemented a forkbomb command that will crash your computer and cause great damage, and it is called simply using ```forkbomb```. 
After calling the command, the question arises to warn the user that (s)he must enter 'YES' (to continue the process of this command) or 'NO' (if (s)he accidentally entered the command and does not want to execute a forkbomb).

## Sources
1. https://www.geeksforgeeks.org/making-linux-shell-c/
2. https://fresh2refresh.com/c-programming/c-file-handling/remove-function-c/
3. https://blog.devgenius.io/lets-build-a-linux-shell-part-i-954c95911501
4. http://www.compciv.org/recipes/cli/basic-shell-scripts/
5. https://www.quora.com/How-do-I-create-my-own-shell-in-Linux
6. https://en.wikipedia.org/wiki/Unix_shell
7. https://www.programiz.com/c-programming/examples/concatenate-string
8. https://www.geeksforgeeks.org/methods-to-concatenate-string-in-c-c-with-examples/
9. https://www.geeksforgeeks.org/fork-bomb/#:~:text=The%20fork%20bomb%20is%20a,destroy%20all%20instances%20of%20it
10. https://www.ibm.com/docs/en/i/7.2?topic=ssw_ibm_i_72/apis/sigkill.htm
11. https://aljensencprogramming.wordpress.com/2014/05/15/the-kill-function-in-c/
12. https://dev.to/ifenna__/adding-colors-to-bash-scripts-48g4
13. https://stackoverflow.com/questions/5947742/how-to-change-the-output-color-of-echo-in-linux
14. https://linuxhint.com/linux-pipe-command-examples/
15. https://stackoverflow.com/questions/33912024/shell-program-with-pipes-in-c
16. https://linuxhint.com/using_mmap_function_linux/#:~:text=The%20mmap()%20function%20is,an%20array%20in%20the%20program.
17. https://en.m.wikipedia.org/wiki/Context_switch
18. https://www.tutorialspoint.com/what-is-context-switching-in-operating-system
