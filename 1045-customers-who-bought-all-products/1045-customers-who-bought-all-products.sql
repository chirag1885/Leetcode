# Write your MySQL query statement below
SELECT customer_id
FROM Customer c
Group by customer_id
having (select count(distinct product_key) from Product )
=count( distinct product_key)