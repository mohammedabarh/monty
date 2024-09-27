,               # Input first digit
>,              # Input second digit
-[->+<]         # Convert both inputs to numbers (subtract 48 from each)
<[              # Multiply the two numbers
  >>[->+>+<<]   # Perform the multiplication by repeatedly adding
  <<[->>-<<]    # Shift result into the correct position
]              
>[->+<]         # Move final result into one cell
>++++++++++     # Convert back to ASCII (to start from '0')

[->+++++<]>    # Handle tens digit if the result is two digits
[->+++<]>+.     # Print the tens digit if present

++++++++++      # Prepare for the ones digit
[->+++++<]>     # Handle ones digit
.               # Print the ones digit

+++[->++++<]    # Print newline ('\n', ASCII 10)
.               # Output the newline

