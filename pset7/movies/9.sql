SELECT DISTINCT (people.name) FROM stars
JOIN movies ON stars.movie_id = movies.id
JOIN people ON people.id = stars.person_id
WHERE year = 2004 ORDER BY people.birth;