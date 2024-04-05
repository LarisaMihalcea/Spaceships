# Spaceships
It is the year 3241, and programmers are still needed in the stellar federation. To train future generations of astronauts, you are secretly a member of the team developing a new simulator for naval battles.

Requirement
Information about the ships participating in the battles will be read from the keyboard, followed by the actual commands. The ships remaining after the conflict will be displayed in descending order of their total power.
Input data
The first line contains the number n representing the number of ships in the fleet. On the following n lines, there is a ship defined by name, attack, and shields, separated by one or more spaces. On line n+2, there is a number k that represents the number of commands, and on the last k lines, there is a command and new ship names. The commands can be "fight" or "transfer". The transfer command will use the "+" operator, and fight will use the "^" operator.

Output data
The names of the surviving ships will be displayed, in descending order of their total power, each on a new line.

Example:
input:
4
athena 50 500
jupiter 80 100 
zeus 200 200  
hera 200 200
2
fight athena jupiter 
combine zeus hera

output:
zeus
athena

Explanations:

The ships Athena and Jupiter fight each other. Athena has a shield strong enough to withstand the damage caused by Jupiter and in two rounds destroys its shield (2 * 50 == 100). It remains with a shield level of 420.

The ships Zeus and Hera combine, thus remaining the ship Zeus (the first) but with increased powers of 400 and 400.

Since the total power of the Zeus ship (800) is greater than that of Athena (470), it is displayed first.
