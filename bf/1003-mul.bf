,>,                     Read two digits
>++++++[<--------<-------->>-]   Convert from ASCII to decimal
<<[                     Multiplication loop
  >[>+>+<<-]            Move first number to two cells
  >>[<<+>>-]            Move back to original cell
  <<<-                  Decrement first number
]
>[-]<                   Clear temporary cells
>>[<<+>>-]              Move result to first cell
<<                      Move pointer to first cell
>++++++[<++++++++>-]<   Convert to ASCII
.                       Print result
>+++++++++[<++++++++>-]<.  Print newline
