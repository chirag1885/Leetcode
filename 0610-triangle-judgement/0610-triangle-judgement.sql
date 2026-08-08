# Write your MySQL query statement below
SELECT x , y , z , (case when abs(x)+abs(y)>abs(z) AND abs(x)+abs(z)>abs(y) AND abs(z)+abs(y)>abs(x)  then 'Yes' else 'No' end) AS triangle
FROM Triangle
