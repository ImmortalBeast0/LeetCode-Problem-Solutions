SELECT 
LEFT(trans_date,7) AS month ,
country ,
COUNT(*) AS trans_count ,
SUM(state LIKE "approved") AS approved_count ,
SUM(amount) AS trans_total_amount ,
SUM(CASE WHEN (state LIKE "approved") THEN amount ELSE 0 END) AS approved_total_amount
FROM Transactions
GROUP BY country ,month;

