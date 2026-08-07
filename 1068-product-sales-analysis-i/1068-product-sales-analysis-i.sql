# Write your MySQL query statement below
Select p.product_name , s.year  , s.price from Sales s LEFT OUTER JOIN Product p ON s.product_id=p.product_id