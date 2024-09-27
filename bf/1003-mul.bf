,>,[<                    Read first digit and store it in cell #1
    [>+>+<<-]            Copy first digit to cell #3 and #4
    >>                   Move to cell #3
    [<<+>>-]             Move copy back to cell #1
    <-                   Decrement cell #2 (second digit)
]
>>[>+>+<<-]              Copy second digit to cell #5 and #6
>>[<<+>>-]               Move copy back to cell #4
<<<<                     Move back to cell #1
[                        Start multiplication loop
    >[>+>+<<-]           Copy first digit to cell #3 and #4
    >>[<<+>>-]           Move copy back to cell #2
    >+                   Increment result in cell #4
    >                    Move to cell #5 (second digit copy)
    [<+>-]               Decrement second digit copy, moving it to cell #4
    <<-                  Decrement first digit in cell #1
]
>>>[<<<+>>>-]            Move result to cell #1
<<<<++++++[>++++++++<-]> Add 48 to convert to ASCII
.                        Print result
>++++++++++.             Print newline
