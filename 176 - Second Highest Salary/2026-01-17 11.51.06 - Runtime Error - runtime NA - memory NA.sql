# Write your MySQL query statement below
select max(salary) as second highestsalry
from employee
where max(salary) is null