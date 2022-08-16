SELECT a.id as 'Id' 
FROM Weather a INNER JOIN Weather b ON DATEDIFF(a.recordDate,b.recordDate) = 1 AND a.temperature > b.temperature;
