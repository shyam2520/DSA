# Write your MySQL query statement below
with low_qual as (select count(*) as lwr,query_name from queries where rating<3 group by query_name),
avg_qual as 
    (select
    query_name, 
    ROUND(AVG(rating/position),2) as neavg,count(*) as newcnt
    from queries group by query_name) 
select
    a.query_name,a.neavg as quality,
    COALESCE(ROUND(b.lwr/a.newcnt*100,2),0) as `poor_query_percentage`
    from
    avg_qual
    a LEFT JOIN low_qual b 
    on a.query_name=b.query_name;