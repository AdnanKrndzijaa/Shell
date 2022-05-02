# A&A Shell

## Group members
- Armin Hrbat
- Adnan Krndžija

## Answers
#### Question 1: 

#### Question 2:

## Description
##### You can run A&A Shell as follows:
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
