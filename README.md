# A&A Shell

## Group members
- Armin Hrbat
- Adnan Krndžija

## Answers
#### Question 1: 

#### Question 2:

## Description
### You can run A&A Shell as follows:
```
gcc 
.\a.out
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
