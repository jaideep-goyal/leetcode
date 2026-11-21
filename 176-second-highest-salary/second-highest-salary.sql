# Write your MySQL query statement below
SELECT MAX(salary) AS Secondhighestsalary
FROM EMPLOYEE
WHERE salary < (SELECT MAX(salary) FROM Employee);
