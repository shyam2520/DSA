# Write your MySQL query statement below
select a1.name,a2.bonus from Employee a1 LEFT JOIN Bonus a2 on a1.empId = a2.empId 
    where a2.bonus is NULL or a2.bonus<1000;