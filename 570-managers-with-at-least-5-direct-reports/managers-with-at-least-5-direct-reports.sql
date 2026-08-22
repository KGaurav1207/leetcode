# Write your MySQL query statement below


select e.name from Employee as e
where(
    select count(*)
    from Employee as x
    where x.managerId = e.id
) >= 5;