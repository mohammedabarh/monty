,       Read first digit
>       Move to second cell
,       Read second digit
[
    <   Move to first cell
    [
        >+  Add to result
        >+  Add to temp
        <<- Decrement first digit
    ]
    >>  Move to temp
    [
        <<+ Restore first digit
        >>- Clear temp
    ]
    <-  Decrement second digit
]
<       Move to result

>>++++++++++<<    Set up 10 in third cell

[           Start division loop
    >       Move to tens place
    [>+>+<<-]   Move digit to fourth and fifth cells
    >
    [<+>-]     Move digit back to fourth cell
    <<-        Decrement original number
]

>>[>+<-]    Move tens digit to fifth cell

>           Move to ones digit (fourth cell)
++++++      Add 6
[
    <++++++>    Add 6 to tens digit (fifth cell)
    -           Decrement counter
]
<           Move to tens digit
++++++      Add 6 more

>           Move to ones digit
[<+>-]      Move ones digit to tens digit cell

<           Move to tens digit
[           Print tens digit if it exists
    -
    >>++++++++++.  Print digit
    [-]        Clear print cell
    <<
]

>           Move to ones digit
++++++++    Add 8 (total 48 for ASCII '0')
.           Print ones digit

>           Move to newline cell
++++++++++  Set to 10
.           Print newline
