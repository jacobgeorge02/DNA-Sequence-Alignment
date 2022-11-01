/**********************************************************************
 *  ps5-readme                                                
 *  DNA Sequence Alignment
 **********************************************************************/

Name: Jacob George

(Partnering is optional. See the guidelines on the assignments page.)
I did not work on this with a partner
Partner's name: N/A

Hours to complete assignment (optional): 7 hours

Which partner is submitting the program files?
N/A 

/**********************************************************************
 *  Explain what you did to find the alignment itself.
 **********************************************************************/
To find the alignment after finding the optimal distance, I run some if-elseif statements
to see if a specific value in the matrix matches up with each other. Depending on the case
(the characters match and/or the values match in a specific row & column), the matrix will
move through the optimal path diagonally, down, or right. I used the dynamic programming
approach in optDistance(), creating a nesting for loop to find the values after calculating
all the values that would only move horizontally & all the values that would move vertically 
(which would be creating segmentation faults if moved down or diagonally).
/**********************************************************************
 * You are required to create one additional test case by hand. 
 * It should be constructed in such a way that you know the correct 
 * output before running your program on it, and it should be a 
 * "corner case" that helps check if your program handles all special 
 * situations correctly. Please list:
 * - a copy of the test case input
 * - the expected test case output
 * - whether your program ran correctly on it or not
 * - optionally, any other remarks
 **********************************************************************/
Input: testCase.txt

Expected output:
Should give an edit distance of 0, the matrix would filled with zeros, and the optimal path would
be filled with zeros

What happened:
Edit Distance = 0
A A 0
A A 0
C C 0
A A 0
G G 0
T T 0
T T 0
A A 0
C C 0
C C 0
Execution time is 0.00179 seconds

/**********************************************************************
 *  How much main memory does your computer have? Typical answers
 *  are 2GB and 4GB. If your machine has 512MB or less, use a cluster
 *  machine for this readme (see the checklist for instructions).
 **********************************************************************/
16 GBs of RAM
/**********************************************************************
 *  For this question assume M=N. Look at your code and determine
 *  approximately how much memory it uses in bytes, as a function of 
 *  N. Give an answer of the form a * N^b for some constants a 
 *  and b, where b is an integer. Note chars are 2 bytes long, and 
 *  ints are 4 bytes long.
 *
 *  Provide a brief explanation.
 *
 *  What is the largest N that your program can handle if it is
 *  limited to 1GB (billion bytes) of memory?
 **********************************************************************/
a = 2
b = 4
largest N = 149.534

The equation I made should be equal to 1000000000 due to the limited size of 1Gb.

2*N^4 = 1000000000 (1GB) 
N^4 = 500000000
N = 149.534
/**********************************************************************
 *  For each data file, fill in the edit distance computed by your
 *  program and the amount of time it takes to compute it.
 *  For help on how to do timing, see the checklist (e.g. -Xprof).
 *  If you get an OutOfMemoryError, see the checklist about -Xmx.
 *  If you get "Could not reserve enough space for object heap" or the timing
 *  of these tests takes too long for the last few test cases (N=20000 or higher), 
 *   note this, and skip filling out those rows of the table.
 **********************************************************************/
data file           distance       time (seconds)
-------------------------------------------------
ecoli2500.txt        118            0.374577
ecoli5000.txt        160            2.29013
ecoli10000.txt       223            8.99543
ecoli20000.txt       3135           25.9576
ecoli50000.txt       19485          142.251
ecoli100000.txt      killed         killed
/*************************************************************************
 *  Here are sample outputs from a run on a different machine for 
 *  comparison.
 ************************************************************************/
data file           distance       time (seconds)
-------------------------------------------------
ecoli2500.txt          118             0.171
ecoli5000.txt          160             0.529
ecoli7000.txt          194             0.990
ecoli10000.txt         223             1.972
ecoli20000.txt         3135            7.730
/**********************************************************************
 *  For this question assume M=N (which is true for the sample files 
 *  above). By applying the doubling method to the data points that you
 *  obtained, estimate the running time of your program in seconds as a 
 *  polynomial function a * N^b of N, where b is an integer.
 *  (If your data seems not to work, describe what went wrong and use 
 *  the sample data instead.)
 *
 *  Provide a brief justification/explanation of how you applied the
 *  doubling method.
 * 
 *  What is the largest N your program can handle if it is limited to 1
 *  day of computation? Assume you have as much main memory as you need.
 **********************************************************************/
a = 2
b = 4
largest N = 598.138

I applied the doubling method by first assuming the max amount of memory I could use, Which
in my case is 1.6e+10 (since I have 16 GBs of RAM) then solved for N, and multiplied
the result by 2.

2*N^4 = 1.6e+10 (16GB) 
N^4 = 1.6e / 2
N = 299.069 * 2 = 598.138

/**********************************************************************
 *  If you worked with a partner, do you have any remarks on the pair
 *  programming method? E.g., how many times did you switch, what are
 *  the tradeoffs of driving vs. navigating, etc.
 **********************************************************************/
N/A
/**********************************************************************
 *  List whatever help (if any) you received from lab TAs, preceptors,
 *  classmates, past COS 126 students, or anyone else.
 **********************************************************************/
Matrix Notes & Matrix Lecture Code: Dr. Daly Lecture Notes
Dr. Daly Discord Server
Links:
https://en.wikipedia.org/wiki/Needleman%E2%80%93Wunsch_algorithm
Explanation of the Needleman-Wunsch Algorithm
Tutor: Seneca A - Explained how alignment cases should work
/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
When testing out the ecoli text files when I tried the print out the edit distance,
the output was so big that I believe the terminal couldn't scroll up to the edit distance 
score. If I ran a smaller txt file such as example10.txt, then there would be no issues.
If running a big txt file such as running ecoli files, you can copy my line 21
in my main.cpp and paste it under my line 22. This way you can properly see the edit
distance score without the terminal cutting it off. Also, a somewhat strange effect that
is going on in my optDistance is that on line 
/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
how to run: 
make
./EDistance < filename.txt
make clean

you can run whatever .txt you want

CPU Info/Type - AMD Ryzen 7 4800H
CPU Speed - 2.90 GHz
Implementation Method: Needleman-Wunsch
Matrix method: 2D-Vector
Operating System: Windows 10

ecoli2500.txt: Memory-used = 7300 MB, time-to-solution = 0.220681 sec
ecoli5000.txt: Memory-used = 7700 MB, time-to-solution = 1.51251 sec
ecoli7000.txt: Memory-used = 7900, time-to-solution = 2.9344 sec
ecoli10000.txt: Memory-used = 8000, time-to-solution = 6.02463 sec
ecoli20000.txt: Memory-used = 9200, time-to-solution = 18.027 sec
ecoli28284.txt: Memory-used = 10100, time-to-solution = 32.5985

Valgrind Analysis: Throughout my code I allocate 82 times to the heap and have no memory
leaks in the end.
