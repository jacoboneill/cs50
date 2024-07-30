SELECT
    m.title,
    m.year
FROM movies m WHERE m.title LIKE 'Harry Potter%' ORDER BY m.year;
