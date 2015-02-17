#1022. Poor contestant Prob

##Constraints

Time Limit: 1 secs, Memory Limit: 32 MB

##Description

As everybody known, “BG meeting” is very very popular in the ACM training team of ZSU. 

After each online contest, they will go out for “smoking”. Who will be the poor ones that have to BG the others? Of course, the half who solve less problems. 
The rule runs well when the number of the contestants is even. But if the number is odd, it is impossible to divide them into two equal parts. It gives a dilemma to the BG meeting committee. After a careful discussion with Mr. Guo, a new rule emerged: if the number of the contestant is odd, the committee will first sort the contestants according to the number of problems they solved, and then they will pick out the middle one. This poor boy or girl will have no chance to attend the BG meeting. 

Strange rule, isn`t it?

As the number of the contestants is becoming more and more large, the committee need to write a program which will pick out the poor one efficiently.
Note that: Every contestant solves different number of problems. The total number of the contestants will not exceed 10^5.

##Input

There are several cases in the input. The first line of the input will be an integer M, the number of the cases.

Each case is consisted of a list of commands. There are 3 types of commands.

1. Add xxx n : add a record to the data base, where xxx is the name of the contestant, which is only consisted of at most 10 letters or digits, n is the number of problems he/she solved. (Each name will appear in Add commands only once).
2. Query :
3. End :End of the case.

##Output

1.For the Query command: If the current number of contestants is odd, the program should output the poor contestant’s name currently even if there is only one contestants, otherwise, just out put “No one!” (without quotes).
2.For the End command: 
   If the total number of contestants in the data base is even, you should out put “Happy BG meeting!!”(without quotes),otherwise, you should out put the “xxx is so poor. ”(without quotes) where xxx is the name of the poor one.
3.Each case should be separated by a blank line.

##Sample Input

2

Add Magicpig 100

Add Radium 600

Add Kingfkong 300

Add Dynamic 700 

Query

Add Axing 400

Query

Add Inkfish 1000

Add Carp 800

End

Add Radium 100

Add Magicpig 200

End
##Sample Output

No one!

Axing

Radium is so poor.

[blank line]

Happy BG meeting!!

Problem Source

ZSUACM Team Member