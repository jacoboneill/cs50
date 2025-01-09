SELECT p.name
FROM people p
JOIN stars s ON p.id = s.person_id
JOIN movies ON s.movie_id = movies.id
WHERE movies.title = "Toy Story";
