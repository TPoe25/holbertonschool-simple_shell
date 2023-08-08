---


---

<h1 id="simple_shell">Simple_Shell 🐚</h1>
<h2 id="description">Description 📃</h2>
<ul>
<li>Here is a code for our Simple Shell code/project that is able to display prompts  execute simple commands utilizing the C programming language. Our shell tackles interactive and non-interactive mode.</li>
</ul>
<h2 id="files">Files 📁</h2>

<table>
<thead>
<tr>
<th align="center">Name</th>
<th align="left">Description</th>
</tr>
</thead>
<tbody>
<tr>
<td align="center">basic_shell.h</td>
<td align="left">The main header file. </td>
</tr>
<td align="center">structure.h</td>
<td align="left">Structure for builtin commands</td>
<tr>
<td align="center">basic_shell.c</td>
<td align="left">Main function for the shell. Interactive or non interactive.</td>
</tr>
<tr>
<td align="center">input_shell.c</td>
<td align="left">Interactive shell process that reads input and prints output</td>
</tr>
<tr>
<td align="center">automatedshell.c</td>
<td align="left">Non interactive shell that interprets Unix command line input.</td>
</tr>
<tr>
<td align="center">stream.c</td>
<td align="left">Reads lines from the stream.</td>
</tr>
<tr>
<td align="center">getline.c</td>
<td align="left">Defines function to read input lines.</td>
</tr1</td>
</tr>
<td align="center">parse.c</td>
<td align="left">Splits a string into multiple tokens.</td>
<tr>
<td align="center">execute.c</td>
<td align="left">Executes commands, both custom built-ins and external programs</td>
</tr>
<tr>
<td align="center">next_process.c</td>
<td align="left">Creates a new process</td>
</tr>
<tr>
<td align="center">cust_env.c</td>
<td align="left">Command to print environmental variables</td>
</tr>
<tr>
<td align="center">cust_cd.c</td>
<td align="left">Command to change the working directory</td>
</tr>
<tr>
<td align="center">cust_exit.c</td>
<td align="left">Command to terminate the shell.</td>
</tr>
<tr>
</tbody>
</table><h2 id="functions-and-system-calls-used">Functions and System calls used</h2>

<table>
<thead>
<tr>
<th align="center">Name</th>
<th align="center">Description</th>
</tr>
</thead>
<tbody>
<tr>
<td align="center">isatty</td>
<td align="left">Checks if a file descriptor refers to a terminal.</td>
</tr>
<tr>
<td align="center">getchar</td>
<td align="left">reads a character from the STDIN</td>
</tr>
<tr>
<td align="center">exit</td>
<td align="left">Exits the program.</td>
</tr>
<tr>
<td align="center">atoi</td>
<td align="left">Converts a string to an integer.</td>
</tr>
<tr>
<td align="center">chdir</td>
<td align="left">Changes the working directory</td>
</tr>
<tr>
<td align="center">malloc</td>
<td align="left">Allocates memory dynamically.</td>
</tr>
<tr>
<td align="center">free</td>
<td align="left">Frees dynamically allocated memory.</td>
</tr>
<tr>
<td align="center">realloc</td>
<td align="left">Changes the size of a dynamically allocated memory block.</td>
</tr>
<tr>
<td align="center">perror</td>
<td align="left">Compares 2 strings.</td>
</tr>
<tr>
<td align="center">strtok</td>
<td align="left">Splits a string into tokens. </td>
</tr>
<tr>
<td align="center">write</td>
<td align="left">Writes to a file descriptor.</td>
</tr>
<tr>
<td align="center">feof</td>
<td align="left">Checks for EOF indicator on a stream.</td>
</tr>
<tr>
<td align="center">write</td>
<td align="left">Writes to a file descriptor.</td>
</tr>
<tr>
<td align="center">waitpid</td>
<td align="left">Waits for a specific process to change state.</td>
</tr>
</tbody>
</table><h2 id="how-to-install">How to install 🔨</h2>
<p>
Clone the repo found at [<a href="http://github.com/TPoe25/holbertonschool-simple_shell">github.com/TPoe25/holbertonschool-simple_shell</a>]</p>
<pre><code>gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
</code></pre>
<h2 id="usage">Usage</h2>
<h3 id="built-ins">Built ins</h3>

<tr>
</tr>

 - [ ] cd
 - [ ] env
 - [ ] exit

<h3 id="examples">Examples</h3>
<ul>

 Run in Interactive Mode:</li>
Interactive mode <pre><code>.root@14af6dc6f829:/holbertonschool-simple_shell# ls -l  
total 108  
-rw-r--r-- 1 root root 285 Aug 7 21:45 AUTHORS  
-rw-r--r-- 1 root root 712 Aug 7 21:05 automatedshell.c  
-rw-r--r-- 1 root root 294 Aug 7 21:05 basic_shell.c  
-rw-r--r-- 1 root root 773 Aug 7 21:14 basic_shell.h  
-rw-r--r-- 1 root root 521 Aug 7 21:05 cust_cd.c  
-rw-r--r-- 1 root root 465 Aug 7 21:05 cust_env.c  
-rw-r--r-- 1 root root 405 Aug 7 21:05 cust_exit.c  
-rw-r--r-- 1 root root 1031 Aug 7 21:05 execute.c  
-rw-r--r-- 1 root root 667 Aug 7 21:05 getline.c  
-rwxr-xr-x 1 root root 106 Jul 26 17:58 **giterdone**  
-rwxr-xr-x 1 root root 39424 Aug 7 21:52 **hsh**  
-rw-r--r-- 1 root root 634 Aug 7 21:05 input_shell.c  
-rw-r--r-- 1 root root 806 Aug 7 21:05 next_process.c  
-rw-r--r-- 1 root root 1062 Aug 7 21:05 parse.c  
-rwxr-xr-x 1 root root 84 Jul 26 17:58 **push**  
-rw-r--r-- 1 root root 1340 Jul 26 18:42 README.md  
-rw-r--r-- 1 root root 988 Aug 7 21:05 stream.c  
-rw-r--r-- 1 root root 359 Aug 7 21:05 structure.h</code></pre>

 Run in Non-interactive Mode:
 Non interactive mode <pre><code>root@14af6dc6f829:/holbertonschool-simple_shell# echo “/bin/ls” | ./hsh  
AUTHORS  cust_cd.c getline.c next_process.c stream.c  
automatedshell.c cust_env.c giterdone parse.c  structure.h  
basic_shell.c  cust_exit.c hsh  push  
basic_shell.h  execute.c input_shell.c README.md</code></pre>

<!--stackedit_data:
<<<<<<< HEAD
eyJoaXN0b3J5IjpbMTQwNDQ0MTMzNSwzODkzNjU3ODddfQ==
-->
=======
eyJoaXN0b3J5IjpbNTczNzQ2NzEzXX0=
-->
>>>>>>> 343044de0624f0217f58c5b86a3fbceeba6d29b5
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTMyOTMwMjM5LDE0OTg5NDYyNiwxMDAwOD
M5MzI5LDE4OTA1NDQzMjUsMjAxOTExNzgwXX0=
-->