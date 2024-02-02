# Write your MySQL query statement below


SELECT DISTINCT Num as ConsecutiveNums
FROM(
    SELECT Num,
    @cnt:= IF (@prev= (@prev:=Num),@cnt+1,1) AS freq
    
    FROM Logs,
    (SELECT @cnt:=0, @prev:=(SELECT Num FROM Logs LIMIT 1)) AS c

) AS n
WHERE freq>2

