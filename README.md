# How to run my code:
## Running using bash script:
    1. clone this repo on your local machine
        ensure your machine have c related environment.

    2. open 'src' folder in terminal
        
    3. Authorize Terminal to execute your script:
    
        chmod +x run.sh
        
    4. Input related information:
        For example:
        
            USERNAME@ID src % ./run.sh
            Input the file path
            ./tests/test1.txt
            ascending(-a) or descending(-d)?
            -a
            alpha-numeric(-alpha) or numeric(-num)?
            -alpha
            Apple
            Banana
            Cake
            Crepe
            Orange

## Running using gcc
    1. clone this repo on your local machine
        ensure your machine have c related environment.

    2. open 'src' folder in terminal

    3. input: gcc homework2.c -o homework2

    4. input: ./homework2 ./tests/<file name> <'-a'/'-d'> <'-alpha'/'num'>
        
        Note that: <'-a'/'-d'> <'-alpha'/'num'> is not necessary needed,
                    the default setting is ascending order, and alpha-numberic.
    
        Sample input for the step 3 can be:

            ./homework2 ./tests/test1.txt
            ./homework2 ./tests/test1.txt -a
            ./homework2 ./tests/test1.txt -a -alpha
    
    Default order is ascending alpha-numeric order.


# Detail of alpha-numeric order:
This alpha-numeric order is that uppercase will also ahead of lowercase first.
Except the Uppercase and lowercae, this algorithm compare each char by using its ASCII value. 
## Example 1
    Apple
    apple
    Banana
    banana
    Cake
    Crepe
    cake
    crepe
    Orange
    orange
   
    Instead of ordering in:
        Cake
        cake
        Crepe
        crepe
    My algorithm cares about Uppercase.
    The first digit 'c' in "cake" is lower case, which should be ordered after "Crepe"
    
    
## Example 2
    1.txt
    10.txt
    3.txt
    a10b1.txt
    a1b1.txt
    a2b1.txt
    a2b11.txt
    a2b2.txt
    b1.txt
    b10.txt
    b2.txt
                
# Detail of numberic order:
Multiple successive digits are counted as one element in this algorithm.
Except the digit, it compares the value of char in ASCII table
## Example 1
    Apple
    Banana
    Cake
    Crepe
    Orange
    apple
    banana
    cake
    crepe
    orange
    
    Without digits, it only compare values in ASCII

## Example 2
    1.txt
    3.txt
    10.txt
    a1b1.txt
    a2b1.txt
    a2b2.txt
    a2b11.txt
    a10b1.txt
    b1.txt
    b2.txt
    b10.txt
    
    Multiple digits number are count as one character. 
    For example: 
        "a2b11.txt", is sepearated in 5 parts: {a, 2, b, 11, .txt}
        "a10b1.txt", is sepearated in 5 parts: {a, 10, b, 1, .txt}
        Since, the first element is equal, the second element will determine which one go first.
        2>10, so that "a2b11.txt" is ahead of "a10b1.txt".





    
    
