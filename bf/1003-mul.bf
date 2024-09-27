,>,                     Read two single-digit numbers from stdin
[<+>-]<                 Move second number to first cell
>++++++[<---------->-]  Convert ASCII to integer for first number
<                       Move back to first cell
[                       Start multiplication loop
  >++++++[<+++++++>-]   Multiply by adding 6 times 7
  <-                    Decrement the counter
]
>++++++[<++++++++>-]    Convert result back to ASCII
<.                      Print result
>++++++++++.            Print newline
