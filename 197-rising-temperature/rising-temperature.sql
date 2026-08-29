# Write your MySQL query statement below


select today.id from Weather as today 
cross join Weather as yesterday 
where datediff(today.recordDate,yesterday.recordDate) = 1 and today.temperature > yesterday.temperature; 