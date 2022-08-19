# SELECT user_id AS buyer_id, join_date, (SELECT COUNT(*) FROM Orders y WHERE x.user_id = y.buyer_id AND YEAR(y.order_date)='2019') AS orders_in_2019 FROM Users x;
# SELECT * FROM Orders WHERE YEAR(order_date)='2019';
SELECT u.user_id AS buyer_id, u.join_date, IFNULL(COUNT(o.order_id),0) AS orders_in_2019
FROM Users u LEFT JOIN Orders o ON u.user_id = o.buyer_id AND YEAR(o.order_date)='2019'
GROUP BY u.user_id;
# HAVING YEAR(o.order_date)='2019';
