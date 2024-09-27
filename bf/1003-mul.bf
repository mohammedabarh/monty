,                                       # Read first digit
>++++++++[<------>-]                    # Convert ASCII to numeric (subtract 48)
>                                       # Move to the next cell
,                                       # Read second digit
>++++++++[<------>-]                    # Convert ASCII to numeric (subtract 48)
<<                                      # Move back to the first input cell

[                                       # Multiply the two digits
  ->                                     # Start of loop for multiplication
  [>+>+<<-]                              # Clone first input to temporary cells
  >>[-<<+>>]                             # Add the cloned value to the second input
  <                                      # Return to the first input cell
  [->>+<<]                               # Add the result of the multiplication to the result cell
  <<                                     # Move back to the first input cell
]                                        # End of loop

>>>>>++++++++++(start)                   # Prepare result cell for output
<                                        # Move to the start of the result calculation
[
  ->                                     # Start of loop for result conversion
  -[>+>>]                                # Convert the result into a printable ASCII character
  >[+[-<+>]>+>>]<<<<<                    # Finalize the conversion
]
>>>>++++++++[<++++++>-]<.                # Output the first digit of the result
<[->>+<<]#                               # Adjust pointer position
>>>++++++++[<++++++>-]<.                 # Output the second digit of the result
>++++++++++.                             # Print a newline

