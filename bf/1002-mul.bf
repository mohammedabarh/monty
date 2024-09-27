++++[>++++[>+++<-]<-]   # Initialize to zero (ASCII 48)
,>,>                    # Read two digits
[<-<->>-]               # Convert ASCII to integers
<<                      # Move to first digit position
[                       # Multiplication loop
    >                   # Move to second digit
    [>+>+<<-]           # Copy value for multiplication
    >>                  # Move to the next cell
    [<<+>>-]            # Accumulate multiplication result
    <<<-                # Decrement the first digit
]
>[-]<                   # Reset the second digit
++++[>++++[>+++<-]<-]   # Convert result back to ASCII
>>.                     # Print the result

