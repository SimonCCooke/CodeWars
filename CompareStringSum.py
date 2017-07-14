"""Compare two strings by comparing the sum of their values (ASCII character code).
For comparing treat all letters as UpperCase.

Null-Strings should be treated as if they are empty strings.
If the string contains other characters than letters, treat the whole string as it would be empty.

Examples:

"AD","BC" -> equal

"AD","DD" -> not equal

"gf","FG" -> equal

"zz1","" -> equal

"ZzZz", "ffPFF" -> equal

"kl", "lz" -> not equal

null, "" -> equal

Your method should return true, if the strings are equal and false if they are not equal."""

def compare(s1,s2):
    #your code here
    sum1 = 0
    sum2 = 0
    
    if s1 != None:
        for char1 in s1:
            if ord(char1.upper()) < 65 or ord(char1.upper()) > 90:
                sum1 = 0
                break
            sum1 = sum1 + ord(char1.upper())
    
    if s2 != None:
        for char2 in s2:
            if ord(char2.upper()) < 65 or ord(char2.upper()) > 90:
                sum2 = 0
                break
            sum2 = sum2 + ord(char2.upper())
            
        return (sum1==sum2)
