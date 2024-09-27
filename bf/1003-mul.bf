# Input: Two integers, separated by a space, from stdin
# Output: The result of their multiplication printed to stdout

,>>>,   # Read two characters from stdin
+++++++ # Convert them to integer form (atoi)
[
    >----- ---     # Adjust the integer range
    >----- ---     # Adjust the integer range for the second value
    <<-            # Loop back to ensure both values are in correct form
]
# Multiply two integers
>[ 
    >[>+>+<<-]     # Perform the repeated addition
    >[<+>-]        # Continue adding to complete multiplication
    <<-            # Final step of the multiplication process
]
# Separate the input digits
>[->+>]+++++++ <   # Prepare the digits for printing
[
    - >- [>>>]+++++ +++++<<+  # Shift and adjust the numbers for output
    [<<<]>>>>                 # Print the result
]
<-                     # Final adjustments to end the loop cleanly
<+++++++ >>>[-<<<->>>]<<<  # Convert final result into readable form
# Convert the result back to characters (itoa)
<++++++
[
    >+++++ ++++>            # Adjust value to printable characters
    [+++++ ++>]             # Further adjustment for larger values
    <[<]>-                  # Final adjustment before printing
]
# Print result with newline
>>[.<<]<[<<]>>.             # Output the final multiplication result
>>,.                       # Print a newline after the result

