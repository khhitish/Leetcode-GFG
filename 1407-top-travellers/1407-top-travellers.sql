SELECT name, (SELECT IFNULL(SUM(distance),0) FROM Rides WHERE user_id=u.id) AS travelled_distance FROM Users u
ORDER BY travelled_distance DESC, name ASC;
