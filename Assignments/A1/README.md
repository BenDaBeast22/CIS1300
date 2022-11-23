All Programs -> Download all programs into same directory
             -> Note: Only CalculatorE.c works on different years (takes into account leap years)
             
CalculatorA.c -> Usage: ./dd1 mm1 yyyy1 dd2 mm2 yyyy2
              -> Function: Input 2 dates and CalculatorA.c will output the differance in days not including last date between the 2 dates
              -> To run: Using Makefile make CalculatorA.c and then run executable according to usage

CalculatorB.c -> Usage: ./dd1 mm1 yyyy1 dd2 mm2 yyyy2 include 
              -> Function: Same function as CalculatorA.c except user can add "include" at the end of input and the differance between the 2 dates will be found including the last date
              -> To run: Using Makefile make CalculatorB.c and then run executable according to usage

CalculatorC.c -> Usage: ./dd1-mm1-yyyy1 dd2-mm2-yyyy2 include 
              -> Function: Same function as CalculatorB.c except dates are formatted differently with dashes (check usage)
              -> To run: Using Makefile make CalculatorC.c and then run executable according to usage
              
CalculatorD.c -> Usage: today dd2-mm2-yyyy2 include (Same as CalculatorC.c except today can be used as either dates)
              -> Function: Same as CalculatorC.c except if the word today is included as the first or second date then the date will set to the current date
              -> To run: Using Makefile make CalculatorD.c and then run executable according to usage

CalculatorE.c -> Usage: today dd2-mm2-yyyy2 include (Same as CalculatorC.c except today can be used as either dates)
              -> Function: Same as CalculatorD.c except takes into account leap years in the amount of days between 2 dates (can be used on two different years)
              -> To run: Using Makefile make CalculatorE.c and then run executable according to usage
            
