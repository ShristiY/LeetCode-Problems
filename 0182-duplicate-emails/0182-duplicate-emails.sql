# Write your MySQL query statement below

select Email
from Person
GROUP BY Email
having count(Email)>1