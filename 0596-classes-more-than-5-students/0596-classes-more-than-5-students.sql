# Write your MySQL query statement below

SELECT class 
from Courses
GROUP BY class
having COUNT(distinct student)>=5