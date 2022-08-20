# Write your MySQL query statement below
SELECT f.product_id, product_name FROM (SELECT product_id, product_name FROM Product 
WHERE product_id NOT IN
(SELECT product_id FROM Sales WHERE sale_date>'2019-03-31' OR sale_date<'2019-01-01')) AS f
WHERE product_id IN (SELECT product_id FROM Sales);