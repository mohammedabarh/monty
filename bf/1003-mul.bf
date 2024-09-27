,>,         Read two digits
<           Move back to first digit
[           Start multiplication loop
    -       Decrement digit
    >       Move to second digit
    [       Start inner loop
        >+  Add to result
        >+  Add to temporary copy
        <<- Decrement second digit
    ]
    >>      Move to temporary copy
    [       Restore second digit
        <<+
        >>-
    ]
    <<<     Move back to first digit
]
>>>         Move to result
>++++++++++  Set up "10" for division
<           Move back to result
[           Start division loop
    >       Move to "10"
    [       Divide by 10
        >+  Add to quotient
        >+  Add to remainder
        <<- Subtract from "10"
    ]
    >       Move to quotient
    [       Restore "10"
        <+
        >-
    ]
    <<      Move back to result
    -       Subtract 1 from result
]
>>          Move to remainder
++++++++    Add 8 (for ASCII offset later)
[           Loop to shift remainder
    <+      Add to quotient
    >-      Subtract from remainder
]
<           Move to quotient
[           Loop to output digits
    <<++++++++++>>    Add 10 to counter
]
<++++++++++          Add 10 more to counter (now 48 for ASCII "0")
<           Move to leftmost digit
[           Output loop
    >.      Output character and move right
    [-]     Clear cell
]
++++++++++. Output newline
