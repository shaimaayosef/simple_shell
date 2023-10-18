# This is a C program that implement a basic shell.

It reads user input from the command line, tokenizes the input into separate arguments, and then executes various shell commands.

## Here's a breakdown of the main components and functionalities of the code:

### main() Function:

This is the entry point of the program. It calls the executeShell function with a custom prompt and a buffer for reading user input.

### executeShell() Function:

This function is the core of the shell. It repeatedly reads user input using the getline function, tokenizes the input, and executes the specified command. The loop continues until the user enters "exit."

### tokenizeInput() Function:

This function tokenizes the input line into separate arguments. It uses space and newline characters as delimiters. It dynamically allocates memory to store the tokens and sets up an array of strings (tokenized_args) to hold the tokenized input.

### executeCommand() Function:

This function takes a command and an array of arguments and tries to execute the specified command. It first checks if the command is "env" and, if so, prints environment variables. If the command is not "env," it searches for the command in directories listed in the PATH environment variable using the searchAndExecute function.

### searchAndExecute() Function:

This function takes a command, an array of arguments, and a directory path. It constructs the full path to the command by concatenating the directory path and the command name. If the command is executable (has execute permission), it forks a child process and attempts to execute the command. It waits for the child process to finish and checks the exit status.

### The main() function:

In the main() function, there are (void) casts for command-line arguments (ac and argv) to silence compiler warnings. However, there's a small issue with (void)\**argv; - it should be (void)*argv; to silence the warning for unused argv.

### Memory Management:

The program dynamically allocates and frees memory for various data structures, such as tokenized arguments and full command paths.

### Exit and Error Handling:

The program handles errors using perror for system errors and checks exit statuses to determine the success or failure of executed commands.

### Exiting the Shell:

The shell can be exited by typing "exit." Upon exiting, it releases allocated memory and prints a goodbye message.

### Environment Variables:

The program can display environment variables when the user enters "env."

