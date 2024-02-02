# Write your MySQL query statement below

select c.name AS Customers
from Customers as c
left join Orders as o
ON c.id=o.customerId 
WHERE o.customerId IS NULL