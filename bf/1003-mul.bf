,>++++++++[<------>-]  # Read first number and normalize it (read1)
,>++++++++[<------>-]  # Read second number and normalize it (read2)
<<  # Move to the cell holding the first number
[->  # Start outer loop (decrement first number each iteration)
    [>+>+<<-]  # Copy second number to two temporary cells
    >>  # Move to the first temporary cell
    [<<+>>-]  # Move value back to the second number cell
    <  # Move back to the outer loop cell
]  # End outer loop

# At this point, the result is in the second temporary cell
# We now normalize the result to be printable
>>[-]  # Reset the cell to zero
<++++[>++++[>+++<-]<-]  # Add 48 ('0') to the cell holding the result
>>.  # Print the result from the cell

