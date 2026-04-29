*This activity has been created as part of the 42 curriculum by mschyns*

## Description
This project is a copy of printf for conversions:
- %c Prints a single character.
- %s Prints a string (as defined by the common C convention).
- %p The void * pointer argument has to be printed in hexadecimal format.
- %d Prints a decimal (base 10) number.
- %i Prints an integer in base 10.
- %u Prints an unsigned decimal (base 10) number.
- %x Prints a number in hexadecimal (base 16) lowercase format.
- %X Prints a number in hexadecimal (base 16) uppercase format.
- %% Prints a percent sign.

## Instructions
**To use ft_printf, you must first create the static library:**
	 
	 make

**Next, you can use the library by including:"

	 #include "ft_printf.h"

**In your program's .c file**

**During compilation, run the program as follows:**

	 cc fichier.c -L. -lftprintf

**file.c is your program that uses ft_printf**

## Resources
More informations about variadic functions : https://x0r.fr/blog/31

AI (chatgpt): 

Was used to perform the English translation of README.md

## Description detaillée
For this project, I implemented a parser that iterates through the first argument provided.

This parser displays the characters entered by the user one by one until it encounters a conversion (e.g., %c).
When a conversion is required, the algorithm executes the corresponding function using the user's argument.

The algorithm also returns the number of characters displayed.