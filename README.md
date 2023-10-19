# This is a C program that implement a basic shell.

It reads user input from the command line, tokenizes the input into separate arguments, and then executes various shell commands.

## Here's a breakdown of the main components and functionalities of the code:

### main() Function:

This is the entry point of the program. It calls the executeShell function with a custom prompt and a buffer for reading user input.
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

