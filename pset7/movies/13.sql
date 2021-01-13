SELECT DISTINCT name FROM stars
JOIN movies ON stars.movie_id = movies.id
JOIN people ON stars.person_id = people.id
WHERE movies.title
IN (SELECT DISTINCT movies.title FROM movies
JOIN stars ON stars.movie_id = movies.id
JOIN people ON stars.person_id = people.id
WHERE name = 'Kevin Bacon' AND birth = 1958)
AND name != 'Kevin Bacon';
