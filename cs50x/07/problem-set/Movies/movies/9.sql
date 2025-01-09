SELECT DISTINCT p.name
FROM people p
JOIN stars s ON p.id = s.person_id
JOIN movies m ON m.id = s.movie_id
WHERE m.year = 2004 AND p.birth > 0
ORDER BY p.birth;
