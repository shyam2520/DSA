# Write your MySQL query statement below
select r.contest_id,ROUND((count(*) / (select count(*) from Users))*100,2) as percentage
     from Register r JOIN Users u on r.user_id=u.user_id
    group by r.contest_id order by percentage desc, r.contest_id ASC;