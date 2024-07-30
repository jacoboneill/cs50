WITH kevin_bacon_movies AS (
    SELECT s.movie_id FROM stars s
    JOIN people p ON p.id = s.person_id
    WHERE p.name = 'Kevin Bacon' AND p.birth = 1958
),

cast_members AS (
    SELECT s.person_id FROM stars s
    JOIN kevin_bacon_movies kbm ON s.movie_id = kbm.movie_id
    WHERE
        s.person_id
        != (SELECT id FROM people WHERE name = 'Kevin Bacon' AND birth = 1958)
)

SELECT DISTINCT p.name
FROM people p
JOIN cast_members cm ON p.id = cm.person_id
