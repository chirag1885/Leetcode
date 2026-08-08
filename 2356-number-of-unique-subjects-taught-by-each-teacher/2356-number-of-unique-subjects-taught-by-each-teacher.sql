# Write your MySQL query statement below
SELECT teacher_id , COUNT(DISTINCT subject_id) AS cnt
FROM Teacher 
Group by teacher_id