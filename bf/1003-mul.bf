,>++++++++[<------>-](num1)  # Read first digit and convert from ASCII to decimal
,>++++++++[<------>-](num2)  # Read second digit and convert from ASCII to decimal
<<[->(copyStart)[>+>+<<-]>>[-<<+>>](copyEnd)<[->>+<<]<<(addition)]  # Multiply the two numbers
>>>>>++++++++++(loopInit)<  # Initialize for decimal conversion
[->-[>+>>]>[+[-<+>]>+>>]<<<<<]  # Convert result to decimal representation
>>>>++++++++[<++++++>-]<.  # Convert first digit to ASCII and print
<[->>+<<]  # Shift to next digit
>>>++++++++[<++++++>-]<.  # Convert second digit to ASCII and print
>++++++++++.  # Print newline character
