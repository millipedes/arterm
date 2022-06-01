# :evergreen_tree: Arterm
![example picture](./resources/example.png "Example Arterm")
This project is intended to be used as a program that can print a quote and
ascii art to the terminal. This quote and art should be stored in separate utf-8
text files.

The above quote is from the artist BUSDRIVER.

# :blossom: How to Use
Once the binary is made, it can be used by executing the binary with the first
argument being the path to the quote text file and the second argument being the
path to the art file.

The program can read a file with multiple quotes and will pick one at random to
display. To work with the program, each quote needs to be separated by a
delimiter. This delimiter is be found and set in
`src/include/constants_macros.h` under the variable QUOTE_DELIM. Notice that
the delimiter ends with a new line character (as it is currently set up,
delimiters need to be on their own line).  By default the quotes are separated
by "--\n", i.e.:
```
quote 1
--
very long
quote 2 taking up multiuple lines
--
quote 3
--
```

The art file can contain an ascii art piece of art of any height but MAX_LEN or
fewer characters wide. This restraint is so that everything can be properly
centered.  To change this centering width, modify the MAX_LEN in
`src/include/constants_macros.h` (note it should be one more than the desired
number of characters as C requires the nul terminator on character pointers).

Finally, the character that borders the quotes can be changed as well in 
`src/include/constants_macros.h` under the QUOTE_BORDER defined constant.

The user can change the order in which the art/quote is displayed or change the
manner in which they are displayed in the `terminal.c` file under the
`print_terminal_art()` function (which just calls the art print function and
then the quote print function).

It is worth mentioning, the [lolcat](https://github.com/busyloop/lolcat.git)
project is very neat and is good in combination with this program (the example
picture includes the use of lolcat with seed value 218 my favorite).

# :floppy_disk: Installation
As I have prepared it, the following tools are required to build the project:
- GNU Make
- Glibc (Or your C compiler of choice but you will need to change compiler in
  Makefile)

Once you are sure that you have these packages, you can run the following to
build this project:
```
git clone https://github.com/millipedes/arterm.git
cd arterm/
mkdir bin/
make
```

The way in which I use this program is to have it execute at the end of my
bashrc.  This will cause it to execute everytime I open a new terminal (also
with this program being relatively small and written in C the additional opening
time is negligible, for additional reference it runs much faster than neofetch
in my experience). So the last lines of my bashrc look like:
```
~/path_to/execuatble_binary path_to/quote path_to/art | lolcat -S 218
```
Piping the output to lolcat is not at all necessary for base funcationality of
the program, but in my opinion it makes it look nice.

Additionally, this program has been checked for memory leaks and memory errors,
to which there are none in the program. If somehow my tests missed one please
open a PR.
