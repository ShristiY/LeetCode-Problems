# Write your MySQL query statement below

select s.name 
from SalesPerson as s
where s.sales_id not in(
select sales_id 
    from Orders as o
    LEFT JOIN Company as c
    on o.com_id=c.com_id
    where c.name="RED"
);
