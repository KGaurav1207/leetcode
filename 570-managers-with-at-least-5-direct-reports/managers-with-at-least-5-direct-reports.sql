# Write your MySQL query statement below

select e.name from Employee e
join (
    select managerId 
    from Employee
    group by managerId 
    having count(*)>=5
) t
on e.id = t.managerId;