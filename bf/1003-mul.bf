>, >, <<               # Read two digits
+++++ +                # Convert to integers
[                       # Loop to subtract 48 from each digit
    >----- ---
    >----- ---
    <<-
]
[                       # Multiplication loop
    >
    [>+>+<<-]           # Copy for multiplication
    >[<+>-]
    <<-
]
>[-]>+> >+++++ +++++<  # Prepare for print
[                       # Loop to adjust ASCII values
    - >- [>>>]+++++ +++++<<+
    [<<<]>>>>
]
<-                     # Clean up
<+++++ +++++>>>[-<<<->>>]<<<
<+++++ +               # Convert result to ASCII
[                       # Loop to print the result
    >+++++ +++>
    [+++++ +++>]
    <[<]>-
]
>>[.<<]<[<<]>>.        # Print result with newline
>>,.                   # Ensure newline is printed

