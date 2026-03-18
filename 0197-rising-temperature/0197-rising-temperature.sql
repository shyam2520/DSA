# Write your MySQL query statement below
select w1.id as `Id` from Weather w1 JOIN Weather w2 where DATEDIFF(w1.recordDate,w2.recordDate)=1
 and w2.temperature<w1.temperature;