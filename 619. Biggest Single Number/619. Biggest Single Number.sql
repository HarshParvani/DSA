/*
 * Problem: 619. Biggest Single Number
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/biggest-single-number/submissions/2039077187/
 * Language: mysql
 * Date: 2026-06-19
 */

SELECT MAX(num) AS num
FROM MyNumbers
WHERE num IN (
    SELECT num
    FROM MyNumbers
    GROUP BY num
    HAVING COUNT(num) = 1
);

