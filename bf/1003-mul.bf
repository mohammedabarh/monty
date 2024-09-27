,>,                     Read two digits
<                       Move to the first digit
[                       Start loop
    >                   Move to second digit
    [                   Start inner loop
        >+              Increment result
        >+              Increment copy of second digit
        <<-             Decrement second digit
    ]                   End inner loop
    >>                  Move to copy of second digit
    [                   Start restore loop
        <<+             Restore second digit
        >>-             Decrement copy
    ]                   End restore loop
    <<<-                Decrement first digit
]                       End outer loop
>>>                     Move to result

>+++++++++              Set up for division by 10
[                       Start division loop
    <                   Move to result
    [->+>+<<]           Move result to two cells
    >>                  Move to divisor
    [-<<+>>]            Restore divisor
    >+                  Increment quotient
    [<]                 Move back to remainder
    <-                  Decrement remainder
]                       End division loop

<                       Move to quotient
[                       Start print loop
    +++++++++++++++++++++++++++++++++++++++++++++++ Add 48 to get ASCII digit
    .                   Print digit
    -------------------------------               Subtract 48 to get back to number
    <                   Move to next digit
]                       End print loop
++++++++++.             Print newline
