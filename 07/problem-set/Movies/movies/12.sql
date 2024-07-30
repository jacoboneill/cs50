SELECT m.title FROM movies m
JOIN stars s ON m.id = s.movie_id
JOIN people p ON p.id = s.person_id
WHERE p.name IN ('Bradley Cooper', 'Jennifer Lawrence')
GROUP BY m.id
HAVING COUNT(p.name) = 2;
