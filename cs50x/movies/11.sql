--In 11.sql, write a SQL query to list the titles of the five highest rated movies (in order) that
--Chadwick Boseman starred in, starting with the highest rated
-- SELECT DISTINCT title, rating
-- FROM movies
-- JOIN stars
-- ON movies.id = stars.movie_id
-- JOIN people
-- ON stars.person_id = people.id
-- JOIN ratings
-- ON movies.id = ratings.movie_id
-- WHERE people.name = 'Chadwick Boseman'
-- ORDER BY rating DESC
-- LIMIT 5;

SELECT title
FROM movies
WHERE id IN (
SELECT movie_id as x
FROM ratings
WHERE movie_id IN (
    SELECT movie_id
    FROM stars
    WHERE person_id = (
        SELECT id
        FROM people
        WHERE name = 'Chadwick Boseman'
    )
)
ORDER BY rating DESC
LIMIT 5
)
ORDER BY (
    SELECT r.rating
    FROM ratings r
    WHERE r.movie_id = movies.id
) DESC
;
