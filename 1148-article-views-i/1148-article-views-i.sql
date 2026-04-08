SELECT DISTINCT author_id as id
FROM Views v
WHERE
(SELECT COUNT(*)
FROM Views
WHERE v.author_id = author_id 
AND v.author_id = viewer_id) >= 1
ORDER BY author_id;