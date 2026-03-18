# Write your MySQL query statement below
select V.customer_id,count(*) as count_no_trans from Visits V LEFT JOIN Transactions T on V.visit_id=T.visit_id
    where T.transaction_id is NULL GROUP BY V.customer_id ; 