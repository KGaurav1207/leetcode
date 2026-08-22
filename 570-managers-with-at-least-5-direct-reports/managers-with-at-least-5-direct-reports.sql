# Write your MySQL query statement below

select e.name from Employee as e
join Employee as m on e.id = m.managerId
group by e.id, e.name
having count(e.id)>=5;
