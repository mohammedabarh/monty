   ++++++++[>++++++++<-]>+.             # Set up initial memory state
   ,                                    # Read first digit
   [->++++++<]>                         # Convert ASCII to numeric
   >,                                   # Move to next cell and read second digit
   [->++++++<]>                         # Convert ASCII to numeric
   <[->[>+>+<<-]>[<+>-]>>[<+>-]<<-]     # Multiply the two digits
   [->++++++<]>.[-]                     # Convert numeric result to ASCII and print
   .

