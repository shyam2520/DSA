# Write your MySQL query statement below
# first join machine_id,process_id then you get  stsart and end activity subtract time stamp get varg
select a1.machine_id,ROUND(AVG(a2.timestamp - a1.timestamp),3) as processing_time from Activity a1 JOIN Activity a2 ON 
    a1.machine_id=a2.machine_id AND a1.process_id=a2.process_id
     where a1.activity_type='start' and a2.activity_type='end' GROUP BY a1.machine_id

