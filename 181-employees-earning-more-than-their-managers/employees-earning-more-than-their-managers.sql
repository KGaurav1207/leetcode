# Write your MySQL query statement below

SELECT e1.name AS Employee FROM Employee as e1
left join Employee as e2 ON e1.managerid = e2.id
WHERE e1.salary>e2.salary;