/*
    TEST 2 QUESTIONS 1 TO 4
    DIEGO ROSENBERG DE ANGOITIA
    NetID: dr3432
    Email: dr3432@nyu.edu
*/

/*
1. 
    Base Case: n = 4
        2(4) + 3 <= 2^4
        8 + 3 <= 16
        11 <= 16 QED

    Induction Case: Since P(k) is true, then P(k + 1) must be true).
    Where P(k) = 2k + 3 <= 2^k, and P(k) = 2(k + 1) + 3 <= 2^(k + 1).

        2(k + 1) + 3 <= 2^(k + 1)
        2k + 2 + 3 <= 2^k * 2
        2k + 5 <= 2^k * 2
            Using the lower bound for the inequality, we know that
            2^k = 2k + 3
        2k + 5 <= (2k + 3) * 2
        2k + 5 <= 4k + 6
            Simplifying
        0 <= 2k + 1 for every k >= 4. QED

    Therefore the inequality is true for all integers n >= 4.

2. 
    a) Since letter 1 and 8 (in a 1-indexed fasihon) are linked,
    we can reduce a degree of freedom from the problem. Since for
    every slot we can pick between all 26 letters for all 7 remaining
    degrees of freedom.

    Therefore the number of words will be:
    Num Words = 26^7 = 8,031,810,176

    b) Here we have 8 possible positions where we can place the letter
    'c'. Therefore once we pick the position of the letter 'c', there
    will be 7 remaining slots for the other letters, including c since there
    has to be AT LEAST 1 'c', and not ONLY one.

    Therefore the number of words will be:
    Num Words = 8 * 26^7 = 64,254,481,408

3. 
    a) Here we have the added restriction where every letter has to be unique.Therefore,
    for the first letter we have 5 options (5 vowels), however for the last we will only
    have 4. The remainig 4 letters will have to be chosen from a pool of 24 letters which
    have not been chosen. 

    Therefore the probability would be: 
    P(3.a) = ( 5 * 4 * C(24, 4) ) / C(26, 6)

    b) Here we have a Bernouli trial problem with 10 tries. So the probability of success, p, will
    be p = 3/4. While the probability of failure, q, will be q = 1/4.

    Therefore using the Bernouli trial equation the result will be:
    P(9 out of 10) = C(10, 9) * (1/4)^(10 - 9) * (3/4)^9
    P(9 out of 10) = 0.1877

4. 
    function1       RESULT: T(n) = Theta(n^2)
    Explanation: Both loops have interior cases that in their "worst" case are O(n),
    and the exterior of the loop is identical so we dont have to use both.
    The outer part of the loop runs in time n/2 since wince we ignore constants this is only n.
    In the inner loop the worst case for the loop is running in time n. Therefore if we run the
    interior loop n times we get n^2.

    function2       RESULT: T(n) = Theta(n^2)
    Explanation: The inner loop of while (j <= i) with j incrementing j*2 every iteration runs at
    n/2 time in its worst case. Since we ignore constants we know that the inner loop runs on n time. 
    For the outer loop it is the same case, the time would be n/2 but since we ignore consants it is n. 
    Therefoere running the interior loop n times we get that the time complexity is n^2.

*/