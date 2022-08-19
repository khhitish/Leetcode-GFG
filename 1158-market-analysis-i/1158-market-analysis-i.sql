SELECT user_id AS buyer_id, join_date, (SELECT COUNT(*) FROM Orders y WHERE x.user_id = y.buyer_id AND YEAR(y.order_date)='2019') AS orders_in_2019 FROM Users x;
