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
<td align="center">cust_cd.c</td>
<td align="left">Command to change the working directory</td>
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
-[] cd
<tr>
-[] env
</tr>

 - [ ] 
 - [ ] 
 - [ ] List item

<h3 id="examples">Examples</h3>
<ul>
<li>
 Run in Interactive Mode</li>


 - Run in Non-interactive Mode</li>
</ul>

<!--stackedit_data:
<<<<<<< HEAD
eyJoaXN0b3J5IjpbMTQwNDQ0MTMzNSwzODkzNjU3ODddfQ==
-->
=======
eyJoaXN0b3J5IjpbNTczNzQ2NzEzXX0=
-->
>>>>>>> 343044de0624f0217f58c5b86a3fbceeba6d29b5
<!--stackedit_data:
eyJoaXN0b3J5IjpbMTMwNDUwNDIzNSwxNDk4OTQ2MjYsMTAwMD
gzOTMyOSwxODkwNTQ0MzI1LDIwMTkxMTc4MF19
-->