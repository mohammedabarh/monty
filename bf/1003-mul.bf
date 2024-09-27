,            Read first digit and store in cell 0
-[----->+<]  Convert ASCII to numeric value (subtract 48)
> ,         Read second digit and store in cell 1
-[----->+<]  Convert ASCII to numeric value (subtract 48)

>           Move to cell 2 (product), ensure it's initialized to 0
[-]         Clear cell 2 just in case

< [         Loop (cell 1) until it is 0
  -> + > +  Add value from cell 0 to cell 2
  < <       Move back to cell 0 and repeat
]

>           Move to cell 2 (product)
++++++[->++++++++++<] Convert numeric result back to ASCII (add 48)
.           Output the result as a character

