# Description
- This program parses the text given in the command line arguments, finds how many times each character is repeated, and prints it on the screen. 
# Task
- The main function is the main point of the program and takes arguments argc and argv. argc is a string array containing the total number of arguments given on the command line, and argv is a string array containing the arguments themselves.
- First, a variable named count is defined. This variable is used to store the number of occurrences of each character.
- The outer for loop works if the ASCII value of the characters is between ' ' (space) and 'z'. This loop is used to find the number of occurrences of each character.
- The first inner for loop scans the command line arguments. Index starts at 1 because index 0 represents the program itself.
- The second inner for loop checks each argument and checks for characters.
- The inner if condition checks if a character matches a letter character. If it matches, the count variable is incremented.
- If the value is greater than zero, the number of the character and itself are printed with printf ->.
# Usage
- This program can be used to analyze texts displayed on the command line. For example, you can run the program using the following command:
./my_printf "Hello world!" "This is a test."
- This command "Hello, world!" and "This is a test." Passes their text to the program as an argument.
- The program finds the number of repetitions of each character and prints it on the screen. For example, when you run the above command, you might get the following output:
:4
!: one
,: one
.:2
H: 1
T: 1
a: 1
d:1
e: 1
i: 2
l: 3
it is: 2
r: 1
p:3
t:4
w: 1
- This output displays characters and the number of occurrences of characters. The space character is repeated 4 times, and the "i" and "t" characters are repeated 2 times.
# Installation
- Open a text editor and copy the program code.
- The program is compiled using the compiler. The following command was used to compile the program in the terminal
gcc my_printf.c -o
printf
- This compiles a file named my_printf.c to create an executable named program.
- After the compilation process is completed successfully, an executable named printf is created in the same directory.
- Run the program using the following command in the terminal:
./printf "Hello world!" "This is a test."
- This command starts an executable program and says "Hello, world!" and "This is a test." Passes their text to the program as an argument.
- When finished, I pushed it to git hub via git. git branch , git switch , git add . , git commit -m"project", git push