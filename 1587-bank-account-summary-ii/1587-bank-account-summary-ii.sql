SELECT f.name, f.balance FROM (SELECT name,(SELECT SUM(amount) FROM Transactions t WHERE t.account=u.account) AS balance FROM Users u) AS f WHERE f.balance > 10000; 