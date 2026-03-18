# Write your MySQL query statement below
select p.product_id, COALESCE(
    ROUND(SUM(u.units * p.price)/NULLIF(SUM(u.units),0),2) ,
    0)  as average_price
     from Prices p LEFT JOIN UnitsSold u
    on u.product_id=p.product_id 
    WHERE 
    p.start_date<=u.purchase_date AND u.purchase_date<=p.end_date or 
    u.purchase_date is NULL
    GROUP BY p.product_id;
    