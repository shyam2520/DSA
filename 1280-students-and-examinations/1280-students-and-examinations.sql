# Write your MySQL query statement below
-- select a1.student_id,a1.student_name,a2.subject_name,count(*)  as attended_exams from Students a1
--     JOIN Examinations a2 on a1.student_id=a2.student_id group by a1.student_name,a2.subject_name;

select a1.student_id,a1.student_name,a2.subject_name,count(e1.subject_name) as attended_exams FROM Students a1 JOIN Subjects a2 
    LEFT JOIN  Examinations e1 on a1.student_id=e1.student_id and e1.subject_name=a2.subject_name
    GROUP BY  a1.student_id,a1.student_name,a2.subject_name order by a1.student_id,a2.subject_name;