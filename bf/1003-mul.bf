,                                # Read first digit
>,                               # Read second digit
-[->+<]                          # Convert both inputs to numbers (ASCII to decimal)
<[                               # Start the multiplication process
  >>[->+>+<<]                    # Copy and accumulate multiplication result
  <<[->>-<<]                     # Shift result to the correct cell
]                                # End the loop
>[->+<]                          # Normalize result into a single cell
>++++++++++                      # Prepare for ASCII conversion

[->+++++<]>                      # Handle two-digit results (print tens place)
[->+++<]>+.                      # Print tens place if applicable

++++++++++                       # Prepare to print the ones digit
[->+++++<]>                      # Handle ones digit
.                                # Print ones digit

+++[->++++<]                     # Move to newline ('\n', ASCII 10)
.                                # Output newline

