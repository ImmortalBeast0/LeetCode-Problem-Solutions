-- SUM(rating / position)  / count(queries) 
-- count(rating less than 3) / count(queries)
SELECT 
Q.query_name ,
ROUND(SUM(Q.rating / Q.position) / COUNT(*),2) AS quality ,
ROUND((SUM(Q.rating < 3)) / COUNT(*) * 100,2)
AS poor_query_percentage 
FROM Queries Q
GROUP BY query_name;