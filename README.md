# :fire: Arterm
This project is intended to be used as a program that can print a quote and
ascii art to the terminal. This quote and art should be stored in separate utf-8
text files.

# :blossom: How to Use
Once the binary is made, it can be used by executing the binary with the first
argument being the path to the quote text file and the second argument being the
path to the art file.

The quote file is unique in that the program can read a file with multiple quote
and it, as currently configured, will pick one at random to display. To do
this, each quote needs to be separated by a delimiter. This  delimiter is be
found and set in `src/include/constants_macros.h` under the variable
QUOTE_DELIM. Notice that the delimiter ends with a new line character (as it is
currently set up, delimiters need to be on their own line).

The art file can contain an ascii art piece of any height but MAX_LEN or fewer
characters wide. This is so that everything can be properly centered
(including quotes of few enough characters).  To change this centering width,
change the MAX_LEN in `src/include/constants_macros.h` (note it should be one
more than the desired number of characters as C requires the nul terminator on
character pointers).

Finally, the character that borders the quotes can be changed as well in 
`src/include/constants_macros.h` under the QUOTE_BORDER defined constant.

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
Additionally, this program has been checked for memory leaks and memory errors,
to which there are none in the program. If somehow my tests missed one please
open a PR.
